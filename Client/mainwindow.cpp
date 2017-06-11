/*-------------------------
최종 작성 일시: 2017. 05. 25
이전 작성자:
최종 작성자: 김효민
로그인, 로그아웃, 회원가입 구현
--------------------------*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&socket,SIGNAL(readyRead()),this,SLOT(recvMsg()));

    /*데이터베이스 추가 및 경로와 연결*/
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/hyomin/user.db");

    if(!mydb.open())
    {
        QMessageBox box;
        box.setText("Failed to open the database");
        box.setStandardButtons(QMessageBox::Ok);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_signin_clicked()
{
    /*사용자가 입력한 id, password 저장*/
    QString id, password;
    id = ui->lineEdit_id->text();
    password = ui->lineEdit_password->text();

    /*데이터베이스 오픈 가능한지 확인*/
    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    /*입력받은 id와 password가 데이터베이스에 존재 하는지 확인하고 존재할 경우 page_3로 이동*/
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

            QString host_str("127.0.1.0");
            QHostAddress host(host_str);
            int port =2402;
            socket.connectToHost(host,port);

            /*입력받은 id의 닉네임 검색후 page_3, page_4에 환영 문구 씀*/
            qry.exec("select Nickname from USER where UID='"+ id +"'");
            qry.next();
            QString nickname = qry.value(0).toString();
            ui->label_welcome->setText(nickname + " welcome!");
            ui->label_welcome_2->setText(nickname + " welcome!");

            //page_3로 이동
            ui->stackedWidget->setCurrentWidget(ui->page_3);
        }
        //존재하지 않을 경우
        if(count<1)
        {
           QMessageBox::warning(this,tr("Error"),tr("Please check your id and password again"));
        }
    }
}

void MainWindow::on_pushButton_signup_clicked()
{
    /*page_2로 이동*/
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_pushButton_cancel_clicked()
{
    /*page로 이동*/
    ui->stackedWidget->setCurrentWidget(ui->page);

    /*page_2의 모든 lineEdit 최기화*/
    ui->lineEdit_id_2->clear();
    ui->lineEdit_password_2->clear();
    ui->lineEdit_passconfirm->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_nickname->clear();
}

void MainWindow::on_pushButton_logout_clicked()
{
    /*사용자가 입력한 id 저장*/
    QString id;
    id = ui->lineEdit_id->text();

    /*데이터베이스에서 해당 id의 State값을 'unConnected'로 update*/
    QString state = "notConnected";
    QSqlQuery qry;
    qry.exec("update USER set State = '" + state + "' where UID = '" + id + "'");

    /*page 로 이동*/
    ui->stackedWidget->setCurrentWidget(ui->page);

    /*page의 id, password 초기화*/
    ui->lineEdit_id->clear();
    ui->lineEdit_password->clear();

    ui->listWidget_room->clear();

    socket.close();
}

void MainWindow::on_pushButton_logout_2_clicked()
{
    QString id;
    id = ui->lineEdit_id->text();

    QString state = "notConnected";
    QSqlQuery qry;
    qry.exec("update USER set State = '" + state + "' where UID = '" + id + "'");

    ui->stackedWidget->setCurrentWidget(ui->page);
    ui->lineEdit_id->clear();
    ui->lineEdit_password->clear();

    socket.close();
}

void MainWindow::on_pushButton_confirm_clicked()
{
    /*사용자가 입력한 id, password, password확인, name, nickname 저장*/
    QString id, password, name, nickname, state, passconfirm;
    id = ui->lineEdit_id_2->text();
    password = ui->lineEdit_password_2->text();
    passconfirm = ui->lineEdit_passconfirm->text();
    name = ui->lineEdit_name->text();
    nickname = ui->lineEdit_nickname->text();

    /*state를 notConnected로 초기화*/
    state = "notConnected";


    /*사용자가 하나라도 입력하지 않은 것이 있을 경우*/
    if(id == "" || password == "" || passconfirm == "" || name == "" || nickname == "" ){
        QMessageBox::warning(this,tr("Error"),tr("Please fill in all blanks"));
        return;
    }

    /*password와 password 확인이 일치하지 않을 경우*/
    if(password != passconfirm){
        QMessageBox::warning(this,tr("Error"),tr("Please check your password again"));
        return;
    }

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
            QMessageBox::warning(this,tr("Error"),tr("Your id is duplicated"));
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
            QMessageBox::warning(this,tr("Error"),tr("Your nickname is duplicated"));
            return;
        }
    }


    /*입력받은 id, password, name, nickname 과 state 삽입*/
    qry.prepare("insert into USER (UID,Password,Name,Nickname,State) values ('" + id + "','" + password + "', '" + name + "', '" + nickname + "', '" + state + "')");

    if(qry.exec()){
        QMessageBox::information(this,tr("Save"),tr("Saved"));
    }
    else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }


    /*page로 이동*/
    ui->stackedWidget->setCurrentWidget(ui->page);

    /*page_2의 모든 lineEdit 초기화*/
    ui->lineEdit_id_2->clear();
    ui->lineEdit_password_2->clear();
    ui->lineEdit_passconfirm->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_nickname->clear();

}

void MainWindow::on_pushButton_check_clicked()
{
    /*사용자가 입력한 id 저장*/
     QString id;
     id = ui->lineEdit_id_2->text();

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
             QMessageBox::warning(this,tr("Error"),tr("you can not use this id"));
         }

         if(count<1)
         {
            QMessageBox::information(this,tr("Ok"),tr("you can use this id"));
         }
     }
}


void MainWindow::on_pushButton_check_2_clicked()
{
    /*사용자가 입력한 닉네임 저장*/
    QString nickname;
    nickname = ui->lineEdit_nickname->text();

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
            QMessageBox::warning(this,tr("Error"),tr("you can not use this nickname"));
        }

        if(count<1)
        {
           QMessageBox::information(this,tr("Ok"),tr("you can use this nickname"));
        }
    }
}

void MainWindow::recvMsg()
{
    QTcpSocket *s = (QTcpSocket*)sender();
    QByteArray arr(s->readAll());
    QString str(arr);
    ui->listWidget_room->addItem(str);
}

void MainWindow::onSent(const QString& room)
{
    QByteArray arr("$%*2/"+room.toUtf8()+"/"+socket.localAddress().toString().toUtf8());
    socket.write(arr);
    socket.flush();
}


void MainWindow::on_pushButton_makeroom_clicked()
{
    /*다이어로그 실행해서 방 이름 입력 받음*/
    dialog = new Dialog(this);
    connect(dialog, &Dialog::notifySent, this, &MainWindow::onSent);
    dialog->show();
}

void MainWindow::on_pushButton_entrance_clicked()
{
    if(ui->listWidget_room->currentItem())
    {
        QString room = ui->listWidget_room->currentItem()->text();

        QByteArray arr("$%*3/"+room.toUtf8()+"/"+socket.localAddress().toString().toUtf8());
        socket.write(arr);
        socket.flush();

        ui->stackedWidget->setCurrentWidget(ui->page_4);
    }

    else
        QMessageBox::warning(this,tr("Error"),tr("please click your room"));

}

void MainWindow::on_pushButton_exit_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
