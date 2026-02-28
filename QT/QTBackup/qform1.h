#ifndef QFORM1_H
#define QFORM1_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <dialog.h>
#include <qpaintbox.h>
#include <QPainter>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#include <QQuickWidget>
#include <QUrl>
#include <QVBoxLayout>
#include <QQuickItem>
#include <QDebug>
#include <QPixmap>
#include <QCursor>

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

public slots:
    void updateFrontSensor(bool visible);
    void updateLeftSensor(bool visible);
    void updateRightSensor(bool visible);
    void updateMotorPower(double left, double right); // Valores de 0.0 a 1.0
    void updateCarPosition(double position); // Valor de 0.0 a 1.0
    void onAnimationDone();
    void triggerForward();
    void triggerLeft();
    void triggerRight();

signals:
    void maxMinValues(uint16_t min, uint16_t max);

private slots:
    void Initialize();

    void OnQTimer1();

    void OnRxChar();

    bool eventFilter(QObject *watched, QEvent *event) override;

    void on_OpenPortButton_clicked();

    void on_buttonClear_clicked();

    void on_SendCommandButton_clicked();

    void InitPaintBox();

    void DrawBackground();

    //void on_pushButton_4_clicked();

    void SendCMD(uint8_t *buf, uint8_t length);

    void DecodeCmd(uint8_t *rxBuf);

    void EngineTest(uint8_t Eng1, uint8_t Eng2);

    void on_aliveButton_clicked();

    void on_OpenWifiButton_clicked();

    void onRxUDP();

    void DecodeHeader(uint8_t *buf, int count);

    void Heartbeat();

    void DrawMovement();

    void Integrate();

    //void on_LeftEngineSlide_sliderMoved(int position);

    //void on_powerButton_clicked();

    void on_powerButton_clicked();

    void on_debugTabButton_clicked();

    void on_telemetryTabButton_clicked();

    void on_homeTabButton_clicked();

    void on_PIDTabButton_clicked();

    void on_setTurnPIDButton_clicked();

    void on_setWallPIDButton_clicked();

    void on_pwmConfigButton_clicked();

    void on_pwmPrescalerConfig_textChanged(const QString &arg1);

    void on_pwmPeriodConfig_textChanged(const QString &arg1);

    void updateResultingFrequency();

    QString formatFrequency(double frequencyHz);

    void on_readTurnPIDButton_clicked();

    void on_readWallPIDButton_clicked();

    void on_viewTabButton_clicked();

    void on_pushButton_clicked();

    void on_setBatteryVoltageButton_clicked();

private:
    Ui::QForm1 *ui;

    QTimer *QTimer1;
    QSerialPort *QSerialPort1;
    QUdpSocket *QUdpSocket1;
    QHostAddress hostAddres;
    QPaintBox *QPaintBox1;

    QQuickItem *m_qmlRootObject = nullptr;

    uint16_t    mask = 0xAAF;
    uint16_t 	moveMask = 0;

    uint8_t     rxBuf[256], header, nBytes, cks, index, tmoRX;

    quint16 remotePort, port;

    int8_t measureAngle, indexWifi;
    uint8_t telemetryState = 0;
    //int32_t measureTime, distance;

    float accValues[3];
    float velValues[3];
    float posValues[3] = {0, 0, 0};
    int16_t gyroValues[3];

    float globalAcc[3];
    float gyroAngle[3];
    float accAngle[3];

    uint8_t ENGINES_ON = 0;


    float filtered[2] = {0};
    float acceleration[450];
    int samples = 0;

    int32_t yaw = 0, pitch = 0, roll = 0;

    float deltaGyro = 0, deltaAcc = 0;

    #define ALPHA_GYRO 0.99
    #define ALPHA_ACC 0.95

    #define X_AXIS 0
    #define Y_AXIS 1
    #define Z_AXIS 2

    #define CENTER_CAR_DEADZONE 75

    Dialog *dialog;

    typedef enum {
        // Communication commands
        ACKNOWLEDGE         = 0x0D,
        GET_LOCAL_IP        = 0xE0,
        ALIVE               = 0xF0,
        GET_FIRMWARE_INFO   = 0xF1, //FIRMWARE
        UNKNOWNCMD          = 0xFF, //UNKNOWNCOMMAND

        // 0xA_ : Sensors & Actuators (Read data)
        GET_IR_SENSORS      = 0xA0,
        GET_MPU_DATA        = 0xA2, //ACCELERATION
        GET_BUTTON_STATE    = 0xA4, //BUTTONS
        GET_MOTOR_SPEED     = 0xA6,

        // 0xB_ : Sensors (Configuration and calibration)
        SET_IR_CALIBRATION  = 0xB0, //CALIBRATION

        // 0xC_ : Actuators and software configuration
        SET_MOTOR_TEST      = 0xC0, //TEST_ENGINE
        SET_PWM_CONFIG      = 0xC2,
        SET_BATTERY_VOLTAGE = 0xC4,

        // 0xD_ : PID Configuration
        // Turn PID
        SET_PID_TURN_GAINS  = 0xD0, //SET_PID
        GET_PID_TURN_GAINS  = 0xD1,

        // Wall PID
        SET_PID_WALL_GAINS  = 0xD2,
        GET_PID_WALL_GAINS  = 0xD3,

        // Movement parameters
        SET_TURN_SPEED      = 0xD8,
        SET_WALL_SPEED      = 0xDA,

        // Maze State
        GET_CURRENT_ACTION      = 0xEA,
        GET_INTERSECTION_TYPE   = 0xEE,
        GET_MAP_INFO            = 0xEF,
    } Command_e;

    typedef enum {
        NORTH = 0,
        EAST = 1,
        SOUTH = 2,
        WEST = 3,
    } Map_Direction_e;

    typedef struct {
        uint8_t walls;
        uint8_t visited;
        uint8_t cost;
    } CellData_s;

    typedef struct {
        CellData_s maze[16][16];
        uint8_t currentDirection;
        uint8_t currentX;
        uint8_t currentY;
    } Map_Position_s;

    Map_Position_s mapData;
    int rotationAngle;
    bool isMirrored;

    typedef struct{
        int32_t width;
        int32_t height;
    }_sWidgetSize;

    _sWidgetSize widgetSize;
};
#endif // QFORM1_H
