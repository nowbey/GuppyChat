#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtWidgets>
#include <QtNetwork>
#include <client.h>


class FenServeur : public QWidget
{
    Q_OBJECT

    public:
        FenServeur();

    private:
        QLabel *etatServeur;
        QPushButton *boutonQuitter;
        QTcpServer *serveur;
        QList<Client *> clients;
    private:
        void envoyerATous(const Message& message) const;

    private slots:
        void nouvelleConnexion();
        void deconnexionClient(Client *client);
        void messageRecuFromClient(const Message& message) const;
};

#endif
