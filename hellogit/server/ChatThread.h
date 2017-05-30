/*-------------------------------
최종 작성 일시:2017. 05. 23.
이전 작성자:
최종 작성자: 송민표
MultiThread를 위한 chatThred.h 헤더
thread를 구현
-------------------------------*/

#ifndef CHAT_THREAD_H__
#define CHAT_THREAD_H__

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class ChatThread : public QThread
{
    Q_OBJECT
public:
    explicit ChatThread(qintptr ID, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;  //socket
    qintptr socketDescriptor;
};

#endif
