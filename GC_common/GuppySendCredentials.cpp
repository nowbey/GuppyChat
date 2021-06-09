#include "GuppySendCredentials.h"

GuppySendCredentials::GuppySendCredentials(){
    GuppyUser = "";
    GuppyPassword = "";
    this->MessageObjectType = MessageType::GUPPYSENDCREDENTAILS;
}

GuppySendCredentials::GuppySendCredentials(const QString& GuppyUser, const QString& GuppyPassword) : GuppyUser(GuppyUser), GuppyPassword(GuppyPassword){
    this->MessageObjectType = MessageType::GUPPYSENDCREDENTAILS;
}



const QString&  GuppySendCredentials::GetGuppyUser() const{
    return GuppyUser;
}
const QString&  GuppySendCredentials::GetGuppyPassword() const{
    return GuppyPassword;
}



QDataStream& GuppySendCredentials::serialize(QDataStream& out) const {
    out << GuppyUser;
    out << GuppyPassword;
    return out;
}

QDataStream& GuppySendCredentials::deserialize(QDataStream& inStream){
    inStream >> GuppyUser;
    inStream >> GuppyPassword;
    return inStream;
}
