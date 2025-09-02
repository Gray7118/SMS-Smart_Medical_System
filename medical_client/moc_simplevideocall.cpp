/****************************************************************************
** Meta object code from reading C++ file 'simplevideocall.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "simplevideocall.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simplevideocall.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimpleVideoCall_t {
    QByteArrayData data[9];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimpleVideoCall_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimpleVideoCall_t qt_meta_stringdata_SimpleVideoCall = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SimpleVideoCall"
QT_MOC_LITERAL(1, 16, 19), // "captureAndSendImage"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "onHangupClicked"
QT_MOC_LITERAL(4, 53, 15), // "onImageCaptured"
QT_MOC_LITERAL(5, 69, 2), // "id"
QT_MOC_LITERAL(6, 72, 5), // "image"
QT_MOC_LITERAL(7, 78, 14), // "readCameraData"
QT_MOC_LITERAL(8, 93, 17) // "testCameraDisplay"

    },
    "SimpleVideoCall\0captureAndSendImage\0"
    "\0onHangupClicked\0onImageCaptured\0id\0"
    "image\0readCameraData\0testCameraDisplay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimpleVideoCall[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    2,   41,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SimpleVideoCall::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SimpleVideoCall *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->captureAndSendImage(); break;
        case 1: _t->onHangupClicked(); break;
        case 2: _t->onImageCaptured((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 3: _t->readCameraData(); break;
<<<<<<< HEAD
        //case 4: _t->testCameraDisplay(); break;
=======
//        case 4: _t->testCameraDisplay(); break;
>>>>>>> main
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SimpleVideoCall::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_SimpleVideoCall.data,
    qt_meta_data_SimpleVideoCall,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SimpleVideoCall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimpleVideoCall::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleVideoCall.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SimpleVideoCall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
