/********************************************************************************
** Form generated from reading UI file 'qform1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFORM1_H
#define UI_QFORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QForm1
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *comboBox;
    QPushButton *OpenPortButton;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *WifiLineEdit;
    QPushButton *OpenWifiButton;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *comboBox_2;
    QPushButton *SendCommandButton;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *aliveButton;
    QHBoxLayout *horizontalLayout_10;
    QFrame *line;
    QLabel *label_9;
    QFrame *line_2;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_14;
    QFrame *line_9;
    QLabel *label_19;
    QFrame *line_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_11;
    QLCDNumber *lcdAccX;
    QLCDNumber *lcdAccY;
    QLCDNumber *lcdAccZ;
    QHBoxLayout *horizontalLayout_19;
    QFrame *line_15;
    QLabel *label_22;
    QFrame *line_14;
    QHBoxLayout *horizontalLayout_20;
    QLCDNumber *lcdGyroX;
    QLCDNumber *lcdGyroY;
    QLCDNumber *lcdGyroZ;
    QHBoxLayout *horizontalLayout_15;
    QFrame *line_10;
    QLabel *label_20;
    QFrame *line_11;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_16;
    QLCDNumber *lcdSpeedX;
    QLCDNumber *lcdSpeedY;
    QLCDNumber *lcdSpeedZ;
    QHBoxLayout *horizontalLayout_17;
    QFrame *line_13;
    QLabel *label_21;
    QFrame *line_12;
    QHBoxLayout *horizontalLayout_18;
    QLCDNumber *lcdPosX;
    QLCDNumber *lcdPosY;
    QLCDNumber *lcdPosZ;
    QHBoxLayout *horizontalLayout_12;
    QFrame *line_6;
    QLabel *label_17;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *LeftEngineSlide;
    QLCDNumber *lcdLeftEngine;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *RightEngineSlide;
    QLCDNumber *lcdRightEngine;
    QPushButton *powerButton;
    QHBoxLayout *horizontalLayout_13;
    QFrame *line_5;
    QLabel *label_18;
    QFrame *line_7;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcdIR1;
    QLCDNumber *lcdIR7;
    QLabel *label_8;
    QLabel *label_14;
    QLCDNumber *lcdIR5;
    QLabel *label_13;
    QLabel *label_11;
    QLCDNumber *lcdIR2;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_12;
    QLCDNumber *lcdIR6;
    QLCDNumber *lcdIR4;
    QLCDNumber *lcdIR3;
    QLCDNumber *lcdIR8;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget;
    QPushButton *ClearButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *QForm1)
    {
        if (QForm1->objectName().isEmpty())
            QForm1->setObjectName("QForm1");
        QForm1->resize(859, 750);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QForm1->sizePolicy().hasHeightForWidth());
        QForm1->setSizePolicy(sizePolicy);
        QForm1->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 31, 49);"));
        centralwidget = new QWidget(QForm1);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));
        comboBox->setFrame(true);

        horizontalLayout_7->addWidget(comboBox);

        OpenPortButton = new QPushButton(centralwidget);
        OpenPortButton->setObjectName("OpenPortButton");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(OpenPortButton->sizePolicy().hasHeightForWidth());
        OpenPortButton->setSizePolicy(sizePolicy1);
        OpenPortButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));
        OpenPortButton->setFlat(false);

        horizontalLayout_7->addWidget(OpenPortButton);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        WifiLineEdit = new QLineEdit(centralwidget);
        WifiLineEdit->setObjectName("WifiLineEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(WifiLineEdit->sizePolicy().hasHeightForWidth());
        WifiLineEdit->setSizePolicy(sizePolicy2);
        WifiLineEdit->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        WifiLineEdit->setMaxLength(32767);

        horizontalLayout_6->addWidget(WifiLineEdit);

        OpenWifiButton = new QPushButton(centralwidget);
        OpenWifiButton->setObjectName("OpenWifiButton");
        sizePolicy1.setHeightForWidth(OpenWifiButton->sizePolicy().hasHeightForWidth());
        OpenWifiButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(false);
        OpenWifiButton->setFont(font);
        OpenWifiButton->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Sans Serif\";\n"
"font-weight: bold;\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        horizontalLayout_6->addWidget(OpenWifiButton);


        verticalLayout_7->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));

        horizontalLayout_8->addWidget(comboBox_2);

        SendCommandButton = new QPushButton(centralwidget);
        SendCommandButton->setObjectName("SendCommandButton");
        sizePolicy1.setHeightForWidth(SendCommandButton->sizePolicy().hasHeightForWidth());
        SendCommandButton->setSizePolicy(sizePolicy1);
        SendCommandButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        horizontalLayout_8->addWidget(SendCommandButton);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        aliveButton = new QPushButton(centralwidget);
        aliveButton->setObjectName("aliveButton");
        sizePolicy2.setHeightForWidth(aliveButton->sizePolicy().hasHeightForWidth());
        aliveButton->setSizePolicy(sizePolicy2);
        aliveButton->setFocusPolicy(Qt::StrongFocus);
        aliveButton->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Sans Serif\";\n"
"font-weight: bold;\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        horizontalLayout_9->addWidget(aliveButton);


        verticalLayout_6->addLayout(horizontalLayout_9);


        horizontalLayout_2->addLayout(verticalLayout_6);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(236, 206, 122);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(line);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(255, 255, 255);"));
        label_9->setFrameShadow(QFrame::Plain);
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setMargin(0);
        label_9->setIndent(-1);

        horizontalLayout_10->addWidget(label_9);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(236, 206, 122);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(line_2);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, -1);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy4);
        plainTextEdit->setToolTipDuration(-1);
        plainTextEdit->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setLineWidth(1);
        plainTextEdit->setCursorWidth(1);

        verticalLayout_3->addWidget(plainTextEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName("line_9");
        line_9->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout_14->addWidget(line_9);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_19);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_14->addWidget(line_8);


        verticalLayout->addLayout(horizontalLayout_14);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_16);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_15);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        lcdAccX = new QLCDNumber(centralwidget);
        lcdAccX->setObjectName("lcdAccX");
        lcdAccX->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdAccX->setFrameShadow(QFrame::Sunken);
        lcdAccX->setSmallDecimalPoint(false);
        lcdAccX->setDigitCount(8);
        lcdAccX->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_11->addWidget(lcdAccX);

        lcdAccY = new QLCDNumber(centralwidget);
        lcdAccY->setObjectName("lcdAccY");
        lcdAccY->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdAccY->setFrameShadow(QFrame::Sunken);
        lcdAccY->setSmallDecimalPoint(false);
        lcdAccY->setDigitCount(8);
        lcdAccY->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_11->addWidget(lcdAccY);

        lcdAccZ = new QLCDNumber(centralwidget);
        lcdAccZ->setObjectName("lcdAccZ");
        lcdAccZ->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdAccZ->setFrameShadow(QFrame::Sunken);
        lcdAccZ->setSmallDecimalPoint(false);
        lcdAccZ->setDigitCount(8);
        lcdAccZ->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_11->addWidget(lcdAccZ);


        verticalLayout_2->addLayout(horizontalLayout_11);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        line_15 = new QFrame(centralwidget);
        line_15->setObjectName("line_15");
        line_15->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);

        horizontalLayout_19->addWidget(line_15);

        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_22);

        line_14 = new QFrame(centralwidget);
        line_14->setObjectName("line_14");
        line_14->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        horizontalLayout_19->addWidget(line_14);


        verticalLayout->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        lcdGyroX = new QLCDNumber(centralwidget);
        lcdGyroX->setObjectName("lcdGyroX");
        lcdGyroX->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdGyroX->setFrameShadow(QFrame::Sunken);
        lcdGyroX->setDigitCount(8);
        lcdGyroX->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_20->addWidget(lcdGyroX);

        lcdGyroY = new QLCDNumber(centralwidget);
        lcdGyroY->setObjectName("lcdGyroY");
        lcdGyroY->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdGyroY->setFrameShadow(QFrame::Sunken);
        lcdGyroY->setDigitCount(8);
        lcdGyroY->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_20->addWidget(lcdGyroY);

        lcdGyroZ = new QLCDNumber(centralwidget);
        lcdGyroZ->setObjectName("lcdGyroZ");
        lcdGyroZ->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdGyroZ->setFrameShadow(QFrame::Sunken);
        lcdGyroZ->setDigitCount(8);
        lcdGyroZ->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_20->addWidget(lcdGyroZ);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName("line_10");
        line_10->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        horizontalLayout_15->addWidget(line_10);

        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");
        label_20->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_20);

        line_11 = new QFrame(centralwidget);
        line_11->setObjectName("line_11");
        line_11->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        horizontalLayout_15->addWidget(line_11);


        verticalLayout->addLayout(horizontalLayout_15);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        lcdSpeedX = new QLCDNumber(centralwidget);
        lcdSpeedX->setObjectName("lcdSpeedX");
        lcdSpeedX->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdSpeedX->setFrameShadow(QFrame::Sunken);
        lcdSpeedX->setDigitCount(8);
        lcdSpeedX->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_16->addWidget(lcdSpeedX);

        lcdSpeedY = new QLCDNumber(centralwidget);
        lcdSpeedY->setObjectName("lcdSpeedY");
        lcdSpeedY->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdSpeedY->setFrameShadow(QFrame::Sunken);
        lcdSpeedY->setDigitCount(8);
        lcdSpeedY->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_16->addWidget(lcdSpeedY);

        lcdSpeedZ = new QLCDNumber(centralwidget);
        lcdSpeedZ->setObjectName("lcdSpeedZ");
        lcdSpeedZ->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdSpeedZ->setFrameShadow(QFrame::Sunken);
        lcdSpeedZ->setDigitCount(8);
        lcdSpeedZ->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_16->addWidget(lcdSpeedZ);


        verticalLayout_4->addLayout(horizontalLayout_16);


        verticalLayout->addLayout(verticalLayout_4);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        line_13 = new QFrame(centralwidget);
        line_13->setObjectName("line_13");
        line_13->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        horizontalLayout_17->addWidget(line_13);

        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");
        label_21->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_21);

        line_12 = new QFrame(centralwidget);
        line_12->setObjectName("line_12");
        line_12->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        horizontalLayout_17->addWidget(line_12);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        lcdPosX = new QLCDNumber(centralwidget);
        lcdPosX->setObjectName("lcdPosX");
        lcdPosX->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdPosX->setFrameShadow(QFrame::Sunken);
        lcdPosX->setDigitCount(8);
        lcdPosX->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_18->addWidget(lcdPosX);

        lcdPosY = new QLCDNumber(centralwidget);
        lcdPosY->setObjectName("lcdPosY");
        lcdPosY->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdPosY->setFrameShadow(QFrame::Sunken);
        lcdPosY->setDigitCount(8);
        lcdPosY->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_18->addWidget(lcdPosY);

        lcdPosZ = new QLCDNumber(centralwidget);
        lcdPosZ->setObjectName("lcdPosZ");
        lcdPosZ->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdPosZ->setFrameShadow(QFrame::Sunken);
        lcdPosZ->setDigitCount(8);
        lcdPosZ->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_18->addWidget(lcdPosZ);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_6);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_17);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_4);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(108, 0));
        label_4->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        LeftEngineSlide = new QSlider(centralwidget);
        LeftEngineSlide->setObjectName("LeftEngineSlide");
        LeftEngineSlide->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(LeftEngineSlide->sizePolicy().hasHeightForWidth());
        LeftEngineSlide->setSizePolicy(sizePolicy5);
        LeftEngineSlide->setMinimumSize(QSize(0, 0));
        LeftEngineSlide->setAutoFillBackground(false);
        LeftEngineSlide->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background-color: rgb(196,219,50);\n"
"	height: 7px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"	background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:0.011, y2:0, stop:0 rgba(74, 90, 107, 255), stop:1 rgba(173, 189, 198, 255));\n"
"	width: 10px;\n"
"	height: 25px;\n"
"	margin: -10px 3px;\n"
"}"));
        LeftEngineSlide->setMinimum(-100);
        LeftEngineSlide->setMaximum(100);
        LeftEngineSlide->setPageStep(1);
        LeftEngineSlide->setValue(0);
        LeftEngineSlide->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(LeftEngineSlide);

        lcdLeftEngine = new QLCDNumber(centralwidget);
        lcdLeftEngine->setObjectName("lcdLeftEngine");
        sizePolicy1.setHeightForWidth(lcdLeftEngine->sizePolicy().hasHeightForWidth());
        lcdLeftEngine->setSizePolicy(sizePolicy1);
        lcdLeftEngine->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdLeftEngine->setFrameShadow(QFrame::Sunken);
        lcdLeftEngine->setSmallDecimalPoint(false);
        lcdLeftEngine->setDigitCount(3);
        lcdLeftEngine->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_4->addWidget(lcdLeftEngine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        RightEngineSlide = new QSlider(centralwidget);
        RightEngineSlide->setObjectName("RightEngineSlide");
        sizePolicy5.setHeightForWidth(RightEngineSlide->sizePolicy().hasHeightForWidth());
        RightEngineSlide->setSizePolicy(sizePolicy5);
        RightEngineSlide->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background-color: rgb(196,219,50);\n"
"	height: 7px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"	background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:0.011, y2:0, stop:0 rgba(74, 90, 107, 255), stop:1 rgba(173, 189, 198, 255));\n"
"	width: 10px;\n"
"	height: 25px;\n"
"	margin: -10px 3px;\n"
"}"));
        RightEngineSlide->setMinimum(-100);
        RightEngineSlide->setMaximum(100);
        RightEngineSlide->setPageStep(1);
        RightEngineSlide->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(RightEngineSlide);

        lcdRightEngine = new QLCDNumber(centralwidget);
        lcdRightEngine->setObjectName("lcdRightEngine");
        sizePolicy1.setHeightForWidth(lcdRightEngine->sizePolicy().hasHeightForWidth());
        lcdRightEngine->setSizePolicy(sizePolicy1);
        lcdRightEngine->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdRightEngine->setFrameShadow(QFrame::Sunken);
        lcdRightEngine->setDigitCount(3);
        lcdRightEngine->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_5->addWidget(lcdRightEngine);


        verticalLayout->addLayout(horizontalLayout_5);

        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName("powerButton");
        sizePolicy2.setHeightForWidth(powerButton->sizePolicy().hasHeightForWidth());
        powerButton->setSizePolicy(sizePolicy2);
        powerButton->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Sans Serif\";\n"
"font-weight: bold;\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        verticalLayout->addWidget(powerButton);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_13->addWidget(line_5);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_18);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_13->addWidget(line_7);


        verticalLayout->addLayout(horizontalLayout_13);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        lcdIR1 = new QLCDNumber(centralwidget);
        lcdIR1->setObjectName("lcdIR1");
        sizePolicy2.setHeightForWidth(lcdIR1->sizePolicy().hasHeightForWidth());
        lcdIR1->setSizePolicy(sizePolicy2);
        lcdIR1->setMinimumSize(QSize(0, 23));
        lcdIR1->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR1->setFrameShape(QFrame::Box);
        lcdIR1->setFrameShadow(QFrame::Sunken);
        lcdIR1->setDigitCount(8);
        lcdIR1->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(lcdIR1, 1, 0, 1, 1);

        lcdIR7 = new QLCDNumber(centralwidget);
        lcdIR7->setObjectName("lcdIR7");
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lcdIR7->sizePolicy().hasHeightForWidth());
        lcdIR7->setSizePolicy(sizePolicy6);
        lcdIR7->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR7->setFrameShadow(QFrame::Sunken);
        lcdIR7->setDigitCount(4);
        lcdIR7->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(lcdIR7, 3, 2, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy7);
        label_8->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        sizePolicy7.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy7);
        label_14->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_14, 2, 3, 1, 1);

        lcdIR5 = new QLCDNumber(centralwidget);
        lcdIR5->setObjectName("lcdIR5");
        sizePolicy6.setHeightForWidth(lcdIR5->sizePolicy().hasHeightForWidth());
        lcdIR5->setSizePolicy(sizePolicy6);
        lcdIR5->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR5->setFrameShadow(QFrame::Sunken);
        lcdIR5->setDigitCount(1);
        lcdIR5->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(lcdIR5, 3, 0, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        sizePolicy7.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy7);
        label_13->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_13, 2, 2, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        sizePolicy7.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy7);
        label_11->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        lcdIR2 = new QLCDNumber(centralwidget);
        lcdIR2->setObjectName("lcdIR2");
        sizePolicy2.setHeightForWidth(lcdIR2->sizePolicy().hasHeightForWidth());
        lcdIR2->setSizePolicy(sizePolicy2);
        lcdIR2->setMinimumSize(QSize(0, 23));
        lcdIR2->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR2->setFrameShape(QFrame::Box);
        lcdIR2->setFrameShadow(QFrame::Sunken);
        lcdIR2->setDigitCount(8);
        lcdIR2->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(lcdIR2, 1, 1, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        sizePolicy7.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy7);
        label_10->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 0, 3, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        sizePolicy7.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy7);
        label_7->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 0, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        sizePolicy7.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy7);
        label_6->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        sizePolicy7.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy7);
        label_12->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 2, 1, 1, 1);

        lcdIR6 = new QLCDNumber(centralwidget);
        lcdIR6->setObjectName("lcdIR6");
        sizePolicy6.setHeightForWidth(lcdIR6->sizePolicy().hasHeightForWidth());
        lcdIR6->setSizePolicy(sizePolicy6);
        lcdIR6->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR6->setFrameShadow(QFrame::Sunken);
        lcdIR6->setDigitCount(4);
        lcdIR6->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(lcdIR6, 3, 1, 1, 1);

        lcdIR4 = new QLCDNumber(centralwidget);
        lcdIR4->setObjectName("lcdIR4");
        sizePolicy6.setHeightForWidth(lcdIR4->sizePolicy().hasHeightForWidth());
        lcdIR4->setSizePolicy(sizePolicy6);
        lcdIR4->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR4->setFrameShadow(QFrame::Sunken);
        lcdIR4->setDigitCount(4);
        lcdIR4->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(lcdIR4, 1, 3, 1, 1);

        lcdIR3 = new QLCDNumber(centralwidget);
        lcdIR3->setObjectName("lcdIR3");
        sizePolicy2.setHeightForWidth(lcdIR3->sizePolicy().hasHeightForWidth());
        lcdIR3->setSizePolicy(sizePolicy2);
        lcdIR3->setMinimumSize(QSize(0, 23));
        lcdIR3->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR3->setFrameShape(QFrame::Box);
        lcdIR3->setFrameShadow(QFrame::Sunken);
        lcdIR3->setDigitCount(4);
        lcdIR3->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(lcdIR3, 1, 2, 1, 1);

        lcdIR8 = new QLCDNumber(centralwidget);
        lcdIR8->setObjectName("lcdIR8");
        sizePolicy6.setHeightForWidth(lcdIR8->sizePolicy().hasHeightForWidth());
        lcdIR8->setSizePolicy(sizePolicy6);
        lcdIR8->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR8->setFrameShadow(QFrame::Sunken);
        lcdIR8->setDigitCount(4);
        lcdIR8->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(lcdIR8, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, -1, 0, -1);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setEnabled(true);
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy8);
        widget->setMinimumSize(QSize(305, 200));

        verticalLayout_8->addWidget(widget);

        ClearButton = new QPushButton(centralwidget);
        ClearButton->setObjectName("ClearButton");
        sizePolicy6.setHeightForWidth(ClearButton->sizePolicy().hasHeightForWidth());
        ClearButton->setSizePolicy(sizePolicy6);
        ClearButton->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Sans Serif\";\n"
"font-weight: bold;\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        verticalLayout_8->addWidget(ClearButton);


        horizontalLayout->addLayout(verticalLayout_8);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        QForm1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QForm1);
        statusbar->setObjectName("statusbar");
        QForm1->setStatusBar(statusbar);
        menubar = new QMenuBar(QForm1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 859, 21));
        QForm1->setMenuBar(menubar);

        retranslateUi(QForm1);

        QMetaObject::connectSlotsByName(QForm1);
    } // setupUi

    void retranslateUi(QMainWindow *QForm1)
    {
        QForm1->setWindowTitle(QCoreApplication::translate("QForm1", "QForm1", nullptr));
        label->setText(QCoreApplication::translate("QForm1", "COMMUNICATION", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("QForm1", "USB/UART", nullptr));
        OpenPortButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        WifiLineEdit->setInputMask(QString());
        WifiLineEdit->setText(QString());
        WifiLineEdit->setPlaceholderText(QCoreApplication::translate("QForm1", "Wifi Port", nullptr));
        OpenWifiButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        label_2->setText(QCoreApplication::translate("QForm1", "COMMAND", nullptr));
        SendCommandButton->setText(QCoreApplication::translate("QForm1", "SEND", nullptr));
        aliveButton->setText(QCoreApplication::translate("QForm1", "ALIVE", nullptr));
        label_9->setText(QCoreApplication::translate("QForm1", "MICROCONTROLADORES", nullptr));
        label_19->setText(QCoreApplication::translate("QForm1", "ACCELERATION", nullptr));
        label_16->setText(QCoreApplication::translate("QForm1", "X", nullptr));
        label_15->setText(QCoreApplication::translate("QForm1", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("QForm1", "Z", nullptr));
        label_22->setText(QCoreApplication::translate("QForm1", "GYROSCOPE", nullptr));
        label_20->setText(QCoreApplication::translate("QForm1", "SPEED", nullptr));
        label_21->setText(QCoreApplication::translate("QForm1", "POSITION", nullptr));
        label_17->setText(QCoreApplication::translate("QForm1", "ENGINES", nullptr));
        label_4->setText(QCoreApplication::translate("QForm1", "LEFT ENGINE", nullptr));
        label_5->setText(QCoreApplication::translate("QForm1", "RIGHT ENGINE", nullptr));
        powerButton->setText(QCoreApplication::translate("QForm1", "SET ENGINES POWER", nullptr));
        label_18->setText(QCoreApplication::translate("QForm1", "INFRARRED", nullptr));
        label_8->setText(QCoreApplication::translate("QForm1", "IR 3", nullptr));
        label_14->setText(QCoreApplication::translate("QForm1", "IR 8", nullptr));
        label_13->setText(QCoreApplication::translate("QForm1", "IR 7", nullptr));
        label_11->setText(QCoreApplication::translate("QForm1", "IR 5", nullptr));
        label_10->setText(QCoreApplication::translate("QForm1", "IR 4", nullptr));
        label_7->setText(QCoreApplication::translate("QForm1", "IR 2", nullptr));
        label_6->setText(QCoreApplication::translate("QForm1", "IR 1", nullptr));
        label_12->setText(QCoreApplication::translate("QForm1", "IR 6", nullptr));
        ClearButton->setText(QCoreApplication::translate("QForm1", "CLEAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QForm1: public Ui_QForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORM1_H
