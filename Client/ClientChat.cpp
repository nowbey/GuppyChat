#include "ClientChat.h"


/*--------------------------------  ClientChat constructor  --------------------------------------
 *
 * ClientChat (TcpSocket* socket, QString userName, QWidget *parent)
 *   QTcpSocket* socket  -> mendatory (the socket must be connected before this object instantiation)
 *   QString userName    -> mendatory (the userName must be validated by server before this object instantiation) Todo
 *   QWidget *parent     -> optional
 *
 * This Object  generate the UI ClientChat
 *
 *-----------------------------------------------------------------------------------------------*/
ClientChat::ClientChat(QTcpSocket* socket, QString userName, QWidget *parent) : QWidget(parent){
    setupUi(this);

    this->socket = socket;
    this->userName = userName;
    this->messageSize = 0;
    this->messageType = MessageType::GUPPYMESSAGEUNKNOWN;

    // Remove the ugly white bar on tabWidget !!!
    tabWidget->tabBar()->setDrawBase(false);

    tabWidget->addTab(new ClientTabChat("Private", this),"Private");


    // Connect all usefull socket signals to the ClientChat slots
    connect(socket, &QTcpSocket::readyRead, this, &ClientChat::dataReceived);
    connect(socket, &QTcpSocket::disconnected, this, &ClientChat::disconnect);

    // Call one time the socket reader is case of data has been recieved before the signal connection
    dataReceived();
}

ClientChat::~ClientChat(){
    delete this;
}



void ClientChat::UpdaterListOfUsersConnected(QList<QString> ListOfUsersConnected){
    ListOfUsersWidget->clear();
    // Remove this client from the list
    ListOfUsersConnected.removeOne(this->userName);

    // Update the display
    ListOfUsersWidget->addItems(ListOfUsersConnected);
}



/*-------------------------  ClientChat::on_sendButton_clicked slot  ----------------------------
 *  This slot is called on sendButton clicked
 *  It use the socket to send an object "Message" to the server
 *-----------------------------------------------------------------------------------------------*/
void ClientChat::on_sendButton_clicked(){
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    // fill the Message with data
    GuppyClientServerMessage* messageToSend = new GuppyClientServerMessage(message->text(),"Public");

    // fill the stream with the size, the object type and the serialized object
    stream << (quint16) 0;
    stream << static_cast<quint8>(messageToSend->GetMessageType());
    messageToSend->serialize(stream);
    stream.device()->seek(0);
    stream << (quint16) (buffer.size() - sizeof(quint16) - sizeof(quint8));

    // Send the buffer to the server
    socket->write(buffer);

    message->clear(); // clear the message field
    message->setFocus(); // set the focus message field
}
// Pressing the Enter key has the same behavior as clicking the "Send" button.
void ClientChat::on_message_returnPressed(){
    on_sendButton_clicked();
}

/*---------------------  ClientChat::on_disconnectButton_clicked slot  ---------------------------
 *  This slot is called on disconnectButton clicked
 *  It stops the current socket
 *-----------------------------------------------------------------------------------------------*/
/*void ClientChat::on_disconnectButton_clicked(){
    this->socket->abort();
}*/



/*---------------------------  ClientChat::dataReceived slot  -----------------------------------
 *  This slot is called on data recived form the server
 *  it can be called several times until a message is completely received
 *-----------------------------------------------------------------------------------------------*/
void ClientChat::dataReceived(){
    while (!this->socket->atEnd()) {
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

        qDebug() << "reading from server buffer.size():" << this->messageSize << "Type:" << static_cast<quint8>(this->messageType);

        // If we still don't have the full message we are waiting for the next exchange
        if (this->socket->bytesAvailable() < this->messageSize)
            return;

        // All the message has been received, let's get the data !
        if (this->messageType == MessageType::GUPPYSERVERCLIENTMESSAGE){
            GuppyServerClientMessage *newMessageReceived = new GuppyServerClientMessage();
            newMessageReceived->deserialize(in);

            // Todo: Do it in a function
            publicMessageList->append(tr("<strong>") + newMessageReceived->GetSender() + tr("</strong> : ") + newMessageReceived->GetMessage());

        } else if (this->messageType == MessageType::GUPPYSENDUSERSLIST){
            GuppySendUserList *newMessageReceived = new GuppySendUserList();
            newMessageReceived->deserialize(in);

            UpdaterListOfUsersConnected(newMessageReceived->GetListOfUsers());

        }



        // reset messageSize for the next messages
        this->messageSize = 0;
        this->messageType = MessageType::GUPPYMESSAGEUNKNOWN;
    }
}

/*------------------------------  ClientChat::disconnect slot  ----------------------------------
 *  This slot is called when the communication with the server is broken voluntarily or not
 *  it close the chat UI and back to connection window (Todo)
 *-----------------------------------------------------------------------------------------------*/
void ClientChat::disconnect(){
    delete this;
}
