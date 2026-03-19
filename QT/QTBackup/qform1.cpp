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

    {
        // Nombramos el widget como "qmlDisplayWidget" en el paso 3
        QQuickWidget* qmlWidget = ui->qmlDisplayWidget;

        connect(qmlWidget, &QQuickWidget::statusChanged, this, [this, qmlWidget](QQuickWidget::Status status) {
            if (status == QQuickWidget::Ready) {
                // El QML ha terminado de cargar. ¡AHORA es seguro acceder a los objetos!
                m_qmlRootObject = qmlWidget->rootObject();
                if (!m_qmlRootObject) {
                    qWarning() << "Error: QML cargado pero el objeto raíz es nulo.";
                    return;
                }

                connect(m_qmlRootObject, SIGNAL(animationFinished()), this, SLOT(onAnimationDone()));

                // Opcional: puedes hacer una prueba inicial aquí
                qInfo() << "QML cargado con éxito. Intentando una actualización inicial...";
                this->updateFrontSensor(true); // Prueba para ver si funciona
                this->updateCarPosition(0.5);
            } else if (status == QQuickWidget::Error) {
                // Si hubo un error cargando el QML, lo mostramos.
                qWarning() << "Error al cargar QML:" << qmlWidget->errors();
            }
        });

        // Cargamos el QML desde los recursos
        // qmlWidget->setSource(QUrl("qrc:/img/Screen01.ui.qml"));
        qmlWidget->setSource(QUrl("qrc:/3d/road3D.qml"));

        // // Guardamos una referencia al objeto raíz del QML para poder manipularlo
        // m_qmlRootObject = qmlWidget->rootObject();

        // if (!m_qmlRootObject) {
        //     qWarning() << "Error: no se pudo cargar el objeto raíz de QML.";
        // }
    }

    {
        QQuickWidget* widget3D = ui->viewer3D; // Obtenemos el puntero al NUEVO widget

        // 2. Cargamos el archivo QML para la escena 3D desde su nueva ruta en los recursos
        widget3D->setSource(QUrl("qrc:/3d/Screen01.ui.qml")); // ¡OJO A LA RUTA!

        // 3. (Opcional) Guardar una referencia a su objeto raíz
        // Si no necesitas interactuar con el modelo 3D desde C++ (y parece que no,
        // ya que la animación es autónoma), no necesitas hacer esto. Pero si quisieras
        // en el futuro (ej: cambiar el color del coche desde un botón C++), lo harías así:
        QQuickItem* rootObject3D = widget3D->rootObject();
        if (!rootObject3D) {
            qWarning() << "Error: no se pudo cargar el objeto raíz de QML para quickWidget3D.";
        }
    }

    // 1. Cargar la imagen del cursor desde los recursos
    QPixmap cursorPixmap(":/cursor/mouse-pointer.png");

    if (cursorPixmap.isNull()) {
        qWarning() << "Error: No se pudo cargar la imagen del cursor desde los recursos.";
    } else {
        // 3. Crear y aplicar el cursor solo si la imagen es válida
        QCursor myCustomCursor(cursorPixmap, 2, 0); // El hot spot (5, 0) debe estar dentro de las dimensiones de la imagen
        this->setCursor(myCustomCursor);
    }

    {
        ui->comboBoxSendCommand->addItem("ALIVE", 0xF0);
        ui->comboBoxSendCommand->addItem("FIRMWARE INFO", 0xF1);
        //ui->comboBox_2->addItem("BUTTONS", 0x12);
        ui->comboBoxSendCommand->addItem("IR SENSORS", 0xA0);
        //ui->comboBox_2->addItem("ENGINE TEST", 0xA1);
        ui->comboBoxSendCommand->addItem("GET_MPU_DATA", 0xA2);
        //ui->comboBox_2->addItem("ENGINES", 0xA3);
    }

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
    updateMotorPower(0, 0);
    updateCarPosition(0.5);

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
    std::memset(mapData.maze, 0, sizeof(mapData.maze));
    mapData.currentDirection = 0;
    mapData.currentX = 0;
    mapData.currentY = 0;

    mapData.maze[0][0].visited = 1;
    mapData.maze[0][0].walls = 0x0E;
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

    static double carPos = 0.0;
    static double power = 0.0;

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
                // buf[0] = GET_MPU_DATA;
                // SendCMD(buf, 1);
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
        time500ms = 40;
        // if (carPos < 1.0)
        //     carPos += 0.004;
        // else
        //     carPos = 0.0;
        // updateCarPosition(carPos);

        if (power < 1.0)
            power += 0.001;
        else
            power = 0;

        updateMotorPower(power, power);
    } else {
        time500ms--;
    }

    DrawMovement();

    switch(ui->stackedWidget->currentIndex()){
    case 0:
        ui->homeTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->telemetryTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->debugTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->PIDTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
                ui->viewTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        break;
    case 1:
        ui->telemetryTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->homeTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->debugTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->PIDTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
                ui->viewTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        break;
    case 2:
        ui->PIDTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->telemetryTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->homeTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->debugTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
                ui->viewTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        break;
    case 3:
        ui->debugTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->telemetryTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->homeTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->PIDTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->viewTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        break;
    case 4:
        ui->viewTabButton->setStyleSheet("color: rgb(79, 216, 218); background-color: rgb(33, 37, 40); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->debugTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->homeTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->PIDTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
        ui->telemetryTabButton->setStyleSheet("color: rgb(222, 223, 225); background-color: rgb(46, 49, 55); font: 13pt Century Gothic; font-weight: bold; border: 0px;");
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
        int16_t leftIR, rightIR;
        int16_t centerDifference;
        double normalizedMovement;
        double newCarPos;

        rightIR = (rxBuf[2] << 8) | rxBuf[1];
        leftIR = (rxBuf[14] << 8) | rxBuf[13];

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

        centerDifference = rightIR - leftIR;

        if (abs(centerDifference) < CENTER_CAR_DEADZONE)
            centerDifference = 0;

        normalizedMovement = (centerDifference) / 4095.0;
        newCarPos = 0.5 - (normalizedMovement * 0.5);

        if (newCarPos > 0.65)
            newCarPos = 0.65;
        else if (newCarPos < 0.35)
            newCarPos = 0.35;

        updateCarPosition(newCarPos);

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
        ui->labelRoll->setText(QString("%1").arg(roll));
        ui->labelPitch->setText(QString("%1").arg(pitch));
        ui->labelYaw->setText(QString("%1").arg(yaw));
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
        ui->labelGyroZ->setText(QString("%1").arg(gyroValues[Z_AXIS]));
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
        ui->lineEditTurnKP->setText(QString::number(w.u16[0]/100.0f, 'f', 2));

        w.u16[0] = ((uint16_t)rxBuf[4] << 8 | rxBuf[3]);
        ui->lineEditTurnKI->setText(QString::number(w.u16[0]/100.0f, 'f', 2));

        w.u16[0] = ((uint16_t)rxBuf[6] << 8 | rxBuf[5]);
        ui->lineEditTurnKD->setText(QString::number(w.u16[0]/100.0f, 'f', 2));

        w.i32 = 0;
        w.i8[0] = static_cast <int8_t> (rxBuf[7]);
        ui->lineEditTurnMin->setText(QString::number(w.i8[0]));

        w.i8[0] = static_cast <int8_t> (rxBuf[8]);
        ui->lineEditTurnMax->setText(QString::number(w.i8[0]));

        w.i8[0] = static_cast <int8_t> (rxBuf[9]);
        ui->lineEditTurnBase->setText(QString::number(w.i8[0]));
        break;
    case GET_PID_WALL_GAINS:
        w.u16[0] = ((uint16_t)rxBuf[2] << 8 | rxBuf[1]);
        ui->lineEditWallKP->setText(QString::number(w.u16[0]/100.0f, 'f', 2));

        w.u16[0] = ((uint16_t)rxBuf[4] << 8 | rxBuf[3]);
        ui->lineEditWallKI->setText(QString::number(w.u16[0]/100.0f, 'f', 2));

        w.u16[0] = ((uint16_t)rxBuf[6] << 8 | rxBuf[5]);
        ui->lineEditWallKD->setText(QString::number(w.u16[0]/100.0f, 'f', 2));

        w.i32 = 0;
        w.i8[0] = static_cast <int8_t> (rxBuf[7]);
        ui->lineEditWallMin->setText(QString::number(w.i8[0]));

        w.i8[0] = static_cast <int8_t> (rxBuf[8]);
        ui->lineEditWallMax->setText(QString::number(w.i8[0]));

        w.i8[0] = static_cast <int8_t> (rxBuf[9]);
        ui->lineEditWallBase->setText(QString::number(w.i8[0]));
        break;
    case GET_INTERSECTION_TYPE:
    {
        uint8_t intersectionIndex = rxBuf[1];

        if (intersectionIndex & (1 << 0)) {
            updateRightSensor(false);
        } else {
            updateRightSensor(true);
        }

        if (intersectionIndex & (1 << 1)) {
            updateFrontSensor(true);
        } else {
            updateFrontSensor(false);
        }

        if (intersectionIndex & (1 << 2)) {
            updateLeftSensor(false);
        } else {
            updateLeftSensor(true);
        }
        // if (intersectionIndex & (1 << 0)) {
        //     ui->labelRightIntersectionState->setText("|");
        //     ui->labelRightIntersectionState->setStyleSheet("color: rgb(255, 136, 0); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        // } else {
        //     ui->labelRightIntersectionState->setText("→");
        //     ui->labelRightIntersectionState->setStyleSheet("color: rgb(50, 205, 50); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        // }

        // if (intersectionIndex & (1 << 1)) {
        //     ui->labelFrontIntersectionState->setText("-");
        //     ui->labelFrontIntersectionState->setStyleSheet("color: rgb(255, 136, 0); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        // } else {
        //     ui->labelFrontIntersectionState->setText("↑");
        //     ui->labelFrontIntersectionState->setStyleSheet("color: rgb(50, 205, 50); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        // }

        // if (intersectionIndex & (1 << 2)) {
        //     ui->labelLeftIntersectionState->setText("|");
        //     ui->labelLeftIntersectionState->setStyleSheet("color: rgb(255, 136, 0); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        // } else {
        //     ui->labelLeftIntersectionState->setText("←");
        //     ui->labelLeftIntersectionState->setStyleSheet("color: rgb(50, 205, 50); font: 13pt Siemens Sans; font-weight: bold; background-color: transparent");
        // }
    }
        break;
    case GET_MAP_INFO:
        mapData.currentX = rxBuf[1];
        mapData.currentY = rxBuf[2];
        mapData.maze[mapData.currentX][mapData.currentY].walls = rxBuf[3];
        mapData.currentDirection = rxBuf[4];
        mapData.maze[mapData.currentX][mapData.currentY].visited = 1;
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

void QForm1::on_buttonClearMap_clicked(){
    ui->plainTextEdit->clear();
    DrawBackground();

    isMirrored = !isMirrored;
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
    QPen tapePen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());

    painter.setRenderHint(QPainter::Antialiasing);

    pen.setWidth(3);
    //pen.setColor(QColor(55, 55, 64, 255));
    pen.setColor(QColor(33, 37, 40, 255));
    //brush.setColor(QColor(55, 55, 64, 255));
    brush.setColor(QColor(33, 37, 40, 255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, widgetSize.width, widgetSize.height);

    pen.setWidth(3);
    // pen.setColor(QColor(96, 100, 103, 255));
    // brush.setColor(QColor(96, 100, 103, 255));
    pen.setColor(QColor(57, 63, 68, 255));
    brush.setColor(QColor(57, 63, 68, 255));
    brush.setStyle(Qt::BrushStyle::NoBrush);
    painter.setBrush(brush);
    painter.setPen(pen);

    // Laberinto
    int minX = 10, maxX = 0;
    int minY = 10, maxY = 0;

    // Recorrer todo el array para encontrar los extremos visitados
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            if (mapData.maze[x][y].visited) {
                if (x < minX) minX = x;
                if (x > maxX) maxX = x;
                if (y < minY) minY = y;
                if (y > maxY) maxY = y;
            }
        }
    }

    // Asegurar un tamaño mínimo (ej. 1x1) para no dividir por cero
    if (minX > maxX) { minX = 0; maxX = 0; minY = 0; maxY = 0; }

    // Dimensiones del área explorada
    int mapWidth = maxX - minX + 1;
    int mapHeight = maxY - minY + 1;

    // 3. Calcular CellSize dinámico
    // IMPORTANTE: Si estamos rotados 90 o 270, invertimos ancho/alto para el cálculo
    int effectiveWidgetW = ui->widgetRadar->width();
    int effectiveWidgetH = ui->widgetRadar->height();

    // Si la rotación es 90 o 270, comparamos ancho del widget con ALTO del mapa
    if (rotationAngle == 90 || rotationAngle == 270) {
        std::swap(effectiveWidgetW, effectiveWidgetH);
    }

    // Margen para que no toque los bordes (ej. 20px)
    int margin = 20;

    // Calcular el tamaño de celda (el menor de los dos para mantener proporción cuadrada)
    // Usamos qMin para asegurar que quepan tanto en ancho como en alto
    int cellSize = qMin((effectiveWidgetW - margin) / mapWidth,
                        (effectiveWidgetH - margin) / mapHeight);

    int totalDrawW = mapWidth * cellSize;
    int totalDrawH = mapHeight * cellSize;

    // Centrar el dibujo en el widget
    // int offsetX = (w - (mapWidth * cellSize)) / 2;
    // int offsetY = (h - (mapHeight * cellSize)) / 2;
    // Invertir Y si quieres que (0,0) esté abajo a la izquierda (típico en laberintos)
    // int startY = h - offsetY - cellSize;

    // 4. APLICAR TRANSFORMACIONES (LA MAGIA)
    // =========================================================
    painter.save(); // Guardar estado inicial

    // A. Mover el origen (0,0) al CENTRO del widget
    painter.translate(ui->widgetRadar->width() / 2, ui->widgetRadar->height() / 2);

    // B. Rotar
    painter.rotate(rotationAngle);

    // C. ESPEJAR (MIRROR)
    // Si escalamos X por -1, todo lo que se dibuje a la derecha aparecerá a la izquierda.
    if (isMirrored) {
        painter.scale(-1, 1);
    }

    // D. Mover hacia atrás la mitad del tamaño del mapa.
    // Esto hace que el mapa quede centrado en el punto de rotación.
    painter.translate(-totalDrawW / 2, -totalDrawH / 2);


    //painter.setPen(QPen(QColor(222, 223, 225, 255), 3)); // Paredes blancas gruesas
    pen.setColor(QColor(222, 223, 225, 255));
    tapePen.setColor(QColor(60, 60, 60));
    tapePen.setWidth(3);

    painter.setPen(tapePen);

    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if (!mapData.maze[x][y].visited) continue;

            // Coordenadas relativas locales (dentro del sistema transformado)
            int px = (x - minX) * cellSize;
            // Invertimos Y localmente para dibujar de abajo hacia arriba
            int py = totalDrawH - ((y - minY + 1) * cellSize);

            // --- CALCULAR MAX COSTO PARA EL GRADIENTE ---
            int maxCost = 1; // Le ponemos 1 para evitar divisiones por cero por las dudas
            for (int mx = minX; mx <= maxX; mx++) {
                for (int my = minY; my <= maxY; my++) {
                    if (mapData.maze[mx][my].visited && mapData.maze[mx][my].cost != 255) {
                        if (mapData.maze[mx][my].cost > maxCost) {
                            maxCost = mapData.maze[mx][my].cost;
                        }
                    }
                }
            }

            // --- DIBUJAR EL COSTO (FLOOD FILL) ---
            if (mapData.maze[x][y].cost != 255) {
                int cost = mapData.maze[x][y].cost;
                // Mapeamos el costo al color.
                // Multiplicamos por 4 para que el cambio de color sea más rápido.
                // qMax evita que el número sea menor a 0 (que rompería el color rojo).
                int hue = 120 - ((cost * 120) / maxCost);
                hue = qBound(0, hue, 120); // Seguridad para que nunca salga del rango 0-120
                // Setear el color usando la rueda HSV (hue, saturación al 100%, brillo al 100%)
                // painter.setPen(QColor::fromHsv(hue, 255, 255));

                QRect cellRect(px, py, cellSize, cellSize);

                // --- FIX PARA LA BANDERA A CUADROS ---
                if (x == mapData.targetX && y == mapData.targetY) {
                    // Dibujamos un circulito negro semi-transparente de fondo para que el 0 resalte
                    painter.setBrush(QColor(0, 0, 0, 180));
                    painter.setPen(Qt::NoPen);
                    int r = cellSize / 2.5; // Tamaño del fondo oscuro
                    painter.drawEllipse(px + cellSize/2 - r/2, py + cellSize/2 - r/2, r, r);
                }

                // Setear el color calculado y dibujar el número
                painter.setPen(QColor::fromHsv(hue, 255, 255));
                painter.setFont(QFont("Arial", 10, QFont::Bold));

                painter.drawText(cellRect, Qt::AlignCenter, QString::number(cost));
            }

            if (x == mapData.targetX && y == mapData.targetY) {
                int squares = 5; // Cambiá este número si querés los cuadros más chicos o grandes
                float sqSize = (float)cellSize / squares;

                for (int i = 0; i < squares; i++) {
                    for (int j = 0; j < squares; j++) {
                        // Alternamos los colores sumando índices (par/impar)
                        QColor color = ((i + j) % 2 == 0) ? Qt::white : Qt::black;
                        painter.fillRect(px + (i * sqSize), py + (j * sqSize), sqSize, sqSize, color);
                    }
                }
                // Pinta la celda de un rojo semi-transparente
                // painter.fillRect(px, py, cellSize, cellSize, QColor(255, 0, 0, 100));
            }

            // 2. Dibujar paredes
            uint8_t walls = mapData.maze[x][y].walls;
            if (!(walls & (1 << 0))) painter.drawLine(px, py, px + cellSize, py); // Norte
            if (!(walls & (1 << 1))) painter.drawLine(px + cellSize, py, px + cellSize, py + cellSize); // Este
            if (!(walls & (1 << 2))) painter.drawLine(px, py + cellSize, px + cellSize, py + cellSize); // Sur
            if (!(walls & (1 << 3))) painter.drawLine(px, py, px, py + cellSize); // Oeste
        }
    }

    painter.setPen(pen);
    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if (!mapData.maze[x][y].visited) continue;

            int px = (x - minX) * cellSize;
            int py = totalDrawH - ((y - minY + 1) * cellSize);
            uint8_t walls = mapData.maze[x][y].walls;

            if (walls & (1 << 0)) painter.drawLine(px, py, px + cellSize, py); // Norte
            if (walls & (1 << 1)) painter.drawLine(px + cellSize, py, px + cellSize, py + cellSize); // Este
            if (walls & (1 << 2)) painter.drawLine(px, py + cellSize, px + cellSize, py + cellSize); // Sur
            if (walls & (1 << 3)) painter.drawLine(px, py, px, py + cellSize); // Oeste

            // --- ROBOT ---
            if (x == mapData.currentX && y == mapData.currentY) {
                painter.save(); // Guardar estado (para no afectar a las siguientes celdas)

                // 1. Mover el origen al CENTRO de la celda actual
                int cx = px + cellSize / 2;
                int cy = py + cellSize / 2;
                painter.translate(cx, cy);

                // 2. Rotar según la dirección del robot
                // Asumiendo: 0=Norte, 1=Este, 2=Sur, 3=Oeste
                // Multiplicamos por 90 grados.
                painter.rotate(mapData.currentDirection * 90);

                // 3. Crear el triángulo (Apuntando hacia "Arriba" localmente)
                // Como ya rotamos el papel, siempre dibujamos un triángulo mirando al Norte (Arriba)
                // y la rotación se encarga del resto.
                int r = cellSize / 3; // Radio/Tamaño del robot

                QPolygon triangle;
                triangle << QPoint(0, -r);       // Punta (Arriba / Norte visual)
                triangle << QPoint(-r + 2, r);   // Base Izquierda (con un pequeño offset estético)
                triangle << QPoint(r - 2, r);    // Base Derecha

                // 4. Dibujar
                painter.setBrush(QColor(0, 250, 154, 255));       // Color de relleno
                painter.setPen(Qt::NoPen);       // Sin borde
                // Opcional: Borde oscuro para que resalte
                // painter.setPen(QPen(Qt::black, 1));

                painter.drawPolygon(triangle);

                painter.restore(); // Restaurar estado (volver al sistema de coordenadas del mapa)
            }
        }
    }

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
    //pen.setColor(QColor(222, 223, 225, 255));
    //brush.setColor(QColor(222, 223, 225, 255));
    pen.setColor(QColor(0, 250, 154, 255));
    brush.setColor(QColor(0, 250, 154, 255));
    brush.setStyle(Qt::BrushStyle::NoBrush);
    painter.setBrush(brush);
    painter.setPen(pen);
    //painter.translate(0, ui->widget->height()/2);

    //painter.drawPoint(samples, -(int)acceleration[samples]*25);

    // MOVIMIENTO
    // painter.translate(ui->widgetRadar->width()/2, ui->widgetRadar->height()/2);

    // painter.drawLine(0, 0, (ui->widgetRadar->width()/2)*cos(yaw * M_PI/180 + M_PI/2), (ui->widgetRadar->height()/2)*-sin(yaw * M_PI/180 + M_PI/2));

    pen.setWidth(3);
    pen.setColor(QColor(222, 223, 225, 255));
    brush.setColor(QColor(222, 223, 225, 255));
    //pen.setColor(QColor(255, 0, 255, 255));rgb(138, 43, 226)
    //brush.setColor(QColor(255, 0, 255, 255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(pen);
    //painter.translate(ui->widget->width()/2, ui->widget->height()/2);

    // MOVIMIENTO
    // painter.drawEllipse(QPointF(posValues[0]*4, posValues[1]*4), 10, 10);

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

