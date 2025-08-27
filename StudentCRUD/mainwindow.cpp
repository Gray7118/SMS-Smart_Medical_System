#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectDatabase();
    fetchSessionId();
    setupModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("qtuser");        // 改成你的 MySQL 用户
    db.setPassword("12345678");        // 改成你的密码
    db.setDatabaseName("studentdb");

    if (!db.open()) {
        QMessageBox::critical(this, "数据库错误", db.lastError().text());
    }
}

void MainWindow::fetchSessionId()
{
    QSqlQuery query(db);
    if (query.exec("SELECT CONNECTION_ID()") && query.next()) {
        currentSid = query.value(0).toInt();
        ui->statusbar->showMessage("当前会话 SID: " + QString::number(currentSid));
    } else {
        currentSid = -1;
    }
}

void MainWindow::setupModel()
{
    model = new QSqlTableModel(this, db);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    refreshTable();

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "年龄");
    model->setHeaderData(3, Qt::Horizontal, "专业");
    model->setHeaderData(4, Qt::Horizontal, "SID");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::refreshTable()
{
    model->setFilter("");  // 清除过滤条件，显示全部
    model->select();
}

void MainWindow::on_addButton_clicked()
{
    QSqlRecord record = model->record();
    record.setValue("name", ui->nameEdit->text());
    record.setValue("age", ui->ageEdit->text().toInt());
    record.setValue("major", ui->majorEdit->text());
    record.setValue("sid", currentSid);

    if (!model->insertRecord(-1, record)) {
        QMessageBox::warning(this, "插入失败", model->lastError().text());
    }
    model->submitAll();
    refreshTable();   // 自动刷新
}

void MainWindow::on_deleteButton_clicked()
{
    QModelIndexList indexes = ui->tableView->selectionModel()->selectedRows();
    for (const QModelIndex &index : indexes) {
        model->removeRow(index.row());
    }
    model->submitAll();
    refreshTable();
}

void MainWindow::on_updateButton_clicked()
{
    if (!model->submitAll()) {
        QMessageBox::warning(this, "修改失败", model->lastError().text());
    }
    refreshTable();   // 自动刷新
}

void MainWindow::on_refreshButton_clicked()
{
    refreshTable();
}

void MainWindow::on_searchSidButton_clicked()
{
    QString sid = ui->sidEdit->text();
    if (sid.isEmpty()) {
        QMessageBox::information(this, "提示", "请输入要查询的会话 SID");
        return;
    }
    model->setFilter(QString("sid = %1").arg(sid));
    model->select();

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "查询结果", "没有找到对应的记录");
        refreshTable();
    }
}
