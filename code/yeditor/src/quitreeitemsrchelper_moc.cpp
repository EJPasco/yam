/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemsrchelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemsrchelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemsrchelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemSrcHelper_t {
    QByteArrayData data[16];
    char stringdata[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_YCQUiTreeItemSrcHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_YCQUiTreeItemSrcHelper_t qt_meta_stringdata_YCQUiTreeItemSrcHelper = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 9),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 10),
QT_MOC_LITERAL(4, 45, 11),
QT_MOC_LITERAL(5, 57, 11),
QT_MOC_LITERAL(6, 69, 12),
QT_MOC_LITERAL(7, 82, 25),
QT_MOC_LITERAL(8, 108, 12),
QT_MOC_LITERAL(9, 121, 13),
QT_MOC_LITERAL(10, 135, 7),
QT_MOC_LITERAL(11, 143, 10),
QT_MOC_LITERAL(12, 154, 18),
QT_MOC_LITERAL(13, 173, 11),
QT_MOC_LITERAL(14, 185, 19),
QT_MOC_LITERAL(15, 205, 15)
    },
    "YCQUiTreeItemSrcHelper\0onChanged\0\0"
    "EImageType\0reImageType\0yam::yint32\0"
    "riImageIndex\0YCQUiTreeItemImageHelper*\0"
    "pImageHelper\0yam::yfloat32\0rfSpeed\0"
    "onSelected\0onImageTypeChanged\0rsImageType\0"
    "onImageIndexChanged\0onChangedImages\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemSrcHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06,
       1,    2,   76,    2, 0x06,
       1,    1,   81,    2, 0x06,
       1,    2,   84,    2, 0x06,
      11,    2,   89,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      12,    1,   94,    2, 0x0a,
      14,    1,   97,    2, 0x0a,
      15,    3,  100,    2, 0x0a,
      15,    2,  107,    2, 0x0a,
      15,    1,  112,    2, 0x0a,
      15,    2,  115,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9,    4,   10,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9,    4,   10,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void YCQUiTreeItemSrcHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemSrcHelper *_t = static_cast<YCQUiTreeItemSrcHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const EImageType(*)>(_a[1])),(*reinterpret_cast< const yam::yint32(*)>(_a[2])),(*reinterpret_cast< YCQUiTreeItemImageHelper*(*)>(_a[3]))); break;
        case 1: _t->onChanged((*reinterpret_cast< const EImageType(*)>(_a[1])),(*reinterpret_cast< const yam::yfloat32(*)>(_a[2]))); break;
        case 2: _t->onChanged((*reinterpret_cast< const EImageType(*)>(_a[1]))); break;
        case 3: _t->onChanged((*reinterpret_cast< const EImageType(*)>(_a[1])),(*reinterpret_cast< const yam::yint32(*)>(_a[2]))); break;
        case 4: _t->onSelected((*reinterpret_cast< const EImageType(*)>(_a[1])),(*reinterpret_cast< const yam::yint32(*)>(_a[2]))); break;
        case 5: _t->onImageTypeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onImageIndexChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 7: _t->onChangedImages((*reinterpret_cast< const EImageType(*)>(_a[1])),(*reinterpret_cast< const yam::yint32(*)>(_a[2])),(*reinterpret_cast< YCQUiTreeItemImageHelper*(*)>(_a[3]))); break;
        case 8: _t->onChangedImages((*reinterpret_cast< const EImageType(*)>(_a[1])),(*reinterpret_cast< const yam::yfloat32(*)>(_a[2]))); break;
        case 9: _t->onChangedImages((*reinterpret_cast< const EImageType(*)>(_a[1]))); break;
        case 10: _t->onChangedImages((*reinterpret_cast< const EImageType(*)>(_a[1])),(*reinterpret_cast< const yam::yint32(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemSrcHelper::*_t)(const EImageType & , const yam::yint32 & , YCQUiTreeItemImageHelper * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemSrcHelper::onChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (YCQUiTreeItemSrcHelper::*_t)(const EImageType & , const yam::yfloat32 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemSrcHelper::onChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (YCQUiTreeItemSrcHelper::*_t)(const EImageType & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemSrcHelper::onChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (YCQUiTreeItemSrcHelper::*_t)(const EImageType & , const yam::yint32 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemSrcHelper::onChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (YCQUiTreeItemSrcHelper::*_t)(const EImageType & , const yam::yint32 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemSrcHelper::onSelected)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemSrcHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemSrcHelper.data,
      qt_meta_data_YCQUiTreeItemSrcHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemSrcHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemSrcHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemSrcHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemSrcHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemSrcHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void YCQUiTreeItemSrcHelper::onChanged(const EImageType & _t1, const yam::yint32 & _t2, YCQUiTreeItemImageHelper * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void YCQUiTreeItemSrcHelper::onChanged(const EImageType & _t1, const yam::yfloat32 & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void YCQUiTreeItemSrcHelper::onChanged(const EImageType & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void YCQUiTreeItemSrcHelper::onChanged(const EImageType & _t1, const yam::yint32 & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void YCQUiTreeItemSrcHelper::onSelected(const EImageType & _t1, const yam::yint32 & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
