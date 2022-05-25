/****************************************************************************
** Meta object code from reading C++ file 'interfaceGraphique.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../interfaceGraphique.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interfaceGraphique.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Affichage__InterfaceGraphique_t {
    QByteArrayData data[8];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Affichage__InterfaceGraphique_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Affichage__InterfaceGraphique_t qt_meta_stringdata_Affichage__InterfaceGraphique = {
    {
QT_MOC_LITERAL(0, 0, 29), // "Affichage::InterfaceGraphique"
QT_MOC_LITERAL(1, 30, 30), // "afficherMenuSelectionEchiquier"
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 21), // "afficherMenuPrincipal"
QT_MOC_LITERAL(4, 84, 17), // "afficherEchiquier"
QT_MOC_LITERAL(5, 102, 11), // "std::string"
QT_MOC_LITERAL(6, 114, 11), // "nomStrategy"
QT_MOC_LITERAL(7, 126, 18) // "afficherReferences"

    },
    "Affichage::InterfaceGraphique\0"
    "afficherMenuSelectionEchiquier\0\0"
    "afficherMenuPrincipal\0afficherEchiquier\0"
    "std::string\0nomStrategy\0afficherReferences"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Affichage__InterfaceGraphique[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void Affichage::InterfaceGraphique::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InterfaceGraphique *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->afficherMenuSelectionEchiquier(); break;
        case 1: _t->afficherMenuPrincipal(); break;
        case 2: _t->afficherEchiquier((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->afficherReferences(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Affichage::InterfaceGraphique::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Affichage__InterfaceGraphique.data,
    qt_meta_data_Affichage__InterfaceGraphique,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Affichage::InterfaceGraphique::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Affichage::InterfaceGraphique::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Affichage__InterfaceGraphique.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Affichage::InterfaceGraphique::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
