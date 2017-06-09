#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;
class QAuthenticator;

class FTPClient : public QObject
{
    Q_OBJECT

public:
    explicit FTPClient(QObject *parent = 0);

    void upload(QString localFilePath, QString remoteSavingPath);
    void download(QString remoteFilePath, QString localSavingPath);
    void authenticate();

private:
    QNetworkAccessManager *manager;

    QString *id;
    QString *pw;

    bool isDownloaded;

    QString localSavingPath;

    void onFinishedUpload(QNetworkReply *reply);
    void onFinishedDownload(QNetworkReply *reply);

private slots:
    void onFinished(QNetworkReply *);
    void onAuthenticationRequired(QNetworkReply *, QAuthenticator *);

signals:
    void updateProgress(qint64 bytesReceived, qint64 bytesTotal);
};

#endif // FTPCLIENT_H
