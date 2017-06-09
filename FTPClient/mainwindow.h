#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dialogftpclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonFTP_clicked();

private:
    Ui::MainWindow *ui;

    DialogFTPClient *dialogFTPClient;
};

#endif // MAINWINDOW_H
