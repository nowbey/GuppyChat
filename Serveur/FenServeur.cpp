#include "FenServeur.h"


//-------------------------------------------------------------------------
//   Constructeur de FenServeur, Créé la fenetre et instancie le serveur
//-------------------------------------------------------------------------
FenServeur::FenServeur()
{
    // Création et disposition des widgets de la fenêtre
    etatServeur = new QLabel;
    boutonQuitter = new QPushButton(tr("Quitter"));
    connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(etatServeur);
    layout->addWidget(boutonQuitter);
    setLayout(layout);

    setWindowTitle(tr("GuppyChat - Serveur"));


    // Gestion du serveur
    serveur = new QTcpServer(this);
    if (!serveur->listen(QHostAddress::Any, 50885)){ // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
        // Si le serveur n'a pas été démarré correctement
        etatServeur->setText(tr("Le serveur n'a pas pu être démarré. Raison :<br />") + serveur->errorString());
    }
    else{ // Si le serveur a été démarré correctement
        etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter. ") + tr("<br />Actuellement: ") + QString::number(clients.size()));
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
    }
}


//-------------------------------------------------------------------------
//   Définition des slots
//-------------------------------------------------------------------------
//-----------------------------------
//  Nouvelle connection d'un client
//-----------------------------------
void FenServeur::nouvelleConnexion()
{
    // Création d'un client, on lui passe la socket on parametre
    Client *nouveauClient = new Client(serveur->nextPendingConnection());
    clients << nouveauClient;

    // Actualisation des affichages pour indiquer qu'un nouveau client est dispo
    etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter. ") + tr("<br />Actuellement: ") + QString::number(clients.size()));

    Message newClientMessage("Server", "Client", tr("<em>New client connected</em>"), "SENDMESSAGE");
    envoyerATous(newClientMessage);

    // Connection des signaux du client aux slots du serveur
    connect(nouveauClient, &Client::messageRecu, this, &FenServeur::messageRecuFromClient);
    connect(nouveauClient, &Client::clientDeconnecte, this, &FenServeur::deconnexionClient);
}

//-----------------------------------
//  Message reçu d'un client
//-----------------------------------
void FenServeur::messageRecuFromClient(const Message& message)const {
    envoyerATous(message);
}


//-----------------------------------
//  Un client s'est déconnecté
//-----------------------------------
void FenServeur::deconnexionClient(Client *client){
    // On retire le client de la liste des clients
    clients.removeOne(client);
    delete client; // appele le destructeur de client

    Message decoMessage("Server", "Client", tr("<em>Un client vient de se déconnecter</em>"), "SENDMESSAGE");
    envoyerATous(decoMessage);

    etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter. ") + tr("<br />Actuellement: ") + QString::number(clients.size()));
}

//-------------------------------------------------------------------------
//   Définition des méthodes
//-------------------------------------------------------------------------
//-----------------------------------
//  Envoyer un message à tous les clients
//-----------------------------------
void FenServeur::envoyerATous(const Message& message) const{
    // Envoi du paquet préparé à tous les clients connectés au serveur
    for (int i = 0; i < clients.size(); i++)
    {
        clients[i]->envoyerMessage(message);
    }
}
