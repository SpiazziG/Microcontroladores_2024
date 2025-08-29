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
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QForm1
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *navigationBar;
    QVBoxLayout *verticalLayout;
    QLabel *labelName;
    QSpacerItem *verticalSpacer_3;
    QPushButton *telemetryTabButton;
    QPushButton *debugTabButton;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *heartbeatLight;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *OpenWifiButton;
    QPushButton *OpenPortButton;
    QLineEdit *WifiLineEdit;
    QComboBox *comboBoxCommunication;
    QSpacerItem *horizontalSpacer;
    QLabel *labelHour;
    QFrame *frameCommunication;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCommunication;
    QStackedWidget *stackedWidget;
    QWidget *Telemetry;
    QGridLayout *gridLayout_7;
    QFrame *frameRadar;
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetRadar;
    QPushButton *buttonClear;
    QFrame *frameMotion;
    QGridLayout *gridLayout_4;
    QLabel *labelAccZ;
    QLabel *labelPosition;
    QLabel *labelGyroX;
    QLabel *labelPosX;
    QLabel *labelY;
    QLabel *labelPosZ;
    QLabel *labelPosY;
    QLabel *labelX;
    QLabel *labelSpeedY;
    QLabel *labelGyroscope;
    QLabel *labelSpeed;
    QLabel *labelMotion;
    QLabel *labelAcceleration;
    QLabel *labelAccX;
    QLabel *labelZ;
    QLabel *labelAccY;
    QLabel *labelSpeedZ;
    QLabel *labelGyroZ;
    QLabel *labelSpeedX;
    QLabel *labelGyroY;
    QFrame *frameEngines;
    QGridLayout *gridLayout_5;
    QPushButton *powerButton;
    QDial *leftEngineDial;
    QLabel *rightEngineLabel;
    QLabel *leftEnginePowerLabel;
    QDial *rightEngineDial;
    QLabel *rightEnginePowerLabel;
    QLabel *enginesLabel;
    QLabel *leftEngineLabel;
    QFrame *frameInfrared;
    QGridLayout *gridLayout_6;
    QLabel *labelNameIR3;
    QLabel *labelNameIR2;
    QLabel *labelValueIR2;
    QLabel *labelNameIR8;
    QLabel *labelValueIR7;
    QLabel *labelValueIR8;
    QLabel *labelValueIR6;
    QLabel *labelValueIR3;
    QLabel *labelValueIR5;
    QLabel *labelInfrared;
    QLabel *labelValueIR1;
    QLabel *labelNameIR1;
    QLabel *labelValueIR4;
    QLabel *labelNameIR7;
    QLabel *labelNameIR6;
    QLabel *labelNameIR4;
    QLabel *labelNameIR5;
    QWidget *Communication;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *plainTextEdit;
    QPushButton *SendCommandButton;
    QPushButton *aliveButton;
    QComboBox *comboBoxSendCommand;
    QLabel *labelCommand;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QForm1)
    {
        if (QForm1->objectName().isEmpty())
            QForm1->setObjectName("QForm1");
        QForm1->resize(860, 680);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QForm1->sizePolicy().hasHeightForWidth());
        QForm1->setSizePolicy(sizePolicy);
        QForm1->setMinimumSize(QSize(645, 510));
        QForm1->setMaximumSize(QSize(1075, 850));
        QForm1->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 229);\n"
