/****************************************************************************
** Meta object code from reading C++ file 'quitreeitemtexthelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitreeitemtexthelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitreeitemtexthelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTreeItemTextHelper_t {
    QByteArrayData data[12];
    char stringdata[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_YCQUiTreeItemTextHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_YCQUiTreeItemTextHelper_t qt_meta_stringdata_YCQUiTreeItemTextHelper = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 9),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 6),
QT_MOC_LITERAL(4, 42, 6),
QT_MOC_LITERAL(5, 49, 11),
QT_MOC_LITERAL(6, 61, 7),
QT_MOC_LITERAL(7, 69, 13),
QT_MOC_LITERAL(8, 83, 13),
QT_MOC_LITERAL(9, 97, 5),
QT_MOC_LITERAL(10, 103, 18),
QT_MOC_LITERAL(11, 122, 14)
    },
    "YCQUiTreeItemTextHelper\0onChanged\0\0"
    "rsFace\0riSize\0rsAlignType\0rsValue\0"
    "onChangedFace\0onChangedSize\0iSize\0"
    "onChangedAlignType\0onChangedValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTreeItemTextHelper[] = {

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
       1,    4,   39,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   48,    2, 0x0a,
       8,    1,   51,    2, 0x0a,
      10,    1,   54,    2, 0x0a,
      11,    1,   57,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void YCQUiTreeItemTextHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTreeItemTextHelper *_t = static_cast<YCQUiTreeItemTextHelper *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->onChangedFace((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onChangedSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onChangedAlignType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onChangedValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTreeItemTextHelper::*_t)(const QString & , const int & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTreeItemTextHelper::onChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject YCQUiTreeItemTextHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YCQUiTreeItemTextHelper.data,
      qt_meta_data_YCQUiTreeItemTextHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTreeItemTextHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTreeItemTextHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTreeItemTextHelper.stringdata))
        return static_cast<void*>(const_cast< YCQUiTreeItemTextHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int YCQUiTreeItemTextHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void YCQUiTreeItemTextHelper::onChanged(const QString & _t1, const int & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
