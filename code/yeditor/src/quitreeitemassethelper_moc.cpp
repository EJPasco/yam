/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemassethelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemassethelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemassethelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemAssetHelper_t {
    QByteArrayData data[13];
    char stringdata[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_YCQUiTreeItemAssetHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_YCQUiTreeItemAssetHelper_t qt_meta_stringdata_YCQUiTreeItemAssetHelper = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 9),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 7),
QT_MOC_LITERAL(4, 44, 12),
QT_MOC_LITERAL(5, 57, 9),
QT_MOC_LITERAL(6, 67, 15),
QT_MOC_LITERAL(7, 83, 13),
QT_MOC_LITERAL(8, 97, 6),
QT_MOC_LITERAL(9, 104, 13),
QT_MOC_LITERAL(10, 118, 6),
QT_MOC_LITERAL(11, 125, 13),
QT_MOC_LITERAL(12, 139, 6)
    },
    "YCQUiTreeItemAssetHelper\0onChanged\0\0"
    "riIndex\0SConfigAsset\0rstConfig\0"
    "onClickedDelete\0onChangedFile\0rsFile\0"
    "onChangedName\0rsName\0onChangedType\0"
    "rsType\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemAssetHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06,
       1,    1,   49,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   52,    2, 0x0a,
       7,    1,   53,    2, 0x0a,
       9,    1,   56,    2, 0x0a,
      11,    1,   59,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void YCQUiTreeItemAssetHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemAssetHelper *_t = static_cast<YCQUiTreeItemAssetHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const SConfigAsset(*)>(_a[2]))); break;
        case 1: _t->onChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->onClickedDelete(); break;
        case 3: _t->onChangedFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onChangedName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onChangedType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemAssetHelper::*_t)(const int & , const SConfigAsset & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemAssetHelper::onChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (YCQUiTreeItemAssetHelper::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemAssetHelper::onChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemAssetHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemAssetHelper.data,
      qt_meta_data_YCQUiTreeItemAssetHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemAssetHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemAssetHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemAssetHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemAssetHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemAssetHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void YCQUiTreeItemAssetHelper::onChanged(const int & _t1, const SConfigAsset & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void YCQUiTreeItemAssetHelper::onChanged(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
