#include "roommanager.h"

RoomManager::RoomManager(){
    roomNum=0;
    createRoom("main"); //0 index room is waiting room
}

void RoomManager::createRoom(QString str){
    Room newRoom(str);
    rooms.append(&newRoom);
    roomNum++;
}

int RoomManager::getRoomNum(QString str){
    for(int i=0; i<roomNum; i++){
        QString temp=rooms.at(i)->getName();
        if(str==temp){
            return i;
        }
    }
    return 0;
}

bool RoomManager::removeRoom(int roomNum){
    /*move to waiting room from current room*/



    /*remove room*/
    rooms.removeAll(rooms.at(roomNum));
}

void RoomManager::addClient(int number,ChatClient* client){
    rooms.at(number)->enterRoom(client);
    client->enterRoom(number);
}

int RoomManager::removeClient(){

}

void RoomManager::moveClient(int number, ChatClient* client){
    int previousRoom=client->getRoomIndex();
    rooms.at(previousRoom)->exitRoom(client);
    client->enterRoom(number);
    rooms.at(number)->enterRoom(client);
}
