#ifndef QFORM1_H
#define QFORM1_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <dialog.h>
#include <qpaintbox.h>
#include <QPainter>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

typedef union{
    uint8_t     u8[4];
    int8_t      i8[4];
    uint16_t    u16[2];
    int16_t     i16[2];
    uint32_t    u32;
    int32_t     i32;
    float       f;
}_work;

QT_BEGIN_NAMESPACE
namespace Ui { class QForm1; }
QT_END_NAMESPACE

class QForm1 : public QMainWindow
{
    Q_OBJECT

public:
    QForm1(QWidget *parent = nullptr);
    ~QForm1();

signals:
    void maxMinValues(uint16_t min, uint16_t max);

private slots:
    void OnQTimer1();

    void OnRxChar();

    bool eventFilter(QObject *watched, QEvent *event) override;

    void on_OpenPortButton_clicked();

    void on_ClearButton_clicked();

    void on_SendCommandButton_clicked();

    void InitPaintBox();

    void DrawBackground();

    //void on_pushButton_4_clicked();

    void SendCMD(uint8_t *buf, uint8_t length);

    void DecodeCmd(uint8_t *rxBuf);

    void EngineTest(int32_t Eng1, int32_t Eng2);

    void on_aliveButton_clicked();

    void on_OpenWifiButton_clicked();

    void onRxUDP();

    void DecodeHeader(uint8_t *buf, int count);

    void Heartbeat();

    void DrawMovement();

    //void on_LeftEngineSlide_sliderMoved(int position);

    //void Scanning();

    //void servoDeg(uint8_t servDeg);

    //void configServo(uint16_t min, uint16_t max);

    //void readServo();

    //void on_powerButton_clicked();

private:
    Ui::QForm1 *ui;

    QTimer *QTimer1;
    QSerialPort *QSerialPort1;
    QUdpSocket *QUdpSocket1;
    QHostAddress hostAddres;
    QPaintBox *QPaintBox1;

    uint16_t    mask = 0xAAF;
    uint16_t 	moveMask = 0;

    uint8_t     rxBuf[256], header, nBytes, cks, index, tmoRX;

    quint16 remotePort, port;

    int8_t measureAngle, indexWifi;
    //int32_t measureTime, distance;

    float lastAcc[3];
    float accValues[3];
    float velValues[3];
    float posValues[3];
    float gyroValues[3];

    #define DELTA_TIME 0.01
    #define THRESHOLD 6.5

    Dialog *dialog;

    typedef enum{
        ALIVE           =0xF0,
        FIRMWARE        =0xF1,
        LEDS            =0x10,
        BUTTONS         =0x12,
        IRSENSOR        =0xA0,
        TEST_ENGINE     =0xA1,
        ACCELERATION    =0xA2,
        ENGINES         =0xA3,
        SPEED           =0xA4,
        SERVO_CONFIG    =0xA5,
        ACKNOWLEDGE     =0x0D,
        UNKNOWNCOMMAND  =0xFF
    }_eIDCommand;

    typedef struct{
        int32_t width;
        int32_t height;
    }_sWidgetSize;

    _sWidgetSize widgetSize;
};
#endif // QFORM1_H
