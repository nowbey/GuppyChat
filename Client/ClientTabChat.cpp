#include "ClientTabChat.h"

ClientTabChat::ClientTabChat(QString TabChatName, QWidget *parent) : QWidget(parent){
    setupUi(this);

    this->TabChatName = TabChatName;



}

ClientTabChat::~ClientTabChat(){
    delete this;
}
