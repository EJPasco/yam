/****************************************************************************
** Meta object code from reading C++ file 'quitreeitempanelhelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitempanelhelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitempanelhelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemPanelHelper_t {
    QByteArrayData data[9];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YCQUiTreeItemPanelHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YCQUiTreeItemPanelHelper_t qt_meta_stringdata_YCQUiTreeItemPanelHelper = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 9),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 9),
QT_MOC_LITERAL(4, 46, 13),
QT_MOC_LITERAL(5, 60, 9),
QT_MOC_LITERAL(6, 70, 16),
QT_MOC_LITERAL(7, 87, 9),
QT_MOC_LITERAL(8, 97, 15)
    },
    "YCQUiTreeItemPanelHelper\0onChanged\0\0"
    "rbNoInput\0SConfigLayout\0rstLayout\0"
    "onChangedNoInput\0rsNoInput\0onChangedLayout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemPanelHelper[] = {

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
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   34,    2, 0x0a /* Public */,
       8,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void YCQUiTreeItemPanelHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemPanelHelper *_t = static_cast<YCQUiTreeItemPanelHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const SConfigLayout(*)>(_a[2]))); break;
        case 1: _t->onChangedNoInput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onChangedLayout((*reinterpret_cast< const SConfigLayout(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemPanelHelper::*_t)(const bool & , const SConfigLayout & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemPanelHelper::onChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemPanelHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemPanelHelper.data,
      qt_meta_data_YCQUiTreeItemPanelHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemPanelHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemPanelHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemPanelHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemPanelHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemPanelHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void YCQUiTreeItemPanelHelper::onChanged(const bool & _t1, const SConfigLayout & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
