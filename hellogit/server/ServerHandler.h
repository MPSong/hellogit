/*-------------------------------
최종 작성 일시:2017. 05. 23.
이전 작성자: 김효민
최종 작성자: 송민표
server 구현을 위한 ServerHandler
-------------------------------*/
#ifndef SERVER_HANDLER_H__
#define SERVER_HANDLER_H__

#include <QTcpServer>
#include <QDebug>

class ServerHandler : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServerHandler(QObject *parent = 0);
    void startServer();

protected:
    void incomingConnection( qintptr socketDescriptor );

signals:

public slots:
    void addConnection();   //connection 추가
    void removeConnection();
    void recvMsg();

private:
    QList<QTcpSocket*> list;
    //QTcpServer server;  //server 변수 대신에 this를 이용..
};

#endif