void QForm1::on_viewTabButton_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}

void QForm1::updateMotorPower(double left, double right)
{
    if (!m_qmlRootObject) return;
    QObject *stateController = m_qmlRootObject->findChild<QObject*>("stateController");
    if (stateController) {
        stateController->setProperty("leftMotorPower", left);
        stateController->setProperty("rightMotorPower", right);
    }
}

void QForm1::updateCarPosition(double position)
{
    if (!m_qmlRootObject) return;
    QObject *stateController = m_qmlRootObject->findChild<QObject*>("stateController");
    if (stateController) {
        stateController->setProperty("carPosition", position);
    }
}

void QForm1::updateFrontSensor(bool visible){
    if (!m_qmlRootObject) return; // Siempre comprueba que el objeto exista

    // 1. Buscamos el objeto "stateController" dentro del QML
    QObject *stateController = m_qmlRootObject->findChild<QObject*>("stateController");

    if (stateController) {
        // 2. Establecemos el valor de su propiedad "sensorFrontal"
        stateController->setProperty("sensorFrontal", visible);
    } else {
        qWarning() << "Error: no se encontró el objeto 'stateController' en QML. SF";
    }
}

void QForm1::updateLeftSensor(bool visible){
    if (!m_qmlRootObject) return;
    QObject *stateController = m_qmlRootObject->findChild<QObject*>("stateController");
    if (stateController) {
        stateController->setProperty("sensorIzquierdo", visible);
    }
}

