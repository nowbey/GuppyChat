#include "ClientTabChat.h"

ClientTabChat::ClientTabChat(QString TabChatName, QWidget *parent) : QWidget(parent){
    setupUi(this);
    this->TabChatName = TabChatName;
}

ClientTabChat::~ClientTabChat(){
    delete this;
}

/*-------------------------  ClientChat::on_sendButton_clicked slot  ----------------------------
 *  This slot is called on sendButton clicked
 *  It use the socket to send an object "Message" to the server
 *-----------------------------------------------------------------------------------------------*/
void ClientTabChat::on_ChatTab_sendButton_clicked(){
    // Create the message to send
    GuppyClientServerMessage* messageToSend = new GuppyClientServerMessage(ChatTab_message->text(),this->TabChatName);

    //emit the signal with the message to send it
    emit MessageToBeDelivered(*messageToSend);

    ChatTab_message->clear(); // clear the message field
    ChatTab_message->setFocus(); // set the focus message field

}
// Pressing the Enter key has the same behavior as clicking the "Send" button.
void ClientTabChat::on_ChatTab_message_returnPressed(){
    on_ChatTab_sendButton_clicked();
}


void ClientTabChat::WriteMessage(const QString& message) const{
    ChatTab_textChat->append(message);
}
