#include "GuppyClientServerMessage.h"

GuppyClientServerMessage::GuppyClientServerMessage(){
    this->message = "";
    this->recipient = "";
    this->MessageObjectType = MessageType::GUPPYCLIENTSERVERMESSAGE;
}

GuppyClientServerMessage::GuppyClientServerMessage(const QString& message, const QString& recipient) : message(message), recipient(recipient){
    this->MessageObjectType = MessageType::GUPPYCLIENTSERVERMESSAGE;
}



const QString& GuppyClientServerMessage::GetMessage() const{
    return message;
}
const QString& GuppyClientServerMessage::GetRecipient() const{
    return recipient;
}



QDataStream& GuppyClientServerMessage::serialize(QDataStream& out) const {
    out << message;
    out << recipient;
    return out;
}

QDataStream& GuppyClientServerMessage::deserialize(QDataStream& inStream){
    inStream >> message;
    inStream >> recipient;
    return inStream;
}
