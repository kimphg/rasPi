/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Radar24/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[21];
    char stringdata0[405];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 32), // "on_Initchar_lineEdit_textChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4), // "arg1"
QT_MOC_LITERAL(4, 46, 47), // "on_Serialavailable_comboBox_c..."
QT_MOC_LITERAL(5, 94, 42), // "on_Serialbaud_comboBox_curren..."
QT_MOC_LITERAL(6, 137, 27), // "on_Start_pushButton_clicked"
QT_MOC_LITERAL(7, 165, 26), // "on_Stop_pushButton_clicked"
QT_MOC_LITERAL(8, 192, 26), // "on_Save_pushButton_clicked"
QT_MOC_LITERAL(9, 219, 8), // "readData"
QT_MOC_LITERAL(10, 228, 11), // "update_plot"
QT_MOC_LITERAL(11, 240, 16), // "selectionChanged"
QT_MOC_LITERAL(12, 257, 10), // "mousePress"
QT_MOC_LITERAL(13, 268, 10), // "mouseWheel"
QT_MOC_LITERAL(14, 279, 38), // "on_Numbersubplots_spinBox_val..."
QT_MOC_LITERAL(15, 318, 23), // "number_of_lines_changed"
QT_MOC_LITERAL(16, 342, 3), // "val"
QT_MOC_LITERAL(17, 346, 13), // "color_changed"
QT_MOC_LITERAL(18, 360, 12), // "deleteObject"
QT_MOC_LITERAL(19, 373, 6), // "thingy"
QT_MOC_LITERAL(20, 380, 24) // "on_checkBox_stateChanged"

    },
    "Widget\0on_Initchar_lineEdit_textChanged\0"
    "\0arg1\0on_Serialavailable_comboBox_currentIndexChanged\0"
    "on_Serialbaud_comboBox_currentIndexChanged\0"
    "on_Start_pushButton_clicked\0"
    "on_Stop_pushButton_clicked\0"
    "on_Save_pushButton_clicked\0readData\0"
    "update_plot\0selectionChanged\0mousePress\0"
    "mouseWheel\0on_Numbersubplots_spinBox_valueChanged\0"
    "number_of_lines_changed\0val\0color_changed\0"
    "deleteObject\0thingy\0on_checkBox_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

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
       4,    1,   97,    2, 0x08 /* Private */,
       5,    1,  100,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      15,    1,  114,    2, 0x08 /* Private */,
      17,    1,  117,    2, 0x08 /* Private */,
      18,    1,  120,    2, 0x08 /* Private */,
      20,    1,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QObjectStar,   19,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Initchar_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_Serialavailable_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_Serialbaud_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_Start_pushButton_clicked(); break;
        case 4: _t->on_Stop_pushButton_clicked(); break;
        case 5: _t->on_Save_pushButton_clicked(); break;
        case 6: _t->readData(); break;
        case 7: _t->update_plot(); break;
        case 8: _t->selectionChanged(); break;
        case 9: _t->mousePress(); break;
        case 10: _t->mouseWheel(); break;
        case 11: _t->on_Numbersubplots_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->number_of_lines_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->color_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->deleteObject((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 15: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
