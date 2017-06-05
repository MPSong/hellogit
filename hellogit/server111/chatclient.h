#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QTcpSocket>

class ChatClient
{
    int roomIndex;
    QTcpSocket* client;
    int index;

public:
    ChatClient();
    void setClient(QTcpSocket* newClient);
    QTcpSocket* getTCP();
    void enterRoom(int roomIndex);
    int exitRoom();

};
#endif // CHATCLIENT_H
