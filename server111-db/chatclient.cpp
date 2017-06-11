#include "chatclient.h"

ChatClient::ChatClient(){

}

void ChatClient::setClient(QTcpSocket* newClient, QString nickname){
    client=newClient;
    nickName=nickname;
}


void ChatClient::enterRoom(int Index){
    roomIndex=Index;
}

int ChatClient::exitRoom(){

}

QTcpSocket* ChatClient::getTCP(){
    return client;
}

int ChatClient::getRoomIndex(){
    return roomIndex;
}

QString ChatClient::getNickName(){
    return nickName;
}
