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
#include <QtQuickWidgets/QQuickWidget>
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
    QLabel *labelHour;
    QFrame *navigationBar;
    QVBoxLayout *verticalLayout;
    QLabel *labelName;
    QSpacerItem *verticalSpacer_3;
    QPushButton *homeTabButton;
    QPushButton *viewTabButton;
    QPushButton *telemetryTabButton;
    QPushButton *PIDTabButton;
    QPushButton *debugTabButton;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *heartbeatLight;
    QFrame *frameCommunication;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCommunication;
    QGridLayout *gridLayout_2;
    QComboBox *comboBoxCommunication;
    QSpacerItem *verticalSpacer;
    QLineEdit *WifiLineEdit;
    QPushButton *OpenPortButton;
    QPushButton *OpenWifiButton;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *Home;
    QGridLayout *gridLayout_8;
    QLabel *labelHomeGS;
    QWidget *Telemetry;
    QGridLayout *gridLayout_7;
    QFrame *frameEngines;
    QGridLayout *gridLayout_5;
    QLabel *leftEngineLabel;
    QDial *leftEngineDial;
    QLabel *leftEnginePowerLabel;
    QLabel *rightEngineLabel;
    QPushButton *powerButton;
    QLabel *enginesLabel;
    QLabel *rightEnginePowerLabel;
    QDial *rightEngineDial;
    QFrame *frameAccelerometer;
    QGridLayout *gridLayout_4;
    QLabel *labelMotion;
    QLabel *labelZ_A;
    QLabel *labelPosX;
    QLabel *labelPosZ;
    QLabel *labelX_A;
    QLabel *labelPosY;
    QLabel *labelY_A;
    QLabel *labelAcceleration;
    QLabel *labelSpeedX;
    QLabel *labelAccX;
    QLabel *labelPosition;
    QLabel *labelSpeed;
    QLabel *labelSpeedZ;
    QLabel *labelAccZ;
    QLabel *labelSpeedY;
    QLabel *labelAccY;
    QFrame *frameInfrared;
    QGridLayout *gridLayout_6;
    QLabel *labelValueIR8;
    QLabel *labelNameIR8;
    QLabel *labelNameIR7;
    QLabel *labelValueIR7;
    QLabel *labelNameIR6;
    QLabel *labelValueIR6;
    QLabel *labelNameIR5;
    QLabel *labelValueIR5;
    QLabel *labelNameIR4;
    QLabel *labelNameIR3;
    QLabel *labelValueIR3;
    QLabel *labelValueIR4;
    QLabel *labelValueIR1;
    QLabel *labelNameIR1;
    QLabel *labelNameIR2;
    QLabel *labelValueIR2;
    QLabel *labelInfrared;
    QFrame *frameGyroscope;
    QGridLayout *gridLayout_22;
    QLabel *labelGyroZ;
    QLabel *labelGyroX;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelGyroY;
    QLabel *labelGyroscope;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *labelX_G;
    QLabel *labelY_G;
    QLabel *labelZ_G;
    QLabel *label_6;
    QWidget *PID;
    QGridLayout *gridLayout_9;
    QFrame *framePID;
    QGridLayout *gridLayout_12;
    QPushButton *readTurnPIDButton;
    QLabel *labelKD;
    QLineEdit *lineEditTurnKD;
    QLineEdit *lineEditTurnBase;
    QLineEdit *lineEditTurnMax;
    QLineEdit *lineEditTurnMin;
    QPushButton *setTurnPIDButton;
    QLabel *labelBaseOut;
    QLineEdit *lineEditTurnKP;
    QLabel *labelMaxOut;
    QLabel *labelMinOut;
    QLineEdit *lineEditTurnKI;
    QLabel *labelKP;
    QLabel *labelKI;
    QPushButton *readWallPIDButton;
    QLineEdit *lineEditWallBase;
    QLineEdit *lineEditWallMax;
    QLineEdit *lineEditWallMin;
    QLineEdit *lineEditWallKD;
    QLineEdit *lineEditWallKI;
    QLineEdit *lineEditWallKP;
    QPushButton *setWallPIDButton;
    QLabel *labelTurnPID;
    QLabel *labelWallPID;
    QLabel *labelPIDValues;
    QFrame *frameFirmware;
    QGridLayout *gridLayout_14;
    QLabel *labelFirmwareVersion;
    QLabel *labelFirmware;
    QFrame *frameHardware;
    QGridLayout *gridLayout_11;
    QLabel *labelIMU;
    QLabel *labelIRModel;
    QLabel *labelMCUModel;
    QLabel *labelInfraSensors;
    QLabel *labelMicrocontroller;
    QLabel *labelMPUModel;
    QLabel *labelDisplayOLED;
    QLabel *labelDriver;
    QLabel *labelDriverModel;
    QLabel *labelDisplayModel;
    QFrame *frameSoftwareConfig;
    QGridLayout *gridLayout_13;
    QLineEdit *pwmPrescalerConfig;
    QLabel *labelResultingFrequency;
    QLabel *labelPeriod;
    QPushButton *pwmConfigButton;
    QLabel *labelPrescaler;
    QLineEdit *pwmPeriodConfig;
    QLabel *labelTimerFreqResult;
    QPushButton *changeConfigWidgetButton;
    QWidget *Communication;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *plainTextEdit;
    QPushButton *SendCommandButton;
    QPushButton *aliveButton;
    QComboBox *comboBoxSendCommand;
    QLabel *labelCommand;
    QWidget *Maze;
    QGridLayout *gridLayout_10;
    QWidget *widget;
    QGridLayout *gridLayout_17;
    QFrame *frameDisplayIntersection;
    QGridLayout *gridLayout_20;
    QQuickWidget *qmlDisplayWidget;
    QSpacerItem *verticalSpacer_4;
    QFrame *frameRadar;
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetRadar;
    QPushButton *buttonClear;
    QFrame *frameCurrentAction;
    QGridLayout *gridLayout_21;
    QLabel *labelCurrentAction;
    QLabel *labelCurrentActionState;
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
        QForm1->setMinimumSize(QSize(700, 600));
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
"color: rgb(96, 100, 103);\n"
"background: transparent;\n"
""));
        labelName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelName);

        verticalSpacer_3 = new QSpacerItem(20, 82, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        homeTabButton = new QPushButton(navigationBar);
        homeTabButton->setObjectName("homeTabButton");
        homeTabButton->setMinimumSize(QSize(80, 80));
        homeTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));

        verticalLayout->addWidget(homeTabButton);

        viewTabButton = new QPushButton(navigationBar);
        viewTabButton->setObjectName("viewTabButton");
        viewTabButton->setMinimumSize(QSize(80, 80));
        viewTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));

        verticalLayout->addWidget(viewTabButton);

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

        PIDTabButton = new QPushButton(navigationBar);
        PIDTabButton->setObjectName("PIDTabButton");
        PIDTabButton->setMinimumSize(QSize(80, 80));
        PIDTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));

        verticalLayout->addWidget(PIDTabButton);

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

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(5, -1, 5, -1);
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

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer, 3, 2, 1, 1);

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

        OpenPortButton = new QPushButton(centralwidget);
        OpenPortButton->setObjectName("OpenPortButton");
        sizePolicy.setHeightForWidth(OpenPortButton->sizePolicy().hasHeightForWidth());
        OpenPortButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Siemens Sans")});
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        OpenPortButton->setFont(font2);
        OpenPortButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(222, 223, 225);"));
        OpenPortButton->setFlat(false);

        gridLayout_2->addWidget(OpenPortButton, 4, 0, 1, 1);

        OpenWifiButton = new QPushButton(centralwidget);
        OpenWifiButton->setObjectName("OpenWifiButton");
        sizePolicy.setHeightForWidth(OpenWifiButton->sizePolicy().hasHeightForWidth());
        OpenWifiButton->setSizePolicy(sizePolicy);
        OpenWifiButton->setFont(font2);
        OpenWifiButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(222, 223, 225);"));
        OpenWifiButton->setFlat(false);

        gridLayout_2->addWidget(OpenWifiButton, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 1, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("QWidget#stackedWidget{\n"
"border: 0px solid rgb(150, 150, 150);\n"
"}"));
        Home = new QWidget();
        Home->setObjectName("Home");
        gridLayout_8 = new QGridLayout(Home);
        gridLayout_8->setObjectName("gridLayout_8");
        labelHomeGS = new QLabel(Home);
        labelHomeGS->setObjectName("labelHomeGS");
        labelHomeGS->setStyleSheet(QString::fromUtf8("font: 256pt \"Ethnocentric\";\n"
"color: rgb(96, 100, 103);"));
        labelHomeGS->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(labelHomeGS, 0, 0, 1, 1);

        stackedWidget->addWidget(Home);
        Telemetry = new QWidget();
        Telemetry->setObjectName("Telemetry");
        gridLayout_7 = new QGridLayout(Telemetry);
        gridLayout_7->setObjectName("gridLayout_7");
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
        gridLayout_5->setContentsMargins(0, 7, 0, 0);
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

        leftEngineDial = new QDial(frameEngines);
        leftEngineDial->setObjectName("leftEngineDial");
        leftEngineDial->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 100, 103);"));
        leftEngineDial->setMaximum(100);
        leftEngineDial->setInvertedAppearance(false);
        leftEngineDial->setWrapping(false);

        gridLayout_5->addWidget(leftEngineDial, 4, 0, 1, 1);

        leftEnginePowerLabel = new QLabel(frameEngines);
        leftEnginePowerLabel->setObjectName("leftEnginePowerLabel");
        leftEnginePowerLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        leftEnginePowerLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(leftEnginePowerLabel, 5, 0, 1, 1);

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

        powerButton = new QPushButton(frameEngines);
        powerButton->setObjectName("powerButton");
        sizePolicy.setHeightForWidth(powerButton->sizePolicy().hasHeightForWidth());
        powerButton->setSizePolicy(sizePolicy);
        powerButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_5->addWidget(powerButton, 7, 0, 1, 2);

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

        rightEnginePowerLabel = new QLabel(frameEngines);
        rightEnginePowerLabel->setObjectName("rightEnginePowerLabel");
        rightEnginePowerLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        rightEnginePowerLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(rightEnginePowerLabel, 5, 1, 1, 1);

        rightEngineDial = new QDial(frameEngines);
        rightEngineDial->setObjectName("rightEngineDial");
        rightEngineDial->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 100, 103);"));

        gridLayout_5->addWidget(rightEngineDial, 4, 1, 1, 1);


        gridLayout_7->addWidget(frameEngines, 2, 0, 1, 1);

        frameAccelerometer = new QFrame(Telemetry);
        frameAccelerometer->setObjectName("frameAccelerometer");
        sizePolicy.setHeightForWidth(frameAccelerometer->sizePolicy().hasHeightForWidth());
        frameAccelerometer->setSizePolicy(sizePolicy);
        frameAccelerometer->setStyleSheet(QString::fromUtf8("QWidget#frameAccelerometer{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"border-radius: 5px;\n"
"background-color: rgb(57, 63, 68);\n"
"}"));
        frameAccelerometer->setFrameShape(QFrame::Panel);
        frameAccelerometer->setFrameShadow(QFrame::Plain);
        frameAccelerometer->setLineWidth(1);
        gridLayout_4 = new QGridLayout(frameAccelerometer);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setHorizontalSpacing(6);
        gridLayout_4->setVerticalSpacing(2);
        gridLayout_4->setContentsMargins(0, 7, 0, 0);
        labelMotion = new QLabel(frameAccelerometer);
        labelMotion->setObjectName("labelMotion");
        labelMotion->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelMotion->setIndent(10);

        gridLayout_4->addWidget(labelMotion, 0, 0, 1, 3);

        labelZ_A = new QLabel(frameAccelerometer);
        labelZ_A->setObjectName("labelZ_A");
        labelZ_A->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelZ_A->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelZ_A, 12, 2, 1, 1);

        labelPosX = new QLabel(frameAccelerometer);
        labelPosX->setObjectName("labelPosX");
        labelPosX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelPosX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosX, 7, 0, 1, 1);

        labelPosZ = new QLabel(frameAccelerometer);
        labelPosZ->setObjectName("labelPosZ");
        labelPosZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelPosZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosZ, 7, 2, 1, 1);

        labelX_A = new QLabel(frameAccelerometer);
        labelX_A->setObjectName("labelX_A");
        labelX_A->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelX_A->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelX_A, 12, 0, 1, 1);

        labelPosY = new QLabel(frameAccelerometer);
        labelPosY->setObjectName("labelPosY");
        labelPosY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelPosY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosY, 7, 1, 1, 1);

        labelY_A = new QLabel(frameAccelerometer);
        labelY_A->setObjectName("labelY_A");
        labelY_A->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelY_A->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelY_A, 12, 1, 1, 1);

        labelAcceleration = new QLabel(frameAccelerometer);
        labelAcceleration->setObjectName("labelAcceleration");
        labelAcceleration->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAcceleration->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAcceleration, 1, 0, 1, 3);

        labelSpeedX = new QLabel(frameAccelerometer);
        labelSpeedX->setObjectName("labelSpeedX");
        labelSpeedX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"\n"
