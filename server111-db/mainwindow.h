/*---------------------------------------
시작일시: 2017. 05. 21(일)
최종일시: 2017. 06. 14
이전 작성자: 송민표
최종 작성자: 송민표
-----------------------------------------*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtSql>
#include "roommanager.h"
#include "logging.h"
#include "chatclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void startServer(); //서버를 스타트하는 함수

    ~MainWindow();
signals:

public slots:
    void addConnection();
    void removeConnection();
    void recvMsg();
private:
    Logging *log;  //logging module
    QTcpServer server;
    Ui::MainWindow *ui;
    QSqlDatabase mydb;

    QString roomManager;
    /*crazy coding*/
    QList<QTcpSocket*> socketList;
    QList<QString> roomNames;
    QList<QString> clientNickname;
    int clientNum;
};

#endif // MAINWINDOW_H
