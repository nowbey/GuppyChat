#include "GuppySendUserList.h"

GuppySendUserList::GuppySendUserList(){
    this->ListOfUsers = {};
    this->MessageObjectType = MessageType::GUPPYSENDUSERSLIST;
}

GuppySendUserList::GuppySendUserList(QList<QString> ListOfUsers) : ListOfUsers(ListOfUsers){
    this->MessageObjectType = MessageType::GUPPYSENDUSERSLIST;
}


QList<QString> const GuppySendUserList::GetListOfUsers() const{
    return this->ListOfUsers;
}



QDataStream& GuppySendUserList::serialize(QDataStream& out) const {
    out << this->ListOfUsers.size();
    for(int i=0 ; i < this->ListOfUsers.size();i++){
        out << this->ListOfUsers[i];
    }
    return out;
}

QDataStream& GuppySendUserList::deserialize(QDataStream& inStream){
    int QlistSize;
    inStream >> QlistSize;

    QString tmp_sting;
    for(int i=0; i < QlistSize;i++){
        inStream >> tmp_sting;
        this->ListOfUsers.append(tmp_sting);
    }
    return inStream;
}

QDataStream& operator<<(QDataStream &outStream, const GuppySendUserList &UserList){
    UserList.serialize(outStream);
    return outStream;
}

QDataStream& operator>>(QDataStream &inStream, GuppySendUserList &UserList){
    UserList.deserialize(inStream);
    return inStream;
}
