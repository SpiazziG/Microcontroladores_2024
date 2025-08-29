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
    "updateMotorLabel",
    "value",
    "Initialize",
    "OnQTimer1",
    "OnRxChar",
    "eventFilter",
    "watched",
    "QEvent*",
    "event",
    "on_OpenPortButton_clicked",
    "on_buttonClear_clicked",
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
    "on_powerButton_clicked",
    "on_debugTabButton_clicked",
    "on_telemetryTabButton_clicked",
    "on_homeTabButton_clicked",
    "on_PIDTabButton_clicked",
    "on_setTurnPIDButton_clicked",
    "on_setWallPIDButton_clicked",
    "on_pwmConfigButton_clicked",
    "on_pwmPrescalerConfig_textChanged",
    "arg1",
    "on_pwmPeriodConfig_textChanged",
    "updateResultingFrequency",
    "formatFrequency",
    "frequencyHz",
    "on_readTurnPIDButton_clicked",
    "on_readWallPIDButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQForm1ENDCLASS_t {
    uint offsetsAndSizes[108];
    char stringdata0[7];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[4];
    char stringdata5[4];
    char stringdata6[17];
    char stringdata7[6];
    char stringdata8[11];
    char stringdata9[10];
    char stringdata10[9];
    char stringdata11[12];
    char stringdata12[8];
    char stringdata13[8];
    char stringdata14[6];
    char stringdata15[26];
    char stringdata16[23];
    char stringdata17[29];
    char stringdata18[13];
    char stringdata19[15];
    char stringdata20[8];
    char stringdata21[9];
    char stringdata22[4];
    char stringdata23[8];
    char stringdata24[7];
    char stringdata25[10];
    char stringdata26[6];
    char stringdata27[11];
    char stringdata28[5];
    char stringdata29[5];
    char stringdata30[23];
    char stringdata31[26];
    char stringdata32[8];
    char stringdata33[13];
    char stringdata34[6];
    char stringdata35[10];
    char stringdata36[13];
    char stringdata37[10];
    char stringdata38[23];
    char stringdata39[26];
    char stringdata40[30];
    char stringdata41[25];
    char stringdata42[24];
    char stringdata43[28];
    char stringdata44[28];
    char stringdata45[27];
    char stringdata46[34];
    char stringdata47[5];
    char stringdata48[31];
    char stringdata49[25];
    char stringdata50[16];
    char stringdata51[12];
    char stringdata52[29];
    char stringdata53[29];
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
        QT_MOC_LITERAL(38, 16),  // "updateMotorLabel"
        QT_MOC_LITERAL(55, 5),  // "value"
        QT_MOC_LITERAL(61, 10),  // "Initialize"
        QT_MOC_LITERAL(72, 9),  // "OnQTimer1"
        QT_MOC_LITERAL(82, 8),  // "OnRxChar"
        QT_MOC_LITERAL(91, 11),  // "eventFilter"
        QT_MOC_LITERAL(103, 7),  // "watched"
        QT_MOC_LITERAL(111, 7),  // "QEvent*"
        QT_MOC_LITERAL(119, 5),  // "event"
        QT_MOC_LITERAL(125, 25),  // "on_OpenPortButton_clicked"
        QT_MOC_LITERAL(151, 22),  // "on_buttonClear_clicked"
        QT_MOC_LITERAL(174, 28),  // "on_SendCommandButton_clicked"
        QT_MOC_LITERAL(203, 12),  // "InitPaintBox"
        QT_MOC_LITERAL(216, 14),  // "DrawBackground"
        QT_MOC_LITERAL(231, 7),  // "SendCMD"
        QT_MOC_LITERAL(239, 8),  // "uint8_t*"
        QT_MOC_LITERAL(248, 3),  // "buf"
        QT_MOC_LITERAL(252, 7),  // "uint8_t"
        QT_MOC_LITERAL(260, 6),  // "length"
        QT_MOC_LITERAL(267, 9),  // "DecodeCmd"
        QT_MOC_LITERAL(277, 5),  // "rxBuf"
        QT_MOC_LITERAL(283, 10),  // "EngineTest"
        QT_MOC_LITERAL(294, 4),  // "Eng1"
        QT_MOC_LITERAL(299, 4),  // "Eng2"
        QT_MOC_LITERAL(304, 22),  // "on_aliveButton_clicked"
        QT_MOC_LITERAL(327, 25),  // "on_OpenWifiButton_clicked"
        QT_MOC_LITERAL(353, 7),  // "onRxUDP"
        QT_MOC_LITERAL(361, 12),  // "DecodeHeader"
        QT_MOC_LITERAL(374, 5),  // "count"
        QT_MOC_LITERAL(380, 9),  // "Heartbeat"
        QT_MOC_LITERAL(390, 12),  // "DrawMovement"
        QT_MOC_LITERAL(403, 9),  // "Integrate"
        QT_MOC_LITERAL(413, 22),  // "on_powerButton_clicked"
        QT_MOC_LITERAL(436, 25),  // "on_debugTabButton_clicked"
        QT_MOC_LITERAL(462, 29),  // "on_telemetryTabButton_clicked"
        QT_MOC_LITERAL(492, 24),  // "on_homeTabButton_clicked"
        QT_MOC_LITERAL(517, 23),  // "on_PIDTabButton_clicked"
        QT_MOC_LITERAL(541, 27),  // "on_setTurnPIDButton_clicked"
        QT_MOC_LITERAL(569, 27),  // "on_setWallPIDButton_clicked"
        QT_MOC_LITERAL(597, 26),  // "on_pwmConfigButton_clicked"
        QT_MOC_LITERAL(624, 33),  // "on_pwmPrescalerConfig_textCha..."
        QT_MOC_LITERAL(658, 4),  // "arg1"
        QT_MOC_LITERAL(663, 30),  // "on_pwmPeriodConfig_textChanged"
        QT_MOC_LITERAL(694, 24),  // "updateResultingFrequency"
        QT_MOC_LITERAL(719, 15),  // "formatFrequency"
        QT_MOC_LITERAL(735, 11),  // "frequencyHz"
        QT_MOC_LITERAL(747, 28),  // "on_readTurnPIDButton_clicked"
        QT_MOC_LITERAL(776, 28)   // "on_readWallPIDButton_clicked"
    },
    "QForm1",
    "maxMinValues",
    "",
    "uint16_t",
    "min",
    "max",
    "updateMotorLabel",
    "value",
    "Initialize",
    "OnQTimer1",
    "OnRxChar",
    "eventFilter",
    "watched",
    "QEvent*",
    "event",
    "on_OpenPortButton_clicked",
    "on_buttonClear_clicked",
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
    "on_powerButton_clicked",
    "on_debugTabButton_clicked",
    "on_telemetryTabButton_clicked",
    "on_homeTabButton_clicked",
    "on_PIDTabButton_clicked",
    "on_setTurnPIDButton_clicked",
    "on_setWallPIDButton_clicked",
    "on_pwmConfigButton_clicked",
    "on_pwmPrescalerConfig_textChanged",
    "arg1",
    "on_pwmPeriodConfig_textChanged",
    "updateResultingFrequency",
    "formatFrequency",
    "frequencyHz",
    "on_readTurnPIDButton_clicked",
    "on_readWallPIDButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQForm1ENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  224,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,  229,    2, 0x0a,    4 /* Public */,
       8,    0,  232,    2, 0x08,    6 /* Private */,
       9,    0,  233,    2, 0x08,    7 /* Private */,
      10,    0,  234,    2, 0x08,    8 /* Private */,
      11,    2,  235,    2, 0x08,    9 /* Private */,
      15,    0,  240,    2, 0x08,   12 /* Private */,
      16,    0,  241,    2, 0x08,   13 /* Private */,
      17,    0,  242,    2, 0x08,   14 /* Private */,
      18,    0,  243,    2, 0x08,   15 /* Private */,
      19,    0,  244,    2, 0x08,   16 /* Private */,
      20,    2,  245,    2, 0x08,   17 /* Private */,
      25,    1,  250,    2, 0x08,   20 /* Private */,
      27,    2,  253,    2, 0x08,   22 /* Private */,
      30,    0,  258,    2, 0x08,   25 /* Private */,
      31,    0,  259,    2, 0x08,   26 /* Private */,
      32,    0,  260,    2, 0x08,   27 /* Private */,
      33,    2,  261,    2, 0x08,   28 /* Private */,
      35,    0,  266,    2, 0x08,   31 /* Private */,
      36,    0,  267,    2, 0x08,   32 /* Private */,
      37,    0,  268,    2, 0x08,   33 /* Private */,
      38,    0,  269,    2, 0x08,   34 /* Private */,
      39,    0,  270,    2, 0x08,   35 /* Private */,
      40,    0,  271,    2, 0x08,   36 /* Private */,
      41,    0,  272,    2, 0x08,   37 /* Private */,
      42,    0,  273,    2, 0x08,   38 /* Private */,
      43,    0,  274,    2, 0x08,   39 /* Private */,
      44,    0,  275,    2, 0x08,   40 /* Private */,
      45,    0,  276,    2, 0x08,   41 /* Private */,
      46,    1,  277,    2, 0x08,   42 /* Private */,
      48,    1,  280,    2, 0x08,   44 /* Private */,
      49,    0,  283,    2, 0x08,   46 /* Private */,
      50,    1,  284,    2, 0x08,   47 /* Private */,
      52,    0,  287,    2, 0x08,   49 /* Private */,
      53,    0,  288,    2, 0x08,   50 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 13,   12,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21, 0x80000000 | 23,   22,   24,
    QMetaType::Void, 0x80000000 | 21,   26,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 23,   28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21, QMetaType::Int,   22,   34,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Double,   51,
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
        // method 'updateMotorLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
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
        // method 'on_buttonClear_clicked'
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
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_debugTabButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_telemetryTabButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_homeTabButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PIDTabButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_setTurnPIDButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_setWallPIDButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pwmConfigButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pwmPrescalerConfig_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pwmPeriodConfig_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateResultingFrequency'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'formatFrequency'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_readTurnPIDButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_readWallPIDButton_clicked'
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
        case 1: _t->updateMotorLabel((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 2: _t->Initialize(); break;
        case 3: _t->OnQTimer1(); break;
        case 4: _t->OnRxChar(); break;
        case 5: { bool _r = _t->eventFilter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->on_OpenPortButton_clicked(); break;
        case 7: _t->on_buttonClear_clicked(); break;
        case 8: _t->on_SendCommandButton_clicked(); break;
        case 9: _t->InitPaintBox(); break;
        case 10: _t->DrawBackground(); break;
        case 11: _t->SendCMD((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 12: _t->DecodeCmd((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1]))); break;
        case 13: _t->EngineTest((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 14: _t->on_aliveButton_clicked(); break;
        case 15: _t->on_OpenWifiButton_clicked(); break;
        case 16: _t->onRxUDP(); break;
        case 17: _t->DecodeHeader((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 18: _t->Heartbeat(); break;
        case 19: _t->DrawMovement(); break;
        case 20: _t->Integrate(); break;
        case 21: _t->on_powerButton_clicked(); break;
        case 22: _t->on_debugTabButton_clicked(); break;
        case 23: _t->on_telemetryTabButton_clicked(); break;
        case 24: _t->on_homeTabButton_clicked(); break;
        case 25: _t->on_PIDTabButton_clicked(); break;
        case 26: _t->on_setTurnPIDButton_clicked(); break;
        case 27: _t->on_setWallPIDButton_clicked(); break;
        case 28: _t->on_pwmConfigButton_clicked(); break;
        case 29: _t->on_pwmPrescalerConfig_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->on_pwmPeriodConfig_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->updateResultingFrequency(); break;
        case 32: { QString _r = _t->formatFrequency((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->on_readTurnPIDButton_clicked(); break;
        case 34: _t->on_readWallPIDButton_clicked(); break;
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
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 35;
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
