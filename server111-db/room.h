#ifndef ROOM_H
#define ROOM_H

#include "chatclient.h"

class Room{
    QList<ChatClient*> clients;
    int clientNum;
    QString name;

public:
    Room(); //for debugging
    Room(QString str);
    Room(ChatClient chiefClient); //constructor
    QString getName();
    void enterRoom(ChatClient *client);
    void exitRoom(ChatClient *client);

};

#endif // ROOM_H
