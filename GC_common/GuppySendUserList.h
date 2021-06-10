#ifndef GUPPYSENDUSERLIST_H
#define GUPPYSENDUSERLIST_H
#include "IGuppyMessage.h"
#include <QList>

class GuppySendUserList : public IGuppyMessage
{
public:
    GuppySendUserList();
    GuppySendUserList(QList<QString> ListOfUsers);

private:
    QList<QString> ListOfUsers;

public:
    const QList<QString> GetListOfUsers() const;

    QDataStream& serialize(QDataStream& out) const;
    QDataStream& deserialize(QDataStream& inStream);

};

QDataStream &operator<<(QDataStream &stream,const GuppySendUserList &message);
QDataStream &operator>>(QDataStream &stream, GuppySendUserList &message);

#endif // GUPPYSENDUSERLIST_H
