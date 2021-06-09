#include "GuppyServerClientMessage.h"

GuppyServerClientMessage::GuppyServerClientMessage(){
    this->message = "";
    this->sender = "";
    this->recipient = "";
    this->MessageObjectType = MessageType::GUPPYSERVERCLIENTMESSAGE;
}

GuppyServerClientMessage::GuppyServerClientMessage(const QString& message, const QString& sender, const QString& recipient) : message(message), sender(sender), recipient(recipient){
    this->MessageObjectType = MessageType::GUPPYSERVERCLIENTMESSAGE;
}



const QString& GuppyServerClientMessage::GetMessage() const{
    return message;
}
const QString& GuppyServerClientMessage::GetSender() const{
    return sender;
}
const QString& GuppyServerClientMessage::GetRecipient() const{
    return recipient;
}


QDataStream& GuppyServerClientMessage::serialize(QDataStream& out) const {
    out << message;
    out << sender;
    out << recipient;
    return out;
}

QDataStream& GuppyServerClientMessage::deserialize(QDataStream& inStream){
    inStream >> message;
    inStream >> sender;
    inStream >> recipient;
    return inStream;
}
