/*****************************************
File name:      mainwindow.cpp
Author:         luolewin
Version:        v2.0
Description:    实现医院导航主窗口功能（去掉菜单）
Date:           2025.08.30
*****************************************/

/* 自定义头文件 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"

/* Qt头文件 */
#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QDialog>
#include <QRegExpValidator>
#include <QDebug>

#define Infinity 2000
#define MAX 40
#define key 28

mgraph initgraph();
int locatevex(mgraph c,int v);
int allpath(mgraph c, int start, int end);
void path(mgraph c,int m,int n,int k);
QString transtring;

mgraph hospital;  // 图变量（医院）
int d[30];
int visited[30];
int shortest[MaxVertexNum][MaxVertexNum];   // 定义全局变量存储最小路径
int pathh[MaxVertexNum][MaxVertexNum];      // 定义存储路径


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    hospital = initgraph();

    /* 使用正则表达式，限制用户输入 */
    QRegExp regx("\\d{1,2}");
    QValidator* validator = new QRegExpValidator(regx, this);

    ui->setupUi(this);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit2->setValidator(validator);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent * event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "提示", tr("确定退出导航系统？\n")
                                                               , QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event-> ignore();
    } else {
        event-> accept();
    }
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect target(0, 0, 800, 600);
    QPixmap umap(":/images/hospital_map.jpg");

    // 检查图片是否加载成功
        if (umap.isNull()) {
            QMessageBox::warning(this, "提示", "hospital_map.jpg 加载失败，请检查文件名、路径或资源文件");
            return; // 图片加载失败，先不绘制
        }

    painter.drawPixmap(target, umap);
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    myDialog *messageWindow;
    QTextBrowser *textBrowser;
    QLabel *label;
    QPixmap *img;

    // 1 住院部
    if (x > 486 && x < 506 && y > 306 && y < 326) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/zhuyuanbu.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("住院部，为住院患者提供医疗服务。\nInpatient Department, providing medical services for hospitalized patients."));
        messageWindow->exec();
    }
    // 2 2号楼
    else if (x > 533 && x < 553 && y > 132 && y < 152) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/2hao.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("2号楼，办公和教学使用。\nBuilding 2, used for offices and teaching."));
        messageWindow->exec();
    }
    // 3 3号楼
    else if (x > 428 && x < 448 && y > 176 && y < 196) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/3hao.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("3号楼，科研办公使用。\nBuilding 3, used for scientific research and offices."));
        messageWindow->exec();
    }
    // 4 停车场
    else if (x > 352 && x < 372 && y > 414 && y < 434) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/parking.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("停车场，为医院车辆提供停放服务。\nParking Lot, providing parking services for hospital vehicles."));
        messageWindow->exec();
    }
    // 5 后勤楼
    else if (x > 339 && x < 359 && y > 186 && y < 206) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/houqin.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("后勤楼，负责医院后勤管理。\nLogistics Building, responsible for hospital logistics management."));
        messageWindow->exec();
    }
    // 6 303栋
    else if (x > 245 && x < 265 && y > 171 && y < 191) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/303dong.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("303栋，宿舍楼。\nBuilding 303, dormitory building."));
        messageWindow->exec();
    }
    // 7 行政楼
    else if (x > 171 && x < 191 && y > 262 && y < 282) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/xingzheng.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("行政楼，医院行政管理部门。\nAdministrative Building, housing hospital administrative offices."));
        messageWindow->exec();
    }
    // 8 外科大楼
    else if (x > 332 && x < 352 && y > 248 && y < 268) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/waike.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("外科大楼，为外科手术和诊疗提供场所。\nSurgical Building, providing space for surgeries and treatments."));
        messageWindow->exec();
    }
    // 9 综合医疗楼
    else if (x > 360 && x < 380 && y > 347 && y < 367) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/zhonghe.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("综合医疗楼，整合各科室医疗服务。\nComprehensive Medical Building, integrating services from multiple departments."));
        messageWindow->exec();
    }
    // 10 第二门诊部
    else if (x > 501 && x < 521 && y > 459 && y < 479) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/menzhen2.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("第二门诊部，提供门诊服务。\nSecond Outpatient Department, providing outpatient services."));
        messageWindow->exec();
    }
    // 11 门诊大楼
    else if (x > 623 && x < 643 && y > 395 && y < 415) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/menzhen.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("门诊大楼，为患者提供门诊就诊。\nOutpatient Building, providing outpatient consultations for patients."));
        messageWindow->exec();
    }
    // 12 急救中心/内科大楼
    else if (x > 656 && x < 676 && y > 328 && y < 348) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/jijiu_neike.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("急救中心/内科大楼，急救及内科就诊。\nEmergency/ Internal Medicine Building, providing emergency and internal medicine services."));
        messageWindow->exec();
    }
    // 13 填0，跳过
    else if (x == -1) { /* 占位 */ textBrowser->setText(tr("未使用。\nNot used.")); }
    // 14 填0，跳过
    else if (x == -1) { /* 占位 */ textBrowser->setText(tr("未使用。\nNot used.")); }
    // 15 科教大楼
    else if (x > 581 && x < 601 && y > 131 && y < 151) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/kejiao.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("科教大楼，用于教学和科研。\nEducation & Research Building, used for teaching and scientific research."));
        messageWindow->exec();
    }
    // 16 放疗中心
    else if (x > 575 && x < 595 && y > 184 && y < 204) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/fangliao.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("放疗中心，进行肿瘤放射治疗。\nRadiotherapy Center, providing cancer radiation therapy."));
        messageWindow->exec();
    }
    // 17 核磁共振
    else if (x > 500 && x < 520 && y > 207 && y < 227) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/heci.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("核磁共振，为患者提供核磁影像检查。\nMRI Center, providing magnetic resonance imaging for patients."));
        messageWindow->exec();
    }
    // 18 污水处理站
    else if (x > 546 && x < 566 && y > 254 && y < 274) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/wushui.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("污水处理站，医院污水处理设施。\nSewage Treatment Station, handling hospital wastewater."));
        messageWindow->exec();
    }
    // 19 热力中心
    else if (x > 605 && x < 625 && y > 254 && y < 274) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/reli.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("热力中心，医院供热设施。\nHeat Supply Center, providing heating for the hospital."));
        messageWindow->exec();
    }
    // 20 高压配电中心
    else if (x > 430 && x < 450 && y > 139 && y < 159) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/gaoya.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("高压配电中心，提供电力供应。\nHigh-Voltage Distribution Center, supplying electricity to the hospital."));
        messageWindow->exec();
    }
    // 21 301栋
    else if (x > 250 && x < 270 && y > 142 && y < 162) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/301dong.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("301栋，宿舍楼。\nBuilding 301, dormitory building."));
        messageWindow->exec();
    }
    // 22 313栋
    else if (x > 165 && x < 185 && y > 147 && y < 167) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/313dong.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("313栋，宿舍楼。\nBuilding 313, dormitory building."));
        messageWindow->exec();
    }
    // 23 幼儿园操场
    else if (x > 181 && x < 201 && y > 167 && y < 187) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/youeryuan.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("幼儿园操场，供儿童活动。\nKindergarten Playground, providing space for children to play."));
        messageWindow->exec();
    }
    // 24 312栋
    else if (x > 148 && x < 168 && y > 310 && y < 330) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/312dong.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("312栋，宿舍楼。\nBuilding 312, dormitory building."));
        messageWindow->exec();
    }
    // 25 316栋
    else if (x > 188 && x < 208 && y > 349 && y < 369) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/316dong.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("316栋，宿舍楼。\nBuilding 316, dormitory building."));
        messageWindow->exec();
    }
    // 26 317栋
    else if (x > 225 && x < 245 && y > 365 && y < 385) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/317dong.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("317栋，宿舍楼。\nBuilding 317, dormitory building."));
        messageWindow->exec();
    }
    // 27 PET中心
    else if (x > 406 && x < 426 && y > 368 && y < 388) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/pet.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("PET中心，提供影像检查。\nPET Center, providing imaging examinations."));
        messageWindow->exec();
    }
    // 28 器材料库房
    else if (x > 257 && x < 277 && y > 388 && y < 408) {
        messageWindow = new myDialog(this);
        textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");
        label = messageWindow->findChild<QLabel *>("label");
        img = new QPixmap(":/images/kucang.jpg");
        label->setPixmap(*img);
        textBrowser->setText(tr("器材料库房，存放医疗器材。\nMedical Supplies Storage, storing hospital equipment and materials."));
        messageWindow->exec();
    }
}



