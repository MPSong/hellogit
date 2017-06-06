#include "roommanager.h"

RoomManager::RoomManager(){
    roomNum=0;
    createRoom(); //0 index room is waiting room
}

bool RoomManager::createRoom(){
    Room *newRoom;
    room.append(newRoom);
}

bool RoomManager::removeRoom(int roomNum){
    /*move to waiting room from current room*/



    /*remove room*/
    room.removeAll(room.at(roomNum));
}

void RoomManager::addClient(int number,ChatClient* client){
    room.at(number)->enterRoom(client);
}

int RoomManager::removeClient(){

}