"background-color: rgb(33, 37, 40);"));
        centralwidget = new QWidget(QForm1);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        navigationBar = new QFrame(centralwidget);
        navigationBar->setObjectName("navigationBar");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(navigationBar->sizePolicy().hasHeightForWidth());
        navigationBar->setSizePolicy(sizePolicy1);
        navigationBar->setStyleSheet(QString::fromUtf8("QWidget#navigationBar{\n"
"	background-color: rgb(46, 49, 55);\n"
"}"));
        navigationBar->setFrameShape(QFrame::NoFrame);
        navigationBar->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(navigationBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        labelName = new QLabel(navigationBar);
        labelName->setObjectName("labelName");
        QFont font;
        font.setFamilies({QString::fromUtf8("Ethnocentric")});
        font.setPointSize(25);
        font.setBold(false);
        font.setItalic(false);
        labelName->setFont(font);
        labelName->setStyleSheet(QString::fromUtf8("font: 25pt \"Ethnocentric\";\n"
"color: rgb(222, 223, 225);\n"
"background: transparent;\n"
""));
        labelName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelName);

        verticalSpacer_3 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        telemetryTabButton = new QPushButton(navigationBar);
        telemetryTabButton->setObjectName("telemetryTabButton");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(telemetryTabButton->sizePolicy().hasHeightForWidth());
        telemetryTabButton->setSizePolicy(sizePolicy2);
        telemetryTabButton->setMinimumSize(QSize(80, 80));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Siemens Sans")});
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        telemetryTabButton->setFont(font1);
        telemetryTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));
        telemetryTabButton->setAutoDefault(false);
        telemetryTabButton->setFlat(false);

        verticalLayout->addWidget(telemetryTabButton);

        debugTabButton = new QPushButton(navigationBar);
        debugTabButton->setObjectName("debugTabButton");
        sizePolicy2.setHeightForWidth(debugTabButton->sizePolicy().hasHeightForWidth());
        debugTabButton->setSizePolicy(sizePolicy2);
        debugTabButton->setMinimumSize(QSize(80, 80));
        debugTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));
        debugTabButton->setFlat(true);

        verticalLayout->addWidget(debugTabButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        heartbeatLight = new QRadioButton(navigationBar);
        heartbeatLight->setObjectName("heartbeatLight");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(heartbeatLight->sizePolicy().hasHeightForWidth());
        heartbeatLight->setSizePolicy(sizePolicy3);
        heartbeatLight->setLayoutDirection(Qt::RightToLeft);
        heartbeatLight->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"	width: 20px;\n"
"	height: 20px;\n"
"	margin-right: 7px; margin-top: 2px;\n"
"	border-radius: 10px;\n"
"}\n"
"QRadioButton::indicator:checked { background-color: rgb(255, 0, 255); border-radius: 10px;}\n"
"QRadioButton::indicator:unchecked { background-color: rgb(227, 227, 227);  border-radius: 10px;}\n"
"QRadioButton{\n"
"	background: transparent;\n"
"	font: 700 12pt \"Siemens Sans\";\n"
"	font-weight: bold;\n"
"	color: rgb(227, 227, 229);\n"
"	background: transparent;\n"
"}"));
        heartbeatLight->setCheckable(true);

        verticalLayout->addWidget(heartbeatLight);


        gridLayout->addWidget(navigationBar, 0, 0, 5, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(5, -1, 5, -1);
        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer, 2, 2, 1, 1);

        OpenWifiButton = new QPushButton(centralwidget);
        OpenWifiButton->setObjectName("OpenWifiButton");
        sizePolicy.setHeightForWidth(OpenWifiButton->sizePolicy().hasHeightForWidth());
        OpenWifiButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Siemens Sans")});
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        OpenWifiButton->setFont(font2);
        OpenWifiButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(222, 223, 225);"));
        OpenWifiButton->setFlat(false);

        gridLayout_2->addWidget(OpenWifiButton, 3, 2, 1, 1);

        OpenPortButton = new QPushButton(centralwidget);
        OpenPortButton->setObjectName("OpenPortButton");
        sizePolicy.setHeightForWidth(OpenPortButton->sizePolicy().hasHeightForWidth());
        OpenPortButton->setSizePolicy(sizePolicy);
        OpenPortButton->setFont(font2);
        OpenPortButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(222, 223, 225);"));
        OpenPortButton->setFlat(false);

        gridLayout_2->addWidget(OpenPortButton, 3, 0, 1, 1);

        WifiLineEdit = new QLineEdit(centralwidget);
        WifiLineEdit->setObjectName("WifiLineEdit");
        sizePolicy.setHeightForWidth(WifiLineEdit->sizePolicy().hasHeightForWidth());
        WifiLineEdit->setSizePolicy(sizePolicy);
        WifiLineEdit->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        WifiLineEdit->setMaxLength(32767);

        gridLayout_2->addWidget(WifiLineEdit, 1, 2, 1, 1);

        comboBoxCommunication = new QComboBox(centralwidget);
        comboBoxCommunication->setObjectName("comboBoxCommunication");
        sizePolicy.setHeightForWidth(comboBoxCommunication->sizePolicy().hasHeightForWidth());
        comboBoxCommunication->setSizePolicy(sizePolicy);
        comboBoxCommunication->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        comboBoxCommunication->setFrame(true);

        gridLayout_2->addWidget(comboBoxCommunication, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 1, 1, 1);

        labelHour = new QLabel(centralwidget);
        labelHour->setObjectName("labelHour");
        sizePolicy.setHeightForWidth(labelHour->sizePolicy().hasHeightForWidth());
        labelHour->setSizePolicy(sizePolicy);
        labelHour->setMinimumSize(QSize(0, 20));
        labelHour->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(227, 227, 229);\n"
