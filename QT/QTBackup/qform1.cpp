#include "qform1.h"
#include "ui_qform1.h"

QForm1::QForm1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QForm1)
{
    ui->setupUi(this);
    QSerialPort1=new QSerialPort(this);
    dialog = new Dialog(this);
    ui->comboBox->installEventFilter(this);

    ui->comboBox_2->addItem("ALIVE", 0xF0);
    //ui->comboBox_2->addItem("FIRMWARE", 0xF1);
    //ui->comboBox_2->addItem("LEDS", 0x10);
    //ui->comboBox_2->addItem("BUTTONS", 0x12);
    ui->comboBox_2->addItem("INFRARED SENSORS", 0xA0);
    //ui->comboBox_2->addItem("ENGINE TEST", 0xA1);
    ui->comboBox_2->addItem("ACCELERATION", 0xA2);
    //ui->comboBox_2->addItem("ENGINES", 0xA3);

    QUdpSocket1 = new QUdpSocket(this);
    connect(QUdpSocket1,&QUdpSocket::readyRead,this,&QForm1::onRxUDP);

    header=0;
    connect(QSerialPort1,&QSerialPort::readyRead, this,&QForm1::OnRxChar);
    connect(dialog, &Dialog::powEng, this, &QForm1::EngineTest);
    connect(this, &QForm1::maxMinValues, dialog, &Dialog::displayMaxMin);

    QPaintBox1 = new QPaintBox(ui->widget->width(), ui->widget->height()+10, ui->widget);
    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &QForm1::OnQTimer1);
    QTimer1->start(10);

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
    ui->lcdAccX->display(QString("0.000"));
    ui->lcdAccY->display(QString("0.000"));
    ui->lcdAccZ->display(QString("0.000"));
    ui->lcdSpeedX->display(QString("0.000"));
    ui->lcdSpeedY->display(QString("0.000"));
    ui->lcdSpeedZ->display(QString("0.000"));
    ui->lcdPosX->display(QString("0.000"));
    ui->lcdPosY->display(QString("0.000"));
    ui->lcdPosZ->display(QString("0.000"));

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
    if(watched == ui->comboBox) {
        if (event->type() == QEvent::MouseButtonPress) {
            ui->comboBox->clear();
            QSerialPortInfo SerialPortInfo1;

            for(int i=0;i<SerialPortInfo1.availablePorts().count();i++)
                ui->comboBox->addItem(SerialPortInfo1.availablePorts().at(i).portName());

            return QMainWindow::eventFilter(watched, event);
        } else {
            return false;
        }
    } else {
         return QMainWindow::eventFilter(watched, event);
    }
}

void QForm1::OnQTimer1(){
    static uint8_t time100ms = 2;
    uint8_t buf[1];

    if(widgetSize.width != ui->widget->width() || widgetSize.height != ui->widget->height()){
        //QPaintBox1->resize(ui->widget->width(), ui->widget->height());

        widgetSize.width = ui->widget->width();
        widgetSize.height = ui->widget->height();
        QPaintBox1->resize(widgetSize.width, widgetSize.height);
        DrawBackground();
    }

    if(time100ms == 0){
        time100ms = 3;
        Heartbeat();
        //buf[0] = IRSENSOR;
        //SendCMD(buf, 1);
        buf[0] = ACCELERATION;
        SendCMD(buf, 1);
    } else {
        time100ms--;
    }

    DrawMovement();
    //buf[0] = IRSENSOR;
    //SendCMD(buf, 1);

    /*
    buf[0] = SPEED;
    SendCMD(buf, 1);

    buf[0] = DISTANCIA;
    SendCMD(buf, 1);
    */
}

void QForm1::Heartbeat(){
    uint8_t write;
    uint8_t buf[1];
    write = ~(mask>>moveMask) & 1;
    moveMask++;
    moveMask ^= (moveMask & 16);

    if(write == 0)
        buf[0] = ALIVE, SendCMD(buf ,1);
    else
        ui->aliveButton->setStyleSheet("color: white; background-color: rgb(189, 206, 214); font: 9pt MS Sans Serif; font-weight: bold; color: rgb(47, 55, 77);");
}

