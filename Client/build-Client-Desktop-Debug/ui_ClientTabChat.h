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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatTab
{
public:
    QGridLayout *gridLayout_2;
    QFrame *ChatTab_frame;
    QGridLayout *gridLayout;
    QTextEdit *ChatTab_textChat;
    QHBoxLayout *ChatTab_horizontalLayout;
    QLabel *ChatTab_labelMessage;
    QLineEdit *ChatTab_message;
    QPushButton *ChatTab_sendButton;

    void setupUi(QWidget *ChatTab)
    {
        if (ChatTab->objectName().isEmpty())
            ChatTab->setObjectName(QString::fromUtf8("ChatTab"));
        ChatTab->resize(725, 455);
        ChatTab->setStyleSheet(QString::fromUtf8("\n"
"#ChatTab_frame{\n"
"	border-left: 1px solid #FF17365D;\n"
"	border-right: 1px solid #FF17365D;\n"
"	border-bottom: 1px solid #FF17365D;\n"
"\n"
"	border-bottom-right-radius:  15px;\n"
"	border-bottom-left-radius:  15px;\n"
"	border-top-right-radius:  15px;\n"
"\n"
"	top:15px;\n"
"\n"
"	background: rgba( 255, 255, 255, 80% );\n"
"}"));
        gridLayout_2 = new QGridLayout(ChatTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        ChatTab_frame = new QFrame(ChatTab);
        ChatTab_frame->setObjectName(QString::fromUtf8("ChatTab_frame"));
        ChatTab_frame->setFrameShape(QFrame::StyledPanel);
        ChatTab_frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(ChatTab_frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ChatTab_textChat = new QTextEdit(ChatTab_frame);
        ChatTab_textChat->setObjectName(QString::fromUtf8("ChatTab_textChat"));
        ChatTab_textChat->setReadOnly(true);

        gridLayout->addWidget(ChatTab_textChat, 0, 0, 1, 1);

        ChatTab_horizontalLayout = new QHBoxLayout();
        ChatTab_horizontalLayout->setObjectName(QString::fromUtf8("ChatTab_horizontalLayout"));
        ChatTab_labelMessage = new QLabel(ChatTab_frame);
        ChatTab_labelMessage->setObjectName(QString::fromUtf8("ChatTab_labelMessage"));

        ChatTab_horizontalLayout->addWidget(ChatTab_labelMessage);

        ChatTab_message = new QLineEdit(ChatTab_frame);
        ChatTab_message->setObjectName(QString::fromUtf8("ChatTab_message"));

        ChatTab_horizontalLayout->addWidget(ChatTab_message);

        ChatTab_sendButton = new QPushButton(ChatTab_frame);
        ChatTab_sendButton->setObjectName(QString::fromUtf8("ChatTab_sendButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChatTab_sendButton->setIcon(icon);

        ChatTab_horizontalLayout->addWidget(ChatTab_sendButton);


        gridLayout->addLayout(ChatTab_horizontalLayout, 1, 0, 1, 1);


        gridLayout_2->addWidget(ChatTab_frame, 0, 0, 1, 1);


        retranslateUi(ChatTab);

        QMetaObject::connectSlotsByName(ChatTab);
    } // setupUi

    void retranslateUi(QWidget *ChatTab)
    {
        ChatTab->setWindowTitle(QApplication::translate("ChatTab", "Form", nullptr));
        ChatTab_labelMessage->setText(QApplication::translate("ChatTab", "Message :", nullptr));
        ChatTab_sendButton->setText(QApplication::translate("ChatTab", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatTab: public Ui_ChatTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTTABCHAT_H
