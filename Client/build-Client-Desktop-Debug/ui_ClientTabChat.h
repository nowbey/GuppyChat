/********************************************************************************
** Form generated from reading UI file 'ClientTabChat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTTABCHAT_H
#define UI_CLIENTTABCHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientTabChat
{
public:
    QGridLayout *gridLayout;
    QTextEdit *publicMessageList_2;
    QHBoxLayout *horizontalLayout_ChatTab;
    QLabel *labelMessage_ChatTab;
    QLineEdit *message_ChatTab;
    QPushButton *sendButton__ChatTab;

    void setupUi(QWidget *ClientTabChat)
    {
        if (ClientTabChat->objectName().isEmpty())
            ClientTabChat->setObjectName(QString::fromUtf8("ClientTabChat"));
        ClientTabChat->resize(725, 455);
        ClientTabChat->setStyleSheet(QString::fromUtf8("#ClientTabChat{\n"
"	border-left: 1px solid #FF17365D;\n"
"	border-right: 1px solid #FF17365D;\n"
"	border-bottom: 1px solid #FF17365D;\n"
"\n"
"	border-bottom-right-radius:  15px;\n"
"	border-bottom-left-radius:  15px;\n"
"\n"
"	top:15px;\n"
"\n"
"	background: rgba( 255, 255, 255, 80% );\n"
"}\n"
""));
        gridLayout = new QGridLayout(ClientTabChat);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        publicMessageList_2 = new QTextEdit(ClientTabChat);
        publicMessageList_2->setObjectName(QString::fromUtf8("publicMessageList_2"));
        publicMessageList_2->setReadOnly(true);

        gridLayout->addWidget(publicMessageList_2, 0, 0, 1, 1);

        horizontalLayout_ChatTab = new QHBoxLayout();
        horizontalLayout_ChatTab->setObjectName(QString::fromUtf8("horizontalLayout_ChatTab"));
        labelMessage_ChatTab = new QLabel(ClientTabChat);
        labelMessage_ChatTab->setObjectName(QString::fromUtf8("labelMessage_ChatTab"));

        horizontalLayout_ChatTab->addWidget(labelMessage_ChatTab);

        message_ChatTab = new QLineEdit(ClientTabChat);
        message_ChatTab->setObjectName(QString::fromUtf8("message_ChatTab"));

        horizontalLayout_ChatTab->addWidget(message_ChatTab);

        sendButton__ChatTab = new QPushButton(ClientTabChat);
        sendButton__ChatTab->setObjectName(QString::fromUtf8("sendButton__ChatTab"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendButton__ChatTab->setIcon(icon);

        horizontalLayout_ChatTab->addWidget(sendButton__ChatTab);


        gridLayout->addLayout(horizontalLayout_ChatTab, 1, 0, 1, 1);


        retranslateUi(ClientTabChat);

        QMetaObject::connectSlotsByName(ClientTabChat);
    } // setupUi

    void retranslateUi(QWidget *ClientTabChat)
    {
        ClientTabChat->setWindowTitle(QApplication::translate("ClientTabChat", "Form", nullptr));
        labelMessage_ChatTab->setText(QApplication::translate("ClientTabChat", "Message :", nullptr));
        sendButton__ChatTab->setText(QApplication::translate("ClientTabChat", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientTabChat: public Ui_ClientTabChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTTABCHAT_H
