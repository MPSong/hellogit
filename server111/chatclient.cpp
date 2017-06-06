#include "chatclient.h"

ChatClient::ChatClient(){

}

void ChatClient::setClient(QTcpSocket* newClient){
    client=newClient;
}


void ChatClient::enterRoom(int roomIndex){

}

int ChatClient::exitRoom(){

}

QTcpSocket* ChatClient::getTCP(){
    return client;
}
