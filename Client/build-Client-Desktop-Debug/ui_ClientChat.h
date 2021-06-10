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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientChat
{
public:
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *Logo;
    QLabel *ListOfUsersLabel;
    QListWidget *ListOfUsersWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *message;
    QPushButton *sendButton;
    QTextEdit *publicMessageList;

    void setupUi(QWidget *ClientChat)
    {
        if (ClientChat->objectName().isEmpty())
            ClientChat->setObjectName(QString::fromUtf8("ClientChat"));
        ClientChat->resize(862, 405);
        ClientChat->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        ClientChat->setWindowIcon(icon);
        ClientChat->setStyleSheet(QString::fromUtf8("#ClientChat{\n"
"	background:black;\n"
"	border:0px;\n"
"}\n"
"\n"
"#frame{\n"
"	background:url(:/img/background2.jpg);\n"
"	border:0px;\n"
"}\n"
"\n"
"#Logo{\n"
"	image:url(:/img/GuppyChat_espace2.png)\n"
"}\n"
"\n"
"#ListOfUsersWidget {\n"
"\n"
"	border-left: 1px solid #FF17365D;\n"
"	border-right: 1px solid #FF17365D;\n"
"	border-bottom: 1px solid #FF17365D;\n"
"\n"
"	border-bottom-left-radius: 15px;\n"
"	border-bottom-right-radius: 15px;\n"
"\n"
"	background: rgba( 255, 255, 255, 80% );\n"
"	padding-bottom:15px;\n"
"	padding-left:15px;\n"
"	padding-right:15px;\n"
"}\n"
"#ListOfUsersLabel {\n"
"	border-left: 1px solid #FF17365D;\n"
"	border-right: 1px solid #FF17365D;\n"
"	\n"
"	border-top-left-radius: 15px;\n"
"	border-top-right-radius: 15px;\n"
"	padding: 5px 0px;\n"
"\n"
"	background: rgba( 255, 255, 255, 80% );\n"
"\n"
"	qproperty-alignment: AlignCenter;\n"
"	color: rgb(0, 0, 0, 100%);\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"	background: rgba( 255, 255, 255, 80% );\n"
"	border-left: 1px solid #FF17365D;\n"
" "
                        "   border-right: 1px solid #FF17365D;\n"
"    border-top: 1px solid #FF17365D;\n"
"\n"
"	border-bottom:0px;\n"
"\n"
"     border-top-left-radius: 15px;\n"
"     border-top-right-radius: 15px;\n"
"\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
"}\n"
"\n"
" QTabBar::tab:!selected {\n"
"    margin-top: 8px; /* make non-selected tabs look smaller */\n"
"	background: rgba( 255, 255, 255, 50% );\n"
" }\n"
"\n"
" QTabBar::close-button {\n"
"    /* todo image: url(close.png) */\n"
"     subcontrol-position: left;\n"
" }\n"
"\n"
"#tab{\n"
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
"\n"
"\n"
""));
        gridLayout_3 = new QGridLayout(ClientChat);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(ClientChat);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Logo = new QLabel(frame);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setEnabled(false);
        Logo->setMinimumSize(QSize(170, 70));
        Logo->setMidLineWidth(0);
        Logo->setScaledContents(false);
        Logo->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        Logo->setWordWrap(false);

        verticalLayout->addWidget(Logo);

        ListOfUsersLabel = new QLabel(frame);
        ListOfUsersLabel->setObjectName(QString::fromUtf8("ListOfUsersLabel"));
        ListOfUsersLabel->setContextMenuPolicy(Qt::DefaultContextMenu);
        ListOfUsersLabel->setLayoutDirection(Qt::RightToLeft);
        ListOfUsersLabel->setAutoFillBackground(false);

        verticalLayout->addWidget(ListOfUsersLabel);

        ListOfUsersWidget = new QListWidget(frame);
        ListOfUsersWidget->setObjectName(QString::fromUtf8("ListOfUsersWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ListOfUsersWidget->sizePolicy().hasHeightForWidth());
        ListOfUsersWidget->setSizePolicy(sizePolicy1);
        ListOfUsersWidget->setMaximumSize(QSize(16777215, 16777215));
        ListOfUsersWidget->setFrameShape(QFrame::StyledPanel);
        ListOfUsersWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ListOfUsersWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ListOfUsersWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        ListOfUsersWidget->setAutoScroll(true);
        ListOfUsersWidget->setAutoScrollMargin(40);
        ListOfUsersWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ListOfUsersWidget->setTextElideMode(Qt::ElideNone);
        ListOfUsersWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        ListOfUsersWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        ListOfUsersWidget->setMovement(QListView::Snap);
        ListOfUsersWidget->setResizeMode(QListView::Adjust);
        ListOfUsersWidget->setViewMode(QListView::ListMode);
        ListOfUsersWidget->setSortingEnabled(false);

        verticalLayout->addWidget(ListOfUsersWidget);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(4);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setEnabled(true);
        QFont font;
        font.setStrikeOut(false);
        tab->setFont(font);
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

        publicMessageList = new QTextEdit(tab);
        publicMessageList->setObjectName(QString::fromUtf8("publicMessageList"));
        publicMessageList->setReadOnly(true);

        gridLayout->addWidget(publicMessageList, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_2->addWidget(tabWidget, 0, 1, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ClientChat);

        ListOfUsersWidget->setCurrentRow(-1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientChat);
    } // setupUi

    void retranslateUi(QWidget *ClientChat)
    {
        ClientChat->setWindowTitle(QApplication::translate("ClientChat", "GuppyChat", nullptr));
        Logo->setText(QString());
        ListOfUsersLabel->setText(QApplication::translate("ClientChat", "List of Users", nullptr));
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
