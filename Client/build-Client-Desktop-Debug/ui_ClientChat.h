/********************************************************************************
** Form generated from reading UI file 'ClientChat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTCHAT_H
#define UI_CLIENTCHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientChat
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *disconnectButton;
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QTextEdit *publicMessageList;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *message;
    QPushButton *sendButton;

    void setupUi(QWidget *ClientChat)
    {
        if (ClientChat->objectName().isEmpty())
            ClientChat->setObjectName(QString::fromUtf8("ClientChat"));
        ClientChat->resize(862, 553);
        QIcon icon;
        icon.addFile(QString::fromUtf8("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        ClientChat->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(ClientChat);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(ClientChat);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        label = new QLabel(ClientChat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        disconnectButton = new QPushButton(ClientChat);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));

        gridLayout_2->addWidget(disconnectButton, 1, 2, 1, 1);

        groupBox = new QGroupBox(ClientChat);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        gridLayout_2->addWidget(groupBox, 2, 2, 1, 1);

        tabWidget = new QTabWidget(ClientChat);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        publicMessageList = new QTextEdit(tab);
        publicMessageList->setObjectName(QString::fromUtf8("publicMessageList"));
        publicMessageList->setReadOnly(true);

        gridLayout->addWidget(publicMessageList, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        message = new QLineEdit(tab);
        message->setObjectName(QString::fromUtf8("message"));

        horizontalLayout_2->addWidget(message);

        sendButton = new QPushButton(tab);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setIcon(icon);

        horizontalLayout_2->addWidget(sendButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_2->addWidget(tabWidget, 2, 0, 1, 2);


        retranslateUi(ClientChat);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientChat);
    } // setupUi

    void retranslateUi(QWidget *ClientChat)
    {
        ClientChat->setWindowTitle(QApplication::translate("ClientChat", "GuppyChat - Public", nullptr));
        label_3->setText(QApplication::translate("ClientChat", "Welcome User ", nullptr));
        label->setText(QApplication::translate("ClientChat", "You are connected on server", nullptr));
        disconnectButton->setText(QApplication::translate("ClientChat", "Disconnection", nullptr));
        groupBox->setTitle(QApplication::translate("ClientChat", "List of connected users", nullptr));
        label_4->setText(QApplication::translate("ClientChat", "Message :", nullptr));
        sendButton->setText(QApplication::translate("ClientChat", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ClientChat", "Public", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientChat: public Ui_ClientChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTCHAT_H
