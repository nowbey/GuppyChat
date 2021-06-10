#ifndef TABCHAT_H
#define TABCHAT_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include "ui_ClientTabChat.h"


class ClientTabChat: public QWidget, private Ui::ClientTabChat
{
    Q_OBJECT
public:
    ClientTabChat(QString TabChatName, QWidget *parent = nullptr);
    ~ClientTabChat();

private:
    QString TabChatName;
};






#endif // TABCHAT_H
