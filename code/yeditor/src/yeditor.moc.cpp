/****************************************************************************
** Meta object code from reading C++ file 'yeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/yeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YEditor_t {
    QByteArrayData data[18];
    char stringdata[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_YEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_YEditor_t qt_meta_stringdata_YEditor = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 13),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 13),
QT_MOC_LITERAL(4, 37, 15),
QT_MOC_LITERAL(5, 53, 13),
QT_MOC_LITERAL(6, 67, 20),
QT_MOC_LITERAL(7, 88, 16),
QT_MOC_LITERAL(8, 105, 9),
QT_MOC_LITERAL(9, 115, 6),
QT_MOC_LITERAL(10, 122, 23),
QT_MOC_LITERAL(11, 146, 4),
QT_MOC_LITERAL(12, 151, 19),
QT_MOC_LITERAL(13, 171, 32),
QT_MOC_LITERAL(14, 204, 37),
QT_MOC_LITERAL(15, 242, 37),
QT_MOC_LITERAL(16, 280, 37),
QT_MOC_LITERAL(17, 318, 38)
    },
    "YEditor\0onClickedOpen\0\0onClickedSave\0"
    "onClickedExport\0onClickedSync\0"
    "onSelectedFormatTree\0QTreeWidgetItem*\0"
    "pTreeItem\0iIndex\0onFormatTreeContextMenu\0"
    "oPos\0onUiTreeContextMenu\0"
    "onClickedFormatMenuItem_ShowHide\0"
    "onClickedUiWidgetMenuItem_CreateScene\0"
    "onClickedUiWidgetMenuItem_CreatePanel\0"
    "onClickedUiWidgetMenuItem_CreateImage\0"
    "onClickedUiWidgetMenuItem_CreateButton\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a,
       3,    0,   75,    2, 0x0a,
       4,    0,   76,    2, 0x0a,
       5,    0,   77,    2, 0x0a,
       6,    2,   78,    2, 0x0a,
      10,    1,   83,    2, 0x0a,
      12,    1,   86,    2, 0x0a,
      13,    0,   89,    2, 0x0a,
      14,    0,   90,    2, 0x0a,
      15,    0,   91,    2, 0x0a,
      16,    0,   92,    2, 0x0a,
      17,    0,   93,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::QPoint,   11,
    QMetaType::Void, QMetaType::QPoint,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void YEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YEditor *_t = static_cast<YEditor *>(_o);
        switch (_id) {
        case 0: _t->onClickedOpen(); break;
        case 1: _t->onClickedSave(); break;
        case 2: _t->onClickedExport(); break;
        case 3: _t->onClickedSync(); break;
        case 4: _t->onSelectedFormatTree((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->onFormatTreeContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->onUiTreeContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->onClickedFormatMenuItem_ShowHide(); break;
        case 8: _t->onClickedUiWidgetMenuItem_CreateScene(); break;
        case 9: _t->onClickedUiWidgetMenuItem_CreatePanel(); break;
        case 10: _t->onClickedUiWidgetMenuItem_CreateImage(); break;
        case 11: _t->onClickedUiWidgetMenuItem_CreateButton(); break;
        default: ;
        }
    }
}

const QMetaObject YEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_YEditor.data,
      qt_meta_data_YEditor,  qt_static_metacall, 0, 0}
};


const QMetaObject *YEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_YEditor.stringdata))
        return static_cast<void*>(const_cast< YEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int YEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
