/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_signin;
    QPushButton *pushButton_signup;
    QWidget *page_2;
    QLineEdit *lineEdit_id_2;
    QLineEdit *lineEdit_password_2;
    QLineEdit *lineEdit_passconfirm;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_nickname;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_check;
    QPushButton *pushButton_check_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_13;
    QWidget *page_3;
    QPushButton *pushButton_logout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_makeroom;
    QLabel *label_8;
    QListWidget *listWidget;
    QLabel *label_welcome;
    QWidget *page_4;
    QListWidget *listWidget_2;
    QPushButton *pushButton_10;
    QLabel *label_10;
    QLabel *label_welcome_2;
    QPushButton *pushButton_logout_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLabel *label_12;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(842, 503);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 841, 501));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        lineEdit_id = new QLineEdit(page);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(402, 140, 181, 25));
        lineEdit_password = new QLineEdit(page);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(402, 220, 181, 25));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 140, 31, 20));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 220, 81, 20));
        pushButton_signin = new QPushButton(page);
        pushButton_signin->setObjectName(QStringLiteral("pushButton_signin"));
        pushButton_signin->setGeometry(QRect(320, 330, 89, 25));
        pushButton_signup = new QPushButton(page);
        pushButton_signup->setObjectName(QStringLiteral("pushButton_signup"));
        pushButton_signup->setGeometry(QRect(450, 330, 89, 25));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        lineEdit_id_2 = new QLineEdit(page_2);
        lineEdit_id_2->setObjectName(QStringLiteral("lineEdit_id_2"));
        lineEdit_id_2->setGeometry(QRect(230, 70, 211, 25));
        lineEdit_password_2 = new QLineEdit(page_2);
        lineEdit_password_2->setObjectName(QStringLiteral("lineEdit_password_2"));
        lineEdit_password_2->setGeometry(QRect(230, 130, 211, 25));
        lineEdit_password_2->setEchoMode(QLineEdit::Password);
        lineEdit_passconfirm = new QLineEdit(page_2);
        lineEdit_passconfirm->setObjectName(QStringLiteral("lineEdit_passconfirm"));
        lineEdit_passconfirm->setGeometry(QRect(230, 190, 211, 25));
        lineEdit_passconfirm->setEchoMode(QLineEdit::Password);
        lineEdit_name = new QLineEdit(page_2);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(230, 250, 211, 25));
        lineEdit_nickname = new QLineEdit(page_2);
        lineEdit_nickname->setObjectName(QStringLiteral("lineEdit_nickname"));
        lineEdit_nickname->setGeometry(QRect(230, 310, 211, 25));
        pushButton_confirm = new QPushButton(page_2);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(320, 400, 89, 25));
        pushButton_cancel = new QPushButton(page_2);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(450, 400, 89, 25));
        pushButton_check = new QPushButton(page_2);
        pushButton_check->setObjectName(QStringLiteral("pushButton_check"));
        pushButton_check->setGeometry(QRect(470, 70, 151, 25));
        pushButton_check_2 = new QPushButton(page_2);
        pushButton_check_2->setObjectName(QStringLiteral("pushButton_check_2"));
        pushButton_check_2->setGeometry(QRect(470, 310, 151, 25));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 50, 67, 17));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 110, 67, 17));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 170, 131, 17));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 230, 67, 17));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(230, 290, 67, 17));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(470, 130, 321, 17));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_logout = new QPushButton(page_3);
        pushButton_logout->setObjectName(QStringLiteral("pushButton_logout"));
        pushButton_logout->setGeometry(QRect(768, 40, 61, 25));
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(630, 450, 89, 25));
        pushButton_makeroom = new QPushButton(page_3);
        pushButton_makeroom->setObjectName(QStringLiteral("pushButton_makeroom"));
        pushButton_makeroom->setGeometry(QRect(730, 450, 89, 25));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(620, 80, 161, 20));
        listWidget = new QListWidget(page_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(620, 110, 211, 321));
        label_welcome = new QLabel(page_3);
        label_welcome->setObjectName(QStringLiteral("label_welcome"));
        label_welcome->setGeometry(QRect(620, 40, 141, 21));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        listWidget_2 = new QListWidget(page_4);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(620, 110, 211, 321));
        pushButton_10 = new QPushButton(page_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(680, 450, 89, 25));
        label_10 = new QLabel(page_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(620, 80, 121, 17));
        label_welcome_2 = new QLabel(page_4);
        label_welcome_2->setObjectName(QStringLiteral("label_welcome_2"));
        label_welcome_2->setGeometry(QRect(620, 40, 141, 20));
        pushButton_logout_2 = new QPushButton(page_4);
        pushButton_logout_2->setObjectName(QStringLiteral("pushButton_logout_2"));
        pushButton_logout_2->setGeometry(QRect(770, 40, 61, 25));
        textEdit = new QTextEdit(page_4);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 409, 481, 71));
        pushButton_12 = new QPushButton(page_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(510, 410, 89, 25));
        pushButton_13 = new QPushButton(page_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(510, 450, 89, 25));
        textEdit_2 = new QTextEdit(page_4);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(13, 80, 591, 311));
        pushButton_14 = new QPushButton(page_4);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(510, 40, 89, 25));
        pushButton_15 = new QPushButton(page_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(410, 40, 89, 25));
        label_12 = new QLabel(page_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 20, 121, 17));
        stackedWidget->addWidget(page_4);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "ID", 0));
        label_2->setText(QApplication::translate("MainWindow", "password", 0));
        pushButton_signin->setText(QApplication::translate("MainWindow", "Sign-in", 0));
        pushButton_signup->setText(QApplication::translate("MainWindow", "Sign-up", 0));
        pushButton_confirm->setText(QApplication::translate("MainWindow", "Confirm", 0));
        pushButton_cancel->setText(QApplication::translate("MainWindow", "Cancel", 0));
        pushButton_check->setText(QApplication::translate("MainWindow", "duplication check", 0));
        pushButton_check_2->setText(QApplication::translate("MainWindow", "duplication check", 0));
        label_3->setText(QApplication::translate("MainWindow", "ID", 0));
        label_4->setText(QApplication::translate("MainWindow", "password", 0));
        label_5->setText(QApplication::translate("MainWindow", "confirm password", 0));
        label_6->setText(QApplication::translate("MainWindow", "name", 0));
        label_7->setText(QApplication::translate("MainWindow", "nickname", 0));
        label_13->setText(QApplication::translate("MainWindow", "Password's length must be between 6 and 10 ", 0));
        pushButton_logout->setText(QApplication::translate("MainWindow", "logout", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "entrance", 0));
        pushButton_makeroom->setText(QApplication::translate("MainWindow", "make room", 0));
        label_8->setText(QApplication::translate("MainWindow", "current chatting room", 0));
        label_welcome->setText(QString());
        pushButton_10->setText(QApplication::translate("MainWindow", "invite", 0));
        label_10->setText(QApplication::translate("MainWindow", "connected usrs", 0));
        label_welcome_2->setText(QString());
        pushButton_logout_2->setText(QApplication::translate("MainWindow", "logout", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "send", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "attachment", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "exit", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "received file", 0));
        label_12->setText(QApplication::translate("MainWindow", "chatting room 1", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
