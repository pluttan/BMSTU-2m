/****************************************************************************
** Meta object code from reading C++ file 'notebook.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dz3_2/notebook.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notebook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_notebook_t {
    uint offsetsAndSizes[18];
    char stringdata0[9];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[24];
    char stringdata5[5];
    char stringdata6[35];
    char stringdata7[2];
    char stringdata8[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_notebook_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_notebook_t qt_meta_stringdata_notebook = {
    {
        QT_MOC_LITERAL(0, 8),  // "notebook"
        QT_MOC_LITERAL(9, 17),  // "on_choose_clicked"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 18),  // "on_save_as_clicked"
        QT_MOC_LITERAL(47, 23),  // "on_lineEdit_textChanged"
        QT_MOC_LITERAL(71, 4),  // "arg1"
        QT_MOC_LITERAL(76, 34),  // "on_fontComboBox_currentFontCh..."
        QT_MOC_LITERAL(111, 1),  // "f"
        QT_MOC_LITERAL(113, 15)   // "on_save_clicked"
    },
    "notebook",
    "on_choose_clicked",
    "",
    "on_save_as_clicked",
    "on_lineEdit_textChanged",
    "arg1",
    "on_fontComboBox_currentFontChanged",
    "f",
    "on_save_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_notebook[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    1,   46,    2, 0x08,    3 /* Private */,
       6,    1,   49,    2, 0x08,    5 /* Private */,
       8,    0,   52,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QFont,    7,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject notebook::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_notebook.offsetsAndSizes,
    qt_meta_data_notebook,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_notebook_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<notebook, std::true_type>,
        // method 'on_choose_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_as_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_fontComboBox_currentFontChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QFont &, std::false_type>,
        // method 'on_save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void notebook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<notebook *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_choose_clicked(); break;
        case 1: _t->on_save_as_clicked(); break;
        case 2: _t->on_lineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_fontComboBox_currentFontChanged((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 4: _t->on_save_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *notebook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *notebook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_notebook.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int notebook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
