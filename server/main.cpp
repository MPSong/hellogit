/*-------------------------------
최종 작성 일시:2017. 05. 23.
이전 작성자:
최종 작성자: 송민표
main.cpp
-------------------------------*/

#include <QCoreApplication>
#include "ServerHandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerHandler Server;  //Handler server 객체 생성
    Server.startServer();  //server start

    return a.exec();
}
