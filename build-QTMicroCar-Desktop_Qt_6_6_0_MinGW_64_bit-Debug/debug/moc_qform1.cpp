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
    "updateFrontSensor",
    "visible",
    "updateLeftSensor",
    "updateRightSensor",
    "updateMotorPower",
    "left",
    "right",
    "updateCarPosition",
    "position",
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
    "on_readWallPIDButton_clicked",
    "on_viewTabButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQForm1ENDCLASS_t {
    uint offsetsAndSizes[124];
    char stringdata0[7];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[4];
    char stringdata5[4];
    char stringdata6[18];
    char stringdata7[8];
    char stringdata8[17];
    char stringdata9[18];
    char stringdata10[17];
    char stringdata11[5];
    char stringdata12[6];
    char stringdata13[18];
    char stringdata14[9];
    char stringdata15[11];
    char stringdata16[10];
    char stringdata17[9];
    char stringdata18[12];
    char stringdata19[8];
    char stringdata20[8];
    char stringdata21[6];
    char stringdata22[26];
    char stringdata23[23];
    char stringdata24[29];
    char stringdata25[13];
    char stringdata26[15];
    char stringdata27[8];
    char stringdata28[9];
    char stringdata29[4];
    char stringdata30[8];
    char stringdata31[7];
    char stringdata32[10];
    char stringdata33[6];
    char stringdata34[11];
    char stringdata35[5];
    char stringdata36[5];
    char stringdata37[23];
    char stringdata38[26];
    char stringdata39[8];
    char stringdata40[13];
    char stringdata41[6];
    char stringdata42[10];
    char stringdata43[13];
    char stringdata44[10];
    char stringdata45[23];
    char stringdata46[26];
    char stringdata47[30];
    char stringdata48[25];
    char stringdata49[24];
    char stringdata50[28];
    char stringdata51[28];
    char stringdata52[27];
    char stringdata53[34];
    char stringdata54[5];
    char stringdata55[31];
    char stringdata56[25];
    char stringdata57[16];
    char stringdata58[12];
    char stringdata59[29];
    char stringdata60[29];
    char stringdata61[25];
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
        QT_MOC_LITERAL(38, 17),  // "updateFrontSensor"
        QT_MOC_LITERAL(56, 7),  // "visible"
        QT_MOC_LITERAL(64, 16),  // "updateLeftSensor"
        QT_MOC_LITERAL(81, 17),  // "updateRightSensor"
        QT_MOC_LITERAL(99, 16),  // "updateMotorPower"
        QT_MOC_LITERAL(116, 4),  // "left"
        QT_MOC_LITERAL(121, 5),  // "right"
        QT_MOC_LITERAL(127, 17),  // "updateCarPosition"
        QT_MOC_LITERAL(145, 8),  // "position"
        QT_MOC_LITERAL(154, 10),  // "Initialize"
        QT_MOC_LITERAL(165, 9),  // "OnQTimer1"
        QT_MOC_LITERAL(175, 8),  // "OnRxChar"
        QT_MOC_LITERAL(184, 11),  // "eventFilter"
        QT_MOC_LITERAL(196, 7),  // "watched"
        QT_MOC_LITERAL(204, 7),  // "QEvent*"
        QT_MOC_LITERAL(212, 5),  // "event"
        QT_MOC_LITERAL(218, 25),  // "on_OpenPortButton_clicked"
        QT_MOC_LITERAL(244, 22),  // "on_buttonClear_clicked"
        QT_MOC_LITERAL(267, 28),  // "on_SendCommandButton_clicked"
        QT_MOC_LITERAL(296, 12),  // "InitPaintBox"
        QT_MOC_LITERAL(309, 14),  // "DrawBackground"
        QT_MOC_LITERAL(324, 7),  // "SendCMD"
        QT_MOC_LITERAL(332, 8),  // "uint8_t*"
        QT_MOC_LITERAL(341, 3),  // "buf"
        QT_MOC_LITERAL(345, 7),  // "uint8_t"
        QT_MOC_LITERAL(353, 6),  // "length"
        QT_MOC_LITERAL(360, 9),  // "DecodeCmd"
        QT_MOC_LITERAL(370, 5),  // "rxBuf"
        QT_MOC_LITERAL(376, 10),  // "EngineTest"
        QT_MOC_LITERAL(387, 4),  // "Eng1"
        QT_MOC_LITERAL(392, 4),  // "Eng2"
        QT_MOC_LITERAL(397, 22),  // "on_aliveButton_clicked"
        QT_MOC_LITERAL(420, 25),  // "on_OpenWifiButton_clicked"
        QT_MOC_LITERAL(446, 7),  // "onRxUDP"
        QT_MOC_LITERAL(454, 12),  // "DecodeHeader"
        QT_MOC_LITERAL(467, 5),  // "count"
        QT_MOC_LITERAL(473, 9),  // "Heartbeat"
        QT_MOC_LITERAL(483, 12),  // "DrawMovement"
        QT_MOC_LITERAL(496, 9),  // "Integrate"
        QT_MOC_LITERAL(506, 22),  // "on_powerButton_clicked"
        QT_MOC_LITERAL(529, 25),  // "on_debugTabButton_clicked"
        QT_MOC_LITERAL(555, 29),  // "on_telemetryTabButton_clicked"
        QT_MOC_LITERAL(585, 24),  // "on_homeTabButton_clicked"
        QT_MOC_LITERAL(610, 23),  // "on_PIDTabButton_clicked"
        QT_MOC_LITERAL(634, 27),  // "on_setTurnPIDButton_clicked"
        QT_MOC_LITERAL(662, 27),  // "on_setWallPIDButton_clicked"
        QT_MOC_LITERAL(690, 26),  // "on_pwmConfigButton_clicked"
        QT_MOC_LITERAL(717, 33),  // "on_pwmPrescalerConfig_textCha..."
        QT_MOC_LITERAL(751, 4),  // "arg1"
        QT_MOC_LITERAL(756, 30),  // "on_pwmPeriodConfig_textChanged"
        QT_MOC_LITERAL(787, 24),  // "updateResultingFrequency"
        QT_MOC_LITERAL(812, 15),  // "formatFrequency"
        QT_MOC_LITERAL(828, 11),  // "frequencyHz"
        QT_MOC_LITERAL(840, 28),  // "on_readTurnPIDButton_clicked"
        QT_MOC_LITERAL(869, 28),  // "on_readWallPIDButton_clicked"
        QT_MOC_LITERAL(898, 24)   // "on_viewTabButton_clicked"
    },
    "QForm1",
    "maxMinValues",
    "",
    "uint16_t",
    "min",
    "max",
    "updateFrontSensor",
    "visible",
    "updateLeftSensor",
    "updateRightSensor",
    "updateMotorPower",
    "left",
    "right",
    "updateCarPosition",
    "position",
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
    "on_readWallPIDButton_clicked",
    "on_viewTabButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQForm1ENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  254,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,  259,    2, 0x0a,    4 /* Public */,
       8,    1,  262,    2, 0x0a,    6 /* Public */,
       9,    1,  265,    2, 0x0a,    8 /* Public */,
      10,    2,  268,    2, 0x0a,   10 /* Public */,
      13,    1,  273,    2, 0x0a,   13 /* Public */,
      15,    0,  276,    2, 0x08,   15 /* Private */,
      16,    0,  277,    2, 0x08,   16 /* Private */,
      17,    0,  278,    2, 0x08,   17 /* Private */,
      18,    2,  279,    2, 0x08,   18 /* Private */,
      22,    0,  284,    2, 0x08,   21 /* Private */,
      23,    0,  285,    2, 0x08,   22 /* Private */,
      24,    0,  286,    2, 0x08,   23 /* Private */,
      25,    0,  287,    2, 0x08,   24 /* Private */,
      26,    0,  288,    2, 0x08,   25 /* Private */,
      27,    2,  289,    2, 0x08,   26 /* Private */,
      32,    1,  294,    2, 0x08,   29 /* Private */,
      34,    2,  297,    2, 0x08,   31 /* Private */,
      37,    0,  302,    2, 0x08,   34 /* Private */,
      38,    0,  303,    2, 0x08,   35 /* Private */,
      39,    0,  304,    2, 0x08,   36 /* Private */,
      40,    2,  305,    2, 0x08,   37 /* Private */,
      42,    0,  310,    2, 0x08,   40 /* Private */,
      43,    0,  311,    2, 0x08,   41 /* Private */,
      44,    0,  312,    2, 0x08,   42 /* Private */,
      45,    0,  313,    2, 0x08,   43 /* Private */,
      46,    0,  314,    2, 0x08,   44 /* Private */,
      47,    0,  315,    2, 0x08,   45 /* Private */,
      48,    0,  316,    2, 0x08,   46 /* Private */,
      49,    0,  317,    2, 0x08,   47 /* Private */,
      50,    0,  318,    2, 0x08,   48 /* Private */,
      51,    0,  319,    2, 0x08,   49 /* Private */,
      52,    0,  320,    2, 0x08,   50 /* Private */,
      53,    1,  321,    2, 0x08,   51 /* Private */,
      55,    1,  324,    2, 0x08,   53 /* Private */,
      56,    0,  327,    2, 0x08,   55 /* Private */,
      57,    1,  328,    2, 0x08,   56 /* Private */,
      59,    0,  331,    2, 0x08,   58 /* Private */,
      60,    0,  332,    2, 0x08,   59 /* Private */,
      61,    0,  333,    2, 0x08,   60 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   11,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 20,   19,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28, 0x80000000 | 30,   29,   31,
    QMetaType::Void, 0x80000000 | 28,   33,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 30,   35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Int,   29,   41,
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
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Double,   58,
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
        // method 'updateFrontSensor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateLeftSensor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateRightSensor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateMotorPower'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'updateCarPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_viewTabButton_clicked'
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
        case 1: _t->updateFrontSensor((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->updateLeftSensor((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->updateRightSensor((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->updateMotorPower((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 5: _t->updateCarPosition((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->Initialize(); break;
        case 7: _t->OnQTimer1(); break;
        case 8: _t->OnRxChar(); break;
        case 9: { bool _r = _t->eventFilter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->on_OpenPortButton_clicked(); break;
        case 11: _t->on_buttonClear_clicked(); break;
        case 12: _t->on_SendCommandButton_clicked(); break;
        case 13: _t->InitPaintBox(); break;
        case 14: _t->DrawBackground(); break;
        case 15: _t->SendCMD((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 16: _t->DecodeCmd((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1]))); break;
        case 17: _t->EngineTest((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 18: _t->on_aliveButton_clicked(); break;
        case 19: _t->on_OpenWifiButton_clicked(); break;
        case 20: _t->onRxUDP(); break;
        case 21: _t->DecodeHeader((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 22: _t->Heartbeat(); break;
        case 23: _t->DrawMovement(); break;
        case 24: _t->Integrate(); break;
        case 25: _t->on_powerButton_clicked(); break;
        case 26: _t->on_debugTabButton_clicked(); break;
        case 27: _t->on_telemetryTabButton_clicked(); break;
        case 28: _t->on_homeTabButton_clicked(); break;
        case 29: _t->on_PIDTabButton_clicked(); break;
        case 30: _t->on_setTurnPIDButton_clicked(); break;
        case 31: _t->on_setWallPIDButton_clicked(); break;
        case 32: _t->on_pwmConfigButton_clicked(); break;
        case 33: _t->on_pwmPrescalerConfig_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->on_pwmPeriodConfig_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->updateResultingFrequency(); break;
        case 36: { QString _r = _t->formatFrequency((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->on_readTurnPIDButton_clicked(); break;
        case 38: _t->on_readWallPIDButton_clicked(); break;
        case 39: _t->on_viewTabButton_clicked(); break;
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
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 40;
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
