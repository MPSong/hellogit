#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
signals:
    void notifySent(const QString& roomName);
private slots:

    void on_pushButton_cancel_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::Dialog *ui;
public:
    QString roomName;
};

#endif // DIALOG_H
