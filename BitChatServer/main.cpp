#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.startServer();

    return a.exec();
}

