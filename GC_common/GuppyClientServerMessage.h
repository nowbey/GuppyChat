#ifndef GUPPYSENDMESSAGE_H
#define GUPPYSENDMESSAGE_H
#include "IGuppyMessage.h"

class GuppyClientServerMessage : public IGuppyMessage
{
public:
    GuppyClientServerMessage();
    GuppyClientServerMessage(const QString& message, const QString& receiver);


private:
    QString message;
    QString recipient;

public:

    const QString& GetRecipient() const;
    const QString& GetMessage() const;


    QDataStream& serialize(QDataStream& out) const;
    QDataStream& deserialize(QDataStream& inStream);

};

#endif // GUPPYSENDMESSAGE_H