void MainWindow::on_pushButton_clicked()
{
    int start = ui->lineEdit->text().toInt();   // 获取起点位置
    int end = ui->lineEdit2->text().toInt();    // 获取终点位置

    ui->textBrowser->clear();                   // 清除浏览框里的文本

    if ((start > 0 and start <= key) and (end > 0 and end <= key)) {
        allpath(hospital, start, end);    // 可选路径搜索
    }
}


void MainWindow::on_pushButton2_clicked()
{
    int start = ui->lineEdit->text().toInt();   // 获取起点位置
    int end = ui->lineEdit2->text().toInt();    // 获取终点位置

    ui->textBrowser2->clear();                  // 清除浏览框里的文本

    if ((start > 0 and start <= key) and (end > 0 and end <= key)) {
        shortdistance(hospital, start, end);
    }
}


void MainWindow::on_pushButton3_clicked()
{
    QDialog *messageWindow = new myDialog(this);
    QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/hospital_building.jpg");
    QLabel *label = messageWindow->findChild<QLabel *>("label");

    label->setPixmap(*img);
    textBrowser->setText(tr(
        "医院简介：本院设有内科、外科、急诊、高压氧等多个科室，环境优美，交通便利。\n"
        "Hospital Overview: This hospital has multiple departments including Internal Medicine, Surgery, Emergency, Hyperbaric Oxygen, with beautiful environment and convenient transportation."
    ));


    messageWindow->exec();
}