/*
void QForm1::onRxUDP(){
    uint8_t buff[256];
    qint64 count = 0;

    while(QUdpSocket1->hasPendingDatagrams()){
        count=QUdpSocket1->pendingDatagramSize();

        if(count<=0){
            return;
        }

        QUdpSocket1->readDatagram((char *)buff, count, &hostAddres, &remotePort);
        ui->lineEdit->setText("IPv4: " + (hostAddres.toString().right(hostAddres.toString().length()-7)) + " - REMOTE IP: " + QString().number(remotePort));
        ui->plainTextEdit->appendPlainText((char*)buff);

        for(uint8_t i=0; i<(count - 1); i++){
            if ((buff[i] == '2')&&(buff[i+1] == '1')){
                indexWifi = i;
                break;
            }
        }

      //  DecodeCmd(buff);
        //DecodeCmd(&buff[indexWifi]);
    //}
//}
*/

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

        //ui->plainTextEdit->appendPlainText(strHex);
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

    //ui->plainTextEdit->appendPlainText(strHex);

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

    switch(rxBuf[0]){
    case LEDS:
        break;
    case BUTTONS:
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
    case ALIVE:
        if(rxBuf[1] == ACKNOWLEDGE)//+3
            ui->aliveButton->setStyleSheet("color: white; background-color: rgb(24, 146, 11); font: 9pt MS Sans Serif; font-weight: bold; color: rgb(47, 55, 77);");
        //else
        //ui->aliveButton->setStyleSheet("color: white; background-color: rgb(224, 14, 21); font: 9pt MS Sans Serif; font-weight: bold; color: rgb(47, 55, 77);");
        break;
    case UNKNOWNCOMMAND:
        ui->plainTextEdit->appendPlainText("NO CMD");
        break;
    case ACCELERATION:
        w.i32 = 0;

        w.u8[0] = rxBuf[1];
        w.u8[1] = rxBuf[2];
        w.f = ((int16_t)w.i32)/16384.0 * 9.806;
        //ui->lcdAccX->display(QString("%1").arg(w.f, 1, 'f', 3));
        accValues[X_AXIS] = w.f;

        w.f = 0;
        w.u8[0] = rxBuf[3];
        w.u8[1] = rxBuf[4];
        w.f = ((int16_t)w.i32)/16384.0 * 9.806;
        //ui->lcdAccY->display(QString("%1").arg(w.f, 1, 'f', 3));
        accValues[Y_AXIS] = w.f;

        w.f = 0;
        w.u8[0] = rxBuf[5];
        w.u8[1] = rxBuf[6];
        w.f = ((int16_t)w.i32)/16384.0 * 9.806;
        //ui->lcdAccZ->display(QString("%1").arg(w.f, 1, 'f', 3));
        accValues[Z_AXIS] = w.f;

        w.f = 0;
        w.u8[0] = rxBuf[7];
        w.u8[1] = rxBuf[8];
        w.f = ((int16_t)w.i32)/131.0; // /131.0
        gyroValues[X_AXIS] = w.f;
        //ui->lcdGyroX->display(QString("%1").arg(w.f, 1, 'f', 3));

        w.f = 0;
        w.u8[0] = rxBuf[9];
        w.u8[1] = rxBuf[10];
        w.f = ((int16_t)w.i32)/131.0;
        gyroValues[Y_AXIS] = w.f;
        //ui->lcdGyroY->display(QString("%1").arg(w.f, 1, 'f', 3));

        w.f = 0;
        w.u8[0] = rxBuf[11];
        w.u8[1] = rxBuf[12];
        w.f = ((int16_t)w.i32)/131.0;
        gyroValues[Z_AXIS] = w.f;
        //ui->lcdGyroZ->display(QString("%1").arg(w.f, 1, 'f', 3));

        deltaGyro = (clock() - deltaGyro) / 1000.0;

        //accAngle[X_AXIS] = atan2(accValues[Y_AXIS], sqrt(accValues[X_AXIS]*accValues[X_AXIS] + accValues[Z_AXIS]*accValues[Z_AXIS])) * 180/M_PI;
        //accAngle[Y_AXIS] = atan2(-accValues[X_AXIS], sqrt(accValues[Y_AXIS]*accValues[Y_AXIS] + accValues[Z_AXIS]*accValues[Z_AXIS])) * 180/M_PI;

        //roll += gyroValues[X_AXIS] * deltaGyro;
        //pitch += gyroValues[Y_AXIS] * deltaGyro;

        //drift = gyroValues[Z_AXIS] * deltaGyro;

        if(gyroValues[Z_AXIS] > 0.15 || gyroValues[Z_AXIS] < -0.15)
            yaw += gyroValues[Z_AXIS] * deltaGyro;

        /*
        if(gyroValues[X_AXIS] > 0.05 || gyroValues[X_AXIS] < -0.05)
            roll = _TAU * (roll + gyroValues[Y_AXIS] * deltaGyro) + (1 - _TAU) * accAngle[X_AXIS];
        //roll = _TAU * roll + (1 - _TAU) * accAngle[X_AXIS];

        if(gyroValues[Y_AXIS] > 0.05 || gyroValues[Y_AXIS] < -0.05)
            pitch = _TAU * (pitch + gyroValues[X_AXIS] * deltaGyro) + (1 - _TAU) * accAngle[Y_AXIS];
        //pitch = _TAU * pitch + (1 - _TAU) * accAngle[Y_AXIS];
        */

        //roll = _TAU * (roll + gyroValues[y] * DELTA_TIME) + (1 - _TAU) * accAngle[x];
        //pitch = _TAU * (pitch + gyroValues[x] * DELTA_TIME) + (1 - _TAU) * accAngle[y];

        //yaw += gyroValues[z] * DELTA_TIME;

        //ui->lcdGyroX->display(QString("%1").arg(roll, 1, 'f', 3));
        //ui->lcdGyroY->display(QString("%1").arg(pitch, 1, 'f', 3));
        ui->lcdGyroZ->display(QString("%1").arg(yaw, 1, 'f', 3));

        //ui->lcdIR8->display(QString("%1").arg(drift, 1, 'f', 3));

        deltaGyro = clock();
        Integrate();
        break;
    case IRSENSOR:
        //uint16_t irValues[8];
        //w.u32 = 0;

        /*
        for(uint8_t i=0; i<16; i++){
            w.i32 = 0;
            w.u8[0] = rxBuf[++i];
            w.u8[1] = rxBuf[i+1];
            irValues[0] = w.i32;
        }

        for(uint8_t i=0; i<8; i++)
            ui->plainTextEdit->appendPlainText("IR: " + QString("%1").arg(irValues[i], 1, 10, QChar('0')));
        */

        /*
        for(uint8_t i=0; i<8; i++){
            irValues[i] = rxBuf[i+1];
        }

        w.u8[0] = rxBuf[1];
        w.u8[1] = rxBuf[2];
        //w.i32 = irValues[0];
        ui->lcdIR1->display(QString("%1").arg(w.i32, 1, 10, QChar('0'))); //+2
        //ui->plainTextEdit->appendPlainText("IR1: " + QString("%1").arg(w.i32, 1, 10, QChar('0')));

        //w.i32 = 0;
        w.u8[0] = rxBuf[3];
        w.u8[1] = rxBuf[4];
        //w.i32 = irValues[2];
        ui->lcdIR2->display(QString("%1").arg(w.i32, 1, 10, QChar('0'))); //+2
        //ui->plainTextEdit->appendPlainText("IR2: " + QString("%1").arg(w.i32, 1, 10, QChar('0')));

        //w.i32 = 0;
        w.u8[0] = rxBuf[5];
        w.u8[1] = rxBuf[6];
        ui->lcdIR3->display(QString("%1").arg(w.i32, 1, 10, QChar('0'))); //+2
        //ui->plainTextEdit->appendPlainText("IR3: " + QString("%1").arg(w.i32, 1, 10, QChar('0')));

        //w.i32 = 0;
        w.u8[0] = rxBuf[7];
        w.u8[1] = rxBuf[8];
        ui->lcdIR4->display(QString("%1").arg(w.i32, 1, 10, QChar('0'))); //+2
        //ui->plainTextEdit->appendPlainText("IR4: " + QString("%1").arg(w.i32, 1, 10, QChar('0')));

        //w.i32 = 0;
        w.u8[0] = rxBuf[9];
        w.u8[1] = rxBuf[10];
        ui->lcdIR5->display(QString("%1").arg(w.i32, 1, 10, QChar('0'))); //+2
        //ui->plainTextEdit->appendPlainText("IR5: " + QString("%1").arg(w.i32, 1, 10, QChar('0')));

        //w.i32 = 0;
        w.u8[0] = rxBuf[11];
        w.u8[1] = rxBuf[12];
        ui->lcdIR6->display(QString("%1").arg(w.i32, 1, 10, QChar('0'))); //+2
        //ui->plainTextEdit->appendPlainText("IR6: " + QString("%1").arg(w.i32, 1, 10, QChar('0')));

        //w.i32 = 0;
        w.u8[0] = rxBuf[13];
        w.u8[1] = rxBuf[14];
        ui->lcdIR7->display(QString("%1").arg(w.i32, 1, 10, QChar('0'))); //+2
        //ui->plainTextEdit->appendPlainText("IR7: " + QString("%1").arg(w.i32, 1, 10, QChar('0')));

        //w.i32 = 0;
        w.u8[0] = rxBuf[15];
        w.u8[1] = rxBuf[16];
        ui->lcdIR8->display(QString("%1").arg(w.i32, 1, 10, QChar('0'))); //+2
        //ui->plainTextEdit->appendPlainText("IR8: " + QString("%1").arg(w.i32, 1, 10, QChar('0')));
*/
        break;
    case TEST_ENGINE:
        if(rxBuf[1] == ACKNOWLEDGE)
            ui->plainTextEdit->appendPlainText("ENGINES OK");
        break;
    case ENGINES:
        w.i32 = 0;
        w.i8[0] = rxBuf[1];
        w.i8[1] = rxBuf[2];
        w.i8[2] = rxBuf[3];
        w.i8[3] = rxBuf[4];
        //speedM1 = w.i32;
        ui->lcdLeftEngine->display(QString("%1").arg(w.i32, 3, 10, QChar('0')));
        //        ui->plainTextEdit->appendPlainText("LEFT SPEED: " + QString("%1").arg(w.i32, 10, 10, QChar('0')));

        w.i32 = 0;
        w.i8[0] = rxBuf[5];
        w.i8[1] = rxBuf[6];
        w.i8[2] = rxBuf[7];
        w.i8[3] = rxBuf[8];
        //speedM2 = w.i32;
        ui->lcdRightEngine->display(QString("%1").arg(w.i32, 3, 10, QChar('0')));
        //        ui->plainTextEdit->appendPlainText("RIGHT SPEED: " + QString("%1").arg(w.i32, 10, 10, QChar('0')));
        break;
    case SERVO_CONFIG:
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
        break;
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

    //ui->plainTextEdit->appendPlainText(strHex);

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
        if(ui->comboBox->currentText() == "")
            return;

        QSerialPort1->setPortName(ui->comboBox->currentText());
        QSerialPort1->setBaudRate(115200);
        QSerialPort1->setParity(QSerialPort::NoParity);
        QSerialPort1->setDataBits(QSerialPort::Data8);
        QSerialPort1->setStopBits(QSerialPort::OneStop);
        QSerialPort1->setFlowControl(QSerialPort::NoFlowControl);

        if(QSerialPort1->open(QSerialPort::ReadWrite)){
            ui->OpenPortButton->setText("CLOSE");
        }
        else
            QMessageBox::information(this, "Serial PORT", "ERROR OPENING PORT");
    }
}

