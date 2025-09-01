/*****************************************
File name:      main.cpp
Author:         luolewin
Version:        v1.0
Description:    Qt自生产的main.cpp，实现事件循环
Date:           2020.12.17
*****************************************/

#include "mainwindow.h"
#include "mystruct.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* 引入自定义结构体 */
    qRegisterMetaType<arcell>("arcell");
    qRegisterMetaType<vexsinfo>("vexsinfo");
    qRegisterMetaType<mgraph>("mgraph");

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

    MainWindow w;
    w.show();

    return a.exec();
}
