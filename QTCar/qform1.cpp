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
    ui->comboBox_2->addItem("FIRMWARE", 0xF1);
    ui->comboBox_2->addItem("LEDS", 0x10);
    ui->comboBox_2->addItem("BUTTONS", 0x12);
    ui->comboBox_2->addItem("IR SENSORS", 0xA0);
    ui->comboBox_2->addItem("ENGINE TEST", 0xA1);
    ui->comboBox_2->addItem("SERVO", 0xA2);
    ui->comboBox_2->addItem("HC-SR04", 0xA3);
    ui->comboBox_2->addItem("SPEED", 0xA4);

    QUdpSocket1 = new QUdpSocket(this);
    connect(QUdpSocket1,&QUdpSocket::readyRead,this,&QForm1::onRxUDP);

    header=0;
    connect(QSerialPort1,&QSerialPort::readyRead, this,&QForm1::OnRxChar);
    connect(dialog, &Dialog::takeDeg, this, &QForm1::servoDeg);
    connect(dialog, &Dialog::powEng, this, &QForm1::EngineTest);
    connect(dialog, &Dialog::configMaxMin, this, &QForm1::configServo);
    connect(dialog, &Dialog::readMaxMin, this, &QForm1::readServo);
    connect(this, &QForm1::maxMinValues, dialog, &Dialog::displayMaxMin);
    QPaintBox1 = new QPaintBox(0, 0, ui->widget);

    DrawBackground();

    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &QForm1::OnQTimer1);
    QTimer1->start(50);

}

QForm1::~QForm1(){
    delete ui;
    delete dialog;
}

bool QForm1::eventFilter(QObject *watched, QEvent *event){
    if(watched == ui->comboBox) {
        if (event->type() == QEvent::MouseButtonPress) {
            ui->comboBox->clear();
            QSerialPortInfo SerialPortInfo1;

            for(int i=0;i<SerialPortInfo1.availablePorts().count();i++)
                ui->comboBox->addItem(SerialPortInfo1.availablePorts().at(i).portName());

            return QMainWindow::eventFilter(watched, event);
        }
        else {
            return false;
        }
    }
    else{
         return QMainWindow::eventFilter(watched, event);
    }
}

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
        DecodeCmd(&buff[indexWifi]);
    }
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

    strHex = "<-- 0x";
    for (int a=0; a<count; a++) {
        strHex = strHex + QString("%1").arg(buf[a], 2, 16, QChar('0')).toUpper();
    }
     ui->plainTextEdit->appendPlainText(strHex);
    for (int i=0; i<count; i++) {
        strHex = strHex + QString("%1").arg(buf[i], 2, 16, QChar('0')).toUpper();

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
            }
            else{
                header = 0;
                i--;
            }
            break;
        case 6:
            nBytes--;
            if(nBytes > 0){
                rxBuf[index++] = buf[i];
                cks ^= buf[i];
            }
            else{
                header = 0;
                if(cks == buf[i])
                    DecodeCmd(rxBuf);
                else
                    ui->plainTextEdit->appendPlainText("ERROR CHECKSUM");
            }
            break;
        }
    }
    delete [] buf;
}

void QForm1::OnQTimer1(){
    //uint8_t buf[24];

    if(SCAN == true)
        Scanning();

    /*
    buf[0] = SPEED;
    SendCMD(buf, 1);

    buf[0] = IRSENSOR;
    SendCMD(buf, 1);

    buf[0] = DISTANCIA;
    SendCMD(buf, 1);
    */
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
    tx[4] = length + 1; //+ 3;
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

void QForm1::on_pushButtonUDP_clicked(){
    qint16 port;
    bool ok;
    if(QUdpSocket1->isOpen()){
        QUdpSocket1->abort();
        QUdpSocket1->close();
        ui->pushButtonUDP->setText("OPEN");
    }else{
        port = ui->lineEdit->text().toInt(&ok);
        if(!ok)
                return;
        QUdpSocket1->bind(port);

        if(QUdpSocket1->open(QUdpSocket::ReadWrite)){
            ui->pushButtonUDP->setText("CLOSE");
        }else{
            QMessageBox::information(this, tr("SERVER PORT"),tr("ERRRO. Number PORT."));
        }
    }
}

/*
//void QForm1::SendCMD(uint8_t *buf, uint8_t length){
//    uint8_t tx[24];
//    uint8_t cks, i;
//    QString strHex;
//    _work w;

//    if(!QSerialPort1->isOpen())
//        return;

//    w.i32 = -1000;

//    tx[7] = w.u8[0];
//    tx[8] = w.u8[1];
//    tx[9] = w.u8[2];
//    tx[10] = w.u8[3];

//    tx[0] = 'U';
//    tx[1] = 'N';
//    tx[2] = 'E';
//    tx[3] = 'R';
//    tx[4] = length + 1;
//    tx[5] = ':';

//    memcpy(&tx[6], buf, length);

//    cks = 0;
//    for (i=0; i<(length+6); i++) {
//        cks ^= tx[i];
//    }

//    tx[i] = cks;

//    strHex = "--> 0x";
//    for (int i=0; i<length+7; i++) {
//        strHex = strHex + QString("%1").arg(tx[i], 2, 16, QChar('0')).toUpper();
//    }

//    ui->plainTextEdit->appendPlainText(strHex);

//    QSerialPort1->write((char *)tx, length+7);
//}
*/

void QForm1::on_pushButton_clicked(){
    if(QSerialPort1->isOpen()){
        QSerialPort1->close();
        ui->pushButton->setText("OPEN");
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
            ui->pushButton->setText("CLOSE");
        }
        else
            QMessageBox::information(this, "Serial PORT", "ERROR. Opening PORT");
    }
}