void QForm1::updateRightSensor(bool visible){
    if (!m_qmlRootObject) return;
    QObject *stateController = m_qmlRootObject->findChild<QObject*>("stateController");
    if (stateController) {
        stateController->setProperty("sensorDerecho", visible);
    }
}

void QForm1::triggerForward() {
    if (!m_qmlRootObject) return;
    QMetaObject::invokeMethod(m_qmlRootObject, "triggerMoveForward");
}

void QForm1::triggerLeft() {
    if (!m_qmlRootObject) return;
    QMetaObject::invokeMethod(m_qmlRootObject, "triggerTurnLeft");
}

void QForm1::triggerRight() {
    if (!m_qmlRootObject) return;
    QMetaObject::invokeMethod(m_qmlRootObject, "triggerTurnRight");
}

void QForm1::onAnimationDone() {
    // Esta función se ejecuta cuando el QML termina el "truco" de teletransportarse
    qDebug() << "Animación terminada. Actualizando muros lógicos...";

    // AQUÍ debes actualizar tus sensores con los datos de la NUEVA celda
    // Ejemplo (debes adaptarlo a tu lógica de laberinto):
    // updateFrontSensor(nuevoValorFrontal);
    // updateLeftSensor(nuevoValorIzquierdo);
    // updateRightSensor(nuevoValorDerecho);
}

