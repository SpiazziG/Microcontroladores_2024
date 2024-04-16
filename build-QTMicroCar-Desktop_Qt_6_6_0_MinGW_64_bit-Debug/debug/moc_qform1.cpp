/****************************************************************************
** Meta object code from reading C++ file 'qform1.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTMicroCar/qform1.h"
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
    "OnQTimer1",
    "OnRxChar",
    "eventFilter",
    "watched",
    "QEvent*",
    "event",
    "on_pushButton_clicked",
    "on_pushButton_3_clicked",
    "on_pushButton_2_clicked",
    "InitPaintBox",
    "DrawBackground",
    "SendCMD",
    "uint8_t*",
    "buf",
    "uint8_t",
    "length",
    "DecodeCmd",
    "rxBuf",
    "servoDeg",
    "servDeg",
    "configServo",
    "readServo",
    "EngineTest",
    "int32_t",
    "Eng1",
    "Eng2",
    "Scanning",
    "on_aliveButton_clicked",
    "on_powerButton_clicked",
    "on_pushButtonUDP_clicked",
    "onRxUDP",
    "on_LeftEngineSlide_sliderMoved",
    "position"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQForm1ENDCLASS_t {
    uint offsetsAndSizes[78];
    char stringdata0[7];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[4];
    char stringdata5[4];
    char stringdata6[10];
    char stringdata7[9];
    char stringdata8[12];
    char stringdata9[8];
    char stringdata10[8];
    char stringdata11[6];
    char stringdata12[22];
    char stringdata13[24];
    char stringdata14[24];
    char stringdata15[13];
    char stringdata16[15];
    char stringdata17[8];
    char stringdata18[9];
    char stringdata19[4];
    char stringdata20[8];
    char stringdata21[7];
    char stringdata22[10];
    char stringdata23[6];
    char stringdata24[9];
    char stringdata25[8];
    char stringdata26[12];
    char stringdata27[10];
    char stringdata28[11];
    char stringdata29[8];
    char stringdata30[5];
    char stringdata31[5];
    char stringdata32[9];
    char stringdata33[23];
    char stringdata34[23];
    char stringdata35[25];
    char stringdata36[8];
    char stringdata37[31];
    char stringdata38[9];
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
        QT_MOC_LITERAL(38, 9),  // "OnQTimer1"
        QT_MOC_LITERAL(48, 8),  // "OnRxChar"
        QT_MOC_LITERAL(57, 11),  // "eventFilter"
        QT_MOC_LITERAL(69, 7),  // "watched"
        QT_MOC_LITERAL(77, 7),  // "QEvent*"
        QT_MOC_LITERAL(85, 5),  // "event"
        QT_MOC_LITERAL(91, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(113, 23),  // "on_pushButton_3_clicked"
        QT_MOC_LITERAL(137, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(161, 12),  // "InitPaintBox"
        QT_MOC_LITERAL(174, 14),  // "DrawBackground"
        QT_MOC_LITERAL(189, 7),  // "SendCMD"
        QT_MOC_LITERAL(197, 8),  // "uint8_t*"
        QT_MOC_LITERAL(206, 3),  // "buf"
        QT_MOC_LITERAL(210, 7),  // "uint8_t"
        QT_MOC_LITERAL(218, 6),  // "length"
        QT_MOC_LITERAL(225, 9),  // "DecodeCmd"
        QT_MOC_LITERAL(235, 5),  // "rxBuf"
        QT_MOC_LITERAL(241, 8),  // "servoDeg"
        QT_MOC_LITERAL(250, 7),  // "servDeg"
        QT_MOC_LITERAL(258, 11),  // "configServo"
        QT_MOC_LITERAL(270, 9),  // "readServo"
        QT_MOC_LITERAL(280, 10),  // "EngineTest"
        QT_MOC_LITERAL(291, 7),  // "int32_t"
        QT_MOC_LITERAL(299, 4),  // "Eng1"
        QT_MOC_LITERAL(304, 4),  // "Eng2"
        QT_MOC_LITERAL(309, 8),  // "Scanning"
        QT_MOC_LITERAL(318, 22),  // "on_aliveButton_clicked"
        QT_MOC_LITERAL(341, 22),  // "on_powerButton_clicked"
        QT_MOC_LITERAL(364, 24),  // "on_pushButtonUDP_clicked"
        QT_MOC_LITERAL(389, 7),  // "onRxUDP"
        QT_MOC_LITERAL(397, 30),  // "on_LeftEngineSlide_sliderMoved"
        QT_MOC_LITERAL(428, 8)   // "position"
    },
    "QForm1",
    "maxMinValues",
    "",
    "uint16_t",
    "min",
    "max",
    "OnQTimer1",
    "OnRxChar",
    "eventFilter",
    "watched",
    "QEvent*",
    "event",
    "on_pushButton_clicked",
    "on_pushButton_3_clicked",
    "on_pushButton_2_clicked",
    "InitPaintBox",
    "DrawBackground",
    "SendCMD",
    "uint8_t*",
    "buf",
    "uint8_t",
    "length",
    "DecodeCmd",
    "rxBuf",
    "servoDeg",
    "servDeg",
    "configServo",
    "readServo",
    "EngineTest",
    "int32_t",
    "Eng1",
    "Eng2",
    "Scanning",
    "on_aliveButton_clicked",
    "on_powerButton_clicked",
    "on_pushButtonUDP_clicked",
    "onRxUDP",
    "on_LeftEngineSlide_sliderMoved",
    "position"
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
       8,    2,  147,    2, 0x08,    6 /* Private */,
      12,    0,  152,    2, 0x08,    9 /* Private */,
      13,    0,  153,    2, 0x08,   10 /* Private */,
      14,    0,  154,    2, 0x08,   11 /* Private */,
      15,    0,  155,    2, 0x08,   12 /* Private */,
      16,    0,  156,    2, 0x08,   13 /* Private */,
      17,    2,  157,    2, 0x08,   14 /* Private */,
      22,    1,  162,    2, 0x08,   17 /* Private */,
      24,    1,  165,    2, 0x08,   19 /* Private */,
      26,    2,  168,    2, 0x08,   21 /* Private */,
      27,    0,  173,    2, 0x08,   24 /* Private */,
      28,    2,  174,    2, 0x08,   25 /* Private */,
      32,    0,  179,    2, 0x08,   28 /* Private */,
      33,    0,  180,    2, 0x08,   29 /* Private */,
      34,    0,  181,    2, 0x08,   30 /* Private */,
      35,    0,  182,    2, 0x08,   31 /* Private */,
      36,    0,  183,    2, 0x08,   32 /* Private */,
      37,    1,  184,    2, 0x08,   33 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 10,    9,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 20,   19,   21,
    QMetaType::Void, 0x80000000 | 18,   23,
    QMetaType::Void, 0x80000000 | 20,   25,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29, 0x80000000 | 29,   30,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,

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
        // method 'OnQTimer1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnRxChar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'eventFilter'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
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
        // method 'servoDeg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        // method 'configServo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>,
        // method 'readServo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'EngineTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<int32_t, std::false_type>,
        // method 'Scanning'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_aliveButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_powerButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonUDP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRxUDP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_LeftEngineSlide_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
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
        case 1: _t->OnQTimer1(); break;
        case 2: _t->OnRxChar(); break;
        case 3: { bool _r = _t->eventFilter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->InitPaintBox(); break;
        case 8: _t->DrawBackground(); break;
        case 9: _t->SendCMD((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 10: _t->DecodeCmd((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1]))); break;
        case 11: _t->servoDeg((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1]))); break;
        case 12: _t->configServo((*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[2]))); break;
        case 13: _t->readServo(); break;
        case 14: _t->EngineTest((*reinterpret_cast< std::add_pointer_t<int32_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int32_t>>(_a[2]))); break;
        case 15: _t->Scanning(); break;
        case 16: _t->on_aliveButton_clicked(); break;
        case 17: _t->on_powerButton_clicked(); break;
        case 18: _t->on_pushButtonUDP_clicked(); break;
        case 19: _t->onRxUDP(); break;
        case 20: _t->on_LeftEngineSlide_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
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