void QForm1::on_pushButton_3_clicked(){
    ui->plainTextEdit->clear();
    DrawBackground();
}

void QForm1::on_pushButton_2_clicked(){
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
        case LEDS://LEDS   PC=>MBED 0x10 LEDS_A_MODIFICAR VALOR_LEDS ;  MBED=>PC 0x10 ESTADO_LEDS
            n = 3;
            ok = true;
            break;
        case BUTTONS://PULSADORES   PC=>MBED 0x12 ;  MBED=>PC 0x12 VALOR PULSADORES
            n = 1;
            ok = true;
            break;
        case SERVO://SERVO    PC=>MBED POSICIONAR_SERVO; MBED=>PC ACKNOWLEDGE FIN_MOVIMIENTO_SERVO
            if(dialog->isHidden())
                dialog->show();
            break;
        case DISTANCIA://HC-SR04   PC=>MBED LAST_DISTANCE; MBED=>PC ACKWNOWLEDGE;  MBED=>PC DISTANCE_US
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

void QForm1::DecodeCmd(uint8_t *rxBuf){
    QString str;
    _work w;
    int32_t speedM1, speedM2;

    switch(rxBuf[0]){
    case LEDS:
        break;
     case BUTTONS:
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
        break;
    case ALIVE:
        if(rxBuf[1] == ACKNOWLEDGE)//+3
            ui->aliveButton->setStyleSheet("color: white; background-color: rgb(0, 128, 0); font: 9pt MS Sans Serif");
        else
            ui->aliveButton->setStyleSheet("color: white; background-color: rgb(128, 0, 0); font: 9pt MS Sans Serif");
        break;
    case UNKNOWNCOMMAND:
        ui->plainTextEdit->appendPlainText("NO CMD");
        break;
    case SERVO:
        if(rxBuf[1+2] == ACKNOWLEDGE)
            ui->plainTextEdit->appendPlainText("SERVO MOVED");
        break;
    case DISTANCIA:
        for(uint8_t i=1; i<5; i++)
            w.i8[i-1] = rxBuf[i+2];
        distance = w.i32/58;
        ui->lcdDistance->display(QString("%1").arg(distance, 2, 10, QChar('0')));
//        ui->plainTextEdit->appendPlainText("Distance: " + QString("%1 cm").arg(distance, 4, 10, QChar('0')));
        break;
    case IRSENSOR:
        ui->lcdIR1->display(QString("%1").arg(rxBuf[1+2], 1, 10, QChar('0')));
        ui->lcdIR2->display(QString("%1").arg(rxBuf[2+2], 1, 10, QChar('0')));
        ui->lcdIR3->display(QString("%1").arg(rxBuf[3+2], 1, 10, QChar('0')));
//        ui->lastIRLCD->display(QString("%1").arg(rxBuf[4+2], 1, 10, QChar('0')));
//        ui->plainTextEdit->appendPlainText("IR1: " + QString("%1").arg(rxBuf[1], 1, 10, QChar('0')));
//        ui->plainTextEdit->appendPlainText("IR2: " + QString("%1").arg(rxBuf[2], 1, 10, QChar('0')));
//        ui->plainTextEdit->appendPlainText("IR3: " + QString("%1").arg(rxBuf[3], 1, 10, QChar('0')));
        break;
    case TEST_ENGINE:
        if(rxBuf[1+2] == ACKNOWLEDGE)
            ui->plainTextEdit->appendPlainText("ENGINES OK");
        break;
    case SPEED:
        w.i32 = 0;
        w.i8[0] = rxBuf[1+2];
        w.i8[1] = rxBuf[2+2];
        w.i8[2] = rxBuf[3+2];
        w.i8[3] = rxBuf[4+2];
        speedM1 = w.i32;
        ui->lcdLeftEng->display(QString("%1").arg(speedM1, 3, 10, QChar('0')));
//        ui->plainTextEdit->appendPlainText("LEFT SPEED: " + QString("%1").arg(w.i32, 10, 10, QChar('0')));

        w.i32 = 0;
        w.i8[0] = rxBuf[5+2];
        w.i8[1] = rxBuf[6+2];
        w.i8[2] = rxBuf[7+2];
        w.i8[3] = rxBuf[8+2];
        speedM2 = w.i32;
        ui->lcdRightEng->display(QString("%1").arg(speedM2, 3, 10, QChar('0')));
//        ui->plainTextEdit->appendPlainText("RIGHT SPEED: " + QString("%1").arg(w.i32, 10, 10, QChar('0')));
        break;
    case SERVO_CONFIG:
        uint16_t min, max;
        w.u8[0] = rxBuf[1+2];
        w.u8[1] = rxBuf[2+2];
        min = w.u16[0];

        w.i8[0] = rxBuf[3+2];
        w.i8[1] = rxBuf[4+2];
        max = w.u16[0];

        emit maxMinValues(min, max);
        break;
    }
}

void QForm1::servoDeg(uint8_t servDeg){
    uint8_t buf[2];
    buf[0] = SERVO;
    buf[1] = servDeg;
    SendCMD(buf, 2);
}

void QForm1::configServo(uint16_t min, uint16_t max){
    uint8_t buf[6];
    _work w;
    buf[0] = SERVO_CONFIG;
    buf[1] = 1;

    w.u32 = min;
    buf[2] = w.i8[0];
    buf[3] = w.i8[1];

    w.u32 = max;
    buf[4] = w.i8[0];
    buf[5] = w.i8[1];

    SendCMD(buf, 6);
}

void QForm1::readServo(){
    uint8_t buf[2];
    buf[0] = SERVO_CONFIG;
    buf[1] = 0;
    SendCMD(buf, 2);
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

void QForm1::DrawBackground(){
    QPen pen;
//    QRadialGradient gradient(QPoint(153, 295), 160);
//    gradient.setColorAt(0, QColor(qRgb(0,0,65)));
//    gradient.setColorAt(1, QColor(qRgb(0,0,150)));
//    QBrush brush(gradient);
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());

    QPaintBox1->resize(400, 400);

    pen.setColor(qRgb(0, 0, 150));
    brush.setColor(qRgb(0, 0, 150));
//    brush.setStyle(Qt::BrushStyle::RadialGradientPattern);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(0, 0, 400, 400);

    pen.setWidth(8);
    painter.setPen(pen);

    pen.setWidth(2);
    pen.setColor(qRgb(255, 255, 255));
    brush.setColor(qRgb(255, 255, 255));
    brush.setStyle(Qt::BrushStyle::NoBrush);
    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawEllipse(QPoint(153, 295), 40, 40);
    painter.drawEllipse(QPoint(153, 295), 100, 100);
    painter.drawEllipse(QPoint(153, 295), 160, 160);
    painter.drawEllipse(QPoint(153, 295), 230, 230);
    painter.drawEllipse(QPoint(153, 295), 300, 300);

    painter.translate(153, 295);
    for(int i=0; i<12; i++){
        painter.drawLine(0, -500, 0, 500);
        painter.rotate(30);
    }

    QPaintBox1->update();
}

void QForm1::on_pushButton_4_clicked()
{
    if(SCAN == false)
        SCAN = true, DrawBackground(), measureAngle = -90;
    else
        SCAN = false;
}

void QForm1::Scanning(){
    uint8_t buf[1];
    int32_t x, y;
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());

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

    x = distance * sin(measureAngle * M_PI / 180.0) * -2.0;
    y = distance * cos(measureAngle * M_PI / 180.0) * -2.7;

    painter.drawEllipse(QPoint(x, y), 3, 3);

    QPaintBox1->update();
}

void QForm1::on_aliveButton_clicked()
{
    uint8_t buf[24];
    buf[0] = ALIVE;
    SendCMD(buf, 1);
}

void QForm1::on_powerButton_clicked()
{
    if(dialog->isHidden())
        dialog->show();
}
