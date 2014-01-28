/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemboundhelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemboundhelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemboundhelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemBoundHelper_t {
    QByteArrayData data[9];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_YCQUiTreeItemBoundHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_YCQUiTreeItemBoundHelper_t qt_meta_stringdata_YCQUiTreeItemBoundHelper = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 9),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 7),
QT_MOC_LITERAL(4, 44, 14),
QT_MOC_LITERAL(5, 59, 6),
QT_MOC_LITERAL(6, 66, 14),
QT_MOC_LITERAL(7, 81, 14),
QT_MOC_LITERAL(8, 96, 14)
    },
    "YCQUiTreeItemBoundHelper\0onChanged\0\0"
    "roBound\0onItemChangedX\0iValue\0"
    "onItemChangedY\0onItemChangedW\0"
    "onItemChangedH\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemBoundHelper[] = {

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
       1,    1,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a,
       6,    1,   45,    2, 0x0a,
       7,    1,   48,    2, 0x0a,
       8,    1,   51,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QRect,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void YCQUiTreeItemBoundHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemBoundHelper *_t = static_cast<YCQUiTreeItemBoundHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 1: _t->onItemChangedX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onItemChangedY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onItemChangedW((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onItemChangedH((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemBoundHelper::*_t)(const QRect & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemBoundHelper::onChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemBoundHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemBoundHelper.data,
      qt_meta_data_YCQUiTreeItemBoundHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemBoundHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemBoundHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemBoundHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemBoundHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemBoundHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void YCQUiTreeItemBoundHelper::onChanged(const QRect & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
