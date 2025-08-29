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
    QFrame *navigationBar;
    QVBoxLayout *verticalLayout;
    QLabel *labelName;
    QSpacerItem *verticalSpacer_3;
    QPushButton *homeTabButton;
    QPushButton *telemetryTabButton;
    QPushButton *PIDTabButton;
    QPushButton *debugTabButton;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *heartbeatLight;
    QStackedWidget *stackedWidget;
    QWidget *Home;
    QGridLayout *gridLayout_8;
    QLabel *labelHomeGS;
    QWidget *Telemetry;
    QGridLayout *gridLayout_7;
    QFrame *frameEngines;
    QGridLayout *gridLayout_5;
    QLabel *leftEnginePowerLabel;
    QLabel *rightEngineLabel;
    QDial *rightEngineDial;
    QLabel *rightEnginePowerLabel;
    QLabel *leftEngineLabel;
    QLabel *enginesLabel;
    QDial *leftEngineDial;
    QPushButton *powerButton;
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
    QFrame *frameRadar;
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetRadar;
    QPushButton *buttonClear;
    QStackedWidget *stackedWidget_3;
    QWidget *page_3;
    QGridLayout *gridLayout_18;
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
    QWidget *page_4;
    QGridLayout *gridLayout_19;
    QFrame *frameIntersectionType;
    QGridLayout *gridLayout_15;
    QLabel *labelCurrentActionState;
    QLabel *labelLeftIntersectionState;
    QLabel *labelRightIntersection;
    QLabel *labelFrontIntersectionState;
    QLabel *labelRightIntersectionState;
    QLabel *labelIntersectionType;
    QLabel *label;
    QLabel *labelCurrentAction;
    QLabel *labelLeftIntersection;
    QLabel *labelFrontIntersection;
    QWidget *PID;
    QGridLayout *gridLayout_9;
    QFrame *frameFirmware;
    QGridLayout *gridLayout_14;
    QLabel *labelFirmware;
    QLabel *labelFirmwareVersion;
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
    QFrame *framePID;
    QGridLayout *gridLayout_12;
    QLabel *labelKD;
    QPushButton *setWallPIDButton;
    QLineEdit *lineEditTurnKI;
    QLabel *labelTurnPID;
    QLineEdit *lineEditWallKI;
    QLineEdit *lineEditTurnMax;
    QLabel *labelWallPID;
    QLineEdit *lineEditTurnKP;
    QLabel *labelKI;
    QLineEdit *lineEditTurnMin;
    QLineEdit *lineEditTurnBase;
    QLineEdit *lineEditTurnKD;
    QLineEdit *lineEditWallBase;
    QLineEdit *lineEditWallKD;
    QPushButton *readTurnPIDButton;
    QLineEdit *lineEditWallMin;
    QPushButton *readWallPIDButton;
    QLineEdit *lineEditWallKP;
    QLabel *labelKP;
    QPushButton *setTurnPIDButton;
    QLineEdit *lineEditWallMax;
    QLabel *labelMaxOut;
    QLabel *labelBaseOut;
    QLabel *labelMinOut;
    QLabel *labelPIDValues;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QGridLayout *gridLayout_16;
    QFrame *frameSoftwareConfig;
    QGridLayout *gridLayout_13;
    QLabel *labelPeriod;
    QLineEdit *pwmPrescalerConfig;
    QLabel *labelResultingFrequency;
    QLabel *labelTimerFreqResult;
    QLabel *labelPrescaler;
    QLineEdit *pwmPeriodConfig;
    QPushButton *pwmConfigButton;
    QPushButton *changeConfigWidgetButton;
    QWidget *page_2;
    QGridLayout *gridLayout_17;
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
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(5, -1, 5, -1);
        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer, 2, 2, 1, 1);

        OpenWifiButton = new QPushButton(centralwidget);
        OpenWifiButton->setObjectName("OpenWifiButton");
        sizePolicy.setHeightForWidth(OpenWifiButton->sizePolicy().hasHeightForWidth());
        OpenWifiButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Siemens Sans")});
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        OpenWifiButton->setFont(font);
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
        OpenPortButton->setFont(font);
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
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ethnocentric")});
        font1.setPointSize(25);
        font1.setBold(false);
        font1.setItalic(false);
        labelName->setFont(font1);
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

        telemetryTabButton = new QPushButton(navigationBar);
        telemetryTabButton->setObjectName("telemetryTabButton");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(telemetryTabButton->sizePolicy().hasHeightForWidth());
        telemetryTabButton->setSizePolicy(sizePolicy2);
        telemetryTabButton->setMinimumSize(QSize(80, 80));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Siemens Sans")});
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setItalic(false);
        telemetryTabButton->setFont(font2);
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
        leftEnginePowerLabel = new QLabel(frameEngines);
        leftEnginePowerLabel->setObjectName("leftEnginePowerLabel");
        leftEnginePowerLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        leftEnginePowerLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(leftEnginePowerLabel, 4, 0, 1, 1);

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

        rightEngineDial = new QDial(frameEngines);
        rightEngineDial->setObjectName("rightEngineDial");
        rightEngineDial->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 100, 103);\n"
