#include "qform1.h"
#include "ui_qform1.h"

QForm1::QForm1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QForm1)
{
    ui->setupUi(this);
    QSerialPort1=new QSerialPort(this);
    dialog = new Dialog(this);
    ui->comboBoxCommunication->installEventFilter(this);

    /*
    QQuickWidget *qmlWidget = ui->quickWidget;
    connect(qmlWidget, &QQuickWidget::statusChanged,
            [=](QQuickWidget::Status status) {

                // Solo procedemos si el QML se ha cargado correctamente.
                if (status == QQuickWidget::Ready) {
                    // AHORA es seguro acceder al árbol de objetos QML.
                    QQuickItem *qmlItem = qmlWidget->rootObject();
                    if (qmlItem) {
                        QObject *dial = qmlItem->findChild<QObject*>("circularSlider");
                        if (dial) {
                            qDebug() << "¡Dial encontrado! Conectando la señal...";
                            // Conectar la señal del dial al slot.
                            QObject::connect(dial, SIGNAL(valueChanged(qreal)),
                                             this, SLOT(updateMotorLabel(qreal)));

                            // Establecer el valor inicial del label.
                            updateMotorLabel(dial->property("value").toDouble());
                        } else {
                            // Este mensaje ya no debería aparecer.
                            qWarning() << "Error: No se pudo encontrar el objeto QML con objectName: 'circularSlider'";
                        }
                    }
                }
            });

    qmlWidget->setSource(QUrl(QStringLiteral("qrc:/RadialDial.qml")));

    qmlWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qmlWidget->setClearColor(Qt::transparent);
    qmlWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    //qmlWidget->setAttribute(Qt::WA_TranslucentBackground);
    //qmlWidget->setStyleSheet("background: transparent;");
    */

    ui->comboBoxSendCommand->addItem("ALIVE", 0xF0);
    ui->comboBoxSendCommand->addItem("FIRMWARE INFO", 0xF1);
    //ui->comboBox_2->addItem("BUTTONS", 0x12);
    ui->comboBoxSendCommand->addItem("IR SENSORS", 0xA0);
    //ui->comboBox_2->addItem("ENGINE TEST", 0xA1);
    ui->comboBoxSendCommand->addItem("GET_MPU_DATA", 0xA2);
    //ui->comboBox_2->addItem("ENGINES", 0xA3);

    QUdpSocket1 = new QUdpSocket(this);
    connect(QUdpSocket1,&QUdpSocket::readyRead,this,&QForm1::onRxUDP);

    header=0;
    connect(QSerialPort1,&QSerialPort::readyRead, this,&QForm1::OnRxChar);
    connect(dialog, &Dialog::powEng, this, &QForm1::EngineTest);
    connect(this, &QForm1::maxMinValues, dialog, &Dialog::displayMaxMin);

    QPaintBox1 = new QPaintBox(ui->widgetRadar->width(), ui->widgetRadar->height()+10, ui->widgetRadar);
    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &QForm1::OnQTimer1);
    QTimer1->start(10);

    ui->labelHour->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->stackedWidget->setCurrentIndex(0);

    DrawBackground();
    Initialize();

    deltaGyro = clock();
    deltaAcc = clock();
}

QForm1::~QForm1(){
    delete ui;
    delete dialog;
    delete QPaintBox1;
}

void QForm1::Initialize(){
    for(uint8_t i=0; i<3; i++){
        accValues[i] = 0;
        velValues[i] = 0;
        posValues[i] = 0;
        gyroValues[i] = 0;

        globalAcc[i] = 0;
        gyroAngle[i] = 0;
        accAngle[i] = 0;
    }
}

bool QForm1::eventFilter(QObject *watched, QEvent *event){
    if(watched == ui->comboBoxCommunication) {
        if (event->type() == QEvent::MouseButtonPress) {
            ui->comboBoxCommunication->clear();
            QSerialPortInfo SerialPortInfo1;

            for(int i=0;i<SerialPortInfo1.availablePorts().count();i++)
                ui->comboBoxCommunication->addItem(SerialPortInfo1.availablePorts().at(i).portName());

            return QMainWindow::eventFilter(watched, event);
        } else {
            return false;
        }
    } else {
         return QMainWindow::eventFilter(watched, event);
    }
}