"background-color: rgb(57, 63, 68);\n"
"margin-right: 1px;\n"
""));
        labelHour->setFrameShadow(QFrame::Plain);
        labelHour->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelHour->setMargin(0);
        labelHour->setIndent(-1);

        gridLayout->addWidget(labelHour, 0, 1, 1, 1);

        frameCommunication = new QFrame(centralwidget);
        frameCommunication->setObjectName("frameCommunication");
        frameCommunication->setMaximumSize(QSize(16777215, 16777215));
        frameCommunication->setStyleSheet(QString::fromUtf8("color: rgb(227, 227, 229);\n"
"background-color: rgb(57, 63, 68);"));
        frameCommunication->setFrameShape(QFrame::NoFrame);
        frameCommunication->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frameCommunication);
        horizontalLayout->setObjectName("horizontalLayout");
        labelCommunication = new QLabel(frameCommunication);
        labelCommunication->setObjectName("labelCommunication");
        labelCommunication->setMinimumSize(QSize(0, 20));
        labelCommunication->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(227, 227, 229);\n"
"background-color: rgb(57, 63, 68);"));
        labelCommunication->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelCommunication);


        gridLayout->addWidget(frameCommunication, 1, 1, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("QWidget#stackedWidget{\n"
"border: 0px solid rgb(150, 150, 150);\n"
"}"));
        Telemetry = new QWidget();
        Telemetry->setObjectName("Telemetry");
        gridLayout_7 = new QGridLayout(Telemetry);
        gridLayout_7->setObjectName("gridLayout_7");
        frameRadar = new QFrame(Telemetry);
        frameRadar->setObjectName("frameRadar");
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frameRadar->sizePolicy().hasHeightForWidth());
        frameRadar->setSizePolicy(sizePolicy4);
        frameRadar->setMinimumSize(QSize(450, 300));
        frameRadar->setStyleSheet(QString::fromUtf8("QWidget#frameRadar{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"border-radius: 5px;\n"
"}"));
        frameRadar->setFrameShape(QFrame::Panel);
        frameRadar->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(frameRadar);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetRadar = new QWidget(frameRadar);
        widgetRadar->setObjectName("widgetRadar");
        widgetRadar->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widgetRadar->sizePolicy().hasHeightForWidth());
        widgetRadar->setSizePolicy(sizePolicy5);
        widgetRadar->setMinimumSize(QSize(305, 200));
        widgetRadar->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));

        verticalLayout_2->addWidget(widgetRadar);

        buttonClear = new QPushButton(frameRadar);
        buttonClear->setObjectName("buttonClear");
        sizePolicy.setHeightForWidth(buttonClear->sizePolicy().hasHeightForWidth());
        buttonClear->setSizePolicy(sizePolicy);
        buttonClear->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        buttonClear->setFlat(false);

        verticalLayout_2->addWidget(buttonClear);


        gridLayout_7->addWidget(frameRadar, 0, 1, 1, 2);

        frameMotion = new QFrame(Telemetry);
        frameMotion->setObjectName("frameMotion");
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(frameMotion->sizePolicy().hasHeightForWidth());
        frameMotion->setSizePolicy(sizePolicy6);
        frameMotion->setStyleSheet(QString::fromUtf8("QWidget#frameMotion{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"border-radius: 5px;\n"
"background-color: rgb(57, 63, 68);\n"
"}"));
        frameMotion->setFrameShape(QFrame::Panel);
        frameMotion->setFrameShadow(QFrame::Plain);
        frameMotion->setLineWidth(1);
        gridLayout_4 = new QGridLayout(frameMotion);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setHorizontalSpacing(6);
        gridLayout_4->setVerticalSpacing(2);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        labelAccZ = new QLabel(frameMotion);
        labelAccZ->setObjectName("labelAccZ");
        labelAccZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccZ, 3, 2, 1, 1);

        labelPosition = new QLabel(frameMotion);
        labelPosition->setObjectName("labelPosition");
        sizePolicy.setHeightForWidth(labelPosition->sizePolicy().hasHeightForWidth());
        labelPosition->setSizePolicy(sizePolicy);
        labelPosition->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelPosition->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosition, 6, 0, 1, 3);

        labelGyroX = new QLabel(frameMotion);
        labelGyroX->setObjectName("labelGyroX");
        labelGyroX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);"));
        labelGyroX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelGyroX, 10, 0, 1, 1);

        labelPosX = new QLabel(frameMotion);
        labelPosX->setObjectName("labelPosX");
        labelPosX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelPosX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosX, 7, 0, 1, 1);

        labelY = new QLabel(frameMotion);
        labelY->setObjectName("labelY");
        labelY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelY, 13, 1, 1, 1);

        labelPosZ = new QLabel(frameMotion);
        labelPosZ->setObjectName("labelPosZ");
        labelPosZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelPosZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosZ, 7, 2, 1, 1);

        labelPosY = new QLabel(frameMotion);
        labelPosY->setObjectName("labelPosY");
        labelPosY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelPosY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosY, 7, 1, 1, 1);

        labelX = new QLabel(frameMotion);
        labelX->setObjectName("labelX");
        labelX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelX, 13, 0, 1, 1);

        labelSpeedY = new QLabel(frameMotion);
        labelSpeedY->setObjectName("labelSpeedY");
        labelSpeedY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"color: rgb(255, 136, 0);"));
        labelSpeedY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedY, 5, 1, 1, 1);

        labelGyroscope = new QLabel(frameMotion);
        labelGyroscope->setObjectName("labelGyroscope");
        sizePolicy.setHeightForWidth(labelGyroscope->sizePolicy().hasHeightForWidth());
        labelGyroscope->setSizePolicy(sizePolicy);
        labelGyroscope->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);"));
        labelGyroscope->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelGyroscope, 9, 0, 1, 3);

        labelSpeed = new QLabel(frameMotion);
        labelSpeed->setObjectName("labelSpeed");
        sizePolicy.setHeightForWidth(labelSpeed->sizePolicy().hasHeightForWidth());
        labelSpeed->setSizePolicy(sizePolicy);
        labelSpeed->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"\n"
