/****************************************************************************
** Meta object code from reading C++ file 'volcanomission.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../volcanomission.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'volcanomission.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVolcanoMissionENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVolcanoMissionENDCLASS = QtMocHelpers::stringData(
    "VolcanoMission",
    "handleIntroDialogue",
    "",
    "handleLavaTunnelPath",
    "handleSteamChamberPath",
    "handlePuzzle",
    "handleFight",
    "handleFightEnded"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVolcanoMissionENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   53,    2, 0x0a,    4 /* Public */,
       6,    0,   54,    2, 0x0a,    5 /* Public */,
       7,    1,   55,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject VolcanoMission::staticMetaObject = { {
    QMetaObject::SuperData::link<Mission::staticMetaObject>(),
    qt_meta_stringdata_CLASSVolcanoMissionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVolcanoMissionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVolcanoMissionENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VolcanoMission, std::true_type>,
        // method 'handleIntroDialogue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleLavaTunnelPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSteamChamberPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePuzzle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleFight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleFightEnded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void VolcanoMission::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VolcanoMission *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleIntroDialogue(); break;
        case 1: _t->handleLavaTunnelPath(); break;
        case 2: _t->handleSteamChamberPath(); break;
        case 3: _t->handlePuzzle(); break;
        case 4: _t->handleFight(); break;
        case 5: _t->handleFightEnded((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *VolcanoMission::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VolcanoMission::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVolcanoMissionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Mission::qt_metacast(_clname);
}

int VolcanoMission::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Mission::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
