#include "widget.h"
#include "splashscreen.h"
#include "navigation/mainwindow.h"
#include <QApplication>
#include <QTimer>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // 加载 QSS 文件
    QFile file(":/MacOS.qss");   // 如果放在资源文件里用 :/ 前缀

    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "无法打开 QSS 文件";
    } else {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);
        file.close();
    }

    // 启动动画
    SplashScreen splash;
    splash.setDisplayTime(3500); // 3.5 秒
    splash.show();

    // 创建主界面 Widget
    Widget w;

    // 当 splash 结束后显示主界面
    QObject::connect(&splash, &SplashScreen::finished, [&w](){
        w.show();
    });

    // 安全机制：防止 splash 卡住，4秒后显示主界面
    QTimer::singleShot(4000, &w, &Widget::show);

    return a.exec();
}

