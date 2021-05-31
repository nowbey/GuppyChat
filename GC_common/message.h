#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

class Message
{

    public:
        Message();
        Message(const QString& sourceName, const QString& destinataireName,const QString& message, const QString& messageType);
        virtual ~Message() = default;

    private:
        QString sourceName;
        QString destinataireName;
        QString message;
        QString messageType;

    public:
        const QString& GetSourceName();
        const QString& GetDestinataireName();
        const QString& GetMessage();
        const QString& GetMessageType();

        void SetSourceName(QString sourceName);
        void SetDestinataireName(QString destinataireName);
        void SetMessage(QString message);
        void SetMessageType(QString messageType);

        QDataStream& serialize(QDataStream& out) const;
        QDataStream& deserialize(QDataStream& inStream);

};

#endif // MESSAGE_H
