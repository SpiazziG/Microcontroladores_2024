/****************************************************************************
** Meta object code from reading C++ file 'qform1.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QT/QTBackup/qform1.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qform1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
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
struct qt_meta_stringdata_CLASSQForm1ENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQForm1ENDCLASS = QtMocHelpers::stringData(
    "QForm1",
    "maxMinValues",
    "",
    "uint16_t",
    "min",
    "max",
    "Initialize",
    "OnQTimer1",
    "OnRxChar",
    "eventFilter",
    "watched",
    "QEvent*",
    "event",
    "on_OpenPortButton_clicked",
    "on_ClearButton_clicked",
    "on_SendCommandButton_clicked",
    "InitPaintBox",
    "DrawBackground",
    "SendCMD",
    "uint8_t*",
    "buf",
    "uint8_t",
    "length",
    "DecodeCmd",
    "rxBuf",
    "EngineTest",
    "int32_t",
    "Eng1",
    "Eng2",
    "on_aliveButton_clicked",
    "on_OpenWifiButton_clicked",
    "onRxUDP",
    "DecodeHeader",
    "count",
    "Heartbeat",
    "DrawMovement",
    "Integrate",
    "on_powerButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQForm1ENDCLASS_t {
    uint offsetsAndSizes[76];
    char stringdata0[7];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[4];
    char stringdata5[4];
    char stringdata6[11];
    char stringdata7[10];
    char stringdata8[9];
    char stringdata9[12];
    char stringdata10[8];
    char stringdata11[8];
    char stringdata12[6];
    char stringdata13[26];
    char stringdata14[23];
    char stringdata15[29];
    char stringdata16[13];
    char stringdata17[15];
    char stringdata18[8];
    char stringdata19[9];
    char stringdata20[4];
    char stringdata21[8];
    char stringdata22[7];
    char stringdata23[10];
    char stringdata24[6];
    char stringdata25[11];
    char stringdata26[8];
    char stringdata27[5];
    char stringdata28[5];
    char stringdata29[23];
    char stringdata30[26];
    char stringdata31[8];
    char stringdata32[13];
    char stringdata33[6];
    char stringdata34[10];
    char stringdata35[13];
    char stringdata36[10];
    char stringdata37[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQForm1ENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQForm1ENDCLASS_t qt_meta_stringdata_CLASSQForm1ENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "QForm1"
        QT_MOC_LITERAL(7, 12),  // "maxMinValues"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 8),  // "uint16_t"
        QT_MOC_LITERAL(30, 3),  // "min"
        QT_MOC_LITERAL(34, 3),  // "max"
        QT_MOC_LITERAL(38, 10),  // "Initialize"
        QT_MOC_LITERAL(49, 9),  // "OnQTimer1"
        QT_MOC_LITERAL(59, 8),  // "OnRxChar"
        QT_MOC_LITERAL(68, 11),  // "eventFilter"
        QT_MOC_LITERAL(80, 7),  // "watched"
        QT_MOC_LITERAL(88, 7),  // "QEvent*"
        QT_MOC_LITERAL(96, 5),  // "event"
        QT_MOC_LITERAL(102, 25),  // "on_OpenPortButton_clicked"
        QT_MOC_LITERAL(128, 22),  // "on_ClearButton_clicked"
        QT_MOC_LITERAL(151, 28),  // "on_SendCommandButton_clicked"
        QT_MOC_LITERAL(180, 12),  // "InitPaintBox"
        QT_MOC_LITERAL(193, 14),  // "DrawBackground"
        QT_MOC_LITERAL(208, 7),  // "SendCMD"
        QT_MOC_LITERAL(216, 8),  // "uint8_t*"
        QT_MOC_LITERAL(225, 3),  // "buf"
        QT_MOC_LITERAL(229, 7),  // "uint8_t"
        QT_MOC_LITERAL(237, 6),  // "length"
        QT_MOC_LITERAL(244, 9),  // "DecodeCmd"
        QT_MOC_LITERAL(254, 5),  // "rxBuf"
        QT_MOC_LITERAL(260, 10),  // "EngineTest"
        QT_MOC_LITERAL(271, 7),  // "int32_t"
        QT_MOC_LITERAL(279, 4),  // "Eng1"
        QT_MOC_LITERAL(284, 4),  // "Eng2"
        QT_MOC_LITERAL(289, 22),  // "on_aliveButton_clicked"
        QT_MOC_LITERAL(312, 25),  // "on_OpenWifiButton_clicked"
        QT_MOC_LITERAL(338, 7),  // "onRxUDP"
        QT_MOC_LITERAL(346, 12),  // "DecodeHeader"
        QT_MOC_LITERAL(359, 5),  // "count"
        QT_MOC_LITERAL(365, 9),  // "Heartbeat"
        QT_MOC_LITERAL(375, 12),  // "DrawMovement"
        QT_MOC_LITERAL(388, 9),  // "Integrate"
        QT_MOC_LITERAL(398, 22)   // "on_powerButton_clicked"
    },
    "QForm1",
    "maxMinValues",
    "",
    "uint16_t",
    "min",
    "max",
    "Initialize",
    "OnQTimer1",
    "OnRxChar",
    "eventFilter",
    "watched",
    "QEvent*",
    "event",
    "on_OpenPortButton_clicked",
    "on_ClearButton_clicked",
    "on_SendCommandButton_clicked",
    "InitPaintBox",
    "DrawBackground",
    "SendCMD",
    "uint8_t*",
    "buf",
    "uint8_t",
    "length",
    "DecodeCmd",
    "rxBuf",
    "EngineTest",
    "int32_t",
    "Eng1",
    "Eng2",
    "on_aliveButton_clicked",
    "on_OpenWifiButton_clicked",
    "onRxUDP",
    "DecodeHeader",
    "count",
    "Heartbeat",
    "DrawMovement",
    "Integrate",
    "on_powerButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQForm1ENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  140,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  145,    2, 0x08,    4 /* Private */,
       7,    0,  146,    2, 0x08,    5 /* Private */,
       8,    0,  147,    2, 0x08,    6 /* Private */,
       9,    2,  148,    2, 0x08,    7 /* Private */,
      13,    0,  153,    2, 0x08,   10 /* Private */,
      14,    0,  154,    2, 0x08,   11 /* Private */,
      15,    0,  155,    2, 0x08,   12 /* Private */,
      16,    0,  156,    2, 0x08,   13 /* Private */,
      17,    0,  157,    2, 0x08,   14 /* Private */,
      18,    2,  158,    2, 0x08,   15 /* Private */,
      23,    1,  163,    2, 0x08,   18 /* Private */,
      25,    2,  166,    2, 0x08,   20 /* Private */,
      29,    0,  171,    2, 0x08,   23 /* Private */,
      30,    0,  172,    2, 0x08,   24 /* Private */,
      31,    0,  173,    2, 0x08,   25 /* Private */,
      32,    2,  174,    2, 0x08,   26 /* Private */,
      34,    0,  179,    2, 0x08,   29 /* Private */,
      35,    0,  180,    2, 0x08,   30 /* Private */,
      36,    0,  181,    2, 0x08,   31 /* Private */,
      37,    0,  182,    2, 0x08,   32 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 11,   10,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21,   20,   22,
    QMetaType::Void, 0x80000000 | 19,   24,
    QMetaType::Void, 0x80000000 | 26, 0x80000000 | 26,   27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, QMetaType::Int,   20,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QForm1::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSQForm1ENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQForm1ENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQForm1ENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QForm1, std::true_type>,
        // method 'maxMinValues'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        // method 'Initialize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnQTimer1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnRxChar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'eventFilter'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>,
        // method 'on_OpenPortButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ClearButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SendCommandButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'InitPaintBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DrawBackground'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SendCMD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t *, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        // method 'DecodeCmd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t *, std::false_type>,
        // method 'EngineTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<int32_t, std::false_type>,
        // method 'on_aliveButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_OpenWifiButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRxUDP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DecodeHeader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Heartbeat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DrawMovement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Integrate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_powerButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QForm1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QForm1 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->maxMinValues((*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2]))); break;
        case 1: _t->Initialize(); break;
        case 2: _t->OnQTimer1(); break;
        case 3: _t->OnRxChar(); break;
        case 4: { bool _r = _t->eventFilter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->on_OpenPortButton_clicked(); break;
        case 6: _t->on_ClearButton_clicked(); break;
        case 7: _t->on_SendCommandButton_clicked(); break;
        case 8: _t->InitPaintBox(); break;
        case 9: _t->DrawBackground(); break;
        case 10: _t->SendCMD((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 11: _t->DecodeCmd((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1]))); break;
        case 12: _t->EngineTest((*reinterpret_cast< std::add_pointer_t<int32_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int32_t>>(_a[2]))); break;
        case 13: _t->on_aliveButton_clicked(); break;
        case 14: _t->on_OpenWifiButton_clicked(); break;
        case 15: _t->onRxUDP(); break;
        case 16: _t->DecodeHeader((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 17: _t->Heartbeat(); break;
        case 18: _t->DrawMovement(); break;
        case 19: _t->Integrate(); break;
        case 20: _t->on_powerButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QForm1::*)(uint16_t , uint16_t );
            if (_t _q_method = &QForm1::maxMinValues; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *QForm1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QForm1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQForm1ENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QForm1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void QForm1::maxMinValues(uint16_t _t1, uint16_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