void QForm1::on_ClearButton_clicked(){
    ui->plainTextEdit->clear();
    DrawBackground();
    ui->aliveButton->setStyleSheet("color: white; background-color: rgb(189, 206, 214); font: 9pt MS Sans Serif; font-weight: bold; color: rgb(47, 55, 77);");
}

void QForm1::on_SendCommandButton_clicked(){
    uint8_t cmd, buf[24];
//    _work w;
    int n;
    bool ok = false;
    //QString strHex;

    if(ui->comboBox_2->currentText() == "")
        return;

    cmd = ui->comboBox_2->currentData().toInt();
    ui->plainTextEdit->appendPlainText("0x" + (QString("%1").arg(cmd, 2, 16, QChar('0'))).toUpper());

    n = 0;
    switch (cmd) {
        case ALIVE://ALIVE   PC=>MBED 0xF0 ;  MBED=>PC 0xF0 0x0D
            n = 1;
            ok = true;
            break;
        case FIRMWARE://FIRMWARE   PC=>MBED 0xF1 ;  MBED=>PC 0xF1 FIRMWARE
            n = 1;
            ok = true;
            break;
        case BUTTONS://PULSADORES   PC=>MBED 0x12 ;  MBED=>PC 0x12 VALOR PULSADORES
            n = 1;
            ok = true;
            break;
        case IRSENSOR://TCRT5000    PC=>MBED LEER;  MBED=>PC VALUES 1, 2, 3;
            n = 1;
            ok = true;
            break;
        case TEST_ENGINE://MOTORES  PC=>MBED POWERM1, POWERM2;  MBED=>PC ACKNOWLEDGE
            if(dialog->isHidden())
                dialog->show();
            break;
        case SPEED:
            n = 1;
            ok = true;
            break;
        default:
        ;
    }
    if(ok == true){
        buf[0] = cmd;
        SendCMD(buf, n);
        //ok = false;
    }
}