// void QForm1::updateMotorLabel(qreal value)
// {
//     // Formatea el valor y lo pone en el label
//     ui->leftEnginePowerLabel->setText(QString::number(value, 'f', 1));
// }

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

    QString strKp = ui->lineEditTurnKP->text().replace(",", ".");
    uint32_t rawKp = strKp.toFloat() * 100.0f; // Usar uint32 temporalmente para atrapar overflows
    if(rawKp > 65535) rawKp = 65535;

    QString strKi = ui->lineEditTurnKI->text().replace(",", ".");
    uint32_t rawKi = strKi.toFloat() * 100.0f; // Usar uint32 temporalmente para atrapar overflows
    if(rawKi > 65535) rawKi = 65535;

    QString strKd = ui->lineEditTurnKD->text().replace(",", ".");
    uint32_t rawKd = strKd.toFloat() * 100.0f; // Usar uint32 temporalmente para atrapar overflows
    if(rawKd > 65535) rawKd = 65535;

    kp = static_cast<uint16_t> (rawKp);
    ki = static_cast<uint16_t> (rawKi);
    kd = static_cast<uint16_t> (rawKd);

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

    QString strKp = ui->lineEditWallKP->text().replace(",", ".");
    uint32_t rawKp = strKp.toFloat() * 100.0f; // Usar uint32 temporalmente para atrapar overflows
    if(rawKp > 65535) rawKp = 65535;

    QString strKi = ui->lineEditWallKI->text().replace(",", ".");
    uint32_t rawKi = strKi.toFloat() * 100.0f; // Usar uint32 temporalmente para atrapar overflows
    if(rawKi > 65535) rawKi = 65535;

    QString strKd = ui->lineEditWallKD->text().replace(",", ".");
    uint32_t rawKd = strKd.toFloat() * 100.0f; // Usar uint32 temporalmente para atrapar overflows
    if(rawKd > 65535) rawKd = 65535;

    kp = static_cast<uint16_t> (rawKp);
    ki = static_cast<uint16_t> (rawKi);
    kd = static_cast<uint16_t> (rawKd);

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


