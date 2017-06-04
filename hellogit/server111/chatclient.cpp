#include "chatclient.h"

ChatClient::ChatClient(){

}

ChatClient::ChatClient(QTcpSocket* newClient){
    this->client=newClient;

}

void ChatClient::enterRoom(int roomIndex){

}

int ChatClient::exitRoom(){

}

QTcpSocket* ChatClient::getTCP(){
    return client;
}
