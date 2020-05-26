#include "mainwindow.h"
#include "startwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/imgs/fav.png"));
    StartWindow startWindow;
    startWindow.show();
    return a.exec();
}

