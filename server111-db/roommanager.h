#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "room.h"
#include "chatclient.h"
#define MAX_ROOM_NUM 10

class RoomManager{
private:
    QList<Room*> rooms;
    int roomNum;

public:
    RoomManager();
    void addClient(int number, ChatClient* client);
    int removeClient();
    void createRoom(QString str);
    void moveClient(int number, ChatClient* client);
    int getRoomNum(QString str);
    bool removeRoom(int roomNum);
};

#endif // ROOMMANAGER_H