void QForm1::on_buttonRotateMap_clicked()
{
    rotationAngle += 90;
    if (rotationAngle >= 360) rotationAngle = 0;
}


void QForm1::on_setBatteryVoltageButton_clicked()
{
    uint8_t buf[3];
    buf[0] = SET_BATTERY_VOLTAGE;

    // Tomar el valor del spinbox, multiplicarlo y hacer bitwise para enviar los MSB y LSB
    double voltageDouble = ui->batteryVoltageSpinBox->value();

    uint16_t voltage = static_cast<uint16_t>(voltageDouble*100);

    buf[1] = static_cast<uint8_t>(voltage & 0xFF);
    buf[2] = static_cast<uint8_t>((voltage >> 8) & 0xFF);

    SendCMD(buf, 3);
}


void QForm1::on_changeThresholdUnitButton_toggled(bool checked)
{

}


void QForm1::on_buttonSetTargetXY_clicked() {
    uint8_t buf[3];

    // Obtenemos los valores de los SpinBoxes de la interfaz
    mapData.targetX = ui->spinBoxTargetX->value();
    mapData.targetY = ui->spinBoxTargetY->value();

    // Armamos el paquete UDP
    buf[0] = 0xEC; // Comando: SET_MAZE_TARGET
    buf[1] = mapData.targetX;
    buf[2] = mapData.targetY;

    SendCMD(buf, 3); // Enviamos los 3 bytes (Comando + X + Y)

    // Forzamos que se redibuje la pantalla para ver la meta pintada
    DrawBackground();
}

