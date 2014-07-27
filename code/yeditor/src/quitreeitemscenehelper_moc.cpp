/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemscenehelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemscenehelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemscenehelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemSceneHelper_t {
    QByteArrayData data[16];
    char stringdata[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YCQUiTreeItemSceneHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YCQUiTreeItemSceneHelper_t qt_meta_stringdata_YCQUiTreeItemSceneHelper = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 9),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 12),
QT_MOC_LITERAL(4, 49, 9),
QT_MOC_LITERAL(5, 59, 13),
QT_MOC_LITERAL(6, 73, 15),
QT_MOC_LITERAL(7, 89, 14),
QT_MOC_LITERAL(8, 104, 7),
QT_MOC_LITERAL(9, 112, 13),
QT_MOC_LITERAL(10, 126, 6),
QT_MOC_LITERAL(11, 133, 15),
QT_MOC_LITERAL(12, 149, 7),
QT_MOC_LITERAL(13, 157, 12),
QT_MOC_LITERAL(14, 170, 8),
QT_MOC_LITERAL(15, 179, 15)
    },
    "YCQUiTreeItemSceneHelper\0onChanged\0\0"
    "SConfigScene\0rstConfig\0SConfigLayout\0"
    "rstConfigLayout\0onChangedLogic\0roLogic\0"
    "onChangedSize\0roSize\0onChangedAssets\0"
    "riIndex\0SConfigAsset\0rstAsset\0"
    "onChangedLayout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemSceneHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   54,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,
      11,    2,   60,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,
      11,    1,   66,    2, 0x0a /* Public */,
      15,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QSize,   10,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 5,    4,

       0        // eod
};

void YCQUiTreeItemSceneHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemSceneHelper *_t = static_cast<YCQUiTreeItemSceneHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const SConfigScene(*)>(_a[1])),(*reinterpret_cast< const SConfigLayout(*)>(_a[2]))); break;
        case 1: _t->onChangedLogic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onChangedSize((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 3: _t->onChangedAssets((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const SConfigAsset(*)>(_a[2]))); break;
        case 4: _t->onChangedAssets(); break;
        case 5: _t->onChangedAssets((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->onChangedLayout((*reinterpret_cast< const SConfigLayout(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemSceneHelper::*_t)(const SConfigScene & , const SConfigLayout & );
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void YCQUiTreeItemSceneHelper::onChanged(const SConfigScene & _t1, const SConfigLayout & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
