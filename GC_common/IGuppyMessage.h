#ifndef GUPPYMESSAGE_H
#define GUPPYMESSAGE_H

#include <QString>
#include <QDataStream>

enum class MessageType
{
    GUPPYSENDCREDENTAILS,
    GUPPYUSERVALIDATION,
    GUPPYCLIENTSERVERMESSAGE,
    GUPPYSERVERCLIENTMESSAGE,
    GUPPYSENDUSERSLIST,
    GUPPYMESSAGEUNKNOWN
 };

/*------------------------------  IGuppyMessage virtual class  -----------------------------------
 *
 * This virtual class is used as parrent for all messages classes used on communication
 * between the clients and the server.
 *
 * It contains the common required methodes serialize/deserialize
 *
 *-----------------------------------------------------------------------------------------------*/
class IGuppyMessage
{

protected:
    MessageType MessageObjectType;

public:
    virtual MessageType GetMessageType() const{
        return MessageObjectType;
     }

    /*--------------------------  virtual serialize/deserialize methodes ----------------------------
     * This methodes must be implemented by childs to serialize/serialize the child class adtibutes
     *-----------------------------------------------------------------------------------------------*/
    virtual QDataStream& serialize(QDataStream& out) const = 0;
    virtual QDataStream& deserialize(QDataStream& inStream) = 0;
};


#endif // GUPPYMESSAGE_H