"color: rgb(255, 136, 0);"));
        labelSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeed, 4, 0, 1, 3);

        labelMotion = new QLabel(frameMotion);
        labelMotion->setObjectName("labelMotion");
        labelMotion->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelMotion->setIndent(10);

        gridLayout_4->addWidget(labelMotion, 0, 0, 1, 3);

        labelAcceleration = new QLabel(frameMotion);
        labelAcceleration->setObjectName("labelAcceleration");
        labelAcceleration->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAcceleration->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAcceleration, 1, 0, 1, 3);

        labelAccX = new QLabel(frameMotion);
        labelAccX->setObjectName("labelAccX");
        labelAccX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccX, 3, 0, 1, 1);

        labelZ = new QLabel(frameMotion);
        labelZ->setObjectName("labelZ");
        labelZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelZ, 13, 2, 1, 1);

        labelAccY = new QLabel(frameMotion);
        labelAccY->setObjectName("labelAccY");
        labelAccY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccY, 3, 1, 1, 1);

        labelSpeedZ = new QLabel(frameMotion);
        labelSpeedZ->setObjectName("labelSpeedZ");
        labelSpeedZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"\n"
"color: rgb(255, 136, 0);"));
        labelSpeedZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedZ, 5, 2, 1, 1);

        labelGyroZ = new QLabel(frameMotion);
        labelGyroZ->setObjectName("labelGyroZ");
        labelGyroZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);"));
        labelGyroZ->setFrameShape(QFrame::NoFrame);
        labelGyroZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelGyroZ, 10, 2, 1, 1);

        labelSpeedX = new QLabel(frameMotion);
        labelSpeedX->setObjectName("labelSpeedX");
        labelSpeedX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"\n"
