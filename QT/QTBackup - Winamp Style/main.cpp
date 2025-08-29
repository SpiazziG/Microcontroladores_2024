#include "qform1.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QForm1 w;
    QApplication::setStyle(QStyleFactory::create("windows"));
    w.show();
    return a.exec();
}