mgraph initgraph()
{
    int i,j;
    mgraph c;
    c.vexnum=28;            // 顶点个数，即地点个数
    c.arcnum=40;             // 边的个数（示例，可根据实际连线调整）

    // 初始化顶点编号和位置
    for(i=1; i<=c.vexnum; i++)
    {
        c.vexs[i].position = i;
    }

    // 设置顶点名称
    strcpy(c.vexs[1].name,"住院部 (Inpatient Department)");
    strcpy(c.vexs[2].name,"2号楼 (Building 2)");
    strcpy(c.vexs[3].name,"3号楼 (Building 3)");
    strcpy(c.vexs[4].name,"停车场 (Parking Lot)");
    strcpy(c.vexs[5].name,"后勤楼 (Logistics Building)");
    strcpy(c.vexs[6].name,"303栋 (Building 303)");
    strcpy(c.vexs[7].name,"行政楼 (Administrative Building)");
    strcpy(c.vexs[8].name,"外科大楼 (Surgical Building)");
    strcpy(c.vexs[9].name,"综合医疗楼 (Comprehensive Medical Building)");
    strcpy(c.vexs[10].name,"第二门诊部 (Second Outpatient Department)");
    strcpy(c.vexs[11].name,"门诊大楼 (Outpatient Building)");
    strcpy(c.vexs[12].name,"急救中心/内科大楼 (Emergency/Internal Medicine Building)");
    strcpy(c.vexs[13].name,"0"); // 填0
    strcpy(c.vexs[14].name,"0"); // 填0
    strcpy(c.vexs[15].name,"科教大楼 (Education & Research Building)");
    strcpy(c.vexs[16].name,"放疗中心 (Radiotherapy Center)");
    strcpy(c.vexs[17].name,"核磁共振 (MRI Center)");
    strcpy(c.vexs[18].name,"污水处理站 (Sewage Treatment Station)");
    strcpy(c.vexs[19].name,"热力中心 (Heat Supply Center)");
    strcpy(c.vexs[20].name,"高压配电中心 (High-Voltage Distribution Center)");
    strcpy(c.vexs[21].name,"301栋 (Building 301)");
    strcpy(c.vexs[22].name,"313栋 (Building 313)");
    strcpy(c.vexs[23].name,"幼儿园操场 (Kindergarten Playground)");
    strcpy(c.vexs[24].name,"312栋 (Building 312)");
    strcpy(c.vexs[25].name,"316栋 (Building 316)");
    strcpy(c.vexs[26].name,"317栋 (Building 317)");
    strcpy(c.vexs[27].name,"PET中心 (PET Center)");
    strcpy(c.vexs[28].name,"器材料库房 (Medical Supplies Storage)");

    // 初始化邻接矩阵为无穷大
    for(i=1; i<=c.vexnum; i++)
    {
        for(j=1;j<=c.vexnum;j++)
            c.arcs[i][j].adj = Infinity;
    }

    // 示例路径（每个点连3条线，可自行调整实际医院距离）
    c.arcs[1][2].adj = 30;  c.arcs[1][3].adj = 25;  c.arcs[1][4].adj = 35;
    c.arcs[2][5].adj = 20;  c.arcs[2][20].adj = 25; c.arcs[3][6].adj = 15;
    c.arcs[3][5].adj = 10;  c.arcs[4][8].adj = 25;  c.arcs[4][9].adj = 20;
    c.arcs[5][16].adj = 15; c.arcs[5][8].adj = 20;  c.arcs[6][21].adj = 10;
    c.arcs[6][22].adj = 15; c.arcs[7][23].adj = 15; c.arcs[7][24].adj = 20;
    c.arcs[8][9].adj = 15;  c.arcs[8][17].adj = 20; c.arcs[9][10].adj = 20;
    c.arcs[10][11].adj = 15;c.arcs[10][12].adj = 10;c.arcs[11][19].adj = 25;
    c.arcs[12][15].adj = 20;c.arcs[15][16].adj = 15;c.arcs[15][17].adj = 20;
    c.arcs[16][18].adj = 15;c.arcs[17][27].adj = 20;c.arcs[18][19].adj = 10;
    c.arcs[19][20].adj = 15;c.arcs[21][24].adj = 15;c.arcs[22][23].adj = 15;
    c.arcs[24][25].adj = 10;c.arcs[25][26].adj = 10;c.arcs[26][28].adj = 15;
    c.arcs[27][28].adj = 10;

    // 对称赋值（无向图）
    for(i=1;i<=c.vexnum;i++)
        for(j=1;j<=c.vexnum;j++)
            c.arcs[j][i].adj = c.arcs[i][j].adj;

    return c;
}







