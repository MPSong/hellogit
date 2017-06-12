#include "dialogftp.h"
#include "ui_dialogftp.h"
#include "ftpclient.h"

#include <QAuthenticator>
#include <QtNetwork>
#include <QFileSystemModel>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

DialogFTP::DialogFTP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFTP)
{
    ui->setupUi(this);
    setWindowTitle("FTP Transfer");

    ui->lineEditRemoteFiles->setText("ftp://58.140.4.133/hyun/");

    fileSystemConfiguration();
    treeViewConfiguration();

    ftpClient = new FTPClient(this);

    connect(ui->treeView, &QTreeView::clicked, this, &DialogFTP::updateLocalFilePath);
    connect(ftpClient, &FTPClient::updateProgress, this, &DialogFTP::updateProgressBar);
}

DialogFTP::~DialogFTP()
{
    delete ui;
}

void DialogFTP::updateLocalFilePath()
{
    QModelIndex index = ui->treeView->currentIndex();
    ui->lineEditLocalFiles->setText(fileSystemModel->filePath(index));
}

void DialogFTP::updateProgressBar(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBar->setValue((bytesTotal+1) / (bytesReceived+1) * 100);
}

void DialogFTP::on_pushButtonUpload_clicked()
{
    ui->progressBar->setValue(0);
    ftpClient->upload(ui->lineEditLocalFiles->text(), ui->lineEditRemoteFiles->text());
}

void DialogFTP::on_pushButtonDownload_clicked()
{
    ui->progressBar->setValue(0);
    ftpClient->download(ui->lineEditRemoteFiles->text(), ui->lineEditLocalFiles->text());
}
void DialogFTP::fileSystemConfiguration()
{
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::currentPath());

    fileSystemModel->setNameFilters(QStringList("*.txt"));
    fileSystemModel->setNameFilterDisables(false);
}

void DialogFTP::treeViewConfiguration()
{
    ui->treeView->setModel(fileSystemModel);
    ui->treeView->setColumnHidden(2, true);
}
