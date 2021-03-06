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
    clientUserName = "Unknown";
    clientPassword = "";
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
    if (Socket->bytesAvailable() < this->messageSize) // Si on n'a pas encore tout re??u, on arr??te la m??thode
        return;

    // All the message has been received, let's get the data !
    // If the client is still waiting for validation, we only expect him to send GUPPYSENDCREDENTAILS message
    if (this->UserValidation == false){
         if (this->messageType == MessageType::GUPPYSENDCREDENTAILS){
             GuppySendCredentials* newMessageReceived = new GuppySendCredentials();
             newMessageReceived->deserialize(in);

             this->clientUserName = newMessageReceived->GetGuppyUser();
             this->clientPassword = newMessageReceived->GetGuppyPassword();

             // Check the user credentials
             emit NewClientIdentificationRequest(this);
         }

    // else, we only expect him to send GUPPYCLIENTSERVERMESSAGE message
    }else if (this->messageType == MessageType::GUPPYCLIENTSERVERMESSAGE){
        qDebug() << "DataReceived: GUPPYCLIENTSERVERMESSAGE recieved";
        GuppyClientServerMessage* newMessageReceived = new GuppyClientServerMessage();
        newMessageReceived->deserialize(in);

        GuppyServerClientMessage* newMessageToSend = new GuppyServerClientMessage(newMessageReceived->GetMessage(),this->clientUserName,newMessageReceived->GetRecipient());
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
    if (this->UserValidation){
        emit ClientDisconnected(this);
    }
}




/*-----------------------------------  Client Methodes  ----------------------------------*/
/*---------------------------------  Client GetClientName  ----------------------------------
 *  Getter on the clientName attribute
 *-----------------------------------------------------------------------------------------*/
const QString& Client::GetClientUserName() const{
    return this->clientUserName;
}
/*---------------------------------  Client Password  ----------------------------------
 *  Getter on the clientName attribute
 *-----------------------------------------------------------------------------------------*/
const QString& Client::GetClientPassword() const{
    return this->clientPassword;
}

bool Client::GetUserValidation() const{
    return this->UserValidation;
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
    qDebug() << "SendMessageToClient: writing GuppyServerClientMessage for client buffer.size():" << buffer.size() << "Type:" << static_cast<quint8>(message.GetMessageType());

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
    qDebug() << "SendUserListToClient: Sending messageList to client:" << this->clientUserName;

    this->Socket->write(buffer);
}


/*-----------------------------  Client sendUserValidation  --------------------------------
 *  This methode is called after reception of GUPPYSENDCREDENTAILS
 *  It inform the Client of the server server decision.
 *-----------------------------------------------------------------------------------------*/
void Client::sendUserValidation(bool UserValidationStatus){
    this->UserValidation = UserValidationStatus;
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    GuppyUserValidation *UserValidation = new GuppyUserValidation(UserValidationStatus);

    stream << (quint16) 0; // On ??crit 0 au d??but du paquet pour r??server la place pour ??crire la taille
    stream << static_cast<quint8>(UserValidation->GetMessageType());
    UserValidation->serialize(stream);
    stream.device()->seek(0);
    stream << (quint16) (buffer.size() - sizeof(quint16) - sizeof(quint8));
    qDebug() << "Sending user validation message with value: " << UserValidationStatus;

    this->Socket->write(buffer);

    if(!UserValidationStatus){
        this->Socket->close();
    }

}



