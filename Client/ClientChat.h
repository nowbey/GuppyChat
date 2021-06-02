#ifndef CLIENTCHAT_H
#define CLIENTCHAT_H

#include <QWidget>
#include <QDialog>
#include <QtNetwork>
#include <QString>
#include "ui_ClientChat.h"
#include "../GC_common/message.h"


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


private slots:
    /*-------------------------  ClientChat::on_sendButton_clicked slot  ----------------------------
     *  This slot is called on sendButton clicked
     *  It use the socket to send an object "Message" to the server
     *-----------------------------------------------------------------------------------------------*/
    void on_sendButton_clicked();
    void on_message_returnPressed(); // Pressing the Enter key has the same behavior as clicking the "Send" button.

    /*---------------------  ClientChat::on_disconnectButton_clicked slot  ---------------------------
     *  This slot is called on disconnectButton clicked
     *  It stops the current socket
     *-----------------------------------------------------------------------------------------------*/
    void on_disconnectButton_clicked();

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
