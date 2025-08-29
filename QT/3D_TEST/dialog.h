#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void takeDeg(int8_t servDeg);

    void powEng(int32_t eng1, int32_t eng2);

    void configMaxMin(uint16_t min, uint16_t max);

    void readMaxMin();

public slots:
    void displayMaxMin(uint16_t min, uint16_t max);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_maxMS_clicked();

    void on_pushButton_read_clicked();

private:
    Ui::Dialog *ui;
    int8_t Deg;
    int32_t PowEng1;
    int32_t PowEng2;
    uint16_t min;
    uint16_t max;
};

#endif // DIALOG_H
