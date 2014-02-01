/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemsizehelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemsizehelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemsizehelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemSizeHelper_t {
    QByteArrayData data[7];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_YCQUiTreeItemSizeHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_YCQUiTreeItemSizeHelper_t qt_meta_stringdata_YCQUiTreeItemSizeHelper = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 9),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 6),
QT_MOC_LITERAL(4, 42, 18),
QT_MOC_LITERAL(5, 61, 6),
QT_MOC_LITERAL(6, 68, 19)
    },
    "YCQUiTreeItemSizeHelper\0onChanged\0\0"
    "roSize\0onItemChangedWidth\0iValue\0"
    "onItemChangedHeight\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemSizeHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a,
       6,    1,   35,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QSize,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void YCQUiTreeItemSizeHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemSizeHelper *_t = static_cast<YCQUiTreeItemSizeHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 1: _t->onItemChangedWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onItemChangedHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemSizeHelper::*_t)(const QSize & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemSizeHelper::onChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemSizeHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemSizeHelper.data,
      qt_meta_data_YCQUiTreeItemSizeHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemSizeHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemSizeHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemSizeHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemSizeHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemSizeHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void YCQUiTreeItemSizeHelper::onChanged(const QSize & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
