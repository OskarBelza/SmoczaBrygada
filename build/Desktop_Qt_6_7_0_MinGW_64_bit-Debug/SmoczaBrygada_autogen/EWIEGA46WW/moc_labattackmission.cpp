/****************************************************************************
** Meta object code from reading C++ file 'labattackmission.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../labattackmission.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labattackmission.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSLabAttackMissionENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSLabAttackMissionENDCLASS = QtMocHelpers::stringData(
    "LabAttackMission",
    "handleIntroDialogue",
    "",
    "handleRescueScientists",
    "handleSecureDocuments",
    "handleFight",
    "handleFightEnded"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLabAttackMissionENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    0,   46,    2, 0x0a,    3 /* Public */,
       5,    0,   47,    2, 0x0a,    4 /* Public */,
       6,    1,   48,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject LabAttackMission::staticMetaObject = { {
    QMetaObject::SuperData::link<Mission::staticMetaObject>(),
    qt_meta_stringdata_CLASSLabAttackMissionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLabAttackMissionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLabAttackMissionENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LabAttackMission, std::true_type>,
        // method 'handleIntroDialogue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleRescueScientists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSecureDocuments'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleFight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleFightEnded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void LabAttackMission::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LabAttackMission *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleIntroDialogue(); break;
        case 1: _t->handleRescueScientists(); break;
        case 2: _t->handleSecureDocuments(); break;
        case 3: _t->handleFight(); break;
        case 4: _t->handleFightEnded((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *LabAttackMission::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabAttackMission::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLabAttackMissionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Mission::qt_metacast(_clname);
}

int LabAttackMission::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Mission::qt_metacall(_c, _id, _a);
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
