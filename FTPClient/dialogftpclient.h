#ifndef DIALOGFTPCLIENT_H
#define DIALOGFTPCLIENT_H

#include <QDialog>

namespace Ui {
class DialogFTPClient;
}

class QAuthenticator;
class QFileSystemModel;
class FTPClient;

class DialogFTPClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFTPClient(QWidget *parent = 0);
    ~DialogFTPClient();

private slots:
    void updateLocalFilePath();
    void updateProgressBar(qint64 bytesReceived, qint64 bytesTotal);

    void on_pushButtonUpload_clicked();

    void on_pushButtonDownload_clicked();

private:
    Ui::DialogFTPClient *ui;

    QFileSystemModel *fileSystemModel;

    FTPClient *ftpClient;

    void fileSystemConfiguration();\
    void treeViewConfiguration();
};

#endif // DIALOGFTPCLIENT_H
