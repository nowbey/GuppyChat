/****************************************************************************
** Meta object code from reading C++ file 'FenServeur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FenServeur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenServeur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FenServeur_t {
    QByteArrayData data[9];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FenServeur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FenServeur_t qt_meta_stringdata_FenServeur = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FenServeur"
QT_MOC_LITERAL(1, 11, 17), // "nouvelleConnexion"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "deconnexionClient"
QT_MOC_LITERAL(4, 48, 7), // "Client*"
QT_MOC_LITERAL(5, 56, 6), // "client"
QT_MOC_LITERAL(6, 63, 21), // "messageRecuFromClient"
QT_MOC_LITERAL(7, 85, 7), // "Message"
QT_MOC_LITERAL(8, 93, 7) // "message"

    },
    "FenServeur\0nouvelleConnexion\0\0"
    "deconnexionClient\0Client*\0client\0"
    "messageRecuFromClient\0Message\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenServeur[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x08 /* Private */,
       6,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void FenServeur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenServeur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nouvelleConnexion(); break;
        case 1: _t->deconnexionClient((*reinterpret_cast< Client*(*)>(_a[1]))); break;
        case 2: _t->messageRecuFromClient((*reinterpret_cast< const Message(*)>(_a[1]))); break;
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
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FenServeur::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FenServeur.data,
    qt_meta_data_FenServeur,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FenServeur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenServeur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenServeur.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FenServeur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
