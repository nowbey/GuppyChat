#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include <QtWidgets>
#include <QtNetwork>
#include "ui_ClientConnection.h"

#include "../GC_common/GuppySendCredentials.h"
#include "../GC_common/GuppyUserValidation.h"

#include "ClientChat.h"


class ClientConnection : public QWidget, private Ui::ClientConnection
{
    Q_OBJECT

public:
    /*--------------------------------  ClientConnection constructor  ---------------------------------
     *
     * ClientConnection (QWidget *parent)
     *   QWidget *parent     -> optional
     *
     * This Object generate the UI ClientConnection.
     * This allows the user to configure these credentials and indicate which server to connect to
     *
     *-----------------------------------------------------------------------------------------------*/
    ClientConnection(QWidget *parent = 0);
    ~ClientConnection();

private:
    ClientChat *fenetreChat;

    QTcpSocket *socket;

    quint16 messageSize;
    MessageType messageType;

private slots:
    /*---------------------  ClientConnection::on_connectButton_clicked slot  ----------------------
    *  This method is called when the connectButton is clicked.
    *  It tries to connect to the server
    *-----------------------------------------------------------------------------------------------*/
    void on_connectButton_clicked();
    void on_userName_returnPressed();// Pressing the Enter key has the same behavior as clicking the "connectButton" button.
    void on_userPassword_returnPressed();// Pressing the Enter key has the same behavior as clicking the "connectButton" button.

    /*---------------------------  ClientConnection::connected slot  ---------------------------------
     *  This slot is called when the connection with server succeeded
     *  it open the ClientChat
     *-----------------------------------------------------------------------------------------------*/
    void connected();

    /*--------------------------  ClientConnection::dataReceived slot  -------------------------------
     *  This slot is called on data recived form the server
     *  it can be called several times until a message is completely received
     *-----------------------------------------------------------------------------------------------*/
    void dataReceived();

    /*--------------------------  ClientConnection::errorSocket slot  --------------------------------
     *  This slot is called if an error signal sent by the socket
     *  it generate a message box depending on the error
     *-----------------------------------------------------------------------------------------------*/
    void errorSocket(QAbstractSocket::SocketError error);
};

#endif // CLIENTCONNECTION_H
