/*---------------------------------------
시작일시: 2017. 06. 05(월)
최종일시: 2017. 06. 06(화)
이전 작성자: 송민표
최종 작성자: 김효민
QList<ChatClient*>를 QList<ChatClient> 로 수정
-----------------------------------------*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatthread.h"
#include "logging.h"
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*UI 설정*/
    ui->setupUi(this);

    /*데이터베이스 추가 및 경로와 연결*/
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/hyomin/다운로드/hellogit-master (2)/user.db");

    if(!mydb.open())
    {
        ui->textEdit->append(QString("Failed to open the database"));
    }

    /*log할 파일 생성 및 open*/
    log=new Logging();
    if(!log->openFile()){
        QString error;
        error.sprintf("cannot open log file");
        ui->textEdit->append(error);
    }

    /*create roomManager*/
    roomManager=new RoomManager();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startServer() //서버를 스타트하는 함수
{
    server.listen(QHostAddress::Any,2402); //포트 2402
    connect(&server,SIGNAL(newConnection()),this,SLOT(addConnection()));
    ui->textEdit->append(QString("wait for client"));
    //server start logging
    log->writeFile(QString("server start!"));
}

/*thread를 위한 함수, 일단 보*/
void incomingConnection(qintptr socketDescriptor){
   // QString usr;
    //usr.sprintf("%s Connecting...", socketDescriptor);
    //ChatThread *thread =new ChatThread(socketDescriptor, &server);

    //connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    //thread->start();
}

void MainWindow::addConnection()
{
    /*새로운 소켓 생성*/
    QTcpSocket *s;

    s = server.nextPendingConnection();
/*
    ChatClient tempClient;
    tempClient.setClient(s);
    clientList.append(tempClient);
    roomManager->addClient(0, &tempClient);  //waiting room is index 0
*/
    /*메시지를 보낼 때, disconnect할 시 규칙*/
    connect(s, SIGNAL(disconnected()),this,SLOT(removeConnection()));
    connect(s, SIGNAL(readyRead()),this,SLOT(recvMsg()));

    /*로깅 모듈을 이용해서 파일에 로그*/
    QString usr;
    usr.sprintf("%dth usr is added", clientList.size());
    ui->textEdit->append(usr);
    log->writeFile(s->localAddress().toString()+" is connected");//write on log file

    /*client에게 보내는 메시지*/
    /*
    QByteArray arr("***welcome to chatting world!***\n");
    QTcpSocket* sock = clientList[clientList.size()-1]->getTCP();
    sock->write(arr);  //write
    sock->flush();
    */
}

