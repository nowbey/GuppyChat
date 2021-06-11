#ifndef CLIENTCHAT_H
#define CLIENTCHAT_H

#include <QTableWidget>
#include <QWidget>
#include <QDialog>
#include <QtNetwork>
#include <QString>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>

#include "ClientTabChat.h"

#include "ui_ClientChat.h"

#include "../GC_common/GuppyClientServerMessage.h"
#include "../GC_common/GuppyServerClientMessage.h"
#include "../GC_common/GuppySendUserList.h"


class ClientChat : public QWidget, private Ui::ClientChat
{
    Q_OBJECT

public:
    /*--------------------------------  ClientChat constructor  --------------------------------------
     *
     * ClientChat (TcpSocket* socket, QString userName, QWidget *parent)
     *   QTcpSocket* socket  -> mendatory (the socket must be connected before this object instantiation)
     *   QString userName    -> mendatory (the userName must be validated by server before this object instantiation) Todo
     *   QWidget *parent     -> optional
     *
     * This Object  generate the UI ClientChat
     *
     *-----------------------------------------------------------------------------------------------*/
    explicit ClientChat(QTcpSocket* Socket, QString userName, QWidget *parent = nullptr);
    ~ClientChat();

private:
    QString userName;

    QTcpSocket* socket;

    quint16 messageSize;
    MessageType messageType;

private:
    void UpdaterListOfUsersConnected(QList<QString> ListOfUsersConnected);
    void DisplayMessage(const GuppyServerClientMessage& message);


private slots:
    void on_ListOfUsersWidget_itemDoubleClicked(QListWidgetItem *item);

    void SendMessageToServer(const GuppyClientServerMessage& message);

    /*----------------------------  ClientChat::dataReceived slot  -----------------------------------
     *  This slot is called on data recived form the server
     *  it can be called several times until a message is completely received
     *-----------------------------------------------------------------------------------------------*/
    void dataReceived();

    /*------------------------------  ClientChat::disconnect slot  ----------------------------------
     *  This slot is called when the communication with the server is broken voluntarily or not
     *  it close the chat UI and back to connection window (Todo)
     *-----------------------------------------------------------------------------------------------*/
    void disconnect();
};

#endif // CLIENTCHAT_H
