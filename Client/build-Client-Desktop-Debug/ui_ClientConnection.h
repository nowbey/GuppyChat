/********************************************************************************
** Form generated from reading UI file 'ClientConnection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTCONNECTION_H
#define UI_CLIENTCONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientConnection
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *userName;
    QLabel *label_3;
    QLineEdit *userPassword;
    QLabel *label_2;
    QLineEdit *serverIP;
    QPushButton *connectButton;

    void setupUi(QWidget *ClientConnection)
    {
        if (ClientConnection->objectName().isEmpty())
            ClientConnection->setObjectName(QString::fromUtf8("ClientConnection"));
        ClientConnection->resize(325, 152);
        gridLayout = new QGridLayout(ClientConnection);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(ClientConnection);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        userName = new QLineEdit(ClientConnection);
        userName->setObjectName(QString::fromUtf8("userName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, userName);

        label_3 = new QLabel(ClientConnection);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        userPassword = new QLineEdit(ClientConnection);
        userPassword->setObjectName(QString::fromUtf8("userPassword"));
        userPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        formLayout->setWidget(1, QFormLayout::FieldRole, userPassword);

        label_2 = new QLabel(ClientConnection);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        serverIP = new QLineEdit(ClientConnection);
        serverIP->setObjectName(QString::fromUtf8("serverIP"));

        formLayout->setWidget(2, QFormLayout::FieldRole, serverIP);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        connectButton = new QPushButton(ClientConnection);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        gridLayout->addWidget(connectButton, 1, 0, 1, 1);


        retranslateUi(ClientConnection);

        QMetaObject::connectSlotsByName(ClientConnection);
    } // setupUi

    void retranslateUi(QWidget *ClientConnection)
    {
        ClientConnection->setWindowTitle(QApplication::translate("ClientConnection", "Form", nullptr));
        label->setText(QApplication::translate("ClientConnection", "User name", nullptr));
        label_3->setText(QApplication::translate("ClientConnection", "User Password", nullptr));
        label_2->setText(QApplication::translate("ClientConnection", "Server IP address", nullptr));
        serverIP->setText(QApplication::translate("ClientConnection", "127.0.0.1", nullptr));
        connectButton->setText(QApplication::translate("ClientConnection", "Connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientConnection: public Ui_ClientConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTCONNECTION_H