void QForm1::setWall(int x, int y, int dir) {
    // Si nos pasamos de los límites, ignoramos
    if (x < 0 || x > 15 || y < 0 || y > 15) return;

    // 1. Pared en la celda actual
    mapData.maze[x][y].walls |= (1 << dir);

    // 2. Pared compartida en la celda vecina
    if (dir == 0 && y < 15) mapData.maze[x][y+1].walls |= (1 << 2); // N -> Vecino S
    if (dir == 1 && x < 15) mapData.maze[x+1][y].walls |= (1 << 3); // E -> Vecino O
    if (dir == 2 && y > 0)  mapData.maze[x][y-1].walls |= (1 << 0); // S -> Vecino N
    if (dir == 3 && x > 0)  mapData.maze[x-1][y].walls |= (1 << 1); // O -> Vecino E
}
void QForm1::on_buttonGenerateMap_clicked()
{
    // 1. Limpiamos cualquier laberinto previo en la memoria
    for(int x = 0; x < 16; x++) {
        for(int y = 0; y < 16; y++) {
            mapData.maze[x][y].walls = 0;
            mapData.maze[x][y].visited = 0;
            mapData.maze[x][y].cost = 255; // Preparamos el costo para el Flood Fill
        }
    }

    // Definimos el tamaño del laberinto de prueba (Ej: 5x5)
    int mazeW = 5;
    int mazeH = 5;

    // 2. Armamos el piso y el perímetro exterior cerrado
    for (int x = 0; x < mazeW; x++) {
        for (int y = 0; y < mazeH; y++) {
            mapData.maze[x][y].visited = 1; // Lo marcamos como visitado para que Qt lo dibuje

            if (x == 0) setWall(x, y, 3); // Borde Oeste
            if (x == mazeW - 1) setWall(x, y, 1); // Borde Este
            if (y == 0) setWall(x, y, 2); // Borde Sur
            if (y == mazeH - 1) setWall(x, y, 0); // Borde Norte
        }
    }

    // 3. Agregamos las paredes internas para armar un camino (Diseño libre)
    // Usamos: 0=Norte, 1=Este, 2=Sur, 3=Oeste
    setWall(0, 0, 0); // Bloqueamos ir al norte desde la salida
    setWall(1, 0, 1);
    setWall(4, 0, 0);
    setWall(1, 1, 0);
    setWall(2, 1, 0);
    setWall(3, 1, 1);
    setWall(0, 2, 0);
    setWall(0, 2, 1);
    setWall(0, 3, 0);
    setWall(1, 3, 1);
    setWall(3, 2, 0);
    setWall(3, 4, 0);
    setWall(3, 4, 1);
    setWall(3, 4, 3);
    // setWall(2, 2, 2);
    // setWall(3, 1, 3);
    // setWall(3, 3, 2);
    // setWall(4, 2, 3);
    // (Podés agregar todos los SetWall que quieras acá para hacerlo más difícil)

    // 4. Seteamos al robot en la salida y definimos la meta
    mapData.currentX = 0;
    mapData.currentY = 0;
    mapData.currentDirection = 1; // Mirando al Este (Derecha)

    mapData.targetX = mazeW - 1; // Esquina superior derecha
    mapData.targetY = mazeH - 1;

    // 5. Forzamos el redibujado
    DrawBackground();
}

