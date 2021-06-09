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
#include <QtWidgets/QFrame>
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
    QFrame *FEtoile;
    QGridLayout *gridLayout_2;
    QLabel *Logo;
    QFrame *FBlanc;
    QGridLayout *gridLayout_3;
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
        ClientConnection->resize(315, 260);
        ClientConnection->setStyleSheet(QString::fromUtf8("#FEtoile{\n"
"background:url(:/img/background2.jpg);\n"
"}\n"
"\n"
"#FBlanc{\n"
"background: rgba( 255, 255, 255, 80% );\n"
"border:1px solid #FF17365D;\n"
"border-radius: 15px;\n"
"}\n"
"\n"
"#Logo{\n"
"image:url(:/img/GuppyChat_espace2.png)\n"
"}"));
        gridLayout = new QGridLayout(ClientConnection);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        FEtoile = new QFrame(ClientConnection);
        FEtoile->setObjectName(QString::fromUtf8("FEtoile"));
        FEtoile->setFrameShape(QFrame::StyledPanel);
        FEtoile->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(FEtoile);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Logo = new QLabel(FEtoile);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setMinimumSize(QSize(120, 100));
        Logo->setAlignment(Qt::AlignBottom|Qt::AlignJustify);

        gridLayout_2->addWidget(Logo, 0, 0, 1, 1);

        FBlanc = new QFrame(FEtoile);
        FBlanc->setObjectName(QString::fromUtf8("FBlanc"));
        FBlanc->setFrameShape(QFrame::StyledPanel);
        FBlanc->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(FBlanc);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(FBlanc);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        userName = new QLineEdit(FBlanc);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setMinimumSize(QSize(150, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, userName);

        label_3 = new QLabel(FBlanc);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        userPassword = new QLineEdit(FBlanc);
        userPassword->setObjectName(QString::fromUtf8("userPassword"));
        userPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        formLayout->setWidget(1, QFormLayout::FieldRole, userPassword);

        label_2 = new QLabel(FBlanc);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        serverIP = new QLineEdit(FBlanc);
        serverIP->setObjectName(QString::fromUtf8("serverIP"));

        formLayout->setWidget(2, QFormLayout::FieldRole, serverIP);


        gridLayout_3->addLayout(formLayout, 0, 0, 1, 1);

        connectButton = new QPushButton(FBlanc);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        gridLayout_3->addWidget(connectButton, 1, 0, 1, 1);


        gridLayout_2->addWidget(FBlanc, 1, 0, 1, 1);


        gridLayout->addWidget(FEtoile, 0, 0, 1, 1);


        retranslateUi(ClientConnection);

        QMetaObject::connectSlotsByName(ClientConnection);
    } // setupUi

    void retranslateUi(QWidget *ClientConnection)
    {
        ClientConnection->setWindowTitle(QApplication::translate("ClientConnection", "GuppyChat", nullptr));
        Logo->setText(QString());
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
