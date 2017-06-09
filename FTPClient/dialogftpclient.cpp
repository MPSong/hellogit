#include "dialogftpclient.h"
#include "ui_dialogftpclient.h"
#include "ftpclient.h"

#include <QAuthenticator>
#include <QtNetwork>
#include <QFileSystemModel>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

DialogFTPClient::DialogFTPClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFTPClient)
{
    ui->setupUi(this);

    setWindowTitle("FTP Transfer");

    ui->lineEditRemoteFiles->setText("ftp://58.140.4.133/hyun/");

    fileSystemConfiguration();
    treeViewConfiguration();

    ftpClient = new FTPClient(this);

    connect(ui->treeViewLocal, &QTreeView::clicked, this, &DialogFTPClient::updateLocalFilePath);
    connect(ftpClient, &FTPClient::updateProgress, this, &DialogFTPClient::updateProgressBar);
}

DialogFTPClient::~DialogFTPClient()
{
    delete ui;
}

void DialogFTPClient::updateLocalFilePath()
{
    QModelIndex index = ui->treeViewLocal->currentIndex();
    ui->lineEditLocalFiles->setText(fileSystemModel->filePath(index));
}

void DialogFTPClient::updateProgressBar(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBar->setValue((bytesTotal+1) / (bytesReceived+1) * 100);
}

void DialogFTPClient::on_pushButtonUpload_clicked()
{
    ui->progressBar->setValue(0);
    ftpClient->upload(ui->lineEditLocalFiles->text(), ui->lineEditRemoteFiles->text());
}

void DialogFTPClient::on_pushButtonDownload_clicked()
{
    ui->progressBar->setValue(0);
    ftpClient->download(ui->lineEditRemoteFiles->text(), ui->lineEditLocalFiles->text());
}

void DialogFTPClient::fileSystemConfiguration()
{
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::currentPath());

    fileSystemModel->setNameFilters(QStringList("*.txt"));
    fileSystemModel->setNameFilterDisables(false);
}

void DialogFTPClient::treeViewConfiguration()
{
    ui->treeViewLocal->setModel(fileSystemModel);
    ui->treeViewLocal->setColumnHidden(2, true);
}
