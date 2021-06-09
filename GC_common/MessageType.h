#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H


enum class MessageType
{
    GUPPYSENDCREDENTAILS,
    GUPPYUSERVALIDATION,
    GUPPYSENDMESSAGE,
    GUPPYRECEIVEMESSAGE,
    GUPPYGETUSERSLIST
 };

    QDataStream &operator<<(QDataStream &stream, Type type)
    {
        return stream << static_cast<char>(type);
    }
};

#endif // MESSAGETYPE_H
