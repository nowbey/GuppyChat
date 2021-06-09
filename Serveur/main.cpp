#include <QApplication>
#include "ServerManagement.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    ServerManagement fenetre;
    fenetre.show();

    return app.exec();
}