void QForm1::calculateFloodFill() {
    // 1. Reiniciamos todos los costos a 255 (infinito / no calculado)
    for(int x = 0; x < 16; x++) {
        for(int y = 0; y < 16; y++) {
            mapData.maze[x][y].cost = 255;
        }
    }

    // 2. Creamos una cola simple para el algoritmo BFS.
    // Como el laberinto máximo es de 16x16, 256 posiciones de memoria son suficientes.
    struct Point { int x, y; };
    Point queue[256];
    int head = 0; // Índice de lectura
    int tail = 0; // Índice de escritura

    // 3. Establecemos la meta, le damos costo 0 y la metemos en la cola
    mapData.maze[mapData.targetX][mapData.targetY].cost = 0;
    queue[tail++] = {mapData.targetX, mapData.targetY};

    // 4. Comenzamos la "inundación"
    while (head < tail) {
        Point p = queue[head++]; // Sacamos la primera celda de la cola
        int cx = p.x;
        int cy = p.y;

        int currentCost = mapData.maze[cx][cy].cost;
        uint8_t walls = mapData.maze[cx][cy].walls;

        // Revisar vecino NORTE (dir = 0)
        // Si no hay pared al Norte y no nos salimos del mapa
        if (!(walls & (1 << 0)) && cy < 15) {
            if (mapData.maze[cx][cy+1].cost == 255) { // Si el vecino no fue visitado por el agua
                mapData.maze[cx][cy+1].cost = currentCost + 1; // Su costo es 1 paso más
                queue[tail++] = {cx, cy+1}; // Lo encolamos para evaluar a SUS vecinos luego
            }
        }

        // Revisar vecino ESTE (dir = 1)
        if (!(walls & (1 << 1)) && cx < 15) {
            if (mapData.maze[cx+1][cy].cost == 255) {
                mapData.maze[cx+1][cy].cost = currentCost + 1;
                queue[tail++] = {cx+1, cy};
            }
        }

        // Revisar vecino SUR (dir = 2)
        if (!(walls & (1 << 2)) && cy > 0) {
            if (mapData.maze[cx][cy-1].cost == 255) {
                mapData.maze[cx][cy-1].cost = currentCost + 1;
                queue[tail++] = {cx, cy-1};
            }
        }

        // Revisar vecino OESTE (dir = 3)
        if (!(walls & (1 << 3)) && cx > 0) {
            if (mapData.maze[cx-1][cy].cost == 255) {
                mapData.maze[cx-1][cy].cost = currentCost + 1;
                queue[tail++] = {cx-1, cy};
            }
        }
    }

    // Forzamos que la interfaz se redibuje para mostrar los números
    DrawBackground();
}

void QForm1::on_buttonCalculatePath_clicked()
{
    calculateFloodFill();
}

