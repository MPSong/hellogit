#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "room.h"
#define MAX_ROOM_NUM 10

class RoomManager{
private:
    Room *room;
    int roomNum;

public:
    RoomManager();
    bool createRoom();
    bool removeRoom();
};

#endif // ROOMMANAGER_H
