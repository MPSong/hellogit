#ifndef ROOM_H
#define ROOM_H

#include "chatclient.h"

class Room{
    QList<ChatClient*> clients;
    int clientNum;

public:
    Room(); //for debugging
    Room(ChatClient chiefClient); //constructor
    void enterRoom(ChatClient *client);
    void exitRoom(ChatClient *client);

};

#endif // ROOM_H
