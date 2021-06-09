#ifndef GUPPYRECEIVEMESSAGE_H
#define GUPPYRECEIVEMESSAGE_H
#include "IGuppyMessage.h"

class GuppyServerClientMessage : public IGuppyMessage
{
public:
    GuppyServerClientMessage();
    GuppyServerClientMessage(const QString& message, const QString& sender, const QString& recipient);


private:
    QString message;
    QString sender;
    QString recipient;
public:

    const QString& GetSender() const;
    const QString& GetMessage() const;
    const QString& GetRecipient() const;

    QDataStream& serialize(QDataStream& out) const;
    QDataStream& deserialize(QDataStream& inStream);

};

#endif // GUPPYRECEIVEMESSAGE_H
