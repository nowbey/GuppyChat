#ifndef GUPPYCREDENTIAL_H
#define GUPPYCREDENTIAL_H
#include "IGuppyMessage.h"

class GuppySendCredentials : public IGuppyMessage
{
public:
    GuppySendCredentials();
    GuppySendCredentials(const QString& GuppyUser, const QString& GuppyPassword);


private:
    QString GuppyUser;
    QString GuppyPassword;

public:
    const QString& GetGuppyUser() const;
    const QString& GetGuppyPassword() const;

    QDataStream& serialize(QDataStream& out) const;
    QDataStream& deserialize(QDataStream& inStream);
};

#endif // GUPPYCREDENTIAL_H
