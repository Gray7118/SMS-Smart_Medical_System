
#include <QtWidgets>

#include "sendemail.h"
#include "../../src/SmtpMime"

#include <iostream>
#include <QFile>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SendEmail form (NULL);

    form.setWindowTitle("Email");

    QFile file(":/MacOS.qss");  // 路径根据你的 qrc 前缀
        if (!file.exists()) {
            qDebug() << "QSS 文件不存在: :/MacOS.qss";
        } else {
            if (file.open(QFile::ReadOnly)) {
                QString qss = file.readAll();
                file.close();
                a.setStyleSheet(qss);  // 设置全局样式
                qDebug() << "QSS 文件加载成功!";
            } else {
                qDebug() << "QSS 文件打开失败!";
            }
        }

    form.show();

    a.exec();


}

