/*---------------------------------------
시작일시: 2017. 05. 21(일)
최종일시: 2017. 05. 21(일)
최종 작성자: 송민표
-----------------------------------------*/

#ifndef CHATTHREAD_H
#define CHATTHREAD_H

#include <QThread>
#include <QTcpSocket>

class ChatThread : public QThread
{
    Q_OBJECT

public:
    //explicit ChatThread(qintptr ID, QObject *parent =0);
    explicit ChatThread(qintptr ID, QTcpSocket *parent =0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // CHATTHREAD_H
