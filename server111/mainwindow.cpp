#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server.listen(QHostAddress::Any,2402);
    connect(&server,SIGNAL(newConnection()),this,SLOT(addConnection()));
    ui->textEdit->append(QString("wait for client"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addConnection()
{
    QTcpSocket *s;
    s = server.nextPendingConnection();
    list.append(s);
    connect(s, SIGNAL(disconnected()),this,SLOT(removeConnection()));
    connect(s, SIGNAL(readyRead()),this,SLOT(recvMsg()));
    QString usr;
    usr.sprintf("%dth usr is added", list.size());
    ui->textEdit->append(usr);
    QByteArray arr("***welcome to linux chatting world!***\n");
    QTcpSocket* sock = list[list.size()-1];
    sock->write(arr);
    sock->flush();
}

void MainWindow::removeConnection()
{
    QTcpSocket* s = (QTcpSocket*)sender();
    list.removeAll(s);
    s->deleteLater();
    QString usr;
    usr.sprintf("One usr leaves. Current number of usrs = %d\nwait for client", list.size());
    ui->textEdit->append(usr);

}

 void MainWindow::recvMsg()
{
     QTcpSocket* s = (QTcpSocket*)sender();
     QByteArray arr(s->readAll());
     foreach(QTcpSocket* sock, list)
     {
         sock->write(arr);
         sock->flush();
     }
     QString str(arr);
     ui->textEdit->append("your are join the chatting room\nwait for client");
}
