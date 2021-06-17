/****************************************************************************
** Meta object code from reading C++ file 'ServerManagement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ServerManagement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerManagement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerManagement_t {
    QByteArrayData data[15];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerManagement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerManagement_t qt_meta_stringdata_ServerManagement = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ServerManagement"
QT_MOC_LITERAL(1, 17, 16), // "ClientConnection"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "ClientDisconnection"
QT_MOC_LITERAL(4, 55, 7), // "Client*"
QT_MOC_LITERAL(5, 63, 6), // "client"
QT_MOC_LITERAL(6, 70, 27), // "ClientIdentificationRequest"
QT_MOC_LITERAL(7, 98, 20), // "MessageToBeDelivered"
QT_MOC_LITERAL(8, 119, 24), // "GuppyServerClientMessage"
QT_MOC_LITERAL(9, 144, 7), // "message"
QT_MOC_LITERAL(10, 152, 21), // "UserListToBeDelivered"
QT_MOC_LITERAL(11, 174, 17), // "GuppySendUserList"
QT_MOC_LITERAL(12, 192, 8), // "UserList"
QT_MOC_LITERAL(13, 201, 18), // "on_addUser_clicked"
QT_MOC_LITERAL(14, 220, 21) // "on_removeUser_clicked"

    },
    "ServerManagement\0ClientConnection\0\0"
    "ClientDisconnection\0Client*\0client\0"
    "ClientIdentificationRequest\0"
    "MessageToBeDelivered\0GuppyServerClientMessage\0"
    "message\0UserListToBeDelivered\0"
    "GuppySendUserList\0UserList\0"
    "on_addUser_clicked\0on_removeUser_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerManagement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,
      13,    0,   62,    2, 0x08 /* Private */,
      14,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ServerManagement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerManagement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClientConnection(); break;
        case 1: _t->ClientDisconnection((*reinterpret_cast< Client*(*)>(_a[1]))); break;
        case 2: _t->ClientIdentificationRequest((*reinterpret_cast< Client*(*)>(_a[1]))); break;
        case 3: _t->MessageToBeDelivered((*reinterpret_cast< const GuppyServerClientMessage(*)>(_a[1]))); break;
        case 4: _t->UserListToBeDelivered((*reinterpret_cast< const GuppySendUserList(*)>(_a[1]))); break;
        case 5: _t->on_addUser_clicked(); break;
        case 6: _t->on_removeUser_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerManagement::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ServerManagement.data,
    qt_meta_data_ServerManagement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ServerManagement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerManagement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerManagement.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ServerManagement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
