#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_refreshButton_clicked();
    void on_searchSidButton_clicked();   // 按 SID 查找

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    int currentSid;                      // 保存本会话 ID

    void connectDatabase();
    void setupModel();
    void refreshTable();
    void fetchSessionId();               // 获取 MySQL 会话 ID
};

#endif // MAINWINDOW_H
