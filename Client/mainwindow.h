#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QTcpSocket>
#include "dialog.h"

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
    void onSent(const QString& room);

    void on_pushButton_signin_clicked();

    void on_pushButton_makeroom_clicked();

    void on_pushButton_signup_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_logout_2_clicked();
    
    void on_pushButton_confirm_clicked();

    void recvMsg();

    void on_pushButton_entrance_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_invite_clicked();

    void on_pushButton_check_id_clicked();

    void on_pushButton_check_nick_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    QTcpSocket socket;
    Dialog *dialog;
    QString nickName;
};

#endif // MAINWINDOW_H
