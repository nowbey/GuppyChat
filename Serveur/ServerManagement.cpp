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

    OpenDatabase(this->sqlitedb, "./GuppyChatServer_DB.sqlite");

    UpdateServerDisplayUserList();

    // Run the Server
    server = new QTcpServer(this);
    if (!server->listen(QHostAddress::Any, 50885)){ // Server start: all authorized IP authorized on port 50585
      QMessageBox::critical(this, "Unable to run the server",  server->errorString());
    }
    else{ // If the server as been started correctly
       ServerLog("Started on the port <strong>" + QString::number(server->serverPort())+ "</strong>.");
       ServerLog("Clients can now join us !");
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

    ServerLog("New client - Waiting credentials for validation");

    connect(nouveauClient, &Client::MessageToBeDelivered, this, &ServerManagement::MessageToBeDelivered);
    connect(nouveauClient, &Client::ClientDisconnected, this, &ServerManagement::ClientDisconnection);
    connect(nouveauClient, &Client::NewClientIdentificationRequest, this, &ServerManagement::ClientIdentificationRequest);
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
    ServerLog("Client disconnected - " + client->GetClientUserName());

    GuppyServerClientMessage *NewClientConnection = new GuppyServerClientMessage("Bye <strong>" + client->GetClientUserName() + "</strong>, see you next time !", "Server", "Public");
    MessageToBeDelivered(*NewClientConnection);

    delete client;

    // Update the list of connected users
    UpdateServerDisplayUserList();
    UpdateClientDisplayUserList();
}


/*---------------------  ServerManagement ClientIdentificationRequest  ---------------------------
 *  This methode is called when a Client Identification Request is recieved from a client
 *-----------------------------------------------------------------------------------------------*/
void ServerManagement::ClientIdentificationRequest(Client *client){

    bool UserValidated = false;
    bool alreadyConnected = false;

    QSqlQuery query;
    query.exec("SELECT * FROM Clients where (user = '" + client->GetClientUserName() + "' and password = '" + client->GetClientPassword() + "') limit 1");

    while (query.next()) {
        UserValidated = true;
    }

    if (UserValidated){
        // Check if the user is already connected
        foreach (Client *alreadyconnectedclient, this->clients) {
            if (alreadyconnectedclient->GetClientUserName() == client->GetClientUserName() && alreadyconnectedclient->GetUserValidation() == true){
             alreadyConnected = true;
            }
        }

        if (!alreadyConnected){
            ServerLog("New client - Credentials accepted for <strong>" + client->GetClientUserName() + "</strong>");
            client->sendUserValidation(UserValidated);

            GuppyServerClientMessage *NewClientConnection = new GuppyServerClientMessage("Welcome <strong>" + client->GetClientUserName() + "</strong> !", "Server", "Public");
            MessageToBeDelivered(*NewClientConnection);

            UpdateServerDisplayUserList();
            UpdateClientDisplayUserList();
        }else{
            ServerLog("New client - Credentials refused for <strong>" + client->GetClientUserName() + "</strong>, user already connected");
            client->sendUserValidation(UserValidated);
            clients.removeOne(client);
            delete client;
        }
    }else{
        ServerLog("New client - Credentials refused for <strong>" + client->GetClientUserName() + "</strong>");
        client->sendUserValidation(UserValidated);
        clients.removeOne(client);
        delete client;
    }
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
            if(clients[i]->GetClientUserName() != message.GetSender()){
                clients[i]->SendMessageToClient(message);
            }
        }
    }else{
        for (int i = 0; i < clients.size(); i++){
            if(message.GetRecipient() == clients[i]->GetClientUserName()){
                ServerLog(message.GetMessage(),message.GetSender() + " (Private to " + message.GetRecipient() +")");
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
    // Get the list of allowed users from database
    QList<QString> allowedClients ={};
    QSqlQuery query;
    query.exec("SELECT * FROM Clients");

    while (query.next()) {
        allowedClients.append(query.value(1).toString());
    }

    // Replace the current display with the new client list
    Userslist->clear();
    Userslist->addItems(allowedClients);


    // Color connected users with green
    QList<QString> connectedClients ={};
    for (int i=0; i< this->clients.size(); i++){
        QList<QListWidgetItem *> list = Userslist->findItems(this->clients[i]->GetClientUserName(), Qt::MatchExactly);
        for ( QListWidgetItem *item : list ){
            item->setTextColor(QColor(50, 180, 50, 255));
            item->font().setBold(true);
        }
    }
}

void ServerManagement::UpdateClientDisplayUserList() const{
    //Create an exhaustive list of actually connected (& validated clients)
    QList<QString> connectedClients ={};
    for (int i=0; i< this->clients.size(); i++){
        connectedClients.append(this->clients[i]->GetClientUserName());
    }

    // Replace the current display with the new client list
    GuppySendUserList *Userlistmessage = new GuppySendUserList(connectedClients);
    UserListToBeDelivered(*Userlistmessage);
}

void ServerManagement::OpenDatabase(QSqlDatabase sqlitedb, QString DatabasePath){
    sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    sqlitedb.setDatabaseName(DatabasePath);

    // If the database already exists, open it
    if(QFileInfo::exists(DatabasePath)){
        if(sqlitedb.open()) {
            ServerLog("Database successfully opened");
        }else{
            ServerLog("Database <strong>" + DatabasePath + "</strong> exists but can't be openned... ");
        }
    // else create it
    }else{
        if(sqlitedb.open()) {
            ServerLog("Database just created <strong>" + DatabasePath + "</strong>");
            sqlitedb.exec("CREATE TABLE Clients(ID integer primary key autoincrement  not null , user VARCHAR(25), password VARCHAR(25));");
        }else{
            ServerLog("Database can't be created on path <strong>" + DatabasePath + "</strong>");
        }
    }
}

