#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_signin_clicked();

    void on_pushButton_makeroom_clicked();

    void on_pushButton_signup_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_logout_2_clicked();
    
    void on_pushButton_confirm_clicked();

    void on_pushButton_check_clicked();

    void on_pushButton_check_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
};

#endif // MAINWINDOW_H
