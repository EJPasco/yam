/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemscenehelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemscenehelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemscenehelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemSceneHelper_t {
    QByteArrayData data[13];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_YCQUiTreeItemSceneHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_YCQUiTreeItemSceneHelper_t qt_meta_stringdata_YCQUiTreeItemSceneHelper = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 9),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 12),
QT_MOC_LITERAL(4, 49, 9),
QT_MOC_LITERAL(5, 59, 14),
QT_MOC_LITERAL(6, 74, 7),
QT_MOC_LITERAL(7, 82, 13),
QT_MOC_LITERAL(8, 96, 6),
QT_MOC_LITERAL(9, 103, 15),
QT_MOC_LITERAL(10, 119, 7),
QT_MOC_LITERAL(11, 127, 12),
QT_MOC_LITERAL(12, 140, 8)
    },
    "YCQUiTreeItemSceneHelper\0onChanged\0\0"
    "SConfigScene\0rstConfig\0onChangedLogic\0"
    "roLogic\0onChangedSize\0roSize\0"
    "onChangedAssets\0riIndex\0SConfigAsset\0"
    "rstAsset\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemSceneHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a,
       7,    1,   50,    2, 0x0a,
       9,    2,   53,    2, 0x0a,
       9,    0,   58,    2, 0x0a,
       9,    1,   59,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QSize,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,   10,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void YCQUiTreeItemSceneHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemSceneHelper *_t = static_cast<YCQUiTreeItemSceneHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const SConfigScene(*)>(_a[1]))); break;
        case 1: _t->onChangedLogic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onChangedSize((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 3: _t->onChangedAssets((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const SConfigAsset(*)>(_a[2]))); break;
        case 4: _t->onChangedAssets(); break;
        case 5: _t->onChangedAssets((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemSceneHelper::*_t)(const SConfigScene & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemSceneHelper::onChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemSceneHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemSceneHelper.data,
      qt_meta_data_YCQUiTreeItemSceneHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemSceneHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemSceneHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemSceneHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemSceneHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemSceneHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void YCQUiTreeItemSceneHelper::onChanged(const SConfigScene & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
