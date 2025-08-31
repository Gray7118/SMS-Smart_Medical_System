#include "widget.h"
#include "splashscreen.h"
#include <QApplication>
#include <QTimer>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载 QSS 文件
    QFile file(":/MacOS.qss");   // 如果放在资源文件里用 :/ 前缀
    if (!file.open(QFile::ReadOnly)) {
        qDebug("无法打开 QSS 文件");
    } else {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);
        file.close();
    }

    // 启动动画
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
