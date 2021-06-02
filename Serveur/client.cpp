#include "client.h"

//-------------------------------------------------------------------------
//   Constructeur de Client, prend en parametre une socket
//-------------------------------------------------------------------------
Client::Client(QTcpSocket* Socket)
{
    name = "Unknown";
    TailleMessage = 0;
    allowed = true;

    this->Socket = Socket;

    connect(Socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(Socket, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
}

Client::~Client()
{
    this->Socket->deleteLater();
}



//-------------------------------------------------------------------------
//   Définition des slots
//-------------------------------------------------------------------------
//---------------------------------------
//  De la donnée est reçu par ce client
//---------------------------------------
void Client::donneesRecues()
{
    // On récupere la socket
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == nullptr) // Si par hasard on n'a pas trouvé la socket à l'origine du signal, on arrête la méthode
        return;

    // Si tout va bien, on récupère le message
    QDataStream in(socket);

    if (TailleMessage == 0){ // Si on ne connaît pas encore la taille du message, on essaie de la récupérer
        if (socket->bytesAvailable() < (int)sizeof(quint16)) // On n'a pas reçu la taille du message en entier
             return;
        in >> TailleMessage; // Si on a reçu la taille du message en entier, on la récupère
    }

    // Si on connaît la taille du message, on vérifie si on a reçu le message en entier
    if (Socket->bytesAvailable() < TailleMessage) // Si on n'a pas encore tout reçu, on arrête la méthode
        return;

    // Si ces lignes s'exécutent, c'est qu'on a reçu tout le message : on peut le récupérer !

    Message *nouveauMessage = new Message();
    nouveauMessage->deserialize(in);

    qDebug()  << "message received from client with type:" << nouveauMessage->GetMessageType();
    /* En fonction du type de message: SENDMESSAGE ou SENDALLOWREQUEST */
    // Si le client est autorisé
    if (this->allowed == true){
        if (nouveauMessage->GetMessageType()  == "SENDMESSAGE"){
            qDebug()  << "sending it to clients: "   << nouveauMessage->GetMessage();
            emit messageRecu(*nouveauMessage);
        }
    }else{
        if (nouveauMessage->GetMessageType()  == "SENDALLOWREQUEST"){
            // Call the Allow request function
        }
    }

    TailleMessage = 0; // 3 : remise de la taille du message à 0 pour permettre la réception des futurs messages
}

//---------------------------------------
//  Le client s'est déconnecté
//---------------------------------------
void Client::deconnexionClient()
{
    // On récupere la socket conserné
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    if (socket == nullptr) // Si par hasard on n'a pas trouvé la socket à l'origine du signal, on arrête la méthode
        return;

    // On renvoie le siganal indiquant que le client s'est déconnecté
    emit clientDeconnecte(this);
}





//-------------------------------------------------------------------------
//   Définition des méthodes
//-------------------------------------------------------------------------
//---------------------------------------
//  Le client à reçu un message
//---------------------------------------
void Client::envoyerMessage(const Message& message)
{
    // Préparation du paquet
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    stream << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    message.serialize(stream); // On ajoute le message à la suite
    stream.device()->seek(0); // On se replace au début du paquet
    stream << (quint16) (buffer.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message


    // Envoi du paquet préparé à tous les clients connectés au serveur
    this->Socket->write(buffer);

}



