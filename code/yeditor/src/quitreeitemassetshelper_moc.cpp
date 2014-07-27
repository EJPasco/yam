/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemassetshelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemassetshelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemassetshelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemAssetsHelper_t {
    QByteArrayData data[9];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YCQUiTreeItemAssetsHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YCQUiTreeItemAssetsHelper_t qt_meta_stringdata_YCQUiTreeItemAssetsHelper = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 9),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 7),
QT_MOC_LITERAL(4, 45, 12),
QT_MOC_LITERAL(5, 58, 9),
QT_MOC_LITERAL(6, 68, 12),
QT_MOC_LITERAL(7, 81, 14),
QT_MOC_LITERAL(8, 96, 8)
    },
    "YCQUiTreeItemAssetsHelper\0onChanged\0"
    "\0riIndex\0SConfigAsset\0rstConfig\0"
    "onClickedAdd\0onChangedAsset\0rstAsset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemAssetsHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       1,    0,   49,    2, 0x06 /* Public */,
       1,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x0a /* Public */,
       7,    2,   54,    2, 0x0a /* Public */,
       7,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    8,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void YCQUiTreeItemAssetsHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemAssetsHelper *_t = static_cast<YCQUiTreeItemAssetsHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const SConfigAsset(*)>(_a[2]))); break;
        case 1: _t->onChanged(); break;
        case 2: _t->onChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->onClickedAdd(); break;
        case 4: _t->onChangedAsset((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const SConfigAsset(*)>(_a[2]))); break;
        case 5: _t->onChangedAsset((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemAssetsHelper::*_t)(const int & , const SConfigAsset & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemAssetsHelper::onChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (YCQUiTreeItemAssetsHelper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemAssetsHelper::onChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (YCQUiTreeItemAssetsHelper::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemAssetsHelper::onChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemAssetsHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemAssetsHelper.data,
      qt_meta_data_YCQUiTreeItemAssetsHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemAssetsHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemAssetsHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemAssetsHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemAssetsHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemAssetsHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void YCQUiTreeItemAssetsHelper::onChanged(const int & _t1, const SConfigAsset & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void YCQUiTreeItemAssetsHelper::onChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void YCQUiTreeItemAssetsHelper::onChanged(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
