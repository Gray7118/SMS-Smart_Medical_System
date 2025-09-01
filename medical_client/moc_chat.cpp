/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chat_t {
    QByteArrayData data[19];
    char stringdata0[323];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chat_t qt_meta_stringdata_Chat = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Chat"
QT_MOC_LITERAL(1, 5, 15), // "returnToProfile"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(4, 46, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(5, 68, 14), // "startVideoCall"
QT_MOC_LITERAL(6, 83, 21), // "handleSocketReadyRead"
QT_MOC_LITERAL(7, 105, 20), // "handleReceiveMessage"
QT_MOC_LITERAL(8, 126, 7), // "Message"
QT_MOC_LITERAL(9, 134, 3), // "msg"
QT_MOC_LITERAL(10, 138, 17), // "handleSendSuccess"
QT_MOC_LITERAL(11, 156, 21), // "handleReceiverOffline"
QT_MOC_LITERAL(12, 178, 16), // "handleRetHistory"
QT_MOC_LITERAL(13, 195, 25), // "handleUpdateIsReadSuccess"
QT_MOC_LITERAL(14, 221, 22), // "handleVideoCallRequest"
QT_MOC_LITERAL(15, 244, 21), // "handleVideoCallAccept"
QT_MOC_LITERAL(16, 266, 21), // "handleVideoCallReject"
QT_MOC_LITERAL(17, 288, 18), // "handleVideoCallEnd"
QT_MOC_LITERAL(18, 307, 15) // "handleVideoData"

    },
    "Chat\0returnToProfile\0\0on_returnButton_clicked\0"
    "on_sendButton_clicked\0startVideoCall\0"
    "handleSocketReadyRead\0handleReceiveMessage\0"
    "Message\0msg\0handleSendSuccess\0"
    "handleReceiverOffline\0handleRetHistory\0"
    "handleUpdateIsReadSuccess\0"
    "handleVideoCallRequest\0handleVideoCallAccept\0"
    "handleVideoCallReject\0handleVideoCallEnd\0"
    "handleVideoData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    1,   94,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      12,    1,  103,    2, 0x08 /* Private */,
      13,    1,  106,    2, 0x08 /* Private */,
      14,    1,  109,    2, 0x08 /* Private */,
      15,    1,  112,    2, 0x08 /* Private */,
      16,    1,  115,    2, 0x08 /* Private */,
      17,    1,  118,    2, 0x08 /* Private */,
      18,    1,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void Chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Chat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnToProfile(); break;
        case 1: _t->on_returnButton_clicked(); break;
        case 2: _t->on_sendButton_clicked(); break;
        case 3: _t->startVideoCall(); break;
        case 4: _t->handleSocketReadyRead(); break;
        case 5: _t->handleReceiveMessage((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 6: _t->handleSendSuccess((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 7: _t->handleReceiverOffline((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 8: _t->handleRetHistory((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 9: _t->handleUpdateIsReadSuccess((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 10: _t->handleVideoCallRequest((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 11: _t->handleVideoCallAccept((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 12: _t->handleVideoCallReject((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 13: _t->handleVideoCallEnd((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        case 14: _t->handleVideoData((*reinterpret_cast< const Message(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Chat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chat::returnToProfile)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Chat::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Chat.data,
    qt_meta_data_Chat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chat.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Chat::returnToProfile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
