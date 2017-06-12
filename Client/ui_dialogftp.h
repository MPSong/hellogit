/********************************************************************************
** Form generated from reading UI file 'dialogftp.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
        DialogFTP->resize(823, 461);
        label = new QLabel(DialogFTP);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 141, 17));
        label_2 = new QLabel(DialogFTP);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 20, 161, 17));
        lineEditLocalFiles = new QLineEdit(DialogFTP);
        lineEditLocalFiles->setObjectName(QStringLiteral("lineEditLocalFiles"));
        lineEditLocalFiles->setGeometry(QRect(160, 20, 221, 25));
        lineEditRemoteFiles = new QLineEdit(DialogFTP);
        lineEditRemoteFiles->setObjectName(QStringLiteral("lineEditRemoteFiles"));
        lineEditRemoteFiles->setGeometry(QRect(560, 20, 251, 25));
        treeView = new QTreeView(DialogFTP);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(10, 60, 801, 311));
        pushButtonUpload = new QPushButton(DialogFTP);
        pushButtonUpload->setObjectName(QStringLiteral("pushButtonUpload"));
        pushButtonUpload->setGeometry(QRect(10, 380, 401, 25));
        pushButtonDownload = new QPushButton(DialogFTP);
        pushButtonDownload->setObjectName(QStringLiteral("pushButtonDownload"));
        pushButtonDownload->setGeometry(QRect(420, 380, 391, 25));
        progressBar = new QProgressBar(DialogFTP);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 420, 801, 23));
        progressBar->setValue(0);

        retranslateUi(DialogFTP);

        QMetaObject::connectSlotsByName(DialogFTP);
    } // setupUi

    void retranslateUi(QDialog *DialogFTP)
    {
        DialogFTP->setWindowTitle(QApplication::translate("DialogFTP", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogFTP", "Local File / directory", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogFTP", "Remote File / directory", Q_NULLPTR));
        pushButtonUpload->setText(QApplication::translate("DialogFTP", "Upload", Q_NULLPTR));
        pushButtonDownload->setText(QApplication::translate("DialogFTP", "Download", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogFTP: public Ui_DialogFTP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFTP_H