"color: rgb(255, 136, 0);"));
        labelSpeedX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedX, 5, 0, 1, 1);

        labelAccX = new QLabel(frameAccelerometer);
        labelAccX->setObjectName("labelAccX");
        labelAccX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccX, 3, 0, 1, 1);

        labelPosition = new QLabel(frameAccelerometer);
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

        labelSpeed = new QLabel(frameAccelerometer);
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

        labelSpeedZ = new QLabel(frameAccelerometer);
        labelSpeedZ->setObjectName("labelSpeedZ");
        labelSpeedZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"\n"
"color: rgb(255, 136, 0)\n"
""));
        labelSpeedZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedZ, 5, 2, 1, 1);

        labelAccZ = new QLabel(frameAccelerometer);
        labelAccZ->setObjectName("labelAccZ");
        labelAccZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccZ, 3, 2, 1, 1);

        labelSpeedY = new QLabel(frameAccelerometer);
        labelSpeedY->setObjectName("labelSpeedY");
        labelSpeedY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"color: rgb(255, 136, 0);"));
        labelSpeedY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedY, 5, 1, 1, 1);

        labelAccY = new QLabel(frameAccelerometer);
        labelAccY->setObjectName("labelAccY");
        labelAccY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccY, 3, 1, 1, 1);


        gridLayout_7->addWidget(frameAccelerometer, 0, 0, 1, 1);

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
        labelValueIR8 = new QLabel(frameInfrared);
        labelValueIR8->setObjectName("labelValueIR8");
        labelValueIR8->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR8->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR8, 5, 2, 1, 1);

        labelNameIR8 = new QLabel(frameInfrared);
        labelNameIR8->setObjectName("labelNameIR8");
        sizePolicy.setHeightForWidth(labelNameIR8->sizePolicy().hasHeightForWidth());
        labelNameIR8->setSizePolicy(sizePolicy);
        labelNameIR8->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR8->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR8, 4, 2, 1, 1);

        labelNameIR7 = new QLabel(frameInfrared);
        labelNameIR7->setObjectName("labelNameIR7");
        sizePolicy.setHeightForWidth(labelNameIR7->sizePolicy().hasHeightForWidth());
        labelNameIR7->setSizePolicy(sizePolicy);
        labelNameIR7->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR7->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR7, 4, 0, 1, 1);

        labelValueIR7 = new QLabel(frameInfrared);
        labelValueIR7->setObjectName("labelValueIR7");
        labelValueIR7->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR7->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR7, 5, 0, 1, 1);

        labelNameIR6 = new QLabel(frameInfrared);
        labelNameIR6->setObjectName("labelNameIR6");
        sizePolicy.setHeightForWidth(labelNameIR6->sizePolicy().hasHeightForWidth());
        labelNameIR6->setSizePolicy(sizePolicy);
        labelNameIR6->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR6, 1, 0, 1, 1);

        labelValueIR6 = new QLabel(frameInfrared);
        labelValueIR6->setObjectName("labelValueIR6");
        labelValueIR6->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR6, 3, 0, 1, 1);

        labelNameIR5 = new QLabel(frameInfrared);
        labelNameIR5->setObjectName("labelNameIR5");
        sizePolicy.setHeightForWidth(labelNameIR5->sizePolicy().hasHeightForWidth());
        labelNameIR5->setSizePolicy(sizePolicy);
        labelNameIR5->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR5, 1, 1, 1, 1);

        labelValueIR5 = new QLabel(frameInfrared);
        labelValueIR5->setObjectName("labelValueIR5");
        labelValueIR5->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR5, 3, 1, 1, 1);

        labelNameIR4 = new QLabel(frameInfrared);
        labelNameIR4->setObjectName("labelNameIR4");
        sizePolicy.setHeightForWidth(labelNameIR4->sizePolicy().hasHeightForWidth());
        labelNameIR4->setSizePolicy(sizePolicy);
        labelNameIR4->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR4, 1, 2, 1, 1);

        labelNameIR3 = new QLabel(frameInfrared);
        labelNameIR3->setObjectName("labelNameIR3");
        sizePolicy.setHeightForWidth(labelNameIR3->sizePolicy().hasHeightForWidth());
        labelNameIR3->setSizePolicy(sizePolicy);
        labelNameIR3->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR3, 1, 3, 1, 1);

        labelValueIR3 = new QLabel(frameInfrared);
        labelValueIR3->setObjectName("labelValueIR3");
        labelValueIR3->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR3, 3, 3, 1, 1);

        labelValueIR4 = new QLabel(frameInfrared);
        labelValueIR4->setObjectName("labelValueIR4");
        labelValueIR4->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR4, 3, 2, 1, 1);

        labelValueIR1 = new QLabel(frameInfrared);
        labelValueIR1->setObjectName("labelValueIR1");
        labelValueIR1->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR1, 5, 4, 1, 1);

        labelNameIR1 = new QLabel(frameInfrared);
        labelNameIR1->setObjectName("labelNameIR1");
        sizePolicy.setHeightForWidth(labelNameIR1->sizePolicy().hasHeightForWidth());
        labelNameIR1->setSizePolicy(sizePolicy);
        labelNameIR1->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR1, 4, 4, 1, 1);

        labelNameIR2 = new QLabel(frameInfrared);
        labelNameIR2->setObjectName("labelNameIR2");
        sizePolicy.setHeightForWidth(labelNameIR2->sizePolicy().hasHeightForWidth());
        labelNameIR2->setSizePolicy(sizePolicy);
        labelNameIR2->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR2, 1, 4, 1, 1);

        labelValueIR2 = new QLabel(frameInfrared);
        labelValueIR2->setObjectName("labelValueIR2");
        labelValueIR2->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR2, 3, 4, 1, 1);

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

        gridLayout_6->addWidget(labelInfrared, 0, 0, 1, 4);


        gridLayout_7->addWidget(frameInfrared, 2, 3, 1, 1);

        frameGyroscope = new QFrame(Telemetry);
        frameGyroscope->setObjectName("frameGyroscope");
        frameGyroscope->setStyleSheet(QString::fromUtf8("QWidget#frameGyroscope{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"border-radius: 5px;\n"
"background-color: rgb(57, 63, 68);\n"
"}"));
        frameGyroscope->setFrameShape(QFrame::StyledPanel);
        frameGyroscope->setFrameShadow(QFrame::Raised);
        gridLayout_22 = new QGridLayout(frameGyroscope);
        gridLayout_22->setObjectName("gridLayout_22");
        gridLayout_22->setContentsMargins(-1, 7, 0, 0);
        labelGyroZ = new QLabel(frameGyroscope);
        labelGyroZ->setObjectName("labelGyroZ");
        labelGyroZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);"));
        labelGyroZ->setFrameShape(QFrame::NoFrame);
        labelGyroZ->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelGyroZ, 2, 2, 1, 1);

        labelGyroX = new QLabel(frameGyroscope);
        labelGyroX->setObjectName("labelGyroX");
        labelGyroX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);"));
        labelGyroX->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelGyroX, 2, 0, 1, 1);

        label_3 = new QLabel(frameGyroscope);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 102);"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(label_3, 4, 1, 1, 1);

        label_4 = new QLabel(frameGyroscope);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 102);"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(label_4, 4, 2, 1, 1);

        labelGyroY = new QLabel(frameGyroscope);
        labelGyroY->setObjectName("labelGyroY");
        labelGyroY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);"));
        labelGyroY->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelGyroY, 2, 1, 1, 1);

        labelGyroscope = new QLabel(frameGyroscope);
        labelGyroscope->setObjectName("labelGyroscope");
        sizePolicy.setHeightForWidth(labelGyroscope->sizePolicy().hasHeightForWidth());
        labelGyroscope->setSizePolicy(sizePolicy);
        labelGyroscope->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelGyroscope->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_22->addWidget(labelGyroscope, 0, 0, 1, 3);

        label_2 = new QLabel(frameGyroscope);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 102);"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(label_2, 4, 0, 1, 1);

        label_5 = new QLabel(frameGyroscope);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(label_5, 1, 0, 1, 3);

        labelX_G = new QLabel(frameGyroscope);
        labelX_G->setObjectName("labelX_G");
        labelX_G->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelX_G->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelX_G, 5, 0, 1, 1);

        labelY_G = new QLabel(frameGyroscope);
        labelY_G->setObjectName("labelY_G");
        labelY_G->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelY_G->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelY_G, 5, 1, 1, 1);

        labelZ_G = new QLabel(frameGyroscope);
        labelZ_G->setObjectName("labelZ_G");
        labelZ_G->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelZ_G->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelZ_G, 5, 2, 1, 1);

        label_6 = new QLabel(frameGyroscope);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 102);"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(label_6, 3, 0, 1, 3);


        gridLayout_7->addWidget(frameGyroscope, 0, 3, 1, 1);

        stackedWidget->addWidget(Telemetry);
        PID = new QWidget();
        PID->setObjectName("PID");
        gridLayout_9 = new QGridLayout(PID);
        gridLayout_9->setObjectName("gridLayout_9");
        framePID = new QFrame(PID);
        framePID->setObjectName("framePID");
        framePID->setMinimumSize(QSize(0, 0));
        framePID->setStyleSheet(QString::fromUtf8("QWidget#framePID{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        framePID->setFrameShape(QFrame::StyledPanel);
        framePID->setFrameShadow(QFrame::Plain);
        gridLayout_12 = new QGridLayout(framePID);
        gridLayout_12->setObjectName("gridLayout_12");
        readTurnPIDButton = new QPushButton(framePID);
        readTurnPIDButton->setObjectName("readTurnPIDButton");
        readTurnPIDButton->setMinimumSize(QSize(79, 0));
        readTurnPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        readTurnPIDButton->setFlat(true);

        gridLayout_12->addWidget(readTurnPIDButton, 11, 1, 1, 1);

        labelKD = new QLabel(framePID);
        labelKD->setObjectName("labelKD");
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelKD->sizePolicy().hasHeightForWidth());
        labelKD->setSizePolicy(sizePolicy4);
        labelKD->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKD->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKD, 5, 0, 1, 1);

        lineEditTurnKD = new QLineEdit(framePID);
        lineEditTurnKD->setObjectName("lineEditTurnKD");
        lineEditTurnKD->setMinimumSize(QSize(79, 0));
        lineEditTurnKD->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKD->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKD, 5, 1, 1, 2);

        lineEditTurnBase = new QLineEdit(framePID);
        lineEditTurnBase->setObjectName("lineEditTurnBase");
        lineEditTurnBase->setMinimumSize(QSize(79, 0));
        lineEditTurnBase->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnBase->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnBase, 9, 1, 1, 2);

        lineEditTurnMax = new QLineEdit(framePID);
        lineEditTurnMax->setObjectName("lineEditTurnMax");
        lineEditTurnMax->setMinimumSize(QSize(79, 0));
        lineEditTurnMax->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnMax->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnMax, 7, 1, 1, 2);

        lineEditTurnMin = new QLineEdit(framePID);
        lineEditTurnMin->setObjectName("lineEditTurnMin");
        lineEditTurnMin->setMinimumSize(QSize(79, 0));
        lineEditTurnMin->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnMin->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnMin, 6, 1, 1, 2);

        setTurnPIDButton = new QPushButton(framePID);
        setTurnPIDButton->setObjectName("setTurnPIDButton");
        setTurnPIDButton->setMinimumSize(QSize(79, 0));
        setTurnPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(setTurnPIDButton, 11, 2, 1, 1);

        labelBaseOut = new QLabel(framePID);
        labelBaseOut->setObjectName("labelBaseOut");
        labelBaseOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelBaseOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelBaseOut, 9, 0, 1, 1);

        lineEditTurnKP = new QLineEdit(framePID);
        lineEditTurnKP->setObjectName("lineEditTurnKP");
        lineEditTurnKP->setMinimumSize(QSize(79, 0));
        lineEditTurnKP->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKP, 3, 1, 1, 2);

        labelMaxOut = new QLabel(framePID);
        labelMaxOut->setObjectName("labelMaxOut");
        labelMaxOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelMaxOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelMaxOut, 7, 0, 1, 1);

        labelMinOut = new QLabel(framePID);
        labelMinOut->setObjectName("labelMinOut");
        labelMinOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelMinOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelMinOut, 6, 0, 1, 1);

        lineEditTurnKI = new QLineEdit(framePID);
        lineEditTurnKI->setObjectName("lineEditTurnKI");
        lineEditTurnKI->setMinimumSize(QSize(79, 0));
        lineEditTurnKI->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKI, 4, 1, 1, 2);

        labelKP = new QLabel(framePID);
        labelKP->setObjectName("labelKP");
        sizePolicy4.setHeightForWidth(labelKP->sizePolicy().hasHeightForWidth());
        labelKP->setSizePolicy(sizePolicy4);
        labelKP->setLayoutDirection(Qt::LeftToRight);
        labelKP->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKP, 3, 0, 1, 1);

        labelKI = new QLabel(framePID);
        labelKI->setObjectName("labelKI");
        sizePolicy4.setHeightForWidth(labelKI->sizePolicy().hasHeightForWidth());
        labelKI->setSizePolicy(sizePolicy4);
        labelKI->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKI, 4, 0, 1, 1);

        readWallPIDButton = new QPushButton(framePID);
        readWallPIDButton->setObjectName("readWallPIDButton");
        readWallPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        readWallPIDButton->setFlat(true);

        gridLayout_12->addWidget(readWallPIDButton, 11, 3, 1, 1);

        lineEditWallBase = new QLineEdit(framePID);
        lineEditWallBase->setObjectName("lineEditWallBase");
        lineEditWallBase->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallBase->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallBase, 9, 3, 1, 2);

        lineEditWallMax = new QLineEdit(framePID);
        lineEditWallMax->setObjectName("lineEditWallMax");
        lineEditWallMax->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallMax->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallMax, 7, 3, 1, 2);

        lineEditWallMin = new QLineEdit(framePID);
        lineEditWallMin->setObjectName("lineEditWallMin");
        lineEditWallMin->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallMin->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallMin, 6, 3, 1, 2);

        lineEditWallKD = new QLineEdit(framePID);
        lineEditWallKD->setObjectName("lineEditWallKD");
        lineEditWallKD->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKD->setFrame(true);
        lineEditWallKD->setAlignment(Qt::AlignCenter);
        lineEditWallKD->setClearButtonEnabled(false);

        gridLayout_12->addWidget(lineEditWallKD, 5, 3, 1, 2);

        lineEditWallKI = new QLineEdit(framePID);
        lineEditWallKI->setObjectName("lineEditWallKI");
        lineEditWallKI->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallKI, 4, 3, 1, 2);

        lineEditWallKP = new QLineEdit(framePID);
        lineEditWallKP->setObjectName("lineEditWallKP");
        lineEditWallKP->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallKP, 3, 3, 1, 2);

        setWallPIDButton = new QPushButton(framePID);
        setWallPIDButton->setObjectName("setWallPIDButton");
        setWallPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(setWallPIDButton, 11, 4, 1, 1);

        labelTurnPID = new QLabel(framePID);
        labelTurnPID->setObjectName("labelTurnPID");
        labelTurnPID->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelTurnPID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(labelTurnPID, 2, 1, 1, 2);

        labelWallPID = new QLabel(framePID);
        labelWallPID->setObjectName("labelWallPID");
        labelWallPID->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelWallPID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(labelWallPID, 2, 3, 1, 2);

        labelPIDValues = new QLabel(framePID);
        labelPIDValues->setObjectName("labelPIDValues");
        sizePolicy4.setHeightForWidth(labelPIDValues->sizePolicy().hasHeightForWidth());
        labelPIDValues->setSizePolicy(sizePolicy4);
        labelPIDValues->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_12->addWidget(labelPIDValues, 0, 0, 1, 1);


        gridLayout_9->addWidget(framePID, 1, 0, 4, 2);

        frameFirmware = new QFrame(PID);
        frameFirmware->setObjectName("frameFirmware");
        frameFirmware->setStyleSheet(QString::fromUtf8("QWidget#frameFirmware{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameFirmware->setFrameShape(QFrame::StyledPanel);
        frameFirmware->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frameFirmware);
        gridLayout_14->setObjectName("gridLayout_14");
        labelFirmwareVersion = new QLabel(frameFirmware);
        labelFirmwareVersion->setObjectName("labelFirmwareVersion");
        labelFirmwareVersion->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_14->addWidget(labelFirmwareVersion, 0, 0, 1, 1);

        labelFirmware = new QLabel(frameFirmware);
        labelFirmware->setObjectName("labelFirmware");
        labelFirmware->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelFirmware->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(labelFirmware, 1, 0, 1, 1);


        gridLayout_9->addWidget(frameFirmware, 1, 2, 2, 1);

        frameHardware = new QFrame(PID);
        frameHardware->setObjectName("frameHardware");
        frameHardware->setStyleSheet(QString::fromUtf8("QWidget#frameHardware{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameHardware->setFrameShape(QFrame::StyledPanel);
        frameHardware->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frameHardware);
        gridLayout_11->setObjectName("gridLayout_11");
        labelIMU = new QLabel(frameHardware);
        labelIMU->setObjectName("labelIMU");
        labelIMU->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelIMU->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelIMU, 2, 0, 1, 1);

        labelIRModel = new QLabel(frameHardware);
        labelIRModel->setObjectName("labelIRModel");
        labelIRModel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelIRModel->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelIRModel, 5, 0, 1, 1);

        labelMCUModel = new QLabel(frameHardware);
        labelMCUModel->setObjectName("labelMCUModel");
        labelMCUModel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelMCUModel->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelMCUModel, 1, 0, 1, 1);

        labelInfraSensors = new QLabel(frameHardware);
        labelInfraSensors->setObjectName("labelInfraSensors");
        labelInfraSensors->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelInfraSensors->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelInfraSensors, 4, 0, 1, 1);

        labelMicrocontroller = new QLabel(frameHardware);
        labelMicrocontroller->setObjectName("labelMicrocontroller");
        labelMicrocontroller->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelMicrocontroller->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelMicrocontroller, 0, 0, 1, 1);

        labelMPUModel = new QLabel(frameHardware);
        labelMPUModel->setObjectName("labelMPUModel");
        labelMPUModel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelMPUModel->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelMPUModel, 3, 0, 1, 1);

        labelDisplayOLED = new QLabel(frameHardware);
        labelDisplayOLED->setObjectName("labelDisplayOLED");
        labelDisplayOLED->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelDisplayOLED->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelDisplayOLED, 8, 0, 1, 1);

        labelDriver = new QLabel(frameHardware);
        labelDriver->setObjectName("labelDriver");
        labelDriver->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelDriver->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelDriver, 6, 0, 1, 1);

        labelDriverModel = new QLabel(frameHardware);
        labelDriverModel->setObjectName("labelDriverModel");
        labelDriverModel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelDriverModel->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelDriverModel, 7, 0, 1, 1);

        labelDisplayModel = new QLabel(frameHardware);
        labelDisplayModel->setObjectName("labelDisplayModel");
        labelDisplayModel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelDisplayModel->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(labelDisplayModel, 9, 0, 1, 1);


        gridLayout_9->addWidget(frameHardware, 3, 2, 3, 1);

        frameSoftwareConfig = new QFrame(PID);
        frameSoftwareConfig->setObjectName("frameSoftwareConfig");
        frameSoftwareConfig->setMinimumSize(QSize(0, 130));
        frameSoftwareConfig->setStyleSheet(QString::fromUtf8("QWidget#frameSoftwareConfig{ \n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"border: 2px solid rgb(150, 150, 150);\n"
"}"));
        frameSoftwareConfig->setFrameShape(QFrame::StyledPanel);
        frameSoftwareConfig->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frameSoftwareConfig);
        gridLayout_13->setObjectName("gridLayout_13");
        pwmPrescalerConfig = new QLineEdit(frameSoftwareConfig);
        pwmPrescalerConfig->setObjectName("pwmPrescalerConfig");
        pwmPrescalerConfig->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_13->addWidget(pwmPrescalerConfig, 1, 1, 1, 1);

        labelResultingFrequency = new QLabel(frameSoftwareConfig);
        labelResultingFrequency->setObjectName("labelResultingFrequency");
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(labelResultingFrequency->sizePolicy().hasHeightForWidth());
        labelResultingFrequency->setSizePolicy(sizePolicy5);
        labelResultingFrequency->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_13->addWidget(labelResultingFrequency, 5, 0, 1, 2);

        labelPeriod = new QLabel(frameSoftwareConfig);
        labelPeriod->setObjectName("labelPeriod");
        sizePolicy.setHeightForWidth(labelPeriod->sizePolicy().hasHeightForWidth());
        labelPeriod->setSizePolicy(sizePolicy);
        labelPeriod->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelPeriod->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(labelPeriod, 3, 0, 1, 1);

        pwmConfigButton = new QPushButton(frameSoftwareConfig);
        pwmConfigButton->setObjectName("pwmConfigButton");
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pwmConfigButton->sizePolicy().hasHeightForWidth());
        pwmConfigButton->setSizePolicy(sizePolicy6);
        pwmConfigButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_13->addWidget(pwmConfigButton, 4, 1, 1, 1);

        labelPrescaler = new QLabel(frameSoftwareConfig);
        labelPrescaler->setObjectName("labelPrescaler");
        labelPrescaler->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelPrescaler->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(labelPrescaler, 1, 0, 1, 1);

        pwmPeriodConfig = new QLineEdit(frameSoftwareConfig);
        pwmPeriodConfig->setObjectName("pwmPeriodConfig");
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(pwmPeriodConfig->sizePolicy().hasHeightForWidth());
        pwmPeriodConfig->setSizePolicy(sizePolicy7);
        pwmPeriodConfig->setCursor(QCursor(Qt::IBeamCursor));
        pwmPeriodConfig->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_13->addWidget(pwmPeriodConfig, 3, 1, 1, 1);

        labelTimerFreqResult = new QLabel(frameSoftwareConfig);
        labelTimerFreqResult->setObjectName("labelTimerFreqResult");
        sizePolicy5.setHeightForWidth(labelTimerFreqResult->sizePolicy().hasHeightForWidth());
        labelTimerFreqResult->setSizePolicy(sizePolicy5);
        labelTimerFreqResult->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelTimerFreqResult->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(labelTimerFreqResult, 6, 0, 1, 2);

        changeConfigWidgetButton = new QPushButton(frameSoftwareConfig);
        changeConfigWidgetButton->setObjectName("changeConfigWidgetButton");
        changeConfigWidgetButton->setCursor(QCursor(Qt::PointingHandCursor));
        changeConfigWidgetButton->setAutoFillBackground(false);
        changeConfigWidgetButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border: 0px;\n"
