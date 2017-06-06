#include "room.h"

Room::Room(){

}

void Room::enterRoom(ChatClient *client){
    clients.append(client);
}

void Room::exitRoom(ChatClient *client){
    clients.removeAll(client);
}
