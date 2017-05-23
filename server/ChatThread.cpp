/*-------------------------------
최종 작성 일시:2017. 05. 23.
이전 작성자:
최종 작성자: 송민표
MultiThread를 위한 chatThred.cpp
thread를 구현
-------------------------------*/
#include "ChatThread.h"

ChatThread::ChatThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

/*실제로 스레드가 작동되는 run 함수*/
void ChatThread::run()
{
    // for debug
    qDebug() << "Thread started";

    socket = new QTcpSocket();

    /*ID*/
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        /*error 처리*/
        emit error(socket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    /*Thread 작동 시 SLOT 함수*/
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // 연결된 client의 ID를 보여준다.
    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();  //실행
}

void ChatThread::readyRead()
{
    // get the information
    QByteArray Data = socket->readAll();

    // will write on server side window
    qDebug() << socketDescriptor << " Data in: " << Data;

    socket->write(Data);
}

/*disconnected 함수*/
void ChatThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    socket->deleteLater();
    exit(0);
}
