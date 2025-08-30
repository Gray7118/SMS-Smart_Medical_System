#include "widget.h"
#include "splashscreen.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SplashScreen splash;
    splash.setDisplayTime(3500); // 延长到3.5秒
    splash.show();

    Widget w;

    QObject::connect(&splash, &SplashScreen::finished, [&w](){
        w.show();
    });

    // 安全机制延长到4秒
    QTimer::singleShot(4000, &w, &Widget::show);

    return a.exec();
}