void MainWindow::removeConnection()
{
    /*list에서 제거*/
    QTcpSocket* s = (QTcpSocket*)sender();
    //list.removeAll(s);
    for(int i=0; i<clientList.size(); i++){
        if(clientList[i].getTCP()==s){
            clientList.removeAt(i);
            break;
        }
    }
    s->deleteLater();

    /*여기서 로깅모듈에 unconnect 되었음을 알려준다.*/
    QString usr;
    usr.sprintf("One usr leaves. Current number of usrs = %d\nwait for client", clientList.size());
    ui->textEdit->append(usr);
    log->writeFile(s->localAddress().toString()+" is unconnected"); //write on log file

}

 void MainWindow::recvMsg()
{
     /*메시지를 보낸다.*/
     QTcpSocket* s = (QTcpSocket*)sender();
     QByteArray arr(s->readAll());

     /* Room module이 완성되면 Room에 따라 뿌려주는 형식으로 변경해야함
      * 현재 연결되어 있는(list에 있는 모든 소켓에 메시지 전달)*/
     /*
     foreach(QTcpSocket* sock, list)
     {
         sock->write(arr);
         sock->flush();
     }*/


     if(arr.contains("$%*1")){  //log in
         QList<QByteArray> tempArr=arr.split('/');
         QByteArray id(tempArr.at(1));
         QByteArray password(tempArr.at(2));
         QString nickName;

         /*데이터베이스 오픈 가능한지 확인*/
         if(!mydb.isOpen()){
             QString usr;
             usr.sprintf("Failed to open the database");
             ui->textEdit->append(usr);
             return;
         }

         /*입력받은 id와 password가 데이터베이스에 존재 하는지 확인*/
         QSqlQuery qry;

         if(qry.exec("select * from USER where UID='"+ id +"' and Password='" + password +"'")){
             int count=0;
             //검색된 튜플 개수 카운트
             while(qry.next())
             {
                 count++;
             }
             //존재할 경우
             if(count==1)
             {
                 //데이터베이스에서 해당 id의 State값을 'connected'로 update
                 QString state = "connected";
                 qry.exec("update USER set State = '" + state + "' where UID = '" + id + "'");

                 /*입력받은 id의 닉네임 검색*/
                 qry.exec("select Nickname from USER where UID='"+ id +"'");
                 qry.next();
                 nickName = qry.value(0).toString();

                 /*send to client about success*/
                 s->write("$%*1/clear/"+ nickName.toUtf8());
                 s->flush();

             }
             //존재하지 않을 경우
             if(count<1)
             {
                 s->write("$%*1/fail");
                 s->flush();
             }
             ChatClient tempClient;
             tempClient.setClient(s, nickName);
             clientList.append(tempClient);
             //roomManager->addClient(0, &tempClient);  //waiting room is index 0
         }

     }

     else if(arr.contains("$%*0")){ //sign up

         /*사용자가 입력한 id, password, password확인, name, nickname 저장*/
         QList<QByteArray> tempArr=arr.split('/');
         QString id(tempArr.at(1));
         QString password(tempArr.at(2));
         QString name(tempArr.at(3));
         QString nickname(tempArr.at(4));

         /*state를 notConnected로 초기화*/
         QString state("notConnected");

         /*데이터베이스가 오픈 불가능할 경우*/
         if(!mydb.isOpen()){
             qDebug()<<"Failed to open the database";
             return;
         }

         /*데이터베이스에 동일한 id가 있는 경우*/
         QSqlQuery qry;

         if(qry.exec("select * from USER where UID='"+ id +"'")){
             int count=0;
             while(qry.next())
             {
                 count++;
             }
             if(count==1)
             {
                 s->write("$%*0/idDuplicate");
                 s->flush();
                 return;
             }
         }

         /*데이터베이스에 동일한 닉네임이 있는 경우*/
         if(qry.exec("select * from USER where Nickname='"+ nickname +"'")){
             int count=0;
             while(qry.next())
             {
                 count++;
             }
             if(count==1)
             {
                 s->write("$%*0/nickNameDuplicate");
                 s->flush();
                 return;
             }
         }

         /*입력받은 id, password, name, nickname 과 state 삽입*/
         qry.prepare("insert into USER (UID,Password,Name,Nickname,State) values ('" + id + "','" + password + "', '" + name + "', '" + nickname + "', '" + state + "')");

         if(qry.exec()){
             s->write("$%*0/clear");
             s->flush();
         }
         else{
             s->write("$%*0/Error");
             s->flush();
         }

         ui->textEdit->append(nickname + " is signup");
         log->writeFile(s->localAddress().toString()+" is signup");
     }

     else if(arr.contains("$%*-1")){  //id check
         /*사용자가 입력한 id 저장*/
         QList<QByteArray> tempArr=arr.split('/');
         QString id(tempArr.at(1));

         if(!mydb.isOpen()){
             qDebug()<<"Failed to open the database";
             return;
         }

         /*데이터베이스에 해당 id가 있는지 확인*/
          QSqlQuery qry;

          if(qry.exec("select * from USER where UID='"+ id +"'")){
              int count=0;
              while(qry.next())
              {
                  count++;
              }
              if(count==1)
              {
                  s->write("$$%*-1/fail");
                  s->flush();
              }

              if(count<1)
              {
                  s->write("$$%*-1/clear");
                  s->flush();
              }
          }
     }
     else if(arr.contains("$%*-2")){  //nick name check
         /*사용자가 입력한 닉네임 저장*/
         QList<QByteArray> tempArr=arr.split('/');
         QString nickname(tempArr.at(1));

        if(!mydb.isOpen()){
            qDebug()<<"Failed to open the database";
            return;
        }

         /*데이터베이스에 해당 nickname이 있는지 확인*/
         QSqlQuery qry;

         if(qry.exec("select * from USER where Nickname='"+ nickname +"'")){
             int count=0;
             while(qry.next())
             {
                 count++;
             }
             if(count==1)
             {
                 s->write("$$%*-2/fail");
                 s->flush();
             }

             if(count<1)
             {
                s->write("$$%*-2/clear");
                s->flush();
             }
         }
     }
     else if(arr.contains("$%*-3")){  //logout
         QList<QByteArray> tempArr=arr.split('/');
         QString id(tempArr.at(1));

         /*데이터베이스에서 해당 id의 State값을 'unConnected'로 update*/
         QString state = "notConnected";
         QSqlQuery qry;
         qry.exec("update USER set State = '" + state + "' where UID = '" + id + "'");

//room move

     }
     else if(arr.contains("$%*2")){  //room make
         QList<QByteArray> tempArr=arr.split('/');
         QByteArray temp(tempArr.at(1));
         QString temp2(temp);
         for(int i=0; i<clientList.size(); i++){
             QTcpSocket* sock=clientList[i].getTCP();
             sock->write("$%*2/" + temp);
             sock->flush();
         }

         QString str(tempArr.at(1));
         ui->textEdit->append(str + " room made");
         log->writeFile(s->localAddress().toString()+" room made");

         roomManager->createRoom(str);
         for(int i=0; i<clientList.size(); i++){
             ChatClient tempClient=clientList.at(i);
             QString clientNickname=tempClient.getNickName();
             if(clientNickname==temp2){
                 roomManager->moveClient(roomManager->getRoomNum(str), &tempClient);
                 clientList.replace(i, tempClient);
             }
         }

     }
     else if(arr.contains("$%*3")){  //entrance
         QList<QByteArray> tempArr=arr.split('/');
         QByteArray temp(tempArr.at(1));
         QString str(tempArr.at(1));
         for(int i=0; i<clientList.size(); i++){
             ChatClient tempClient=clientList.at(i);
             QString clientNickname=tempClient.getNickName();
             if(clientNickname==str){
                 roomManager->moveClient(roomManager->getRoomNum(str), &tempClient);
                 clientList.replace(i, tempClient);
             }
         }

         for(int i=0; i<clientList.size(); i++){

             QTcpSocket* sock=clientList[i].getTCP();
             sock->write(temp);
             sock->flush();
         }



         ui->textEdit->append(str + " room made");
         log->writeFile(s->localAddress().toString()+" room made");
         roomManager->createRoom(str);
     }
     else{         
         QString str(arr);
         ui->textEdit->append(str + " send message\nwait for client");
         log->writeFile(s->localAddress().toString()+" sends the message");
     }



}