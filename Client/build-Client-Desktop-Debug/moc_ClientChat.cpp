/****************************************************************************
** Meta object code from reading C++ file 'ClientChat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ClientChat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientChat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientChat_t {
    QByteArrayData data[10];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientChat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientChat_t qt_meta_stringdata_ClientChat = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ClientChat"
QT_MOC_LITERAL(1, 11, 38), // "on_ListOfUsersWidget_itemDoub..."
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 68, 4), // "item"
QT_MOC_LITERAL(5, 73, 19), // "SendMessageToServer"
QT_MOC_LITERAL(6, 93, 24), // "GuppyClientServerMessage"
QT_MOC_LITERAL(7, 118, 7), // "message"
QT_MOC_LITERAL(8, 126, 12), // "dataReceived"
QT_MOC_LITERAL(9, 139, 10) // "disconnect"

    },
    "ClientChat\0on_ListOfUsersWidget_itemDoubleClicked\0"
    "\0QListWidgetItem*\0item\0SendMessageToServer\0"
    "GuppyClientServerMessage\0message\0"
    "dataReceived\0disconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientChat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,
       8,    0,   40,    2, 0x08 /* Private */,
       9,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientChat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientChat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ListOfUsersWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->SendMessageToServer((*reinterpret_cast< const GuppyClientServerMessage(*)>(_a[1]))); break;
        case 2: _t->dataReceived(); break;
        case 3: _t->disconnect(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientChat::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ClientChat.data,
    qt_meta_data_ClientChat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientChat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientChat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientChat.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClientChat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
