#include "ServerManagement.h"

/*--------------------------------  ServerManagement constructor  ---------------------------------
 *
 * ClientConnection (QWidget *parent)
 *   QWidget *parent     -> optional
 *
 * This Object generate the UI ServerManagement.
 * This allows the user to manage the GuppyChat from server
 *
 *-----------------------------------------------------------------------------------------------*/
ServerManagement::ServerManagement(QWidget *parent) :  QWidget(parent){
    setupUi(this);

    // Run the Server
    server = new QTcpServer(this);
    if (!server->listen(QHostAddress::Any, 50885)){ // Server start: all authorized IP authorized on port 50585
      QMessageBox::critical(this, "Unable to run the server",  server->errorString());
    }
    else{ // If the server as been started correctly
       ServerLog("Started on the port <strong>" + QString::number(server->serverPort())+ "</strong>.<br />Clients can now join us !");
       connect(server, SIGNAL(newConnection()), this, SLOT(ClientConnection()));
    }
}
ServerManagement::~ServerManagement(){
    delete this;
}



/*----------------------------------  ServerManagement slots  ----------------------------------*/
/*----------------------------  ServerManagement ClientConnection  ------------------------------
 *  This slot is called when a client open a socket
 *  we add a new client object to the client list
 *-----------------------------------------------------------------------------------------------*/
void ServerManagement::ClientConnection()
{
    // Create new Client giving to it the socket
    Client *nouveauClient = new Client(server->nextPendingConnection());
    clients << nouveauClient;

    ServerLog("New client - Waiting for credentials for validation");

    connect(nouveauClient, &Client::MessageToBeDelivered, this, &ServerManagement::MessageToBeDelivered);
    connect(nouveauClient, &Client::ClientDisconnected, this, &ServerManagement::ClientDisconnection);
    connect(nouveauClient, &Client::NewClientIdentified, this, &ServerManagement::ClientIdentified);
}

/*-----------------------  ServerManagement deconnexionClient  -----------------------------
 *  This slot is called when the socket with a client is aborted
 *  Remove the client from the clients list
 *  Inform the ServerManagement
 *  Inform the users
 *  Update the displayed list of users (server & clients)
 *-----------------------------------------------------------------------------------------------*/
void ServerManagement::ClientDisconnection(Client *client){

    clients.removeOne(client);
    ServerLog("Client disconnected - " + client->GetClientName());
    // Send the information to users
    delete client;

    // Update the list of connected users
    UpdateServerDisplayUserList();
    UpdateClientDisplayUserList();
}

/*-----------------------  ServerManagement ClientIdentified  -----------------------------
 *  This slot is called when a message is recieved from a client
 *  The GuppyServerClientMessage contain the source, the destination and the message
 *  The Methode must delivery the message to the conserned clients
 *-----------------------------------------------------------------------------------------------*/
void ServerManagement::ClientIdentified(Client *client){
    ServerLog("New client - Credentials accepted for " + client->GetClientName());

    GuppyServerClientMessage *NewClientConnection = new GuppyServerClientMessage("Welcome <strong>" + client->GetClientName() + "</strong> !", "Server", "Public");
    MessageToBeDelivered(*NewClientConnection);

    UpdateServerDisplayUserList();

    UpdateClientDisplayUserList();
}


/*-----------------------  ServerManagement MessageToBeDelivered  -----------------------------
 *  This slot is called when a message is recieved from a client
 *  The GuppyServerClientMessage contain the source, the destination and the message
 *  The Methode must delivery the message to the conserned clients
 *-----------------------------------------------------------------------------------------------*/
void ServerManagement::MessageToBeDelivered(const GuppyServerClientMessage& message) const{
    qDebug() << "MessageToBeDelivered message to forwarded to " << message.GetRecipient();

    if(message.GetRecipient() == "Public"){
        ServerLog(message.GetMessage(),message.GetSender());

        for (int i = 0; i < clients.size(); i++)
        {
            if(clients[i]->GetClientName() != message.GetSender()){
                clients[i]->SendMessageToClient(message);
            }
        }
    }else{
        for (int i = 0; i < clients.size(); i++){
            if(message.GetRecipient() == clients[i]->GetClientName()){
                ServerLog(message.GetMessage(),message.GetSender() + " (Private to " + message.GetRecipient() +")");
                qDebug() << "MessageToBeDelivered Private message to be delivered";
                clients[i]->SendMessageToClient(message);
            }
        }
    }
}

void ServerManagement::UserListToBeDelivered(const GuppySendUserList& UserList) const{
    for (int i = 0; i < clients.size(); i++)
    {
       clients[i]->SendUserListToClient(UserList);
    }
}


void ServerManagement::ServerLog(QString message) const{
    ServerLogs->append(tr("<strong>Server logs: </strong>") + message );
}

void ServerManagement::ServerLog(QString message,QString sender) const{
    ServerLogs->append("<strong>" + sender + ": </strong>" + message );
}

void ServerManagement::UpdateServerDisplayUserList() const{
    //Create an exhaustive list of actually connected (& validated clients)
    QList<QString> connectedClients ={};
    for (int i=0; i< this->clients.size(); i++){
        connectedClients.append(this->clients[i]->GetClientName());
    }

    // Replace the current display with the new client list
    Userslist->clear();
    Userslist->addItems(connectedClients);
}

void ServerManagement::UpdateClientDisplayUserList() const{
    //Create an exhaustive list of actually connected (& validated clients)
    QList<QString> connectedClients ={};
    for (int i=0; i< this->clients.size(); i++){
        connectedClients.append(this->clients[i]->GetClientName());
    }

    // Replace the current display with the new client list
    GuppySendUserList *Userlistmessage = new GuppySendUserList(connectedClients);
    UserListToBeDelivered(*Userlistmessage);
}
