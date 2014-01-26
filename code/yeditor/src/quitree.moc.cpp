/****************************************************************************
** Meta object code from reading C++ file 'quitree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/quitree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quitree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YCQUiTree_t {
    QByteArrayData data[9];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_YCQUiTree_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_YCQUiTree_t qt_meta_stringdata_YCQUiTree = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 9),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 10),
QT_MOC_LITERAL(4, 32, 5),
QT_MOC_LITERAL(5, 38, 13),
QT_MOC_LITERAL(6, 52, 16),
QT_MOC_LITERAL(7, 69, 5),
QT_MOC_LITERAL(8, 75, 7)
    },
    "YCQUiTree\0onChanged\0\0YCQUiTree*\0pSelf\0"
    "onItemChanged\0QTreeWidgetItem*\0pItem\0"
    "iColume\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YCQUiTree[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    2,   27,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,

       0        // eod
};

void YCQUiTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YCQUiTree *_t = static_cast<YCQUiTree *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< YCQUiTree*(*)>(_a[1]))); break;
        case 1: _t->onItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< YCQUiTree* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (YCQUiTree::*_t)(YCQUiTree * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YCQUiTree::onChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject YCQUiTree::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_YCQUiTree.data,
      qt_meta_data_YCQUiTree,  qt_static_metacall, 0, 0}
};


const QMetaObject *YCQUiTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YCQUiTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YCQUiTree.stringdata))
        return static_cast<void*>(const_cast< YCQUiTree*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int YCQUiTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void YCQUiTree::onChanged(YCQUiTree * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
