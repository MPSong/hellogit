/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[451];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "onSent"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "room"
QT_MOC_LITERAL(4, 24, 28), // "on_pushButton_signin_clicked"
QT_MOC_LITERAL(5, 53, 30), // "on_pushButton_makeroom_clicked"
QT_MOC_LITERAL(6, 84, 28), // "on_pushButton_signup_clicked"
QT_MOC_LITERAL(7, 113, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(8, 142, 28), // "on_pushButton_logout_clicked"
QT_MOC_LITERAL(9, 171, 30), // "on_pushButton_logout_2_clicked"
QT_MOC_LITERAL(10, 202, 29), // "on_pushButton_confirm_clicked"
QT_MOC_LITERAL(11, 232, 7), // "recvMsg"
QT_MOC_LITERAL(12, 240, 30), // "on_pushButton_entrance_clicked"
QT_MOC_LITERAL(13, 271, 26), // "on_pushButton_exit_clicked"
QT_MOC_LITERAL(14, 298, 28), // "on_pushButton_invite_clicked"
QT_MOC_LITERAL(15, 327, 30), // "on_pushButton_check_id_clicked"
QT_MOC_LITERAL(16, 358, 32), // "on_pushButton_check_nick_clicked"
QT_MOC_LITERAL(17, 391, 26), // "on_pushButton_send_clicked"
QT_MOC_LITERAL(18, 418, 32) // "on_pushButton_attachment_clicked"

    },
    "MainWindow\0onSent\0\0room\0"
    "on_pushButton_signin_clicked\0"
    "on_pushButton_makeroom_clicked\0"
    "on_pushButton_signup_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_pushButton_logout_clicked\0"
    "on_pushButton_logout_2_clicked\0"
    "on_pushButton_confirm_clicked\0recvMsg\0"
    "on_pushButton_entrance_clicked\0"
    "on_pushButton_exit_clicked\0"
    "on_pushButton_invite_clicked\0"
    "on_pushButton_check_id_clicked\0"
    "on_pushButton_check_nick_clicked\0"
    "on_pushButton_send_clicked\0"
    "on_pushButton_attachment_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       4,    0,   97,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_signin_clicked(); break;
        case 2: _t->on_pushButton_makeroom_clicked(); break;
        case 3: _t->on_pushButton_signup_clicked(); break;
        case 4: _t->on_pushButton_cancel_clicked(); break;
        case 5: _t->on_pushButton_logout_clicked(); break;
        case 6: _t->on_pushButton_logout_2_clicked(); break;
        case 7: _t->on_pushButton_confirm_clicked(); break;
        case 8: _t->recvMsg(); break;
        case 9: _t->on_pushButton_entrance_clicked(); break;
        case 10: _t->on_pushButton_exit_clicked(); break;
        case 11: _t->on_pushButton_invite_clicked(); break;
        case 12: _t->on_pushButton_check_id_clicked(); break;
        case 13: _t->on_pushButton_check_nick_clicked(); break;
        case 14: _t->on_pushButton_send_clicked(); break;
        case 15: _t->on_pushButton_attachment_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
