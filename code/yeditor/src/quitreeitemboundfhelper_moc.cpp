/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemboundfhelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemboundfhelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemboundfhelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemBoundfHelper_t {
    QByteArrayData data[9];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YCQUiTreeItemBoundfHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YCQUiTreeItemBoundfHelper_t qt_meta_stringdata_YCQUiTreeItemBoundfHelper = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 9),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 7),
QT_MOC_LITERAL(4, 45, 14),
QT_MOC_LITERAL(5, 60, 6),
QT_MOC_LITERAL(6, 67, 14),
QT_MOC_LITERAL(7, 82, 14),
QT_MOC_LITERAL(8, 97, 14)
    },
    "YCQUiTreeItemBoundfHelper\0onChanged\0"
    "\0roBound\0onItemChangedX\0dValue\0"
    "onItemChangedY\0onItemChangedW\0"
    "onItemChangedH"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemBoundfHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       7,    1,   48,    2, 0x0a /* Public */,
       8,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QRectF,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,

       0        // eod
};

void YCQUiTreeItemBoundfHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemBoundfHelper *_t = static_cast<YCQUiTreeItemBoundfHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 1: _t->onItemChangedX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->onItemChangedY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->onItemChangedW((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->onItemChangedH((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemBoundfHelper::*_t)(const QRectF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemBoundfHelper::onChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemBoundfHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemBoundfHelper.data,
      qt_meta_data_YCQUiTreeItemBoundfHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemBoundfHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemBoundfHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemBoundfHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemBoundfHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemBoundfHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void YCQUiTreeItemBoundfHelper::onChanged(const QRectF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
