#include "XImageEdit.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XImageEdit w;
    w.show();
    return a.exec();
}


