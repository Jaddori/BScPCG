/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CityGenerator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[456];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_btn_generate_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 34), // "on_slider_d1MinHeight_valueCh..."
QT_MOC_LITERAL(4, 71, 5), // "value"
QT_MOC_LITERAL(5, 77, 34), // "on_slider_d2MinHeight_valueCh..."
QT_MOC_LITERAL(6, 112, 34), // "on_slider_d3MinHeight_valueCh..."
QT_MOC_LITERAL(7, 147, 34), // "on_slider_d1MaxHeight_valueCh..."
QT_MOC_LITERAL(8, 182, 34), // "on_slider_d2MaxHeight_valueCh..."
QT_MOC_LITERAL(9, 217, 34), // "on_slider_d3MaxHeight_valueCh..."
QT_MOC_LITERAL(10, 252, 32), // "on_slider_d1Density_valueChanged"
QT_MOC_LITERAL(11, 285, 32), // "on_slider_d2Density_valueChanged"
QT_MOC_LITERAL(12, 318, 32), // "on_slider_d3Density_valueChanged"
QT_MOC_LITERAL(13, 351, 34), // "on_slider_d1BlockSize_valueCh..."
QT_MOC_LITERAL(14, 386, 34), // "on_slider_d2BlockSize_valueCh..."
QT_MOC_LITERAL(15, 421, 34) // "on_slider_d3BlockSize_valueCh..."

    },
    "MainWindow\0on_btn_generate_clicked\0\0"
    "on_slider_d1MinHeight_valueChanged\0"
    "value\0on_slider_d2MinHeight_valueChanged\0"
    "on_slider_d3MinHeight_valueChanged\0"
    "on_slider_d1MaxHeight_valueChanged\0"
    "on_slider_d2MaxHeight_valueChanged\0"
    "on_slider_d3MaxHeight_valueChanged\0"
    "on_slider_d1Density_valueChanged\0"
    "on_slider_d2Density_valueChanged\0"
    "on_slider_d3Density_valueChanged\0"
    "on_slider_d1BlockSize_valueChanged\0"
    "on_slider_d2BlockSize_valueChanged\0"
    "on_slider_d3BlockSize_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    1,   80,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       6,    1,   86,    2, 0x08 /* Private */,
       7,    1,   89,    2, 0x08 /* Private */,
       8,    1,   92,    2, 0x08 /* Private */,
       9,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      12,    1,  104,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,
      14,    1,  110,    2, 0x08 /* Private */,
      15,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_generate_clicked(); break;
        case 1: _t->on_slider_d1MinHeight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_slider_d2MinHeight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_slider_d3MinHeight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_slider_d1MaxHeight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_slider_d2MaxHeight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_slider_d3MaxHeight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_slider_d1Density_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_slider_d2Density_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_slider_d3Density_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_slider_d1BlockSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_slider_d2BlockSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_slider_d3BlockSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
