/****************************************************************************
** Meta object code from reading C++ file 'schoolevacuationmission.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../schoolevacuationmission.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schoolevacuationmission.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSchoolEvacuationMissionENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSchoolEvacuationMissionENDCLASS = QtMocHelpers::stringData(
    "SchoolEvacuationMission",
    "handleIntroDialogue",
    "",
    "handleDecisionMaking",
    "handleEvacuation",
    "handleMaterialSecuring",
    "handleMissionOutcome",
    "success"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSchoolEvacuationMissionENDCLASS[] = {

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
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject SchoolEvacuationMission::staticMetaObject = { {
    QMetaObject::SuperData::link<Mission::staticMetaObject>(),
    qt_meta_stringdata_CLASSSchoolEvacuationMissionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSchoolEvacuationMissionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSchoolEvacuationMissionENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SchoolEvacuationMission, std::true_type>,
        // method 'handleIntroDialogue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleDecisionMaking'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleEvacuation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleMaterialSecuring'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleMissionOutcome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void SchoolEvacuationMission::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SchoolEvacuationMission *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleIntroDialogue(); break;
        case 1: _t->handleDecisionMaking(); break;
        case 2: _t->handleEvacuation(); break;
        case 3: _t->handleMaterialSecuring(); break;
        case 4: _t->handleMissionOutcome((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *SchoolEvacuationMission::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SchoolEvacuationMission::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSchoolEvacuationMissionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Mission::qt_metacast(_clname);
}

int SchoolEvacuationMission::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
