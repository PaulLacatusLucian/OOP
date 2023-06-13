/****************************************************************************
** Meta object code from reading C++ file 'ScooterUIWidgetClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ScooterUIWidgetClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScooterUIWidgetClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScooterUIWidgetClient_t {
    QByteArrayData data[9];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScooterUIWidgetClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScooterUIWidgetClient_t qt_meta_stringdata_ScooterUIWidgetClient = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ScooterUIWidgetClient"
QT_MOC_LITERAL(1, 22, 21), // "onSearchButtonClicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 30), // "onKilometerFilterButtonClicked"
QT_MOC_LITERAL(4, 76, 24), // "onAgeFilterButtonClicked"
QT_MOC_LITERAL(5, 101, 22), // "onReserveButtonClicked"
QT_MOC_LITERAL(6, 124, 23), // "onAvalibleButtonClicked"
QT_MOC_LITERAL(7, 148, 19), // "onParkButtonClicked"
QT_MOC_LITERAL(8, 168, 21) // "onGoBackButtonClicked"

    },
    "ScooterUIWidgetClient\0onSearchButtonClicked\0"
    "\0onKilometerFilterButtonClicked\0"
    "onAgeFilterButtonClicked\0"
    "onReserveButtonClicked\0onAvalibleButtonClicked\0"
    "onParkButtonClicked\0onGoBackButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScooterUIWidgetClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScooterUIWidgetClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScooterUIWidgetClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSearchButtonClicked(); break;
        case 1: _t->onKilometerFilterButtonClicked(); break;
        case 2: _t->onAgeFilterButtonClicked(); break;
        case 3: _t->onReserveButtonClicked(); break;
        case 4: _t->onAvalibleButtonClicked(); break;
        case 5: _t->onParkButtonClicked(); break;
        case 6: _t->onGoBackButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ScooterUIWidgetClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ScooterUIWidgetClient.data,
    qt_meta_data_ScooterUIWidgetClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScooterUIWidgetClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScooterUIWidgetClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScooterUIWidgetClient.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ScooterUIWidgetClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
