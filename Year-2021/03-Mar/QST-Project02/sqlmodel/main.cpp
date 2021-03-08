#include "mainwindow.h"
#include <QApplication>

#include "message.h"
#include "transfer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    if (!createConnection()) return 1;

    MainWindow w;
    w.show();

    return a.exec();
}