/**
 * @brief 查找景点在图中的序号
 * @param c
 * @param v
 * @return i 顶点序号; -1 没有找到该顶点
 */
int locatevex(mgraph c,int v)
{
    int i;
    for (i=1;i<=c.vexnum;i++)
      if (v==c.vexs[i].position)  return i;  // 找到，返回顶点序号i
    return -1;  // 没有找到该顶点
}


/**
 * @brief 查找并输出序号为m,n景点间的长度不超过8个景点的路径
 * @param c
 * @param m
 * @param n
 * @param k
 */
void MainWindow::path(mgraph c, int m, int n, int k)
{
    if (k > 8) return;  // 限制路径最多 8 个景点

    if (d[k] == n) {  // 到达终点
        int length = 0;
        for (int i = 0; i < k; i++)
            length += c.arcs[d[i]][d[i+1]].adj;

        QString tmp;
        for (int i = 0; i <= k; i++) {
            tmp += QString(c.vexs[d[i]].name);  // 使用景点名称
            if (i != k) tmp += " --> ";
        }

        ui->textBrowser->append(tmp);
        ui->textBrowser->append(
            "总路线长为 " + QString::number(length) + "\n" +
            "Total route length: " + QString::number(length)
        );

        return;
    }

    for (int s = 1; s <= c.vexnum; s++) {
        if (c.arcs[d[k]][s].adj < Infinity && visited[s] == 0) {
            visited[s] = 1;
            d[k+1] = s;
            path(c, m, n, k+1);
            visited[s] = 0;
        }
    }
}


