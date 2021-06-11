#ifndef TABCHAT_H
#define TABCHAT_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include "ui_ClientTabChat.h"

#include "../GC_common/GuppyClientServerMessage.h"

/*------------------------------------  ClientTabChat   -----------------------------------------
 *
 * ClientTabChat (QWidget *parent)
 *   QString TabChatName -> mandatory
 *   QWidget *parent     -> optional
 *
 * This Object generate the tab content UI To be added on tabWidget in the ClientChat.
 *
 *-----------------------------------------------------------------------------------------------*/
class ClientTabChat: public QWidget, private Ui::ChatTab
{
    Q_OBJECT
public:
    ClientTabChat(QString TabChatName, QString UserName, QWidget *parent = nullptr);
    ~ClientTabChat();

public:
    /*--------------------------  ClientTabChat::WriteMessage methode  ------------------------------
     *  This methode is called to display the message in the tab
     *  the message must by formated before
     *-----------------------------------------------------------------------------------------------*/
    void WriteMessage(const QString& message) const;

private slots:
    /*--------------------  ClientTabChat::on_ChatTab_sendButton_clicked slot  ------------------------
     *  This slot is called on sendButton clicked
     *  It send a signal with GuppyClientServerMessage fully prepared
     *-----------------------------------------------------------------------------------------------*/
    void on_ChatTab_sendButton_clicked();
    void on_ChatTab_message_returnPressed(); // Pressing the Enter key has the same behavior as clicking the "Send" button.

signals:
    void MessageToBeDelivered (const GuppyClientServerMessage& message);

private:
    QString TabChatName;
    QString UserName;
};






#endif // TABCHAT_H
