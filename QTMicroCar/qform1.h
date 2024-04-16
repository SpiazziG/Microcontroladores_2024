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

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void InitPaintBox();

    void DrawBackground();

    //void on_pushButton_4_clicked();

    void SendCMD(uint8_t *buf, uint8_t length);

    void DecodeCmd(uint8_t *rxBuf);

    void servoDeg(uint8_t servDeg);

    void configServo(uint16_t min, uint16_t max);

    void readServo();

    void EngineTest(int32_t Eng1, int32_t Eng2);

    void Scanning();

    void on_aliveButton_clicked();

    void on_powerButton_clicked();

    void on_pushButtonUDP_clicked();

    void onRxUDP();

    void on_LeftEngineSlide_sliderMoved(int position);

private:
    Ui::QForm1 *ui;

    QTimer *QTimer1;
    QSerialPort *QSerialPort1;

    uint8_t rxBuf[256], header, nBytes, cks, index, tmoRX;

    QUdpSocket *QUdpSocket1;
    QHostAddress hostAddres;
    quint16 remotePort;

    int8_t measureAngle, indexWifi;
    int32_t measureTime, distance;
    bool SCAN = false;

    Dialog *dialog;

    QPaintBox *QPaintBox1;

    typedef enum{
        ALIVE=0xF0,
        FIRMWARE=0xF1,
        LEDS=0x10,
        BUTTONS=0x12,
        IRSENSOR=0xA0,
        TEST_ENGINE=0xA1,
        SERVO=0xA2,
        DISTANCIA=0xA3,
        SPEED=0xA4,
        SERVO_CONFIG=0xA5,
        ACKNOWLEDGE=0x0D,
        UNKNOWNCOMMAND=0xFF
    }_eIDCommand;

    typedef struct{
        int32_t width;
        int32_t height;
    }_sWidgetSize;

    _sWidgetSize widgetSize;
};
#endif // QFORM1_H