"	color: rgb(79, 216, 218);\n"
"    background-color: transparent;  /* mientras se presiona */\n"
"}"));
        changeConfigWidgetButton->setFlat(true);

        gridLayout_13->addWidget(changeConfigWidgetButton, 0, 0, 1, 1);


        gridLayout_9->addWidget(frameSoftwareConfig, 5, 0, 1, 2);

        stackedWidget->addWidget(PID);
        Communication = new QWidget();
        Communication->setObjectName("Communication");
        gridLayout_3 = new QGridLayout(Communication);
        gridLayout_3->setObjectName("gridLayout_3");
        plainTextEdit = new QPlainTextEdit(Communication);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy8);
        plainTextEdit->setToolTipDuration(-1);
        plainTextEdit->setStyleSheet(QString::fromUtf8("QWidget#plainTextEdit{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(227, 227, 229);\n"
"border-radius: 5px;\n"
"}"));
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
"border-radius: 5px;\n"
""));
        labelCommand->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelCommand, 0, 0, 1, 3);

        stackedWidget->addWidget(Communication);
        Maze = new QWidget();
        Maze->setObjectName("Maze");
        gridLayout_10 = new QGridLayout(Maze);
        gridLayout_10->setObjectName("gridLayout_10");
        widget = new QWidget(Maze);
        widget->setObjectName("widget");
        gridLayout_17 = new QGridLayout(widget);
        gridLayout_17->setObjectName("gridLayout_17");
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        frameDisplayIntersection = new QFrame(widget);
        frameDisplayIntersection->setObjectName("frameDisplayIntersection");
        frameDisplayIntersection->setMinimumSize(QSize(0, 0));
        frameDisplayIntersection->setMaximumSize(QSize(16777215, 332));
        frameDisplayIntersection->setStyleSheet(QString::fromUtf8("QWidget#frameDisplayIntersection{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"border-radius: 5px;\n"
"}"));
        frameDisplayIntersection->setFrameShape(QFrame::StyledPanel);
        frameDisplayIntersection->setFrameShadow(QFrame::Raised);
        gridLayout_20 = new QGridLayout(frameDisplayIntersection);
        gridLayout_20->setObjectName("gridLayout_20");
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        qmlDisplayWidget = new QQuickWidget(frameDisplayIntersection);
        qmlDisplayWidget->setObjectName("qmlDisplayWidget");
        sizePolicy8.setHeightForWidth(qmlDisplayWidget->sizePolicy().hasHeightForWidth());
        qmlDisplayWidget->setSizePolicy(sizePolicy8);
        qmlDisplayWidget->setStyleSheet(QString::fromUtf8("QWidget#qmlDisplayWidget{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"border-radius: 5px;\n"
"}"));
        qmlDisplayWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        gridLayout_20->addWidget(qmlDisplayWidget, 0, 0, 1, 1);


        gridLayout_17->addWidget(frameDisplayIntersection, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_17->addItem(verticalSpacer_4, 3, 0, 1, 1);

        frameRadar = new QFrame(widget);
        frameRadar->setObjectName("frameRadar");
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(frameRadar->sizePolicy().hasHeightForWidth());
        frameRadar->setSizePolicy(sizePolicy9);
        frameRadar->setMinimumSize(QSize(370, 300));
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
        sizePolicy.setHeightForWidth(widgetRadar->sizePolicy().hasHeightForWidth());
        widgetRadar->setSizePolicy(sizePolicy);
        widgetRadar->setMinimumSize(QSize(305, 200));
        widgetRadar->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));

        verticalLayout_2->addWidget(widgetRadar);

        buttonClear = new QPushButton(frameRadar);
        buttonClear->setObjectName("buttonClear");
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(buttonClear->sizePolicy().hasHeightForWidth());
        buttonClear->setSizePolicy(sizePolicy10);
        buttonClear->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        buttonClear->setFlat(false);

        verticalLayout_2->addWidget(buttonClear);


        gridLayout_17->addWidget(frameRadar, 1, 0, 1, 1);

        frameCurrentAction = new QFrame(widget);
        frameCurrentAction->setObjectName("frameCurrentAction");
        frameCurrentAction->setStyleSheet(QString::fromUtf8("QWidget#frameCurrentAction{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameCurrentAction->setFrameShape(QFrame::StyledPanel);
        frameCurrentAction->setFrameShadow(QFrame::Raised);
        gridLayout_21 = new QGridLayout(frameCurrentAction);
        gridLayout_21->setObjectName("gridLayout_21");
        labelCurrentAction = new QLabel(frameCurrentAction);
        labelCurrentAction->setObjectName("labelCurrentAction");
        labelCurrentAction->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_21->addWidget(labelCurrentAction, 0, 0, 1, 1);

        labelCurrentActionState = new QLabel(frameCurrentAction);
        labelCurrentActionState->setObjectName("labelCurrentActionState");
        labelCurrentActionState->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelCurrentActionState->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(labelCurrentActionState, 0, 1, 1, 1);


        gridLayout_17->addWidget(frameCurrentAction, 2, 0, 1, 2);


        gridLayout_10->addWidget(widget, 0, 0, 1, 1);

        stackedWidget->addWidget(Maze);

        gridLayout->addWidget(stackedWidget, 4, 1, 1, 1);

        QForm1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QForm1);
        statusbar->setObjectName("statusbar");
        QForm1->setStatusBar(statusbar);

        retranslateUi(QForm1);

        telemetryTabButton->setDefault(false);
        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(QForm1);
    } // setupUi

    void retranslateUi(QMainWindow *QForm1)
    {
        QForm1->setWindowTitle(QCoreApplication::translate("QForm1", "QTCar v3.0", nullptr));
        labelHour->setText(QCoreApplication::translate("QForm1", "00:00:00", nullptr));
        labelName->setText(QCoreApplication::translate("QForm1", "GS", nullptr));
        homeTabButton->setText(QCoreApplication::translate("QForm1", "Home", nullptr));
        viewTabButton->setText(QCoreApplication::translate("QForm1", "View", nullptr));
        telemetryTabButton->setText(QCoreApplication::translate("QForm1", "Sensors", nullptr));
        PIDTabButton->setText(QCoreApplication::translate("QForm1", "Config", nullptr));
        debugTabButton->setText(QCoreApplication::translate("QForm1", "Debug", nullptr));
        heartbeatLight->setText(QCoreApplication::translate("QForm1", "Alive", nullptr));
        labelCommunication->setText(QCoreApplication::translate("QForm1", "Communication", nullptr));
        comboBoxCommunication->setPlaceholderText(QCoreApplication::translate("QForm1", "USB/UART", nullptr));
        WifiLineEdit->setInputMask(QString());
        WifiLineEdit->setText(QString());
        WifiLineEdit->setPlaceholderText(QCoreApplication::translate("QForm1", "Wifi Port", nullptr));
        OpenPortButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        OpenWifiButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        labelHomeGS->setText(QCoreApplication::translate("QForm1", "GS", nullptr));
        leftEngineLabel->setText(QCoreApplication::translate("QForm1", "Left", nullptr));
        leftEnginePowerLabel->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        rightEngineLabel->setText(QCoreApplication::translate("QForm1", "Right", nullptr));
        powerButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        enginesLabel->setText(QCoreApplication::translate("QForm1", "Engines", nullptr));
        rightEnginePowerLabel->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelMotion->setText(QCoreApplication::translate("QForm1", "Accelerometer", nullptr));
        labelZ_A->setText(QCoreApplication::translate("QForm1", "Z", nullptr));
        labelPosX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelPosZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelX_A->setText(QCoreApplication::translate("QForm1", "X", nullptr));
        labelPosY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelY_A->setText(QCoreApplication::translate("QForm1", "Y", nullptr));
        labelAcceleration->setText(QCoreApplication::translate("QForm1", "Acceleration", nullptr));
        labelSpeedX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelAccX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelPosition->setText(QCoreApplication::translate("QForm1", "Position", nullptr));
        labelSpeed->setText(QCoreApplication::translate("QForm1", "Speed", nullptr));
        labelSpeedZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelAccZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelSpeedY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelAccY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelValueIR8->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR8->setText(QCoreApplication::translate("QForm1", "8", nullptr));
        labelNameIR7->setText(QCoreApplication::translate("QForm1", "7", nullptr));
        labelValueIR7->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR6->setText(QCoreApplication::translate("QForm1", "6", nullptr));
        labelValueIR6->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR5->setText(QCoreApplication::translate("QForm1", "5", nullptr));
        labelValueIR5->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR4->setText(QCoreApplication::translate("QForm1", "4", nullptr));
        labelNameIR3->setText(QCoreApplication::translate("QForm1", "3", nullptr));
        labelValueIR3->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR4->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR1->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR1->setText(QCoreApplication::translate("QForm1", "1", nullptr));
        labelNameIR2->setText(QCoreApplication::translate("QForm1", "2", nullptr));
        labelValueIR2->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelInfrared->setText(QCoreApplication::translate("QForm1", "Infrared", nullptr));
        labelGyroZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        label_3->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        label_4->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroscope->setText(QCoreApplication::translate("QForm1", "Gyroscope", nullptr));
        label_2->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        label_5->setText(QCoreApplication::translate("QForm1", "Angular Speed", nullptr));
        labelX_G->setText(QCoreApplication::translate("QForm1", "X", nullptr));
        labelY_G->setText(QCoreApplication::translate("QForm1", "Y", nullptr));
        labelZ_G->setText(QCoreApplication::translate("QForm1", "Z", nullptr));
        label_6->setText(QCoreApplication::translate("QForm1", "Angular Position", nullptr));
        readTurnPIDButton->setText(QCoreApplication::translate("QForm1", "READ", nullptr));
        labelKD->setText(QCoreApplication::translate("QForm1", "KD", nullptr));
        setTurnPIDButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        labelBaseOut->setText(QCoreApplication::translate("QForm1", "Base Out", nullptr));
        labelMaxOut->setText(QCoreApplication::translate("QForm1", "Max. Out", nullptr));
        labelMinOut->setText(QCoreApplication::translate("QForm1", "Min. Out", nullptr));
        labelKP->setText(QCoreApplication::translate("QForm1", "KP", nullptr));
        labelKI->setText(QCoreApplication::translate("QForm1", "KI", nullptr));
        readWallPIDButton->setText(QCoreApplication::translate("QForm1", "READ", nullptr));
        setWallPIDButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        labelTurnPID->setText(QCoreApplication::translate("QForm1", "Turn PID", nullptr));
        labelWallPID->setText(QCoreApplication::translate("QForm1", "Wall PID", nullptr));
        labelPIDValues->setText(QCoreApplication::translate("QForm1", "PID Values", nullptr));
        labelFirmwareVersion->setText(QCoreApplication::translate("QForm1", "Firmware Version", nullptr));
        labelFirmware->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        labelIMU->setText(QCoreApplication::translate("QForm1", "IMU", nullptr));
        labelIRModel->setText(QCoreApplication::translate("QForm1", "TCRT5000", nullptr));
        labelMCUModel->setText(QCoreApplication::translate("QForm1", "STM32F103C8T6", nullptr));
        labelInfraSensors->setText(QCoreApplication::translate("QForm1", "IR Sensors", nullptr));
        labelMicrocontroller->setText(QCoreApplication::translate("QForm1", "Microcontroller", nullptr));
        labelMPUModel->setText(QCoreApplication::translate("QForm1", "MPU6050", nullptr));
        labelDisplayOLED->setText(QCoreApplication::translate("QForm1", "Display OLED", nullptr));
        labelDriver->setText(QCoreApplication::translate("QForm1", "Motor Driver", nullptr));
        labelDriverModel->setText(QCoreApplication::translate("QForm1", "L9110", nullptr));
        labelDisplayModel->setText(QCoreApplication::translate("QForm1", "SSD1306", nullptr));
        labelResultingFrequency->setText(QCoreApplication::translate("QForm1", "Resulting Frequency", nullptr));
        labelPeriod->setText(QCoreApplication::translate("QForm1", "Period", nullptr));
        pwmConfigButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        labelPrescaler->setText(QCoreApplication::translate("QForm1", "Prescaler", nullptr));
        labelTimerFreqResult->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        changeConfigWidgetButton->setText(QCoreApplication::translate("QForm1", "Timer Configuration", nullptr));
        SendCommandButton->setText(QCoreApplication::translate("QForm1", "SEND", nullptr));
        aliveButton->setText(QCoreApplication::translate("QForm1", "ALIVE", nullptr));
        labelCommand->setText(QCoreApplication::translate("QForm1", "Command", nullptr));
        buttonClear->setText(QCoreApplication::translate("QForm1", "CLEAR", nullptr));
        labelCurrentAction->setText(QCoreApplication::translate("QForm1", "Current Action", nullptr));
        labelCurrentActionState->setText(QCoreApplication::translate("QForm1", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QForm1: public Ui_QForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORM1_H
