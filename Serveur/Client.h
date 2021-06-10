#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QDebug>

#include "../GC_common/GuppySendCredentials.h"
#include "../GC_common/GuppyUserValidation.h"
#include "../GC_common/GuppyClientServerMessage.h"
#include "../GC_common/GuppyServerClientMessage.h"
#include "../GC_common/GuppySendUserList.h"

class Client: public QObject
{  
    Q_OBJECT

    public:
        Client(QTcpSocket* serveur);
        ~Client();

    private:
        QString clientName;
        QTcpSocket* Socket;
        quint16 messageSize;
        MessageType messageType;
        bool UserValidation;

    public:
        const QString& GetClientName() const;
        void SendMessageToClient(const GuppyServerClientMessage& message);
        void SendUserListToClient(const GuppySendUserList& userList);

    private:
        void sendUserValidation(bool UserValidationStatus);

    private slots:
        void DataReceived();
        void ClientDisconnection();

    signals:
        void ClientDisconnected(Client* thisClient);
        void NewClientIdentified(Client* thisClient);
        void MessageToBeDelivered (const GuppyServerClientMessage& message);

};

#endif // CLIENT_H
