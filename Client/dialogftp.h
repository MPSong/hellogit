#ifndef DIALOGFTP_H
#define DIALOGFTP_H

#include <QDialog>

namespace Ui {
class DialogFTP;
}

class QAuthenticator;
class QFileSystemModel;
class FTPClient;

class DialogFTP : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFTP(QWidget *parent = 0);
    ~DialogFTP();

private slots:
    void updateLocalFilePath();
    void updateProgressBar(qint64 bytesReceived, qint64 bytesTotal);
    void on_pushButtonUpload_clicked();

    void on_pushButtonDownload_clicked();

private:
    Ui::DialogFTP *ui;

    QFileSystemModel *fileSystemModel;

    FTPClient *ftpClient;

    void fileSystemConfiguration();\
    void treeViewConfiguration();
};

#endif // DIALOGFTP_H
