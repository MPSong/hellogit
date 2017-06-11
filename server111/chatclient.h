#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QTcpSocket>

class ChatClient
{
    int roomIndex;
    QTcpSocket* client;
    QString nickName;

public:
    ChatClient();
    void setClient(QTcpSocket* newClient, QString nickname);

    QTcpSocket* getTCP();
    void enterRoom(int Index);
    QString getNickName();
    int getRoomIndex();
    int exitRoom();

};
#endif // CHATCLIENT_H
