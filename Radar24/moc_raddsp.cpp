/****************************************************************************
** Meta object code from reading C++ file 'raddsp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "raddsp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'raddsp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RadDSP_t {
    QByteArrayData data[5];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RadDSP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RadDSP_t qt_meta_stringdata_RadDSP = {
    {
QT_MOC_LITERAL(0, 0, 6), // "RadDSP"
QT_MOC_LITERAL(1, 7, 12), // "deleteObject"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "thingy"
QT_MOC_LITERAL(4, 28, 6) // "doWork"

    },
    "RadDSP\0deleteObject\0\0thingy\0doWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RadDSP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void RadDSP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RadDSP *_t = static_cast<RadDSP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteObject((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->doWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RadDSP::*_t)(QObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RadDSP::deleteObject)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RadDSP::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RadDSP.data,
      qt_meta_data_RadDSP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RadDSP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RadDSP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RadDSP.stringdata0))
        return static_cast<void*>(const_cast< RadDSP*>(this));
    return QObject::qt_metacast(_clname);
}

int RadDSP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RadDSP::deleteObject(QObject * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
