#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    QString id, password;
    id = ui->lineEdit_id->text();
    password = ui->lineEdit_password->text();

    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }


    QSqlQuery qry;

    if(qry.exec("select * from USER where UID='"+ id +"' and Password='" + password +"'")){
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            QString state = "connected";
            qry.exec("update USER set State = '" + state + "' where UID = '" + id + "'");
            ui->stackedWidget->setCurrentWidget(ui->page_3);
        }

        if(count<1)
        {
           QMessageBox::warning(this,tr("Error"),tr("Please check your id and password again"));
        }
    }

    qry.exec("select Nickname from USER where UID='"+ id +"'");
    qry.next();
    QString nickname = qry.value(0).toString();
    ui->label_welcome->setText(nickname + " welcome!");
    ui->label_welcome_2->setText(nickname + " welcome!");
}


void MainWindow::on_pushButton_makeroom_clicked()
{
    Dialog dia;
    dia.exec();
}

void MainWindow::on_pushButton_signup_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_pushButton_cancel_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);

    ui->lineEdit_id_2->clear();
    ui->lineEdit_password_2->clear();
    ui->lineEdit_passconfirm->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_nickname->clear();
}

void MainWindow::on_pushButton_logout_clicked()
{
    QString id;
    id = ui->lineEdit_id->text();

    QString state = "notConnected";
    QSqlQuery qry;
    qry.exec("update USER set State = '" + state + "' where UID = '" + id + "'");

    ui->stackedWidget->setCurrentWidget(ui->page);
    ui->lineEdit_id->clear();
    ui->lineEdit_password->clear();
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
}

void MainWindow::on_pushButton_confirm_clicked()
{
    QString id, password, name, nickname, state, passconfirm;
    id = ui->lineEdit_id_2->text();
    password = ui->lineEdit_password_2->text();
    passconfirm = ui->lineEdit_passconfirm->text();
    name = ui->lineEdit_name->text();
    nickname = ui->lineEdit_nickname->text();
    state = "notConnected";


    if(id == "" || password == "" || passconfirm == "" || name == "" || nickname == "" ){
        QMessageBox::warning(this,tr("Error"),tr("Please fill in all blanks"));
        return;
    }

    if(password != passconfirm){
        QMessageBox::warning(this,tr("Error"),tr("Please check your password again"));
        return;
    }


    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }


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


    qry.prepare("insert into USER (UID,Password,Name,Nickname,State) values ('" + id + "','" + password + "', '" + name + "', '" + nickname + "', '" + state + "')");

    if(qry.exec()){
        QMessageBox::information(this,tr("Save"),tr("Saved"));
    }
    else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }


    ui->stackedWidget->setCurrentWidget(ui->page);

    ui->lineEdit_id_2->clear();
    ui->lineEdit_password_2->clear();
    ui->lineEdit_passconfirm->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_nickname->clear();

}

void MainWindow::on_pushButton_check_clicked()
{
     QString id;
     id = ui->lineEdit_id_2->text();

    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

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
    QString nickname;
    nickname = ui->lineEdit_nickname->text();

   if(!mydb.isOpen()){
       qDebug()<<"Failed to open the database";
       return;
   }

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

