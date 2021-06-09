#include "ClientConnection.h"

/*--------------------------------  ClientConnection constructor  ---------------------------------
 *
 * ClientConnection (QWidget *parent)
 *   QWidget *parent     -> optional
 *
 * This Object generate the UI ClientConnection.
 * This allows the user to configure these credentials and indicate which server to connect to
 *
 *-----------------------------------------------------------------------------------------------*/
ClientConnection::ClientConnection(QWidget *parent) :  QWidget(parent){
    setupUi(this);

    this->messageType = MessageType::GUPPYMESSAGEUNKNOWN;
    this->messageSize = 0;

    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &ClientConnection::connected);
    connect(socket, &QTcpSocket::readyRead, this, &ClientConnection::dataReceived);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorSocket(QAbstractSocket::SocketError)));
}

ClientConnection::~ClientConnection(){
    delete this;
}




/*---------------------  ClientConnection::on_connectButton_clicked slot  ----------------------
*  This method is called when the connectButton is clicked.
*  It tries to connect to the server
*-----------------------------------------------------------------------------------------------*/
void ClientConnection::on_connectButton_clicked(){
    socket->abort(); // abort previous connections
    socket->connectToHost(serverIP->text(), 50885); // connect to the server
}
// Pressing the Enter key has the same behavior as clicking the "connectButton" button.
void ClientConnection::on_userName_returnPressed(){
    on_connectButton_clicked();
}

/*---------------------------  ClientConnection::connected slot  ---------------------------------
 *  This slot is called when the connection with server succeeded
 *  it open the ClientChat
 *-----------------------------------------------------------------------------------------------*/
void ClientConnection::connected(){
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    GuppySendCredentials *IdentificationMessage = new GuppySendCredentials(userName->text(),userPassword->text());

    stream << (quint16) 0;
    stream << static_cast<quint8>(IdentificationMessage->GetMessageType());
    IdentificationMessage->serialize(stream);
    stream.device()->seek(0);
    stream << (quint16) (buffer.size() - sizeof(quint16) - sizeof(quint8));

    socket->write(buffer);

}

void ClientConnection::dataReceived(){
    qDebug() << "Message from server";
    QDataStream in(this->socket);

    // If this is the first exchange of this communication, get the full message size
    if (this->messageSize == 0){
        if (this->socket->bytesAvailable() < (int)sizeof(quint16))
             return;
        in >> this->messageSize;
    }
    if(this->messageType == MessageType::GUPPYMESSAGEUNKNOWN){
        if (this->socket->bytesAvailable() < (int)sizeof(quint8))
             return;
        quint8 tmp;
        in >> tmp;
        this->messageType = static_cast<enum MessageType>(tmp);
    }

    qDebug() << "Connection Message from server socket->bytesAvailable()" << socket->bytesAvailable();
    qDebug() << "Connection Message from server messageSize:" <<this->messageSize;
    qDebug() << "Connection Message from server messageType:" << static_cast<quint8>(this->messageType);

    // If we still don't have the full message we are waiting for the next exchange
    if (this->socket->bytesAvailable() < this->messageSize)
        return;

    // All the message has been received, let's get the data !
    if (this->messageType == MessageType::GUPPYUSERVALIDATION){
        GuppyUserValidation *newMessageReceived = new GuppyUserValidation();
        newMessageReceived->deserialize(in);

        if (newMessageReceived->GetGuppyUserValidationVar() == true){
            fenetreChat = new ClientChat(socket,  userName->text());
            disconnect(socket, &QTcpSocket::readyRead, this, &ClientConnection::dataReceived);
            fenetreChat->show();
            this->close();
        }
    }
    // reset messageSize for the next messages
    this->messageSize = 0;
    this->messageType = MessageType::GUPPYMESSAGEUNKNOWN;
}


/*--------------------------  ClientConnection::errorSocket slot  --------------------------------
 *  This slot is called if an error signal sent by the socket
 *  it generate a message box depending on the error
 *-----------------------------------------------------------------------------------------------*/
void ClientConnection::errorSocket(QAbstractSocket::SocketError error){
    switch(error){
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::critical(this, "Unable to find the server", "Make sure that ther server is running and check the IP address and port");
            break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::critical(this, "Connection refused by the server", "maybe you're knocking on the wrong door");
            break;
        case QAbstractSocket::RemoteHostClosedError:
            QMessageBox::critical(this, "Connection aborted by the server", "Get out of here !");
            break;
        default:
            QMessageBox::critical(this, "ERROR", socket->errorString());
    }
}



