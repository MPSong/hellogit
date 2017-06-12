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

    QString host_str("127.0.1.0");
    QHostAddress host(host_str);
    int port =2402;
    socket.connectToHost(host,port);
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

    QByteArray arr("$%*1/"+id.toUtf8()+"/" + password.toUtf8());
    socket.write(arr);
    socket.flush();
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

    /*send nickname to server*/
    QByteArray arr(nickName.toUtf8());
    socket.write("$%*-3/" + arr);
    socket.flush();


    /*page 로 이동*/
    ui->stackedWidget->setCurrentWidget(ui->page);

    /*page의 id, password 초기화*/
    ui->lineEdit_id->clear();
    ui->lineEdit_password->clear();

    ui->listWidget_room->clear();
    ui->listWidget_users->clear();
}

void MainWindow::on_pushButton_logout_2_clicked()
{
    QString id;
    id = ui->lineEdit_id->text();

    QByteArray arr(nickName.toUtf8());
    socket.write("$%*-3/" + arr);
    socket.flush();

    ui->stackedWidget->setCurrentWidget(ui->page);
    ui->lineEdit_id->clear();
    ui->lineEdit_password->clear();

    ui->listWidget_room->clear();
    ui->listWidget_users->clear();
}

void MainWindow::on_pushButton_confirm_clicked()
{
    /*사용자가 입력한 id, password, password확인, name, nickname 저장*/
    QString id, password, name, nickname, passconfirm;
    id = ui->lineEdit_id_2->text();
    password = ui->lineEdit_password_2->text();
    passconfirm = ui->lineEdit_passconfirm->text();
    name = ui->lineEdit_name->text();
    nickname = ui->lineEdit_nickname->text();


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

    /*send to server*/
    QByteArray arr("$%*0/"+id.toUtf8()+"/" + password.toUtf8() + "/" + name.toUtf8() + "/" + nickname.toUtf8());
    socket.write(arr);
    socket.flush();

}

void MainWindow::on_pushButton_check_id_clicked()
{
    /*사용자가 입력한 id 저장*/
     QString id;
     id = ui->lineEdit_id_2->text();

     QByteArray arr("$%*-1/"+id.toUtf8());
     socket.write(arr);
     socket.flush();
}


void MainWindow::on_pushButton_check_nick_clicked()
{
    /*사용자가 입력한 닉네임 저장*/
    QString nickname;
    nickname = ui->lineEdit_nickname->text();

    QByteArray arr("$%*-2/"+ nickname.toUtf8());
    socket.write(arr);
    socket.flush();
}

void MainWindow::recvMsg()
{
    QTcpSocket *s = (QTcpSocket*)sender();
    QByteArray arr(s->readAll());

    QList<QByteArray> tempArr;
    QByteArray temp;
    QString str;
/*
    str = arr;
    ui->listWidget_room->addItem(str);
    */

    //sign in
    if(arr.contains("$%*1")){
        tempArr=arr.split('/');
        temp = tempArr.at(1);
        if(temp == "clear"){
             ui->stackedWidget->setCurrentWidget(ui->page_3);
             QByteArray temp2 = tempArr.at(2);
             str = temp2;
             nickName = temp2;
             ui->label_welcome->setText(nickName + " welcome!");
             ui->label_welcome_2->setText(nickName + " welcome!");
        }

        else if(temp == "fail"){
            QMessageBox::warning(this,tr("Error"),tr("Please check your id and password again"));
        }
    }

    //sign up
    else if(arr.contains("$%*0")){
        tempArr=arr.split('/');
        temp = tempArr.at(1);
        if(temp == "clear"){
            QMessageBox::information(this,tr("Save"),tr("Saved"));

            ui->stackedWidget->setCurrentWidget(ui->page);

            ui->lineEdit_id_2->clear();
            ui->lineEdit_password_2->clear();
            ui->lineEdit_passconfirm->clear();
            ui->lineEdit_name->clear();
            ui->lineEdit_nickname->clear();
        }
        else if(temp == "idDuplicate"){
            QMessageBox::warning(this,tr("Error"),tr("Your id is duplicated"));
        }
        else if(temp == "nickNameDuplicate"){
            QMessageBox::warning(this,tr("Error"),tr("Your nickname is duplicated"));
        }
    }

    else if(arr.contains("$%*-1")){
        tempArr=arr.split('/');
        temp = tempArr.at(1);
        if(temp == "clear")
            QMessageBox::information(this,tr("Ok"),tr("You can use this id"));

        else if(temp == "fail")
            QMessageBox::warning(this,tr("Error"),tr("Your id is duplicated"));
    }

    else if(arr.contains("$%*-2")){
        tempArr=arr.split('/');
        temp = tempArr.at(1);
        if(temp == "clear")
            QMessageBox::information(this,tr("Ok"),tr("You can use this nickname"));

        else if(temp == "fail")
            QMessageBox::warning(this,tr("Error"),tr("Your nickname is duplicated"));
    }

    //new room
    else if(arr.contains("$%*2") ){
        tempArr=arr.split('/');
        temp = tempArr.at(1);
        str = temp;
        ui->listWidget_room->addItem(str);
    }

    //users
    else if(arr.contains("$%*4")){
        tempArr=arr.split('/');
        temp = tempArr.at(1);
        str = temp;
        ui->listWidget_users->addItem(str);
    }

    else if(arr.contains("$%*5")){
        tempArr=arr.split('/');
        temp = tempArr.at(1);
        str = temp;
        ui->textEdit_chat->append(str);
    }

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
        ui->label_roomname->setText("chatting room: " + room);
    }

    else
        QMessageBox::warning(this,tr("Error"),tr("please click your room"));

}

void MainWindow::on_pushButton_exit_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}


void MainWindow::on_pushButton_invite_clicked()
{
    if(ui->listWidget_users->currentItem())
    {
        QString user = ui->listWidget_users->currentItem()->text();

        QByteArray arr("$%*4/"+user.toUtf8()+"/"+socket.localAddress().toString().toUtf8());
        socket.write(arr);
        socket.flush();
    }

    else
        QMessageBox::warning(this,tr("Error"),tr("please click a user"));
}



void MainWindow::on_pushButton_send_clicked()
{
    QString message = ui->textEdit_message->toPlainText();
    QByteArray arr("$%*5/" + nickName.toUtf8() + ":  " + message.toUtf8());
    socket.write(arr);
    socket.flush();

    ui->textEdit_message->clear();
}


void MainWindow::on_pushButton_attachment_clicked()
{
    dialogFTP = new DialogFTP(this);
    dialogFTP->show();
}