"color: rgb(255, 136, 0);"));
        labelSpeedX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedX, 5, 0, 1, 1);

        labelGyroY = new QLabel(frameMotion);
        labelGyroY->setObjectName("labelGyroY");
        labelGyroY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);"));
        labelGyroY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelGyroY, 10, 1, 1, 1);


        gridLayout_7->addWidget(frameMotion, 0, 0, 1, 1);

        frameEngines = new QFrame(Telemetry);
        frameEngines->setObjectName("frameEngines");
        sizePolicy.setHeightForWidth(frameEngines->sizePolicy().hasHeightForWidth());
        frameEngines->setSizePolicy(sizePolicy);
        frameEngines->setStyleSheet(QString::fromUtf8("QWidget#frameEngines{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameEngines->setFrameShape(QFrame::NoFrame);
        frameEngines->setFrameShadow(QFrame::Plain);
        gridLayout_5 = new QGridLayout(frameEngines);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        powerButton = new QPushButton(frameEngines);
        powerButton->setObjectName("powerButton");
        sizePolicy.setHeightForWidth(powerButton->sizePolicy().hasHeightForWidth());
        powerButton->setSizePolicy(sizePolicy);
        powerButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_5->addWidget(powerButton, 6, 0, 1, 2);

        leftEngineDial = new QDial(frameEngines);
        leftEngineDial->setObjectName("leftEngineDial");
        leftEngineDial->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 100, 103);"));
        leftEngineDial->setMaximum(100);
        leftEngineDial->setInvertedAppearance(false);
        leftEngineDial->setWrapping(false);

        gridLayout_5->addWidget(leftEngineDial, 3, 0, 1, 1);

        rightEngineLabel = new QLabel(frameEngines);
        rightEngineLabel->setObjectName("rightEngineLabel");
        sizePolicy.setHeightForWidth(rightEngineLabel->sizePolicy().hasHeightForWidth());
        rightEngineLabel->setSizePolicy(sizePolicy);
        rightEngineLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        rightEngineLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(rightEngineLabel, 2, 1, 1, 1);

        leftEnginePowerLabel = new QLabel(frameEngines);
        leftEnginePowerLabel->setObjectName("leftEnginePowerLabel");
        leftEnginePowerLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        leftEnginePowerLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(leftEnginePowerLabel, 4, 0, 1, 1);

        rightEngineDial = new QDial(frameEngines);
        rightEngineDial->setObjectName("rightEngineDial");
        rightEngineDial->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 100, 103);"));
        rightEngineDial->setMaximum(100);
        rightEngineDial->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(rightEngineDial, 3, 1, 1, 1);

        rightEnginePowerLabel = new QLabel(frameEngines);
        rightEnginePowerLabel->setObjectName("rightEnginePowerLabel");
        rightEnginePowerLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        rightEnginePowerLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(rightEnginePowerLabel, 4, 1, 1, 1);

        enginesLabel = new QLabel(frameEngines);
        enginesLabel->setObjectName("enginesLabel");
        sizePolicy.setHeightForWidth(enginesLabel->sizePolicy().hasHeightForWidth());
        enginesLabel->setSizePolicy(sizePolicy);
        enginesLabel->setMinimumSize(QSize(0, 25));
        enginesLabel->setMaximumSize(QSize(16777215, 25));
        enginesLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"margin-top: 2px;"));
        enginesLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        enginesLabel->setIndent(10);

        gridLayout_5->addWidget(enginesLabel, 1, 0, 1, 2);

        leftEngineLabel = new QLabel(frameEngines);
        leftEngineLabel->setObjectName("leftEngineLabel");
        sizePolicy.setHeightForWidth(leftEngineLabel->sizePolicy().hasHeightForWidth());
        leftEngineLabel->setSizePolicy(sizePolicy);
        leftEngineLabel->setMinimumSize(QSize(108, 0));
        leftEngineLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        leftEngineLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(leftEngineLabel, 2, 0, 1, 1);


        gridLayout_7->addWidget(frameEngines, 1, 0, 1, 1);

        frameInfrared = new QFrame(Telemetry);
        frameInfrared->setObjectName("frameInfrared");
        sizePolicy.setHeightForWidth(frameInfrared->sizePolicy().hasHeightForWidth());
        frameInfrared->setSizePolicy(sizePolicy);
        frameInfrared->setStyleSheet(QString::fromUtf8("QWidget#frameInfrared{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameInfrared->setFrameShape(QFrame::NoFrame);
        frameInfrared->setFrameShadow(QFrame::Plain);
        gridLayout_6 = new QGridLayout(frameInfrared);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        labelNameIR3 = new QLabel(frameInfrared);
        labelNameIR3->setObjectName("labelNameIR3");
        sizePolicy.setHeightForWidth(labelNameIR3->sizePolicy().hasHeightForWidth());
        labelNameIR3->setSizePolicy(sizePolicy);
        labelNameIR3->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR3, 1, 2, 1, 1);

        labelNameIR2 = new QLabel(frameInfrared);
        labelNameIR2->setObjectName("labelNameIR2");
        sizePolicy.setHeightForWidth(labelNameIR2->sizePolicy().hasHeightForWidth());
        labelNameIR2->setSizePolicy(sizePolicy);
        labelNameIR2->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR2, 1, 1, 1, 1);

        labelValueIR2 = new QLabel(frameInfrared);
        labelValueIR2->setObjectName("labelValueIR2");
        labelValueIR2->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR2, 2, 1, 1, 1);

        labelNameIR8 = new QLabel(frameInfrared);
        labelNameIR8->setObjectName("labelNameIR8");
        sizePolicy.setHeightForWidth(labelNameIR8->sizePolicy().hasHeightForWidth());
        labelNameIR8->setSizePolicy(sizePolicy);
        labelNameIR8->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR8->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR8, 3, 2, 1, 1);

        labelValueIR7 = new QLabel(frameInfrared);
        labelValueIR7->setObjectName("labelValueIR7");
        labelValueIR7->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR7->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR7, 4, 4, 1, 1);

        labelValueIR8 = new QLabel(frameInfrared);
        labelValueIR8->setObjectName("labelValueIR8");
        labelValueIR8->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR8->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR8, 4, 2, 1, 1);

        labelValueIR6 = new QLabel(frameInfrared);
        labelValueIR6->setObjectName("labelValueIR6");
        labelValueIR6->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR6, 4, 0, 1, 1);

        labelValueIR3 = new QLabel(frameInfrared);
        labelValueIR3->setObjectName("labelValueIR3");
        labelValueIR3->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR3, 2, 2, 1, 1);

        labelValueIR5 = new QLabel(frameInfrared);
        labelValueIR5->setObjectName("labelValueIR5");
        labelValueIR5->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR5, 2, 4, 1, 1);

        labelInfrared = new QLabel(frameInfrared);
        labelInfrared->setObjectName("labelInfrared");
        sizePolicy.setHeightForWidth(labelInfrared->sizePolicy().hasHeightForWidth());
        labelInfrared->setSizePolicy(sizePolicy);
        labelInfrared->setMinimumSize(QSize(0, 25));
        labelInfrared->setMaximumSize(QSize(16777215, 25));
        labelInfrared->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"margin-top: 2px;"));
        labelInfrared->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelInfrared->setIndent(10);

        gridLayout_6->addWidget(labelInfrared, 0, 0, 1, 5);

        labelValueIR1 = new QLabel(frameInfrared);
        labelValueIR1->setObjectName("labelValueIR1");
        labelValueIR1->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR1, 2, 0, 1, 1);

        labelNameIR1 = new QLabel(frameInfrared);
        labelNameIR1->setObjectName("labelNameIR1");
        sizePolicy.setHeightForWidth(labelNameIR1->sizePolicy().hasHeightForWidth());
        labelNameIR1->setSizePolicy(sizePolicy);
        labelNameIR1->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR1, 1, 0, 1, 1);

        labelValueIR4 = new QLabel(frameInfrared);
        labelValueIR4->setObjectName("labelValueIR4");
        labelValueIR4->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR4, 2, 3, 1, 1);

        labelNameIR7 = new QLabel(frameInfrared);
        labelNameIR7->setObjectName("labelNameIR7");
        sizePolicy.setHeightForWidth(labelNameIR7->sizePolicy().hasHeightForWidth());
        labelNameIR7->setSizePolicy(sizePolicy);
        labelNameIR7->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR7->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR7, 3, 4, 1, 1);

        labelNameIR6 = new QLabel(frameInfrared);
        labelNameIR6->setObjectName("labelNameIR6");
        sizePolicy.setHeightForWidth(labelNameIR6->sizePolicy().hasHeightForWidth());
        labelNameIR6->setSizePolicy(sizePolicy);
        labelNameIR6->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR6, 3, 0, 1, 1);

        labelNameIR4 = new QLabel(frameInfrared);
        labelNameIR4->setObjectName("labelNameIR4");
        sizePolicy.setHeightForWidth(labelNameIR4->sizePolicy().hasHeightForWidth());
        labelNameIR4->setSizePolicy(sizePolicy);
        labelNameIR4->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR4, 1, 3, 1, 1);

        labelNameIR5 = new QLabel(frameInfrared);
        labelNameIR5->setObjectName("labelNameIR5");
        sizePolicy.setHeightForWidth(labelNameIR5->sizePolicy().hasHeightForWidth());
        labelNameIR5->setSizePolicy(sizePolicy);
        labelNameIR5->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR5, 1, 4, 1, 1);


        gridLayout_7->addWidget(frameInfrared, 1, 1, 1, 2);

        stackedWidget->addWidget(Telemetry);
        Communication = new QWidget();
        Communication->setObjectName("Communication");
        gridLayout_3 = new QGridLayout(Communication);
        gridLayout_3->setObjectName("gridLayout_3");
        plainTextEdit = new QPlainTextEdit(Communication);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy7);
        plainTextEdit->setToolTipDuration(-1);
        plainTextEdit->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setLineWidth(1);
        plainTextEdit->setCursorWidth(1);

        gridLayout_3->addWidget(plainTextEdit, 2, 0, 1, 3);

        SendCommandButton = new QPushButton(Communication);
        SendCommandButton->setObjectName("SendCommandButton");
        sizePolicy2.setHeightForWidth(SendCommandButton->sizePolicy().hasHeightForWidth());
        SendCommandButton->setSizePolicy(sizePolicy2);
        SendCommandButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_3->addWidget(SendCommandButton, 1, 1, 1, 1);

        aliveButton = new QPushButton(Communication);
        aliveButton->setObjectName("aliveButton");
        sizePolicy2.setHeightForWidth(aliveButton->sizePolicy().hasHeightForWidth());
        aliveButton->setSizePolicy(sizePolicy2);
        aliveButton->setFocusPolicy(Qt::StrongFocus);
        aliveButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_3->addWidget(aliveButton, 1, 2, 1, 1);

        comboBoxSendCommand = new QComboBox(Communication);
        comboBoxSendCommand->setObjectName("comboBoxSendCommand");
        comboBoxSendCommand->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_3->addWidget(comboBoxSendCommand, 1, 0, 1, 1);

        labelCommand = new QLabel(Communication);
        labelCommand->setObjectName("labelCommand");
        labelCommand->setMinimumSize(QSize(0, 25));
        labelCommand->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);\n"
