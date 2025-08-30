/****************************************************************************
** Meta object code from reading C++ file 'patientprofile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../patientprofile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientprofile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PatientProfile_t {
    QByteArrayData data[12];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PatientProfile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PatientProfile_t qt_meta_stringdata_PatientProfile = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PatientProfile"
QT_MOC_LITERAL(1, 15, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "on_chatButton_clicked"
QT_MOC_LITERAL(4, 60, 28), // "on_appointmentButton_clicked"
QT_MOC_LITERAL(5, 89, 23), // "on_healthButton_clicked"
QT_MOC_LITERAL(6, 113, 23), // "on_doctorButton_clicked"
QT_MOC_LITERAL(7, 137, 30), // "on_medicalRecordButton_clicked"
QT_MOC_LITERAL(8, 168, 24), // "on_profileButton_clicked"
QT_MOC_LITERAL(9, 193, 29), // "on_prescriptionButton_clicked"
QT_MOC_LITERAL(10, 223, 32), // "on_appointmentCaseButton_clicked"
QT_MOC_LITERAL(11, 256, 25) // "on_scheduleButton_clicked"

    },
    "PatientProfile\0on_quitButton_clicked\0"
    "\0on_chatButton_clicked\0"
    "on_appointmentButton_clicked\0"
    "on_healthButton_clicked\0on_doctorButton_clicked\0"
    "on_medicalRecordButton_clicked\0"
    "on_profileButton_clicked\0"
    "on_prescriptionButton_clicked\0"
    "on_appointmentCaseButton_clicked\0"
    "on_scheduleButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PatientProfile[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PatientProfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PatientProfile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_quitButton_clicked(); break;
        case 1: _t->on_chatButton_clicked(); break;
        case 2: _t->on_appointmentButton_clicked(); break;
        case 3: _t->on_healthButton_clicked(); break;
        case 4: _t->on_doctorButton_clicked(); break;
        case 5: _t->on_medicalRecordButton_clicked(); break;
        case 6: _t->on_profileButton_clicked(); break;
        case 7: _t->on_prescriptionButton_clicked(); break;
        case 8: _t->on_appointmentCaseButton_clicked(); break;
        case 9: _t->on_scheduleButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PatientProfile::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_PatientProfile.data,
    qt_meta_data_PatientProfile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PatientProfile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PatientProfile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PatientProfile.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PatientProfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
