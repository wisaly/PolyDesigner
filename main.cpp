#include "polydesigner.h"
#include <QtWidgets/QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PolyDesigner w;
    w.show();
    return a.exec();
}
