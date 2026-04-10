#include "qform1.h"

#include <QApplication>
#include <QStyleFactory>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // QPixmap pixmap(":/loadingScreen/loadingScreen.png");
    QPixmap pixmap(":/loadingScreen/GS_SplashScreen.png");

    QSplashScreen splash(pixmap);
    splash.setAttribute(Qt::WA_TranslucentBackground);
    splash.show();

    QForm1 w;
    QApplication::setStyle("fusion");
    //QApplication::setStyle(QStyleFactory::create("windows")); //"fusion"
    QTimer::singleShot(2000, &splash, &QSplashScreen::close);
    QTimer::singleShot(2400, &w, &QMainWindow::show);

    // w.show();
    return a.exec();
}


// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);

//     // QPixmap pixmap(":/loadingScreen/loadingScreen.png");
//     QPixmap pixmap(":/loadingScreen/GS.png");

//     QSplashScreen splash(pixmap);
//     splash.setMask(pixmap.mask());
//     splash.show();

//     QForm1 w;
//     //QApplication::setStyle(QStyleFactory::create("windows")); //"fusion"
//     QApplication::setStyle("fusion");
//     QTimer::singleShot(1600, &splash, &QSplashScreen::close);
//     QTimer::singleShot(2000, &w, &QMainWindow::show);

//     // w.show();
//     return a.exec();
// }
