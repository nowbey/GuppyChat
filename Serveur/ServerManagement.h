#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtNetwork>

#include "ui_ServerManagement.h"

#include <Client.h>

/*--------------------------------  ServerManagement constructor  ---------------------------------
 *
 * ClientConnection (QWidget *parent)
 *   QWidget *parent     -> optional
 *
 * This Object generate the UI ServerManagement.
 * This allows the user to manage the GuppyChat from server
 *
 *-----------------------------------------------------------------------------------------------*/
class ServerManagement : public QWidget, private Ui::ServerManagement
{
    Q_OBJECT

public:
    ServerManagement(QWidget *parent = 0);
    ~ServerManagement();

private slots:
    void ClientConnection();
    void ClientDisconnection(Client *client);
    void ClientIdentified(Client *client);

    void MessageToBeDelivered(const GuppyServerClientMessage& message) const;
    void UserListToBeDelivered(const GuppySendUserList& UserList) const;

private:
    void ServerLog(QString message) const;
    void ServerLog(QString message,QString sender) const;
    void UpdateServerDisplayUserList() const;
    void UpdateClientDisplayUserList() const;

private:
    QList<Client *> clients;
    QTcpServer *server;
};

#endif
