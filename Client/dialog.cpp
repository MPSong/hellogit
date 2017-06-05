#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_cancel_clicked()
{
    reject();
}


void Dialog::on_pushButton_confirm_clicked()
{
    roomName = ui->lineEdit_roomName->text();
    emit notifySent(roomName);
    accept();
}
