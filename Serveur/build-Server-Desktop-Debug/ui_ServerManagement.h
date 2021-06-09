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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerManagement
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QTextEdit *ServerLogs;

    void setupUi(QWidget *ServerManagement)
    {
        if (ServerManagement->objectName().isEmpty())
            ServerManagement->setObjectName(QString::fromUtf8("ServerManagement"));
        ServerManagement->resize(677, 300);
        gridLayout = new QGridLayout(ServerManagement);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ServerManagement);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);

        ServerLogs = new QTextEdit(frame);
        ServerLogs->setObjectName(QString::fromUtf8("ServerLogs"));
        ServerLogs->setBaseSize(QSize(0, 0));

        gridLayout_2->addWidget(ServerLogs, 0, 1, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ServerManagement);

        QMetaObject::connectSlotsByName(ServerManagement);
    } // setupUi

    void retranslateUi(QWidget *ServerManagement)
    {
        ServerManagement->setWindowTitle(QApplication::translate("ServerManagement", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerManagement: public Ui_ServerManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERMANAGEMENT_H