void QForm1::EngineTest(int32_t Eng1, int32_t Eng2){
    _work w;
    uint8_t buf[9];

    buf[0] = TEST_ENGINE;

    w.i32 = Eng1;
    for(uint8_t i=0; i<4; i++)
        buf[i+1] = w.i8[i];

    w.i32 = Eng2;
    for(uint8_t i=0; i<4; i++)
        buf[i+5] = w.i8[i];

    SendCMD(buf, 9);
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
    painter.translate(ui->widget->width()/2, ui->widget->height());

    QPaintBox1->update();
}

void QForm1::DrawBackground(){
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());

    pen.setWidth(2);
    pen.setColor(QColor(0, 0, 0, 255));
    brush.setColor(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, widgetSize.width, widgetSize.height);

    pen.setWidth(2);
    pen.setColor(QColor(0, 232, 0, 255));
    brush.setColor(QColor(0, 232, 0, 255));
    brush.setStyle(Qt::BrushStyle::NoBrush);
    painter.setBrush(brush);
    painter.setPen(pen);

    painter.translate(ui->widget->width()/2, ui->widget->height()/2);
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
    //if(samples==0)
        DrawBackground();
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());

    pen.setWidth(3);
    //pen.setColor(QColor(0, 232, 0, 255));
    //brush.setColor(QColor(0, 232, 0, 255));
    //pen.setColor(QColor(0, 232, 232, 255));
    //brush.setColor(QColor(0, 232, 232, 255));
    pen.setColor(QColor(255, 255, 255, 255));
    brush.setColor(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::BrushStyle::NoBrush);
    painter.setBrush(brush);
    painter.setPen(pen);

    //painter.translate(0, ui->widget->height()/2);

    //painter.drawPoint(samples, -(int)acceleration[samples]*25);

    painter.translate(ui->widget->width()/2, ui->widget->height()/2);

    painter.drawLine(0, 0, 150*cos(yaw * M_PI/180 + M_PI/2), 150*-sin(yaw * M_PI/180 + M_PI/2));

    pen.setWidth(20);
    pen.setColor(QColor(0, 255, 255, 255));
    painter.setPen(pen);

    //painter.translate(ui->widget->width()/2, ui->widget->height()/2);

    painter.drawPoint(posValues[0]*4, posValues[1]*4);

    QPaintBox1->update();
}

