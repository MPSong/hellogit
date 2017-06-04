#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "room.h"
#include "chatclient.h"
#define MAX_ROOM_NUM 10

class RoomManager{
private:
    QList<Room*> room;
    int roomNum;

public:
    RoomManager();
    void addClient(int number, ChatClient* client);
    int removeClient();
    bool createRoom();
    bool removeRoom(int roomNum);
};

#endif // ROOMMANAGER_H
