#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include "../GC_common/message.h"

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
        void envoyerMessage(const Message& message);

    private slots:
        void donneesRecues();
        void deconnexionClient();

    signals:
        void clientDeconnecte(Client* ceClient);
        void messageRecu(const Message& message);

};

#endif // CLIENT_H
