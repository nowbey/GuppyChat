/********************************************************************************
** Form generated from reading UI file 'ServerManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERMANAGEMENT_H
#define UI_SERVERMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerManagement
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QListWidget *Userslist;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *ServerLogs;

    void setupUi(QWidget *ServerManagement)
    {
        if (ServerManagement->objectName().isEmpty())
            ServerManagement->setObjectName(QString::fromUtf8("ServerManagement"));
        ServerManagement->resize(655, 300);
        gridLayout = new QGridLayout(ServerManagement);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ServerManagement);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        Userslist = new QListWidget(frame);
        Userslist->setObjectName(QString::fromUtf8("Userslist"));
        Userslist->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(Userslist, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);

        ServerLogs = new QTextEdit(frame);
        ServerLogs->setObjectName(QString::fromUtf8("ServerLogs"));
        ServerLogs->setBaseSize(QSize(0, 0));

        gridLayout_2->addWidget(ServerLogs, 0, 1, 3, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ServerManagement);

        QMetaObject::connectSlotsByName(ServerManagement);
    } // setupUi

    void retranslateUi(QWidget *ServerManagement)
    {
        ServerManagement->setWindowTitle(QApplication::translate("ServerManagement", "GuppyChat - Server", nullptr));
        label->setText(QApplication::translate("ServerManagement", "Allowed users", nullptr));
        pushButton->setText(QApplication::translate("ServerManagement", "Add", nullptr));
        pushButton_2->setText(QApplication::translate("ServerManagement", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerManagement: public Ui_ServerManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERMANAGEMENT_H