void QForm1::on_aliveButton_clicked()
{
    uint8_t buf[24];
    buf[0] = ALIVE;
    SendCMD(buf, 1);
}


void QForm1::Integrate(){
    float yaw_rad = yaw * M_PI/180;

    //if(abs(accValues[Y_AXIS]) < 2)
        //globalAcc[Y_AXIS] = 0.0;

    filtered[X_AXIS] = ALPHA * filtered[X_AXIS] + (1 - ALPHA) * accValues[X_AXIS];

    /*
    if(samples < 450)
        acceleration[samples] = filtered;
    else
        samples = 0;
    DrawMovement();
    samples++;
    */

    // Calcular aceleración respecto al marco de referencia global
    globalAcc[X_AXIS] = filtered[X_AXIS] * cosf(yaw_rad) - filtered[Y_AXIS] * sinf(yaw_rad);
    globalAcc[Y_AXIS] = accValues[X_AXIS] * sinf(yaw_rad) + accValues[Y_AXIS] * cosf(yaw_rad);

    //Calculate Speed
    deltaAcc = (clock() - deltaAcc) / 1000.0;

    //Si los motores están apagados, la velocidad disminuye
    if(abs(globalAcc[X_AXIS]) < 0.08 && ENGINES_ON == 0)
        velValues[X_AXIS] *= 0.05;

    //Si la aceleración aumenta, la velocidad también
    if(abs(globalAcc[X_AXIS]) > 0.08)
        velValues[X_AXIS] += globalAcc[X_AXIS] * deltaAcc;

    //Si los motores están apagados, la velocidad disminuye
    if(abs(globalAcc[Y_AXIS]) < 0.08 && ENGINES_ON == 0)
        velValues[Y_AXIS] *= 0.05;

    //Si la aceleración aumenta, la velocidad también
    if(abs(globalAcc[Y_AXIS]) > 0.08)
        velValues[Y_AXIS] += globalAcc[Y_AXIS] * deltaAcc;

    //Calculating Position
    if(abs(velValues[X_AXIS]) > 0.04)
        posValues[X_AXIS] += velValues[X_AXIS] * deltaAcc * 100;
    else
        velValues[X_AXIS] = 0;

    if(abs(velValues[Y_AXIS]) > 0.04)
        posValues[Y_AXIS] += velValues[Y_AXIS] * deltaAcc * 100;
    else
        velValues[Y_AXIS] = 0;

    if(posValues[X_AXIS] > 80)
        posValues[X_AXIS] = 80;
    if(posValues[X_AXIS] < -80)
        posValues[X_AXIS] = -80;

    if(posValues[Y_AXIS] > 60)
        posValues[Y_AXIS] = 60;
    if(posValues[Y_AXIS] < -60)
        posValues[Y_AXIS] = -60;

    ui->lcdAccX->display(QString("%1").arg(accValues[X_AXIS], 1, 'f', 3));
    ui->lcdAccY->display(QString("%1").arg(accValues[Y_AXIS], 1, 'f', 3));
    ui->lcdAccZ->display(QString("%1").arg(accValues[Z_AXIS], 1, 'f', 3));

    ui->lcdIR1->display(QString("%1").arg(globalAcc[X_AXIS], 1, 'f', 3));
    ui->lcdIR2->display(QString("%1").arg(globalAcc[Y_AXIS], 1, 'f', 3));

    ui->lcdSpeedX->display(QString("%1").arg(velValues[X_AXIS], 1, 'f', 3));
    ui->lcdSpeedY->display(QString("%1").arg(velValues[Y_AXIS], 1, 'f', 3));

    ui->lcdPosX->display(QString("%1").arg(posValues[X_AXIS], 1, 'f', 3));
    ui->lcdPosY->display(QString("%1").arg(posValues[Y_AXIS], 1, 'f', 3));

    deltaAcc = clock();
}

