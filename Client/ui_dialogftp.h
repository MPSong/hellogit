/********************************************************************************
** Form generated from reading UI file 'dialogftp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFTP_H
#define UI_DIALOGFTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_DialogFTP
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditLocalFiles;
    QLineEdit *lineEditRemoteFiles;
    QTreeView *treeView;
    QPushButton *pushButtonUpload;
    QPushButton *pushButtonDownload;
    QProgressBar *progressBar;

    void setupUi(QDialog *DialogFTP)
    {
        if (DialogFTP->objectName().isEmpty())
            DialogFTP->setObjectName(QStringLiteral("DialogFTP"));
        DialogFTP->resize(972, 482);
        label = new QLabel(DialogFTP);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 67, 17));
        label_2 = new QLabel(DialogFTP);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 40, 91, 17));
        lineEditLocalFiles = new QLineEdit(DialogFTP);
        lineEditLocalFiles->setObjectName(QStringLiteral("lineEditLocalFiles"));
        lineEditLocalFiles->setGeometry(QRect(110, 30, 341, 25));
        lineEditRemoteFiles = new QLineEdit(DialogFTP);
        lineEditRemoteFiles->setObjectName(QStringLiteral("lineEditRemoteFiles"));
        lineEditRemoteFiles->setGeometry(QRect(550, 30, 371, 25));
        treeView = new QTreeView(DialogFTP);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(40, 80, 881, 331));
        pushButtonUpload = new QPushButton(DialogFTP);
        pushButtonUpload->setObjectName(QStringLiteral("pushButtonUpload"));
        pushButtonUpload->setGeometry(QRect(40, 420, 461, 25));
        pushButtonDownload = new QPushButton(DialogFTP);
        pushButtonDownload->setObjectName(QStringLiteral("pushButtonDownload"));
        pushButtonDownload->setGeometry(QRect(520, 420, 401, 25));
        progressBar = new QProgressBar(DialogFTP);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 450, 881, 23));
        progressBar->setValue(0);

        retranslateUi(DialogFTP);

        QMetaObject::connectSlotsByName(DialogFTP);
    } // setupUi

    void retranslateUi(QDialog *DialogFTP)
    {
        DialogFTP->setWindowTitle(QApplication::translate("DialogFTP", "Dialog", 0));
        label->setText(QApplication::translate("DialogFTP", "Local File", 0));
        label_2->setText(QApplication::translate("DialogFTP", "Remote File", 0));
        pushButtonUpload->setText(QApplication::translate("DialogFTP", "Upload", 0));
        pushButtonDownload->setText(QApplication::translate("DialogFTP", "Download", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogFTP: public Ui_DialogFTP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFTP_H
