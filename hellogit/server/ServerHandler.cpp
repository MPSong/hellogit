/*-------------------------------
최종 작성 일시:2017. 05. 23.
이전 작성자: 김효민
최종 작성자: 송민표
server 구현을 위한 ServerHandler
-------------------------------*/
#include "ServerHandler.h"
#include "ChatThread.h"

ServerHandler::ServerHandler(QObject *parent) :
    QTcpServer(parent)
{

}

void ServerHandler::startServer()
{
    if(this->listen(QHostAddress::Any, 2402))  //포트 2402
    {
        qDebug() << "Server started";
    }
    else
    {
        qDebug() << "Server did not start!";
    }
    connect(&this, SIGNAL(newConnection()), this, SLOT(addConnection()));  //connect
    qDebug()<<"wait for client";
}

void ServerHandler::addConnection(){

    /*새로운 소켓 생성*/
    QTcpSocket *newSocket;
    newSocket=this.nextPendingConnection();
    list.append(newSocket);  //list에 추가

    /*메시지를 보낼 때, disconnect할 때 규칙*/
    connect(newSocket, SIGNAL(disconnected()), this, SLOT(removeConnection()));
    connect(newSocket, SIGNAL(readyRead()), this, SLOT(recvMsg()));

    /*여기서 부턴 수정할 코드(로깅 모듈을 이용해서 파일에 로그)*/
    qDebug() << list.size()<<"th usr is added";  //일단 Debug용

    /*Client에게 보내는 메시지 일단 */
    QByteArray arr("***welcome to linux chatting world!***\n");
    QTcpSocket* sock = list[list.size()-1];
    sock->write(arr);
    sock->flush();
}

void removeConnection(){
    /*list에서 제거*/
    QTcpSocket *tempSocket=(QTcpSocket*)sender();
    list.removeAll(tempSocket);
    tempSocket->deleteLater();

    /*여기에 로깅모듈에 unconnnect 되었음을 알려준다.*/
    qDebug() << "One user leaves. Current number of usr = "<<list.size()<<"\n wait for client";  //일단 debug용

}

void recvMsg(){
    /*메시지를 보낸다.*/
    QTcpSocket *messageSocket=(QTcpSocket*)sender();
    QByteArray arr(messageSocket->readAll());

    /*현재 연결되어 있는(list에 있는 모든 소켓에 메시지 전달)*/
    foreach(QTcpSocket *sock, list){
      sock->write(arr);
      sock->flush();
    }

    /*로깅 모듈에 message가 날렸음을 알려준다?*/
    qDebug() <<"your are join the chatting room\nwait for client";  //일단 디버그 용
}

void ServerHandler::incomingConnection(qintptr socketDescriptor)  //thread connection
{
  // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    ChatThread *thread = new ChatThread(socketDescriptor, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