/*
void QForm1::on_pushButton_4_clicked()
{
    if(SCAN == false)
        SCAN = true, DrawBackground(), measureAngle = -90;
    else
        SCAN = false;
}
*/

/*
void QForm1::on_powerButton_clicked()
{
    if(dialog->isHidden())
        dialog->show();
}

void QForm1::on_LeftEngineSlide_sliderMoved(int position)
{
    QString strHex;
    int r, g, b;

    if(position <= 0){
        r = 24 + position * (200 / 100);
        g = 146 + position * (59 / 100);
        b = 11 + position * (37 / 100);
    } else {
        r = 224 - position * (200 / 100);
        g = 205 - position * (157 / 100);
        b = 48 - position * (37 / 100);
    }

    r = int((position + 100) * (224 - 24) / 200 + 24);
    g = int((position + 100) * (14 - 146) / 200 + 146);
    b = int((position + 100) * (21 - 11) / 200 + 11);

    strHex = strHex + QString("%1 ").arg(r, 3, 10, QChar('0'));
    strHex = strHex + QString("%1 ").arg(g, 3, 10, QChar('0'));
    strHex = strHex + QString("%1").arg(b, 3, 10, QChar('0'));
    ui->plainTextEdit->appendPlainText(strHex);

    strHex = "QSlider::groove:horizontal{background-color: rgb(";
    strHex = strHex + QString("%1,").arg(r, 3, 10, QChar('0'));
    strHex = strHex + QString("%1,").arg(g, 3, 10, QChar('0'));
    strHex = strHex + QString("%1);").arg(b, 3, 10, QChar('0'));
    strHex = strHex + "height: 7px; width: 90px;}QSlider::handle:horizontal{background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:0.011, y2:0, stop:0 rgba(74, 90, 107, 255), stop:1 rgba(173, 189, 198, 255)); width: 10px; height: 25px; margin: -10px 0px;}";
    strHex = strHex + ")";
    ui->LeftEngineSlide->setStyleSheet(strHex);

    ui->LeftEngineSlide->setStyleSheet("QSlider::groove:horizontal{background-color: rgb(196,219,50); height: 7px; width: 90px;}"
                                       "QSlider::handle:horizontal{background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:0.011, y2:0, stop:0 rgba(74, 90, 107, 255), stop:1 rgba(173, 189, 198, 255));"
                                       "width: 10px; height: 25px; margin: -10px 0px;}");

}

void QForm1::Scanning(){
    uint8_t buf[1];
    int32_t x, y;
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());
    float eq_dist;


    pen.setWidth(1);
    pen.setColor(qRgb(0, 0, 150));
    brush.setColor(Qt::white);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.translate(QPointF(154,295));

    if((clock() - measureTime) > 500){
        measureTime = clock();
        if(measureAngle <= 90){
            servoDeg(measureAngle);
            measureAngle= measureAngle + 6;
        } else {
            measureAngle = -90;
            SCAN = false;
            servoDeg(0);
        }
    }

    buf[0] = DISTANCIA;
    SendCMD(buf, 1);

    eq_dist = ((float)widgetSize.width / 200.0) * (float)distance;
    x = eq_dist * cos((float)measureAngle * M_PI / 180.0);
    y = eq_dist * sin((float)measureAngle * M_PI / 180.0);

    //x = distance * sin(measureAngle * M_PI / 180.0) * -2.0;
    //y = distance * cos(measureAngle * M_PI / 180.0) * -2.7;

    painter.drawEllipse(QPoint(x, y), 3, 3);

    QPaintBox1->update();
}
*/

void QForm1::on_powerButton_clicked(){
    if(ENGINES_ON == 0)
        ENGINES_ON = 1;
    else
        ENGINES_ON = 0;

    posValues[X_AXIS] = 0;
    posValues[Y_AXIS] = 0;

    ui->lcdIR4->display(QString("%1").arg(ENGINES_ON, 1, 10, QChar('0')));

    //ui->lcdIR4->display(QString("%1").arg(ENGINES_ON, 1, 'f', 3));
}