""));
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

        leftEngineDial = new QDial(frameEngines);
        leftEngineDial->setObjectName("leftEngineDial");
        leftEngineDial->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 100, 103);"));
        leftEngineDial->setMaximum(100);
        leftEngineDial->setInvertedAppearance(false);
        leftEngineDial->setWrapping(false);

        gridLayout_5->addWidget(leftEngineDial, 3, 0, 1, 1);

        powerButton = new QPushButton(frameEngines);
        powerButton->setObjectName("powerButton");
        sizePolicy.setHeightForWidth(powerButton->sizePolicy().hasHeightForWidth());
        powerButton->setSizePolicy(sizePolicy);
        powerButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_5->addWidget(powerButton, 6, 0, 1, 2);


        gridLayout_7->addWidget(frameEngines, 2, 0, 1, 1);

        frameMotion = new QFrame(Telemetry);
        frameMotion->setObjectName("frameMotion");
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frameMotion->sizePolicy().hasHeightForWidth());
        frameMotion->setSizePolicy(sizePolicy4);
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
        gridLayout_4->setContentsMargins(0, 7, 0, 0);
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
"color: rgb(255, 136, 0)\n"
""));
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

        frameRadar = new QFrame(Telemetry);
        frameRadar->setObjectName("frameRadar");
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frameRadar->sizePolicy().hasHeightForWidth());
        frameRadar->setSizePolicy(sizePolicy5);
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
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(widgetRadar->sizePolicy().hasHeightForWidth());
        widgetRadar->setSizePolicy(sizePolicy6);
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

        stackedWidget_3 = new QStackedWidget(Telemetry);
        stackedWidget_3->setObjectName("stackedWidget_3");
        stackedWidget_3->setStyleSheet(QString::fromUtf8("QWidget#stackedWidget_3{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QWidget#stackedWidget_3 > QWidget{\n"
"	background-color: transparent;\n"
"}"));
        stackedWidget_3->setLineWidth(1);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_18 = new QGridLayout(page_3);
        gridLayout_18->setObjectName("gridLayout_18");
        frameInfrared = new QFrame(page_3);
        frameInfrared->setObjectName("frameInfrared");
        sizePolicy.setHeightForWidth(frameInfrared->sizePolicy().hasHeightForWidth());
        frameInfrared->setSizePolicy(sizePolicy);
        frameInfrared->setStyleSheet(QString::fromUtf8("QWidget#frameInfrared{\n"
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


        gridLayout_18->addWidget(frameInfrared, 0, 0, 1, 1);

        stackedWidget_3->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        gridLayout_19 = new QGridLayout(page_4);
        gridLayout_19->setObjectName("gridLayout_19");
        frameIntersectionType = new QFrame(page_4);
        frameIntersectionType->setObjectName("frameIntersectionType");
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(frameIntersectionType->sizePolicy().hasHeightForWidth());
        frameIntersectionType->setSizePolicy(sizePolicy7);
        frameIntersectionType->setStyleSheet(QString::fromUtf8("QWidget#frameIntersectionType{\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameIntersectionType->setFrameShape(QFrame::StyledPanel);
        frameIntersectionType->setFrameShadow(QFrame::Plain);
        gridLayout_15 = new QGridLayout(frameIntersectionType);
        gridLayout_15->setObjectName("gridLayout_15");
        gridLayout_15->setContentsMargins(-1, 0, 9, -1);
        labelCurrentActionState = new QLabel(frameIntersectionType);
        labelCurrentActionState->setObjectName("labelCurrentActionState");
        labelCurrentActionState->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelCurrentActionState->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(labelCurrentActionState, 0, 1, 1, 2);

        labelLeftIntersectionState = new QLabel(frameIntersectionType);
        labelLeftIntersectionState->setObjectName("labelLeftIntersectionState");
        labelLeftIntersectionState->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelLeftIntersectionState->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(labelLeftIntersectionState, 4, 0, 1, 1);

        labelRightIntersection = new QLabel(frameIntersectionType);
        labelRightIntersection->setObjectName("labelRightIntersection");
        labelRightIntersection->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelRightIntersection->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_15->addWidget(labelRightIntersection, 3, 2, 1, 1);

        labelFrontIntersectionState = new QLabel(frameIntersectionType);
        labelFrontIntersectionState->setObjectName("labelFrontIntersectionState");
        labelFrontIntersectionState->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelFrontIntersectionState->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(labelFrontIntersectionState, 3, 1, 1, 1);

        labelRightIntersectionState = new QLabel(frameIntersectionType);
        labelRightIntersectionState->setObjectName("labelRightIntersectionState");
        labelRightIntersectionState->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelRightIntersectionState->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(labelRightIntersectionState, 4, 2, 1, 1);

        labelIntersectionType = new QLabel(frameIntersectionType);
        labelIntersectionType->setObjectName("labelIntersectionType");
        labelIntersectionType->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_15->addWidget(labelIntersectionType, 1, 0, 1, 1);

        label = new QLabel(frameIntersectionType);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label, 4, 1, 1, 1);

        labelCurrentAction = new QLabel(frameIntersectionType);
        labelCurrentAction->setObjectName("labelCurrentAction");
        labelCurrentAction->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelCurrentAction->setMargin(0);

        gridLayout_15->addWidget(labelCurrentAction, 0, 0, 1, 1);

        labelLeftIntersection = new QLabel(frameIntersectionType);
        labelLeftIntersection->setObjectName("labelLeftIntersection");
        labelLeftIntersection->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelLeftIntersection->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_15->addWidget(labelLeftIntersection, 3, 0, 1, 1);

        labelFrontIntersection = new QLabel(frameIntersectionType);
        labelFrontIntersection->setObjectName("labelFrontIntersection");
        labelFrontIntersection->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelFrontIntersection->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_15->addWidget(labelFrontIntersection, 2, 1, 1, 1);


        gridLayout_19->addWidget(frameIntersectionType, 0, 0, 1, 1);

        stackedWidget_3->addWidget(page_4);

        gridLayout_7->addWidget(stackedWidget_3, 2, 1, 1, 2);

        stackedWidget->addWidget(Telemetry);
        PID = new QWidget();
        PID->setObjectName("PID");
        gridLayout_9 = new QGridLayout(PID);
        gridLayout_9->setObjectName("gridLayout_9");
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
        labelFirmware = new QLabel(frameFirmware);
        labelFirmware->setObjectName("labelFirmware");
        labelFirmware->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelFirmware->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(labelFirmware, 1, 0, 1, 1);

        labelFirmwareVersion = new QLabel(frameFirmware);
        labelFirmwareVersion->setObjectName("labelFirmwareVersion");
        labelFirmwareVersion->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_14->addWidget(labelFirmwareVersion, 0, 0, 1, 1);


        gridLayout_9->addWidget(frameFirmware, 3, 1, 1, 1);

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


        gridLayout_9->addWidget(frameHardware, 4, 1, 2, 1);

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
        labelKD = new QLabel(framePID);
        labelKD->setObjectName("labelKD");
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(labelKD->sizePolicy().hasHeightForWidth());
        labelKD->setSizePolicy(sizePolicy8);
        labelKD->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKD->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKD, 1, 3, 1, 1);

        setWallPIDButton = new QPushButton(framePID);
        setWallPIDButton->setObjectName("setWallPIDButton");
        setWallPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(setWallPIDButton, 7, 8, 1, 1);

        lineEditTurnKI = new QLineEdit(framePID);
        lineEditTurnKI->setObjectName("lineEditTurnKI");
        lineEditTurnKI->setMinimumSize(QSize(79, 0));
        lineEditTurnKI->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKI, 3, 2, 1, 1);

        labelTurnPID = new QLabel(framePID);
        labelTurnPID->setObjectName("labelTurnPID");
        labelTurnPID->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelTurnPID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(labelTurnPID, 3, 0, 1, 1);

        lineEditWallKI = new QLineEdit(framePID);
        lineEditWallKI->setObjectName("lineEditWallKI");
        lineEditWallKI->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallKI, 7, 2, 1, 1);

        lineEditTurnMax = new QLineEdit(framePID);
        lineEditTurnMax->setObjectName("lineEditTurnMax");
        lineEditTurnMax->setMinimumSize(QSize(79, 0));
        lineEditTurnMax->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnMax->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnMax, 3, 5, 1, 1);

        labelWallPID = new QLabel(framePID);
        labelWallPID->setObjectName("labelWallPID");
        labelWallPID->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelWallPID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(labelWallPID, 7, 0, 1, 1);

        lineEditTurnKP = new QLineEdit(framePID);
        lineEditTurnKP->setObjectName("lineEditTurnKP");
        lineEditTurnKP->setMinimumSize(QSize(79, 0));
        lineEditTurnKP->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKP, 3, 1, 1, 1);

        labelKI = new QLabel(framePID);
        labelKI->setObjectName("labelKI");
        sizePolicy8.setHeightForWidth(labelKI->sizePolicy().hasHeightForWidth());
        labelKI->setSizePolicy(sizePolicy8);
        labelKI->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKI, 1, 2, 1, 1);

        lineEditTurnMin = new QLineEdit(framePID);
        lineEditTurnMin->setObjectName("lineEditTurnMin");
        lineEditTurnMin->setMinimumSize(QSize(79, 0));
        lineEditTurnMin->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnMin->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnMin, 3, 4, 1, 1);

        lineEditTurnBase = new QLineEdit(framePID);
        lineEditTurnBase->setObjectName("lineEditTurnBase");
        lineEditTurnBase->setMinimumSize(QSize(79, 0));
        lineEditTurnBase->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnBase->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnBase, 3, 6, 1, 1);

        lineEditTurnKD = new QLineEdit(framePID);
        lineEditTurnKD->setObjectName("lineEditTurnKD");
        lineEditTurnKD->setMinimumSize(QSize(79, 0));
        lineEditTurnKD->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKD->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKD, 3, 3, 1, 1);

        lineEditWallBase = new QLineEdit(framePID);
        lineEditWallBase->setObjectName("lineEditWallBase");
        lineEditWallBase->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallBase->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallBase, 7, 6, 1, 1);

        lineEditWallKD = new QLineEdit(framePID);
        lineEditWallKD->setObjectName("lineEditWallKD");
        lineEditWallKD->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKD->setFrame(true);
        lineEditWallKD->setAlignment(Qt::AlignCenter);
        lineEditWallKD->setClearButtonEnabled(false);

        gridLayout_12->addWidget(lineEditWallKD, 7, 3, 1, 1);

        readTurnPIDButton = new QPushButton(framePID);
        readTurnPIDButton->setObjectName("readTurnPIDButton");
        readTurnPIDButton->setMinimumSize(QSize(79, 0));
        readTurnPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(readTurnPIDButton, 3, 7, 1, 1);

        lineEditWallMin = new QLineEdit(framePID);
        lineEditWallMin->setObjectName("lineEditWallMin");
        lineEditWallMin->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallMin->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallMin, 7, 4, 1, 1);

        readWallPIDButton = new QPushButton(framePID);
        readWallPIDButton->setObjectName("readWallPIDButton");
        readWallPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(readWallPIDButton, 7, 7, 1, 1);

        lineEditWallKP = new QLineEdit(framePID);
        lineEditWallKP->setObjectName("lineEditWallKP");
        lineEditWallKP->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallKP, 7, 1, 1, 1);

        labelKP = new QLabel(framePID);
        labelKP->setObjectName("labelKP");
        sizePolicy8.setHeightForWidth(labelKP->sizePolicy().hasHeightForWidth());
        labelKP->setSizePolicy(sizePolicy8);
        labelKP->setLayoutDirection(Qt::LeftToRight);
        labelKP->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKP, 1, 1, 1, 1);

        setTurnPIDButton = new QPushButton(framePID);
        setTurnPIDButton->setObjectName("setTurnPIDButton");
        setTurnPIDButton->setMinimumSize(QSize(79, 0));
        setTurnPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(setTurnPIDButton, 3, 8, 1, 1);

        lineEditWallMax = new QLineEdit(framePID);
        lineEditWallMax->setObjectName("lineEditWallMax");
        lineEditWallMax->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallMax->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallMax, 7, 5, 1, 1);

        labelMaxOut = new QLabel(framePID);
        labelMaxOut->setObjectName("labelMaxOut");
        labelMaxOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelMaxOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelMaxOut, 1, 5, 1, 1);

        labelBaseOut = new QLabel(framePID);
        labelBaseOut->setObjectName("labelBaseOut");
        labelBaseOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelBaseOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelBaseOut, 1, 6, 1, 1);

        labelMinOut = new QLabel(framePID);
        labelMinOut->setObjectName("labelMinOut");
        labelMinOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelMinOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelMinOut, 1, 4, 1, 1);

        labelPIDValues = new QLabel(framePID);
        labelPIDValues->setObjectName("labelPIDValues");
        sizePolicy8.setHeightForWidth(labelPIDValues->sizePolicy().hasHeightForWidth());
        labelPIDValues->setSizePolicy(sizePolicy8);
        labelPIDValues->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_12->addWidget(labelPIDValues, 0, 0, 1, 9);


        gridLayout_9->addWidget(framePID, 1, 0, 2, 2);

        stackedWidget_2 = new QStackedWidget(PID);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setStyleSheet(QString::fromUtf8("QWidget#stackedWidget_2{ \n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}	\n"
"\n"
"QWidget#stackedWidget_2 > QWidget {\n"
"	background-color: transparent;\n"
"}"));
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_16 = new QGridLayout(page);
        gridLayout_16->setObjectName("gridLayout_16");
        frameSoftwareConfig = new QFrame(page);
        frameSoftwareConfig->setObjectName("frameSoftwareConfig");
        frameSoftwareConfig->setMinimumSize(QSize(0, 130));
        frameSoftwareConfig->setStyleSheet(QString::fromUtf8("QWidget#frameSoftwareConfig{ \n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameSoftwareConfig->setFrameShape(QFrame::StyledPanel);
        frameSoftwareConfig->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frameSoftwareConfig);
        gridLayout_13->setObjectName("gridLayout_13");
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

        pwmPrescalerConfig = new QLineEdit(frameSoftwareConfig);
        pwmPrescalerConfig->setObjectName("pwmPrescalerConfig");
        pwmPrescalerConfig->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_13->addWidget(pwmPrescalerConfig, 1, 1, 1, 1);

        labelResultingFrequency = new QLabel(frameSoftwareConfig);
        labelResultingFrequency->setObjectName("labelResultingFrequency");
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(labelResultingFrequency->sizePolicy().hasHeightForWidth());
        labelResultingFrequency->setSizePolicy(sizePolicy9);
        labelResultingFrequency->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_13->addWidget(labelResultingFrequency, 5, 0, 1, 2);

        labelTimerFreqResult = new QLabel(frameSoftwareConfig);
        labelTimerFreqResult->setObjectName("labelTimerFreqResult");
        sizePolicy9.setHeightForWidth(labelTimerFreqResult->sizePolicy().hasHeightForWidth());
        labelTimerFreqResult->setSizePolicy(sizePolicy9);
        labelTimerFreqResult->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelTimerFreqResult->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(labelTimerFreqResult, 6, 0, 1, 2);

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
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(pwmPeriodConfig->sizePolicy().hasHeightForWidth());
        pwmPeriodConfig->setSizePolicy(sizePolicy10);
        pwmPeriodConfig->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_13->addWidget(pwmPeriodConfig, 3, 1, 1, 1);

        pwmConfigButton = new QPushButton(frameSoftwareConfig);
        pwmConfigButton->setObjectName("pwmConfigButton");
        QSizePolicy sizePolicy11(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(pwmConfigButton->sizePolicy().hasHeightForWidth());
        pwmConfigButton->setSizePolicy(sizePolicy11);
        pwmConfigButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_13->addWidget(pwmConfigButton, 4, 1, 1, 1);

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


        gridLayout_16->addWidget(frameSoftwareConfig, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_17 = new QGridLayout(page_2);
        gridLayout_17->setObjectName("gridLayout_17");
        stackedWidget_2->addWidget(page_2);

        gridLayout_9->addWidget(stackedWidget_2, 3, 0, 3, 1);

        stackedWidget->addWidget(PID);
        Communication = new QWidget();
        Communication->setObjectName("Communication");
        gridLayout_3 = new QGridLayout(Communication);
        gridLayout_3->setObjectName("gridLayout_3");
        plainTextEdit = new QPlainTextEdit(Communication);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy12(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy12);
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
        stackedWidget_3->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QForm1);
    } // setupUi

    void retranslateUi(QMainWindow *QForm1)
    {
        QForm1->setWindowTitle(QCoreApplication::translate("QForm1", "QTCar v3.0", nullptr));
        OpenWifiButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        OpenPortButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        WifiLineEdit->setInputMask(QString());
        WifiLineEdit->setText(QString());
        WifiLineEdit->setPlaceholderText(QCoreApplication::translate("QForm1", "Wifi Port", nullptr));
        comboBoxCommunication->setPlaceholderText(QCoreApplication::translate("QForm1", "USB/UART", nullptr));
        labelHour->setText(QCoreApplication::translate("QForm1", "00:00:00", nullptr));
        labelCommunication->setText(QCoreApplication::translate("QForm1", "Communication", nullptr));
        labelName->setText(QCoreApplication::translate("QForm1", "GS", nullptr));
        homeTabButton->setText(QCoreApplication::translate("QForm1", "Home", nullptr));
        telemetryTabButton->setText(QCoreApplication::translate("QForm1", "Telemetry", nullptr));
        PIDTabButton->setText(QCoreApplication::translate("QForm1", "Config", nullptr));
        debugTabButton->setText(QCoreApplication::translate("QForm1", "Debug", nullptr));
        heartbeatLight->setText(QCoreApplication::translate("QForm1", "Alive", nullptr));
        labelHomeGS->setText(QCoreApplication::translate("QForm1", "GS", nullptr));
        leftEnginePowerLabel->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        rightEngineLabel->setText(QCoreApplication::translate("QForm1", "Right", nullptr));
        rightEnginePowerLabel->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        leftEngineLabel->setText(QCoreApplication::translate("QForm1", "Left", nullptr));
        enginesLabel->setText(QCoreApplication::translate("QForm1", "Engines", nullptr));
        powerButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
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
        buttonClear->setText(QCoreApplication::translate("QForm1", "CLEAR", nullptr));
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
        labelCurrentActionState->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        labelLeftIntersectionState->setText(QCoreApplication::translate("QForm1", "NN", nullptr));
        labelRightIntersection->setText(QCoreApplication::translate("QForm1", "Right", nullptr));
        labelFrontIntersectionState->setText(QCoreApplication::translate("QForm1", "NN", nullptr));
        labelRightIntersectionState->setText(QCoreApplication::translate("QForm1", "NN", nullptr));
        labelIntersectionType->setText(QCoreApplication::translate("QForm1", "Intersection Type", nullptr));
        label->setText(QCoreApplication::translate("QForm1", "CAR", nullptr));
        labelCurrentAction->setText(QCoreApplication::translate("QForm1", "Current Action", nullptr));
        labelLeftIntersection->setText(QCoreApplication::translate("QForm1", "Left", nullptr));
        labelFrontIntersection->setText(QCoreApplication::translate("QForm1", "Front", nullptr));
        labelFirmware->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        labelFirmwareVersion->setText(QCoreApplication::translate("QForm1", "Firmware Version", nullptr));
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
        labelKD->setText(QCoreApplication::translate("QForm1", "KD", nullptr));
        setWallPIDButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        labelTurnPID->setText(QCoreApplication::translate("QForm1", "Turn PID", nullptr));
        labelWallPID->setText(QCoreApplication::translate("QForm1", "Wall PID", nullptr));
        labelKI->setText(QCoreApplication::translate("QForm1", "KI", nullptr));
        readTurnPIDButton->setText(QCoreApplication::translate("QForm1", "READ", nullptr));
        readWallPIDButton->setText(QCoreApplication::translate("QForm1", "READ", nullptr));
        labelKP->setText(QCoreApplication::translate("QForm1", "KP", nullptr));
        setTurnPIDButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        labelMaxOut->setText(QCoreApplication::translate("QForm1", "Max. Out", nullptr));
        labelBaseOut->setText(QCoreApplication::translate("QForm1", "Base Out", nullptr));
        labelMinOut->setText(QCoreApplication::translate("QForm1", "Min. Out", nullptr));
        labelPIDValues->setText(QCoreApplication::translate("QForm1", "PID Values", nullptr));
        labelPeriod->setText(QCoreApplication::translate("QForm1", "Period", nullptr));
        labelResultingFrequency->setText(QCoreApplication::translate("QForm1", "Resulting Frequency", nullptr));
        labelTimerFreqResult->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        labelPrescaler->setText(QCoreApplication::translate("QForm1", "Prescaler", nullptr));
        pwmConfigButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        changeConfigWidgetButton->setText(QCoreApplication::translate("QForm1", "Timer Configuration", nullptr));
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