void QForm1::OnQTimer1(){
    static uint8_t time100ms = 10;
    static uint8_t time20ms = 2;
    static uint8_t time500ms = 50;
    uint8_t buf[3];

    if(widgetSize.width != ui->widgetRadar->width() || widgetSize.height != ui->widgetRadar->height()){
        //QPaintBox1->resize(ui->widget->width(), ui->widget->height());

        widgetSize.width = ui->widgetRadar->width();
        widgetSize.height = ui->widgetRadar->height();
        QPaintBox1->resize(widgetSize.width, widgetSize.height);
        DrawBackground();
    }

    if(time100ms == 0){
        time100ms = 10;
        switch (telemetryState) {
            case 0:
                Heartbeat();
                break;
            case 1:
                buf[0] = GET_IR_SENSORS;
                SendCMD(buf, 1);
                break;
            case 2:
                buf[0] = GET_MPU_DATA;
                SendCMD(buf, 1);
                break;
            case 3:
                buf[0] = GET_INTERSECTION_TYPE;
                SendCMD(buf, 1);
                break;
        }
        telemetryState++;

        if (telemetryState > 3) {
            telemetryState = 0;
        }
    } else {
        time100ms--;
    }

    if(time20ms == 0){
        time20ms = 2;
    } else {
        time20ms--;
    }

    if(time500ms == 0){
        //EngineTest(40, 40);
        time500ms = 50;
    } else {
        time500ms--;
    }

    DrawMovement();

    switch(ui->stackedWidget->currentIndex()){
    case 0:
        ui->homeTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->telemetryTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->debugTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->PIDTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        break;
    case 1:
        ui->telemetryTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->homeTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->debugTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->PIDTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        break;
    case 2:
        ui->PIDTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->telemetryTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->homeTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->debugTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        break;
    case 3:
        ui->debugTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->telemetryTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->homeTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        ui->PIDTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Siemens Sans; font-weight: bold; border: 0px;");
        break;
    default:
        break;
    }

    ui->plainTextEdit->viewport()->update();
    ui->labelHour->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void QForm1::Heartbeat(){
    uint8_t write;
    uint8_t buf[1];
    write = ~(mask>>moveMask) & 1;
    moveMask++;
    moveMask ^= (moveMask & 16);


    if(write == 0){
        buf[0] = ALIVE, SendCMD(buf ,1);
    } else {
        ui->aliveButton->setStyleSheet("background-color: rgb(57, 63, 68); font: 10pt Siemens Sans; font-weight: bold; color: rgb(227, 227, 229);");
        ui->heartbeatLight->setChecked(false) ;
    }
}

void QForm1::onRxUDP(){
    uint8_t *buf;
    qint64 count = 0;
    QString strHex;

    while(QUdpSocket1->hasPendingDatagrams()){
        count=QUdpSocket1->pendingDatagramSize();

        if(count<=0){
            return;
        }

        buf = new uint8_t[count];

        QUdpSocket1->readDatagram((char *)buf, count, &hostAddres, &remotePort);
        ui->WifiLineEdit->setText("IPv4: " + (hostAddres.toString().right(hostAddres.toString().length()-7)) + " - REMOTE IP: " + QString().number(remotePort));

        strHex = "WIFI<-- 0x";
        for (int a=0; a<count; a++) {
            strHex = strHex + QString("%1").arg(buf[a], 2, 16, QChar('0')).toUpper();
        }

        ui->plainTextEdit->appendPlainText(strHex);
    }

    DecodeHeader(buf, count);
    delete [] buf;
}

void QForm1::OnRxChar(){
    int count;
    uint8_t *buf;
    QString strHex;

    count = QSerialPort1->bytesAvailable();

    if(count <= 0)
        return;

    buf = new uint8_t[count];
    QSerialPort1->read((char *)buf, count);

    strHex = "USB<-- 0x";
    for (int a=0; a<count; a++) {
        strHex = strHex + QString("%1").arg(buf[a], 2, 16, QChar('0')).toUpper();
    }

    ui->plainTextEdit->appendPlainText(strHex);

    DecodeHeader(buf, count);
    delete [] buf;
}

void QForm1::DecodeHeader(uint8_t *buf, int count){
    for (int i=0; i<count; i++) {

        switch(header){
        case 0:
            if(buf[i] == 'U'){
                header = 1;
                tmoRX = 5;
            }
            break;
        case 1:
            if(buf[i] == 'N')
                header = 2;
            else{
                header = 0;
                i--;
            }
            break;
        case 2:
            if(buf[i] == 'E')
                header = 3;
            else{
                header = 0;
                i--;
            }
            break;
        case 3:
            if(buf[i] == 'R')
                header = 4;
            else{
                header = 0;
                i--;
            }
            break;
        case 4:
            nBytes = buf[i];
            header = 5;
            break;
        case 5:
            if(buf[i] == ':'){
                header = 6;
                index = 0;
                cks = 'U' ^ 'N' ^ 'E' ^ 'R' ^ ':' ^ nBytes;
            }else{
                header = 0;
                i--;
            }
            break;
        case 6:
            nBytes--;
            if(nBytes > 0){
                rxBuf[index++] = buf[i];
                cks ^= buf[i];
            }else{
                header = 0;
                if(cks == buf[i])
                    DecodeCmd(rxBuf);
                else
                    ui->plainTextEdit->appendPlainText("ERROR CHECKSUM");
            }
            break;
        }
    }
}

void QForm1::DecodeCmd(uint8_t *rxBuf){
    QString str;
    _work w;
    char fwVersion[23];

    switch(rxBuf[0]){
    case ALIVE:
        if(rxBuf[1] == ACKNOWLEDGE){//+3
            ui->aliveButton->setStyleSheet("color: white; background-color: rgb(255, 0, 255); font: 10pt Siemens Sans; font-weight: bold; color: rgb(57, 63, 68);");
            ui->heartbeatLight->setChecked(true);
        }
        //else
        //ui->aliveButton->setStyleSheet("color: white; background-color: rgb(224, 14, 21); font: 9pt MS Sans Serif; font-weight: bold; color: rgb(47, 55, 77);");
        break;
    case GET_FIRMWARE_INFO:
        for(uint8_t i = 0; i < 22; i++)
            fwVersion[i] = rxBuf[i+1];

        str = QString::fromUtf8(fwVersion);

        ui->labelFirmware->setText(str);
        break;
    case GET_BUTTON_STATE:
        /*
            str = "SW3: ";
            if(rxBuf[1] & 0x08)
                str = str + "HIGH";
            else
                str = str + "LOW";
            str = str + " - SW2: ";
            if(rxBuf[1] & 0x04)
                str = str + "HIGH";
            else
                str = str + "LOW";
            str = str + " - SW1: ";
            if(rxBuf[1] & 0x02)
                str = str + "HIGH";
            else
                str = str + "LOW";
            str = str + " - SW0: ";
            if(rxBuf[1] & 0x01)
                str = str + "HIGH";
            else
                str = str + "LOW";
            ui->plainTextEdit->appendPlainText(str);
        */
        break;
    case UNKNOWNCMD:
        ui->plainTextEdit->appendPlainText("NO CMD");
        break;
    case GET_IR_SENSORS:
        w.u32 = 0;
        uint8_t baseIndex;
        // For 12 bits measures
        for (int i = 0; i < 8; ++i){
            baseIndex = 1 + (i * 2);
            w.u8[0] = rxBuf[baseIndex];
            w.u8[1] = rxBuf[baseIndex + 1];

            QString labelName = QString("labelValueIR%1").arg(i + 1);
            QLabel* label = this->findChild<QLabel*>(labelName);
            if(label)
                label->setText(QString("%1").arg(w.i32, 4, 10, QChar(' ')));
        }
        // For millimeter measures
        // for (int i = 0; i < 8; ++i){
        //     w.u8[0] = rxBuf[1 + i];

        //     QString labelName = QString("labelValueIR%1").arg(i + 1);
        //     QLabel* label = this->findChild<QLabel*>(labelName);
        //     if(label)
        //         label->setText(QString("%1").arg(w.i32, 4, 10, QChar(' ')));
        // }
        break;
    case GET_MPU_DATA:
        static float pitchgy, rollgy, pitchac, rollac;
        w.i32 = 0;

        w.u8[0] = rxBuf[1];
        w.u8[1] = rxBuf[2];
        accValues[X_AXIS] = ((float)w.i16[0] / 16384.0f) * 9.806f;

        w.u8[0] = rxBuf[3];
        w.u8[1] = rxBuf[4];
        accValues[Y_AXIS] = ((float)w.i16[0] / 16384.0f) * 9.806f;

        w.u8[0] = rxBuf[5];
        w.u8[1] = rxBuf[6];
        accValues[Z_AXIS] = ((float)w.i16[0] / 16384.0f) * 9.806f;

        w.u8[0] = rxBuf[7];
        w.u8[1] = rxBuf[8];
        gyroValues[X_AXIS] = (w.i16[0])/65.5f; // /131.0

        w.u8[0] = rxBuf[9];
        w.u8[1] = rxBuf[10];
        gyroValues[Y_AXIS] = (w.i16[0])/65.5f;

        w.i32 = 0;
        w.u8[0] = rxBuf[11];
        w.u8[1] = rxBuf[12];
        gyroValues[Z_AXIS] = (w.u8[1]<<8) | w.u8[0];

        w.u8[0] = rxBuf[13];
        w.u8[1] = rxBuf[14];
        yaw = w.i16[0];

        //deltaGyro = (clock() - deltaGyro);

        //aux = deltaGyro;

        //if(gyroValues[Z_AXIS] > 19 || gyroValues[Z_AXIS] < -19)
            //yaw += (gyroValues[Z_AXIS] * deltaGyro);  // /1000

        if(gyroValues[X_AXIS] > 0.15 || gyroValues[X_AXIS] < -0.15)
            rollgy += gyroValues[X_AXIS] * deltaGyro;

        if(gyroValues[Y_AXIS] > 0.15 || gyroValues[Y_AXIS] < -0.15)
            pitchgy += gyroValues[Y_AXIS] * deltaGyro;

        //deltaGyro = clock();

        pitchac = atan2(accValues[Y_AXIS], accValues[Z_AXIS]) * (180.0/M_PI);

        rollac =  atan2(-accValues[X_AXIS], sqrt((accValues[Y_AXIS] * accValues[Y_AXIS]) + (accValues[Z_AXIS] * accValues[Z_AXIS]))) * (180.0/M_PI);

        roll = ALPHA_GYRO * rollgy + (1 - ALPHA_GYRO) * rollac;
        pitch = ALPHA_GYRO * pitchgy + (1 - ALPHA_GYRO) * pitchac;

        //ui->labelGyroX->setText(QString("%1").arg(aux));
        //ui->labelGyroY->setText(QString("%1").arg(deltaGyro));
        //ui->labelGyroZ->setText(QString("%1").arg(yaw/(131*1000)));
        ui->labelGyroZ->setText(QString("%1").arg(yaw));
        //ui->rightEnginePowerLabel->setText(QString("%1").arg(gyroValues[Z_AXIS]));
        //ui->leftEnginePowerLabel->setText(QString("%1").arg(yaw));
        //Integrate();

        ui->labelAccX->setText(QString("%1").arg(accValues[X_AXIS]/10.0, 1, 'f', 3));
        ui->labelAccY->setText(QString("%1").arg(accValues[Y_AXIS]/10.0, 1, 'f', 3));
        ui->labelAccZ->setText(QString("%1").arg(accValues[Z_AXIS]/10.0, 1, 'f', 3));

        ui->labelSpeedX->setText(QString("%1").arg(velValues[X_AXIS]/1000.0, 1, 'f', 3));
        ui->labelSpeedY->setText(QString("%1").arg(velValues[Y_AXIS]/1000.0, 1, 'f', 3));

        ui->labelPosX->setText(QString("%1").arg(posValues[X_AXIS]/1000.0, 1, 'f', 3));
        ui->labelPosY->setText(QString("%1").arg(posValues[Y_AXIS]/1000.0, 1, 'f', 3));

        ui->labelGyroX->setText(QString("%1").arg(gyroValues[X_AXIS]));
        ui->labelGyroY->setText(QString("%1").arg(gyroValues[Y_AXIS]));
        //ui->labelValueIR1->setText(QString("%1").arg(globalAcc[X_AXIS]/1000.0, 1, 'f', 3));
        //ui->labelValueIR2->setText(QString("%1").arg(globalAcc[Y_AXIS]/1000.0, 1, 'f', 3));
        break;
    case GET_MOTOR_SPEED:
        /*
        w.i32 = 0;
        w.i8[0] = rxBuf[1];
        w.i8[1] = rxBuf[2];
        w.i8[2] = rxBuf[3];
        w.i8[3] = rxBuf[4];
        //speedM1 = w.i32;
        ui->leftEnginePowerLabel->setText(QString("%1").arg(w.i32, 3, 10, QChar('0')));
        ui->leftEngineDial->setValue(w.i32);
        //        ui->plainTextEdit->appendPlainText("LEFT SPEED: " + QString("%1").arg(w.i32, 10, 10, QChar('0')));

        w.i32 = 0;
        w.i8[0] = rxBuf[5];
        w.i8[1] = rxBuf[6];
        w.i8[2] = rxBuf[7];
        w.i8[3] = rxBuf[8];
        //speedM2 = w.i32;
        ui->rightEnginePowerLabel->setText(QString("%1").arg(w.i32, 3, 10, QChar('0')));
        ui->rightEngineDial->setValue(w.i32);
        //        ui->plainTextEdit->appendPlainText("RIGHT SPEED: " + QString("%1").arg(w.i32, 10, 10, QChar('0')));
        */
        break;
    case GET_PID_TURN_GAINS:
        w.u16[0] = ((uint16_t)rxBuf[2] << 8 | rxBuf[1]);
        ui->lineEditTurnKP->setText(QString::number(w.f/100.0, 'f', 2));

        w.u16[0] = ((uint16_t)rxBuf[4] << 8 | rxBuf[3]);
        ui->lineEditTurnKI->setText(QString::number(w.f/100.0, 'f', 2));

        w.u16[0] = ((uint16_t)rxBuf[6] << 8 | rxBuf[5]);
        ui->lineEditTurnKD->setText(QString::number(w.f/100.0, 'f', 2));

        w.i32 = 0;
        w.i8[0] = static_cast <int8_t> (rxBuf[7]);
        ui->lineEditTurnMin->setText(QString::number(w.i8[0], 'd', 2));

        w.i8[0] = static_cast <int8_t> (rxBuf[8]);
        ui->lineEditTurnMax->setText(QString::number(w.i8[0], 'd', 2));

        w.i8[0] = static_cast <int8_t> (rxBuf[9]);
        ui->lineEditTurnBase->setText(QString::number(w.i8[0], 'd', 2));
        break;
    case GET_PID_WALL_GAINS:
        w.u16[0] = ((uint16_t)rxBuf[2] << 8 | rxBuf[1]);
        ui->lineEditWallKP->setText(QString::number(w.f/100.0, 'f', 2));

        w.u16[0] = ((uint16_t)rxBuf[4] << 8 | rxBuf[3]);
        ui->lineEditWallKI->setText(QString::number(w.f/100.0, 'f', 2));

        w.u16[0] = ((uint16_t)rxBuf[6] << 8 | rxBuf[5]);
        ui->lineEditWallKD->setText(QString::number(w.f/100.0, 'f', 2));

        w.i32 = 0;
        w.i8[0] = static_cast <int8_t> (rxBuf[7]);
        ui->lineEditWallMin->setText(QString::number(w.i8[0], 'd', 2));

        w.i8[0] = static_cast <int8_t> (rxBuf[8]);
        ui->lineEditWallMax->setText(QString::number(w.i8[0], 'd', 2));

        w.i8[0] = static_cast <int8_t> (rxBuf[9]);
        ui->lineEditWallBase->setText(QString::number(w.i8[0], 'd', 2));
        break;
    case GET_INTERSECTION_TYPE:
        uint8_t intersectionIndex = rxBuf[1];

        if (intersectionIndex & (1 << 0)) {
            ui->labelRightIntersectionState->setText("|");
            ui->labelRightIntersectionState->setStyleSheet("color: rgb(255, 136, 0); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        } else {
            ui->labelRightIntersectionState->setText("→");
            ui->labelRightIntersectionState->setStyleSheet("color: rgb(50, 205, 50); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        }

        if (intersectionIndex & (1 << 1)) {
            ui->labelFrontIntersectionState->setText("-");
            ui->labelFrontIntersectionState->setStyleSheet("color: rgb(255, 136, 0); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        } else {
            ui->labelFrontIntersectionState->setText("↑");
            ui->labelFrontIntersectionState->setStyleSheet("color: rgb(50, 205, 50); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        }

        if (intersectionIndex & (1 << 2)) {
            ui->labelLeftIntersectionState->setText("|");
            ui->labelLeftIntersectionState->setStyleSheet("color: rgb(255, 136, 0); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        } else {
            ui->labelLeftIntersectionState->setText("←");
            ui->labelLeftIntersectionState->setStyleSheet("color: rgb(50, 205, 50); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        }

        break;
    //case SERVO_CONFIG:
        /*
        uint16_t min, max;
        w.u8[0] = rxBuf[1+2];
        w.u8[1] = rxBuf[2+2];
        min = w.u16[0];

        w.i8[0] = rxBuf[3+2];
        w.i8[1] = rxBuf[4+2];
        max = w.u16[0];

        emit maxMinValues(min, max);
        */
      //  break;
    }
}

void QForm1::SendCMD(uint8_t *buf, uint8_t length){
    uint8_t tx[256];
    uint8_t cks, i;
    QString strHex;

    if((!QSerialPort1->isOpen())&&(!QUdpSocket1->isOpen()))
        return;

    tx[0] = 'U';
    tx[1] = 'N';
    tx[2] = 'E';
    tx[3] = 'R';
    tx[4] = length +1 ; //+ 3;
    tx[5] = ':';

    memcpy(&tx[6], buf, length); //8

    cks = 0;

    for (i=0; i<(length+6); i++){ //+8
        cks ^= tx[i];
    }

    tx[i] = cks;

    strHex = "--> 0x";

    for (int i=0; i<length+7; i++){ //+9
        strHex = strHex + QString("%1").arg(tx[i], 2, 16, QChar('0')).toUpper();
    }

    ui->plainTextEdit->appendPlainText(strHex);

    if (QUdpSocket1->isOpen())
        QUdpSocket1->writeDatagram((char *)tx, length+7, hostAddres, remotePort); //+9

    if (QSerialPort1->isOpen())
        QSerialPort1->write((char *)tx, length+7); //+9
}

void QForm1::on_OpenWifiButton_clicked(){
    bool ok;
    if(QUdpSocket1->isOpen()){
        QUdpSocket1->abort();
        QUdpSocket1->close();
        ui->OpenWifiButton->setText("OPEN");
        ui->WifiLineEdit->setText(QString("%1").arg(port, 2, 10, QChar('0')));
        //ui->WifiLineEdit->setPlaceholderText("Wifi Port");
    }else{
        port = ui->WifiLineEdit->text().toInt(&ok);
        if(!ok)
            return;
        QUdpSocket1->bind(port);

        if(QUdpSocket1->open(QUdpSocket::ReadWrite)){
                ui->OpenWifiButton->setText("CLOSE");
        }else{
            QMessageBox::information(this, tr("SERVER PORT"),tr("ERRRO. Number PORT."));
        }
    }
}

void QForm1::on_OpenPortButton_clicked(){

    if(QSerialPort1->isOpen()){
        QSerialPort1->close();
        ui->OpenPortButton->setText("OPEN");
    } else {
        if(ui->comboBoxCommunication->currentText() == "")
            return;

        QSerialPort1->setPortName(ui->comboBoxCommunication->currentText());
        QSerialPort1->setBaudRate(115200);
        QSerialPort1->setParity(QSerialPort::NoParity);
        QSerialPort1->setDataBits(QSerialPort::Data8);
        QSerialPort1->setStopBits(QSerialPort::OneStop);
        QSerialPort1->setFlowControl(QSerialPort::NoFlowControl);

        if(QSerialPort1->open(QSerialPort::ReadWrite)){
            ui->OpenPortButton->setText("CLOSE");
        }
        else {
            QMessageBox::information(nullptr, "Serial PORT", "ERROR OPENING PORT");
        }
    }
}

void QForm1::on_buttonClear_clicked(){
    ui->plainTextEdit->clear();
    DrawBackground();
}

void QForm1::on_SendCommandButton_clicked(){
    uint8_t cmd, buf[24];
//    _work w;
    int n;
    bool ok = false;
    //QString strHex;

    if(ui->comboBoxSendCommand->currentText() == "")
        return;

    cmd = ui->comboBoxSendCommand->currentData().toInt();
    ui->plainTextEdit->appendPlainText("0x" + (QString("%1").arg(cmd, 2, 16, QChar('0'))).toUpper());

    n = 0;
    switch (cmd) {
        case ALIVE://ALIVE   PC=>MBED 0xF0 ;  MBED=>PC 0xF0 0x0D
            n = 1;
            ok = true;
            break;
        case GET_FIRMWARE_INFO://FIRMWARE   PC=>MBED 0xF1 ;  MBED=>PC 0xF1 FIRMWARE
            n = 1;
            ok = true;
            break;
        case GET_BUTTON_STATE://PULSADORES   PC=>MBED 0x12 ;  MBED=>PC 0x12 VALOR PULSADORES
            n = 1;
            ok = true;
            break;
        case GET_IR_SENSORS://TCRT5000    PC=>MBED LEER;  MBED=>PC VALUES 1, 2, 3;
            n = 1;
            ok = true;
            break;
        case SET_MOTOR_TEST://MOTORES  PC=>MBED POWERM1, POWERM2;  MBED=>PC ACKNOWLEDGE
            if(dialog->isHidden())
                dialog->show();
            break;
        case GET_MOTOR_SPEED:
            n = 1;
            ok = true;
            break;
        default:
        ;
    }
    if(ok == true){
        buf[0] = cmd;
        SendCMD(buf, n);
        ok = false;
    }
}

void QForm1::EngineTest(uint8_t Eng1, uint8_t Eng2){
    //_work w;
    uint8_t buf[3];

    buf[0] = SET_MOTOR_TEST;

    buf[1] = Eng1;
    buf[2] = Eng2;
    SendCMD(buf, 3);
    /*
    w.i32 = Eng2;
    for(uint8_t i=0; i<4; i++)
        buf[i+5] = w.i8[i];
    SendCMD(buf, 9);
    */
}

void QForm1::InitPaintBox(){
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());
    pen.setWidth(2);
    pen.setColor(QColor(0, 0, 0, 255));
    brush.setColor(QColor(0, 0, 0, 255));
    //pen.setColor(QColor(0, 0, 150, 255));     Blue Windows XP
    //brush.setColor(QColor(0, 0, 150, 255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, widgetSize.width, widgetSize.height);
    painter.translate(ui->widgetRadar->width()/2, ui->widgetRadar->height());

    QPaintBox1->update();
}

void QForm1::DrawBackground(){
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());

    pen.setWidth(2);
    pen.setColor(QColor(55, 55, 64, 255));
    brush.setColor(QColor(55, 55, 64, 255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, widgetSize.width, widgetSize.height);

    pen.setWidth(2);
    pen.setColor(QColor(96, 100, 103, 255));
    brush.setColor(QColor(96, 100, 103, 255));
    brush.setStyle(Qt::BrushStyle::NoBrush);
    painter.setBrush(brush);
    painter.setPen(pen);

    painter.translate(ui->widgetRadar->width()/2, ui->widgetRadar->height()/2);
    painter.drawEllipse(-widgetSize.width/2, -widgetSize.height/2, widgetSize.width, widgetSize.height);
    painter.drawEllipse(-widgetSize.width/4, -widgetSize.height/4, widgetSize.width/2, widgetSize.height/2);
    painter.drawEllipse(-widgetSize.width/8, -widgetSize.height/8, widgetSize.width/4, widgetSize.height/4);
    painter.drawEllipse(-3*widgetSize.width/8, -3*widgetSize.height/8, 3*widgetSize.width/4, 3*widgetSize.height/4);

    painter.drawLine(-widgetSize.width/2, 0, widgetSize.width/2, 0);
    painter.drawLine(0, -widgetSize.height/2, 0, widgetSize.height/2);
    /*
    for(int i=0; i<8; i++){
        //painter.drawLine(x1 y1 x2 y2)
        painter.drawLine(-widgetSize.width/2, 0, widgetSize.width/2, 0);
        painter.drawLine(-widgetSize.width/2, -widgetSize.height/2, widgetSize.width/2, widgetSize.height/2);
        //painter.drawLine(-widgetSize.width, -widgetSize.height, widgetSize.width, widgetSize.height);
        //painter.drawLine(0, -ui->widget->width(), 0, ui->widget->height());
        painter.rotate(45);
    }
    */
    QPaintBox1->update();
}

void QForm1::DrawMovement(){
    DrawBackground();

    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());

    pen.setWidth(3);
    //pen.setColor(QColor(0, 232, 0, 255));
    //brush.setColor(QColor(0, 232, 0, 255));
    //pen.setColor(QColor(0, 232, 232, 255));
    //brush.setColor(QColor(0, 232, 232, 255));
    pen.setColor(QColor(222, 223, 225, 255));
    brush.setColor(QColor(222, 223, 225, 255));
    brush.setStyle(Qt::BrushStyle::NoBrush);
    painter.setBrush(brush);
    painter.setPen(pen);

    //painter.translate(0, ui->widget->height()/2);

    //painter.drawPoint(samples, -(int)acceleration[samples]*25);

    painter.translate(ui->widgetRadar->width()/2, ui->widgetRadar->height()/2);

    painter.drawLine(0, 0, (ui->widgetRadar->width()/2)*cos(yaw * M_PI/180 + M_PI/2), (ui->widgetRadar->height()/2)*-sin(yaw * M_PI/180 + M_PI/2));

    pen.setWidth(3);
    pen.setColor(QColor(255, 255, 0, 255));
    brush.setColor(QColor(255, 255, 0, 255));
    //pen.setColor(QColor(255, 0, 255, 255));rgb(138, 43, 226)
    //brush.setColor(QColor(255, 0, 255, 255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(pen);
    //painter.translate(ui->widget->width()/2, ui->widget->height()/2);

    painter.drawEllipse(QPointF(posValues[0]*4, posValues[1]*4), 10, 10);

    QPaintBox1->update();
}

void QForm1::on_aliveButton_clicked(){
    uint8_t buf[24];
    buf[0] = ALIVE;
    SendCMD(buf, 1);
}

void QForm1::Integrate(){
    float yaw_rad = yaw * M_PI/180.0;

    filtered[X_AXIS] = ALPHA_ACC * filtered[X_AXIS] + (1 - ALPHA_ACC) * accValues[X_AXIS];
    filtered[Y_AXIS] = ALPHA_ACC * filtered[Y_AXIS] + (1 - ALPHA_ACC) * accValues[Y_AXIS];

    // Calcular aceleración respecto al marco de referencia global
    globalAcc[X_AXIS] = filtered[X_AXIS] * cosf(yaw_rad) - filtered[Y_AXIS] * sinf(yaw_rad);
    globalAcc[Y_AXIS] = filtered[Y_AXIS] * sinf(yaw_rad) + filtered[Y_AXIS] * cosf(yaw_rad);

    //Calculate Speed
    deltaAcc = (clock() - deltaAcc) / 1000.0;

    if(ENGINES_ON == 0){
        velValues[X_AXIS] = 0;
        velValues[Y_AXIS] = 0;
        velValues[Z_AXIS] = 0;
        globalAcc[X_AXIS] = 0;
        globalAcc[Y_AXIS] = 0;
        globalAcc[Z_AXIS] = 0;
    } else {
        if (abs(globalAcc[X_AXIS]) > 0.022)
            velValues[X_AXIS] += globalAcc[X_AXIS] * deltaAcc;

        if (abs(globalAcc[Y_AXIS]) > 0.022)
            velValues[Y_AXIS] += globalAcc[Y_AXIS] * deltaAcc;
    }

    //Calculating Position
    if(abs(velValues[X_AXIS]) > 0.01)
        posValues[X_AXIS] += velValues[X_AXIS] * deltaAcc * 100;

    if(abs(velValues[Y_AXIS]) > 0.01)
        posValues[Y_AXIS] += velValues[Y_AXIS] * deltaAcc * 100;

    deltaAcc = clock();

    if(posValues[X_AXIS] > 52)
        posValues[X_AXIS] = 52;
    if(posValues[X_AXIS] < -52)
        posValues[X_AXIS] = -52;

    if(posValues[Y_AXIS] > 30)
        posValues[Y_AXIS] = 30;
    if(posValues[Y_AXIS] < -30)
        posValues[Y_AXIS] = -30;
}

void QForm1::on_powerButton_clicked(){
    if(ENGINES_ON == 0){
        ENGINES_ON = 1;
        ui->leftEnginePowerLabel->setText(QString("%1").arg(100, 1, 10, QChar('0')));
        ui->rightEnginePowerLabel->setText(QString("%1").arg(100, 1, 10, QChar('0')));
    } else {
        ENGINES_ON = 0;
        ui->leftEnginePowerLabel->setText(QString("%1").arg(0, 1, 10, QChar('0')));
        ui->rightEnginePowerLabel->setText(QString("%1").arg(0, 1, 10, QChar('0')));
    }
}


void QForm1::on_debugTabButton_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}


void QForm1::on_telemetryTabButton_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void QForm1::on_homeTabButton_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

void QForm1::on_PIDTabButton_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
}

void QForm1::updateMotorLabel(qreal value)
{
    // Formatea el valor y lo pone en el label
    ui->leftEnginePowerLabel->setText(QString::number(value, 'f', 1));
}

/*
    //Si los motores están apagados, la velocidad disminuye
    if(abs(globalAcc[X_AXIS]) < 0.02 && ENGINES_ON == 0)
        velValues[X_AXIS] = 0, globalAcc[X_AXIS] = 0;

    //Si la aceleración aumenta, la velocidad también
    if(abs(globalAcc[X_AXIS]) > 0.02 && ENGINES_ON == 1)
        velValues[X_AXIS] += globalAcc[X_AXIS] * deltaAcc;

    //Si los motores están apagados, la velocidad disminuye
    if(abs(globalAcc[Y_AXIS]) < 0.02 && ENGINES_ON == 0)
        velValues[Y_AXIS] = 0, globalAcc[Y_AXIS] =0;

    //Si la aceleración aumenta, la velocidad también
    if(abs(globalAcc[Y_AXIS]) > 0.02 && ENGINES_ON == 1)
        velValues[Y_AXIS] += globalAcc[Y_AXIS] * deltaAcc;
*/

/*
void QForm1::on_powerButton_clicked()
{
    if(dialog->isHidden())
        dialog->show();
}
*/

void QForm1::on_setTurnPIDButton_clicked(){
    uint8_t buf[10];
    uint16_t kp, ki, kd;
    buf[0] = SET_PID_TURN_GAINS;

    kp = static_cast<uint16_t> (ui->lineEditTurnKP->text().toFloat() * 100.0f);
    ki = static_cast<uint16_t> (ui->lineEditTurnKI->text().toFloat() * 100.0f);
    kd = static_cast<uint16_t> (ui->lineEditTurnKD->text().toFloat() * 100.0f);

    buf[1] = (uint8_t)(kp & 0xFF);
    buf[2] = (uint8_t)((kp >> 8) & 0xFF);

    buf[3] = (uint8_t)(ki & 0xFF);
    buf[4] = (uint8_t)((ki >> 8) & 0xFF);

    buf[5] = (uint8_t)(kd & 0xFF);
    buf[6] = (uint8_t)((kd >> 8) & 0xFF);

    buf[7] = static_cast<int8_t>(ui->lineEditTurnMin->text().toShort());
    buf[8] = static_cast<int8_t>(ui->lineEditTurnMax->text().toShort());
    buf[9] = static_cast<int8_t>(ui->lineEditTurnBase->text().toShort());

    SendCMD(buf, 10);
}

void QForm1::on_setWallPIDButton_clicked(){
    uint8_t buf[10];
    uint16_t kp, ki, kd;
    buf[0] = SET_PID_WALL_GAINS;

    kp = static_cast<uint16_t> (ui->lineEditWallKP->text().toFloat() * 100.0f);
    ki = static_cast<uint16_t> (ui->lineEditWallKI->text().toFloat() * 100.0f);
    kd = static_cast<uint16_t> (ui->lineEditWallKD->text().toFloat() * 100.0f);

    buf[1] = (uint8_t)(kp & 0xFF);
    buf[2] = (uint8_t)((kp >> 8) & 0xFF);

    buf[3] = (uint8_t)(ki & 0xFF);
    buf[4] = (uint8_t)((ki >> 8) & 0xFF);

    buf[5] = (uint8_t)(kd & 0xFF);
    buf[6] = (uint8_t)((kd >> 8) & 0xFF);

    buf[7] = static_cast<int8_t>(ui->lineEditWallMin->text().toShort());
    buf[8] = static_cast<int8_t>(ui->lineEditWallMax->text().toShort());
    buf[9] = static_cast<int8_t>(ui->lineEditWallBase->text().toShort());

    SendCMD(buf, 10);
}

void QForm1::on_pwmConfigButton_clicked(){
    uint8_t buf[4];
    uint16_t aux;

    buf[0] = SET_PWM_CONFIG;

    aux = ui->pwmPrescalerConfig->text().toUShort();

    buf[1] = static_cast<uint8_t>(aux);

    aux = ui->pwmPeriodConfig->text().toUShort();
    buf[2] = (uint8_t)(aux & 0xFF);
    buf[3] = (uint8_t)((aux >> 8) & 0xFF);

    SendCMD(buf, 4);
}


void QForm1::on_pwmPrescalerConfig_textChanged(const QString &arg1){
    updateResultingFrequency();
}


void QForm1::on_pwmPeriodConfig_textChanged(const QString &arg1){
    updateResultingFrequency();
}

void QForm1::updateResultingFrequency(){
    bool ok1, ok2;

    double prescaler = ui->pwmPrescalerConfig->text().toDouble(&ok1);
    double period = ui->pwmPeriodConfig->text().toDouble(&ok2);

    if (ok1 && ok2 && prescaler >= 0 && period >= 0) {
        const double clock = 72000000.0;

        if ((prescaler + 1) * (period + 1) == 0) {
            ui->labelTimerFreqResult->setText("Error: Div by zero");
            return;
        }
        double freq = clock / (prescaler + 1) / (period + 1);

        ui->labelTimerFreqResult->setText(formatFrequency(freq));


    } else {
        ui->labelTimerFreqResult->setText("-");
    }
}

QString QForm1::formatFrequency(double frequencyHz){
    uint8_t precision = 2;

    if (qFuzzyCompare(frequencyHz, 0)) {
        return QString::number(0.0, 'f', precision) + " Hz";
    }

    const double KILO = 1000.0;
    const double MEGA = KILO * KILO;
    const double GIGA = MEGA * KILO;

    double absFreq = std::fabs(frequencyHz);
    QString unit;
    double valueToFormat;

    if (absFreq >= GIGA) {
        valueToFormat = frequencyHz / GIGA;
        unit = "GHz";
    } else if (absFreq >= MEGA) {
        valueToFormat = frequencyHz / MEGA;
        unit = "MHz";
    } else if (absFreq >= KILO) {
        valueToFormat = frequencyHz / KILO;
        unit = "kHz";
    } else {
        valueToFormat = frequencyHz;
        unit = "Hz";
    }

    // Siempre usa formato de punto fijo con la precisión especificada.
    return QString::number(valueToFormat, 'f', precision) + " " + unit;
}

void QForm1::on_readTurnPIDButton_clicked(){
    uint8_t buf[1];

    buf[0] = GET_PID_TURN_GAINS;

    SendCMD(buf, 1);
}


void QForm1::on_readWallPIDButton_clicked(){
    uint8_t buf[1];

    buf[0] = GET_PID_WALL_GAINS;

    SendCMD(buf, 1);
}

