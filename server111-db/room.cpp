#include "room.h"

Room::Room(){

}

Room::Room(QString str){
     name=str;
}

void Room::enterRoom(ChatClient *client){
    clients.append(client);
}

void Room::exitRoom(ChatClient *client){
    clients.removeAll(client);
}

QString Room::getName(){
    return name;
}
