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

    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &ClientConnection::connected);
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
    this->hide();
    fenetreChat = new ClientChat(socket,  userName->text());
    fenetreChat->show();
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
