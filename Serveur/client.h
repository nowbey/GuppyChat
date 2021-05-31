#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include "message.h"

class Client: public QObject
{  
    Q_OBJECT

    public:
        Client(QTcpSocket* serveur);
        ~Client();

    private:
        QString name;
        QTcpSocket *Socket;
        quint16 TailleMessage;
        bool allowed;

    public:
        void envoyerMessage(const QString &message);

    private slots:
        void donneesRecues();
        void deconnexionClient();

    signals:
        void clientDeconnecte(Client* ceClient);
        void messageRecu(Message* message);

};

#endif // CLIENT_H
