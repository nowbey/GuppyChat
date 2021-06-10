#include "Client.h"

/*-------------------------------------  Client constructor  ------------------------------------
 *
 * ClientConnection (QWidget *parent)
 *   QWidget *parent     -> optional
 *
 * This Object hold the client socket and all the client/server communication
 *
 *-----------------------------------------------------------------------------------------------*/
Client::Client(QTcpSocket* Socket)
{
    clientName = "Unknown";
    messageSize = 0;
    UserValidation = false;
    messageType = MessageType::GUPPYMESSAGEUNKNOWN;

    this->Socket = Socket;

    connect(Socket, SIGNAL(readyRead()), this, SLOT(DataReceived()));
    connect(Socket, SIGNAL(disconnected()), this, SLOT(ClientDisconnection()));
}
Client::~Client()
{
    this->Socket->deleteLater();
}


/*-------------------------------------  Client slots  -----------------------------------*/
/*---------------------------------  Client DataReceived  ----------------------------------
 *  This slot is called when data is recieved from the socket
 *  Lets get the message and cast it to get the client request
 *-----------------------------------------------------------------------------------------*/
void Client::DataReceived()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    // Return if we an't get the socket
    if (socket == nullptr)
        return;

    QDataStream in(socket);

    // If this is the first exchange of this communication, get the full message size
    if (this->messageSize == 0){
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;
        in >> this->messageSize;
    }

    // If we still don't know the message format, get it (!!! Required to deserialize in the correct object)
    if(this->messageType == MessageType::GUPPYMESSAGEUNKNOWN){
        if (socket->bytesAvailable() < (int)sizeof(quint8))
             return;
        quint8 tmp;
        in >> tmp;
        this->messageType = static_cast<enum MessageType>(tmp);
    }

    // If we still don't have the full message we are waiting for the next exchange
    if (Socket->bytesAvailable() < this->messageSize) // Si on n'a pas encore tout reçu, on arrête la méthode
        return;

    // All the message has been received, let's get the data !
    // If the client is still waiting for validation, we only expect him to send GUPPYSENDCREDENTAILS message
    if (this->UserValidation == false){
         if (this->messageType == MessageType::GUPPYSENDCREDENTAILS){
             GuppySendCredentials* newMessageReceived = new GuppySendCredentials();
             newMessageReceived->deserialize(in);

             // Check the user credentials

             this->UserValidation = true;
             this->clientName = newMessageReceived->GetGuppyUser();


             sendUserValidation(this->UserValidation);
             emit NewClientIdentified(this);
         }

    // else, we only expect him to send GUPPYCLIENTSERVERMESSAGE message
    }else if (this->messageType == MessageType::GUPPYCLIENTSERVERMESSAGE){
        GuppyClientServerMessage* newMessageReceived = new GuppyClientServerMessage();
        newMessageReceived->deserialize(in);

        GuppyServerClientMessage* newMessageToSend = new GuppyServerClientMessage(newMessageReceived->GetMessage(),this->clientName,"Public");
        emit MessageToBeDelivered(*newMessageToSend);
    }

    // reset messageSize for the next messages
    this->messageSize = 0;
    this->messageType = MessageType::GUPPYMESSAGEUNKNOWN;
}


/*-----------------------------  Client ClientDisconnection  -------------------------------
 *  This slot is called when the socket is aborted
 *  Send this information
 *-----------------------------------------------------------------------------------------*/
void Client::ClientDisconnection()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    // Return if we an't get the socket
    if (socket == nullptr)
        return;
    // Send the ClientDisconnected signal indicating which client is disconnected
    emit ClientDisconnected(this);
}




/*-----------------------------------  Client Methodes  ----------------------------------*/
/*---------------------------------  Client GetClientName  ----------------------------------
 *  Getter on the clientName attribute
 *-----------------------------------------------------------------------------------------*/
const QString& Client::GetClientName() const{
    return this->clientName;
}

/*-----------------------------  Client SendMessageToClient  -------------------------------
 *  This slot is called to send a message to the client
 *-----------------------------------------------------------------------------------------*/
void Client::SendMessageToClient(const GuppyServerClientMessage& message)
{
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    // fill the stream with the size, the object type and the serialized object
    stream << (quint16) 0;
    stream << static_cast<quint8>(message.GetMessageType());
    message.serialize(stream);
    stream.device()->seek(0);
    stream << (quint16) (buffer.size() - sizeof(quint16) - sizeof(quint8));
    qDebug() << "writing GuppyServerClientMessage for client buffer.size():" << buffer.size() << "Type:" << static_cast<quint8>(message.GetMessageType());

    this->Socket->write(buffer);
}

/*-----------------------------  Client SendUserListToClientconst  -------------------------------
 *  This slot is called to send a message to the client
 *-----------------------------------------------------------------------------------------*/
void Client::SendUserListToClient(const GuppySendUserList& UserList)
{
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    // fill the stream with the size, the object type and the serialized object
    stream << (quint16) 0;
    stream << static_cast<quint8>(UserList.GetMessageType());
    UserList.serialize(stream);
    stream.device()->seek(0);
    stream << (quint16) (buffer.size() - sizeof(quint16) - sizeof(quint8));
    qDebug() << "Sending messageList to client:" << this->clientName;

    this->Socket->write(buffer);
}


/*-----------------------------  Client sendUserValidation  --------------------------------
 *  This methode is called after reception of GUPPYSENDCREDENTAILS
 *  It inform the Client of the server server decision.
 *-----------------------------------------------------------------------------------------*/
void Client::sendUserValidation(bool UserValidationStatus){
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    GuppyUserValidation UserValidation = new GuppyUserValidation(UserValidationStatus);

    stream << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    stream << static_cast<quint8>(UserValidation.GetMessageType());
    UserValidation.serialize(stream);
    stream.device()->seek(0);
    stream << (quint16) (buffer.size() - sizeof(quint16) - sizeof(quint8));
    qDebug() << "writing for client buffer.size():" << buffer.size();

    this->Socket->write(buffer);

}



