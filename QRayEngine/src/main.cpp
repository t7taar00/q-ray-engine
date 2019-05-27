#include <QApplication>

#include "mainview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w;
    w.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    w.show();

    return a.exec();
}
