/*---------------------------------------
시작일시: 2017. 05. 21(일)
최종일시: 2017. 05. 25(일)
이전 작성자: 송민표
최종 작성자: 송민표
logmodule 추가
-----------------------------------------*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include "logging.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void startServer(); //서버를 스타트하는 함수
    void incomingConnection(qintptr socketDescriptor);

    ~MainWindow();
signals:

public slots:
    void addConnection();
    void removeConnection();
    void recvMsg();
private:
    Logging log;  //logging module
    QList<QTcpSocket*> list;
    QTcpServer server;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
