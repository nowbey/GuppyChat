#include <QApplication>
#include "ClientConnection.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    ClientConnection Connectionfenetre;
    Connectionfenetre.show();

    return app.exec();
}