"\n"
""));
        labelCommand->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelCommand, 0, 0, 1, 3);

        stackedWidget->addWidget(Communication);

        gridLayout->addWidget(stackedWidget, 4, 1, 1, 1);

        QForm1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QForm1);
        statusbar->setObjectName("statusbar");
        QForm1->setStatusBar(statusbar);

        retranslateUi(QForm1);

        telemetryTabButton->setDefault(false);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QForm1);
    } // setupUi

    void retranslateUi(QMainWindow *QForm1)
    {
        QForm1->setWindowTitle(QCoreApplication::translate("QForm1", "QTCar v3.0", nullptr));
        labelName->setText(QCoreApplication::translate("QForm1", "GS", nullptr));
        telemetryTabButton->setText(QCoreApplication::translate("QForm1", "Telemetry", nullptr));
        debugTabButton->setText(QCoreApplication::translate("QForm1", "Debug", nullptr));
        heartbeatLight->setText(QCoreApplication::translate("QForm1", "Alive", nullptr));
        OpenWifiButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        OpenPortButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        WifiLineEdit->setInputMask(QString());
        WifiLineEdit->setText(QString());
        WifiLineEdit->setPlaceholderText(QCoreApplication::translate("QForm1", "Wifi Port", nullptr));
        comboBoxCommunication->setPlaceholderText(QCoreApplication::translate("QForm1", "USB/UART", nullptr));
        labelHour->setText(QCoreApplication::translate("QForm1", "00:00:00", nullptr));
        labelCommunication->setText(QCoreApplication::translate("QForm1", "Communication", nullptr));
        buttonClear->setText(QCoreApplication::translate("QForm1", "CLEAR", nullptr));
        labelAccZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelPosition->setText(QCoreApplication::translate("QForm1", "Position", nullptr));
        labelGyroX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelPosX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelY->setText(QCoreApplication::translate("QForm1", "Y", nullptr));
        labelPosZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelPosY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelX->setText(QCoreApplication::translate("QForm1", "X", nullptr));
        labelSpeedY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroscope->setText(QCoreApplication::translate("QForm1", "Gyroscope", nullptr));
        labelSpeed->setText(QCoreApplication::translate("QForm1", "Speed", nullptr));
        labelMotion->setText(QCoreApplication::translate("QForm1", "Motion", nullptr));
        labelAcceleration->setText(QCoreApplication::translate("QForm1", "Acceleration", nullptr));
        labelAccX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelZ->setText(QCoreApplication::translate("QForm1", "Z", nullptr));
        labelAccY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelSpeedZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelSpeedX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        powerButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        rightEngineLabel->setText(QCoreApplication::translate("QForm1", "Right", nullptr));
        leftEnginePowerLabel->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        rightEnginePowerLabel->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        enginesLabel->setText(QCoreApplication::translate("QForm1", "Engines", nullptr));
        leftEngineLabel->setText(QCoreApplication::translate("QForm1", "Left", nullptr));
        labelNameIR3->setText(QCoreApplication::translate("QForm1", "3", nullptr));
        labelNameIR2->setText(QCoreApplication::translate("QForm1", "2", nullptr));
        labelValueIR2->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR8->setText(QCoreApplication::translate("QForm1", "8", nullptr));
        labelValueIR7->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR8->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR6->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR3->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR5->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelInfrared->setText(QCoreApplication::translate("QForm1", "Infrared", nullptr));
        labelValueIR1->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR1->setText(QCoreApplication::translate("QForm1", "1", nullptr));
        labelValueIR4->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR7->setText(QCoreApplication::translate("QForm1", "7", nullptr));
        labelNameIR6->setText(QCoreApplication::translate("QForm1", "6", nullptr));
        labelNameIR4->setText(QCoreApplication::translate("QForm1", "4", nullptr));
        labelNameIR5->setText(QCoreApplication::translate("QForm1", "5", nullptr));
        SendCommandButton->setText(QCoreApplication::translate("QForm1", "SEND", nullptr));
        aliveButton->setText(QCoreApplication::translate("QForm1", "ALIVE", nullptr));
        labelCommand->setText(QCoreApplication::translate("QForm1", "Command", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QForm1: public Ui_QForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORM1_H
