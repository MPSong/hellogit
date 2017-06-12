#include "ftpclient.h"

#include <QtNetwork>
#include <QFile>
#include <QMessageBox>

FTPClient::FTPClient(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);

    id = new QString();
    pw = new QString();

    isDownloaded = false;

    connect(manager, &QNetworkAccessManager::finished, this, &FTPClient::onFinished);
    connect(manager, &QNetworkAccessManager::authenticationRequired, this, &FTPClient::onAuthenticationRequired);
}

void FTPClient::upload(QString localFilePath, QString remoteSavingPath)
{
    QFile fileSource(localFilePath);
    if(!fileSource.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(0, "Error", QString("There is no file"));
        return;
    }


    // 파일 보내기
    QNetworkReply *reply = manager->put(QNetworkRequest(QUrl(remoteSavingPath + localFilePath.mid(localFilePath.lastIndexOf("/")))), fileSource.readAll());
    connect(reply, &QNetworkReply::downloadProgress, this, &FTPClient::updateProgress);
    QMessageBox::critical(0, "", QString("Complete"));
}

void FTPClient::download(QString remoteFilePath, QString localSavingPath)
{
    isDownloaded = true;

    // 저장 경로 설정
    this->localSavingPath = localSavingPath + remoteFilePath.mid(7);
    //this->localSavingPath = localSavingPath + remoteFilePath.mid(remoteFilePath.lastIndexOf("/"));

    // 파일 받기
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(remoteFilePath)));
    connect(reply, &QNetworkReply::downloadProgress, this, &FTPClient::updateProgress);
    QMessageBox::critical(0, "", QString("Complete"));
}

void FTPClient::authenticate()
{
    *id = "hyun";
    *pw = "1234";
}

void FTPClient::onFinishedUpload(QNetworkReply *reply)
{

}

void FTPClient::onFinishedDownload(QNetworkReply *reply)
{
    QByteArray byteArray = reply->readAll();

    QFile file(localSavingPath);
    //if(!file.open(QIODevice::WriteOnly))
    //    QMessageBox::critical(0, "Error", QString("There is no file"));

    QTextStream out(&file);
    out << QString::fromUtf8(byteArray, byteArray.size());

    file.close();
}

void FTPClient::onFinished(QNetworkReply *reply)
{
    if(isDownloaded)
        onFinishedDownload(reply);
    else
        onFinishedUpload(reply);
    isDownloaded = false;
}

void FTPClient::onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *auth)
{
    if(*id == "" || *pw == "")
        authenticate();

    auth->setUser("hyun");
    auth->setPassword("1234");
}
