/*---------------------------------------
시작일시: 2017. 06. 05(월)
최종일시: 2017. 06. 06(화)
이전 작성자: 송민표
최종 작성자: 김효민
QList<ChatClient*>를 QList<ChatClient> 로 수정
-----------------------------------------*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatthread.h"
#include "logging.h"
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*UI 설정*/
    ui->setupUi(this);


    /*log할 파일 생성 및 open*/
    log=new Logging();
    if(!log->openFile()){
        QString error;
        error.sprintf("cannot open log file");
        ui->textEdit->append(error);
    }

    /*create roomManager*/
    roomManager=new RoomManager();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startServer() //서버를 스타트하는 함수
{
    server.listen(QHostAddress::Any,2402); //포트 2402
    connect(&server,SIGNAL(newConnection()),this,SLOT(addConnection()));
    ui->textEdit->append(QString("wait for client"));
    //server start logging
    log->writeFile(QString("server start!"));
}

/*thread를 위한 함수, 일단 보*/
void incomingConnection(qintptr socketDescriptor){
   // QString usr;
    //usr.sprintf("%s Connecting...", socketDescriptor);
    //ChatThread *thread =new ChatThread(socketDescriptor, &server);

    //connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    //thread->start();
}

void MainWindow::addConnection()
{
    /*새로운 소켓 생성*/
    QTcpSocket *s;
    s = server.nextPendingConnection();

    ChatClient tempClient;
    tempClient.setClient(s);
    clientList.append(tempClient);
    //   roomManager->addClient(0, tempClient);  //waiting room is index 0

     //list.append(s); //list에 추가

    /*메시지를 보낼 때, disconnect할 시 규칙*/
    connect(s, SIGNAL(disconnected()),this,SLOT(removeConnection()));
    connect(s, SIGNAL(readyRead()),this,SLOT(recvMsg()));

    /*로깅 모듈을 이용해서 파일에 로그*/
    QString usr;
//    usr.sprintf("%dth usr is added", list.size());
    usr.sprintf("%dth usr is added", clientList.size());
    ui->textEdit->append(usr);
    log->writeFile(s->localAddress().toString()+" is connected");//write on log file

    /*client에게 보내는 메시지*/
    /*
    QByteArray arr("***welcome to chatting world!***\n");
    QTcpSocket* sock = clientList[clientList.size()-1]->getTCP();
    sock->write(arr);  //write
    sock->flush();
    */
}

void MainWindow::removeConnection()
{
    /*list에서 제거*/
    QTcpSocket* s = (QTcpSocket*)sender();
    //list.removeAll(s);
    for(int i=0; i<clientList.size(); i++){
        if(clientList[i].getTCP()==s){
            clientList.removeAt(i);
            break;
        }
    }
    s->deleteLater();

    /*여기서 로깅모듈에 unconnect 되었음을 알려준다.*/
    QString usr;
    usr.sprintf("One usr leaves. Current number of usrs = %d\nwait for client", clientList.size());
    ui->textEdit->append(usr);
    log->writeFile(s->localAddress().toString()+" is unconnected"); //write on log file

}

 void MainWindow::recvMsg()
{
     /*메시지를 보낸다.*/
     QTcpSocket* s = (QTcpSocket*)sender();
     QByteArray arr(s->readAll());

     /* Room module이 완성되면 Room에 따라 뿌려주는 형식으로 변경해야함
      * 현재 연결되어 있는(list에 있는 모든 소켓에 메시지 전달)*/
     /*
     foreach(QTcpSocket* sock, list)
     {
         sock->write(arr);
         sock->flush();
     }*/

     if(arr.contains("$%*2")){
         QList<QByteArray> tempArr=arr.split('/');
         QByteArray temp(tempArr.at(1));
         for(int i=0; i<clientList.size(); i++){
             QTcpSocket* sock=clientList[i].getTCP();
             sock->write(temp);
             sock->flush();
         }
     }


     /*로깅 모듈에 message가 날렸음을 알려주는 거 구현 필요*/
     QString str(arr);
     ui->textEdit->append(str + " send message\nwait for client");
     log->writeFile(s->localAddress().toString()+" sends the message");
}
