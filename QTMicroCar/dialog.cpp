#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->spinBox->setRange(-90, 90);
    ui->spinBox_2->setRange(-100, 100);
    ui->spinBox_3->setRange(-100, 100);
    ui->spinBox_minMS->setRange(500, 1400);
    ui->spinBox_maxMS->setRange(1600, 2500);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    Deg = ui->spinBox->value();
    emit takeDeg(Deg);
}

void Dialog::on_pushButton_2_clicked()
{
    PowEng1 = ui->spinBox_2->value();
    PowEng2 = ui->spinBox_3->value();
    emit powEng(PowEng1, PowEng2);
}

void Dialog::on_pushButton_maxMS_clicked()
{
    min = ui->spinBox_minMS->value();
    max = ui->spinBox_maxMS->value();
    emit configMaxMin(min, max);
}

void Dialog::on_pushButton_read_clicked()
{
    emit readMaxMin();
}

void Dialog::displayMaxMin(uint16_t min, uint16_t max){
    ui->lcdNumber_maxMS->display(QString("%1").arg(max));
    ui->lcdNumber_minMS->display(QString("%1").arg(min));
}