void MainWindow::allpath(mgraph c, int start, int end)
{
    int m = locatevex(c, start);
    int n = locatevex(c, end);
    if (m == -1 || n == -1) return;

    // 初始化
    for (int i = 0; i <= c.vexnum; i++) visited[i] = 0;
    d[0] = m;
    visited[m] = 1;

    ui->textBrowser->clear();
    path(c, m, n, 0);
}



/**
 * @brief 任意两点间最短距离
 * @param c     地图数据结构
 * @param start 起点序号
 * @param end   终点序号
 */
void MainWindow::findShortestPaths(mgraph c, int start, int end, int current, int length, QVector<int> &tmp)
{
    if (tmp.size() > 8) return;  // 限制最多 8 个景点

    if (current == end) {
        if (length == shortest[start][end]) {
            QString pathStr;
            for (int i = 0; i < tmp.size(); i++) {
                pathStr += QString(c.vexs[tmp[i]].name);  // 使用景点名称
                if (i != tmp.size()-1) pathStr += " --> ";
            }
            ui->textBrowser2->append(pathStr);
            ui->textBrowser2->append(
                "最短路线长为 " + QString::number(length) + "\n" +
                "Shortest route length: " + QString::number(length)
            );
        }
        return;
    }

    for (int s = 1; s <= c.vexnum; s++) {
        if (c.arcs[current][s].adj < Infinity && visited[s] == 0) {
            if (length + c.arcs[current][s].adj <= shortest[start][end]) {
                visited[s] = 1;
                tmp.append(s);
                findShortestPaths(c, start, end, s, length + c.arcs[current][s].adj, tmp);
                visited[s] = 0;
                tmp.removeLast();
            }
        }
    }
}


void MainWindow::shortdistance(mgraph c, int start, int end)
{
    floyd(c);  // 计算 shortest 数组
    ui->textBrowser2->clear();

    for (int i = 0; i <= c.vexnum; i++) visited[i] = 0;
    QVector<int> tmp;
    tmp.append(start);
    visited[start] = 1;

    findShortestPaths(c, start, end, start, 0, tmp);
}



/**
 * @brief 弗洛伊德算法
 * @param c 地图数据结构
 */
void MainWindow::floyd(mgraph c)
{
    int i, j, k;
    for (i=1; i<=key; i++) {   // 将图的邻接矩阵赋值给 shortest二维数组，将矩阵pathh全部初始化为-1
        for (j=1; j<=key; j++) {
            shortest[i][j] = c.arcs[i][j].adj;
            pathh[i][j] = j;
        }
    }

    for (k=1; k<=key; k++) {   // 核心操作，完成了以k为中间点对所有的顶点对（i,j）进行检测和修改
        for (i=1; i<=key; i++) {
            for (j=1; j<=key; j++) {
                if (shortest[i][j] > shortest[i][k]+shortest[k][j]) {
                    shortest[i][j] = shortest[i][k]+shortest[k][j];
                    pathh[i][j] = pathh[i][k];  // 记录一下所走的路，P数组用来存放前驱顶点
                }
             }
        }
    }
}

