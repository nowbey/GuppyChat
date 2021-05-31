#include "message.h"

Message::Message()
{
    messageType = "SENDMESSAGE";
    sourceName = "Unknown";
    destinataireName = "Unknown";
    message = "";
}

Message::Message(const QString& sourceName, const QString& destinataireName,const QString& message, const QString& messageType) : sourceName(sourceName), destinataireName(destinataireName), message(message), messageType(messageType)
{
}


const QString&  Message::GetSourceName(){
    return sourceName;
}
const QString&  Message::GetDestinataireName(){
    return destinataireName;
}
const QString& Message::GetMessage(){
    return message;
}
const QString& Message::GetMessageType(){
    return messageType;
}



void Message::SetSourceName(QString sourceName){
    this->sourceName = sourceName;
}
void Message::SetDestinataireName(QString destinataireName){
    this->destinataireName = destinataireName;
}
void Message::SetMessage(QString message){
    this->message = message;
}
void Message::SetMessageType(QString messageType){
    this->messageType = messageType;
}


QDataStream& Message::serialize(QDataStream& out) const {
    out << sourceName;
    out << destinataireName;
    out << message;
    return out;
}

QDataStream& Message::deserialize(QDataStream& inStream){
    inStream >> sourceName;
    inStream >> destinataireName;
    inStream >> message;
    return inStream;
}
