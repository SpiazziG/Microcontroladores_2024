/********************************************************************************
** Form generated from reading UI file 'qform1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFORM1_H
#define UI_QFORM1_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QForm1
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *line;
    QFrame *frameHourAndPathfinder;
    QGridLayout *gridLayout_24;
    QLabel *labelPathfinderTop;
    QLabel *labelHour;
    QLabel *labelVoid;
    QGridLayout *gridLayout_2;
    QPushButton *OpenPortButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBoxCommunication;
    QPushButton *OpenWifiButton;
    QLineEdit *WifiLineEdit;
    QSpacerItem *verticalSpacer;
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
    QStackedWidget *stackedWidget;
    QWidget *Home;
    QGridLayout *gridLayout_8;
    QLabel *labelHomeGS;
    QLabel *label;
    QQuickWidget *viewer3D;
    QWidget *Telemetry;
    QGridLayout *gridLayout_7;
    QFrame *frameAccelerometer;
    QGridLayout *gridLayout_4;
    QLabel *labelSpeedZ;
    QLabel *labelZ_A;
    QLabel *labelPosY;
    QCheckBox *checkBoxAccelerometer;
    QLabel *labelPosition;
    QLabel *labelAccX;
    QLabel *labelAccZ;
    QLabel *labelAccY;
    QLabel *labelSpeed;
    QLabel *labelX_A;
    QLabel *labelSpeedY;
    QLabel *labelPosZ;
    QLabel *labelY_A;
    QLabel *labelPosX;
    QLabel *labelAcceleration;
    QLabel *labelSpeedX;
    QLabel *labelMotion;
    QFrame *frameGyroscope;
    QGridLayout *gridLayout_22;
    QLabel *labelY_G;
    QLabel *labelAngularPosition;
    QLabel *labelGyroY;
    QLabel *labelPitch;
    QLabel *labelGyroX;
    QLabel *labelGyroZ;
    QLabel *labelGyroscope;
    QLabel *labelYaw;
    QCheckBox *checkBoxGyro;
    QLabel *labelX_G;
    QLabel *labelRoll;
    QLabel *labelZ_G;
    QLabel *labelAngularSpeed;
    QFrame *frameEngines;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBoxEngines;
    QLabel *leftEngineLabel;
    QDial *rightEngineDial;
    QPushButton *powerButton;
    QDial *leftEngineDial;
    QLabel *leftEnginePowerLabel;
    QLabel *rightEnginePowerLabel;
    QLabel *rightEngineLabel;
    QLabel *enginesLabel;
    QFrame *frameInfrared;
    QGridLayout *gridLayout_6;
    QLabel *labelNameIR5;
    QLabel *labelValueIR3;
    QLabel *labelNameIR2;
    QLabel *labelValueIR2;
    QLabel *labelValueIR7;
    QLabel *labelNameIR8;
    QLabel *labelNameIR1;
    QLabel *labelNameIR7;
    QLabel *labelValueIR6;
    QLabel *labelValueIR4;
    QLabel *labelValueIR1;
    QLabel *labelNameIR6;
    QLabel *labelValueIR5;
    QLabel *labelNameIR4;
    QLabel *labelNameIR3;
    QLabel *labelValueIR8;
    QCheckBox *checkBoxIR;
    QPushButton *buttonInfrared;
    QWidget *PID;
    QGridLayout *gridLayout_9;
    QFrame *frameThresholds;
    QGridLayout *gridLayout_18;
    QLabel *labelDiagonalThreshold;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox;
    QLabel *labelFrontThreshold;
    QLabel *labelLeftThreshold;
    QSpinBox *spinBox_4;
    QLabel *labelLateralThreshold;
    QLabel *labelRightThreshold;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_6;
    QPushButton *readThresholdButton;
    QPushButton *setThresholdButton;
    QPushButton *changeThresholdUnitButton;
    QLabel *labelThresholds;
    QFrame *frameSoftwareConfig;
    QGridLayout *gridLayout_13;
    QLineEdit *pwmPrescalerConfig;
    QLabel *labelPrescaler;
    QLabel *labelPeriod;
    QLineEdit *pwmPeriodConfig;
    QLabel *labelResultingFrequency;
    QLabel *labelTimerFreqResult;
    QPushButton *pwmConfigButton;
    QPushButton *changeConfigWidgetButton;
    QFrame *frameBatteryLevel;
    QGridLayout *gridLayout_16;
    QDoubleSpinBox *batteryVoltageSpinBox;
    QPushButton *setBatteryVoltageButton;
    QLabel *label_2;
    QFrame *framePID;
    QGridLayout *gridLayout_12;
    QLabel *labelWallPID;
    QLabel *labelPIDValues;
    QLineEdit *lineEditWallMin;
    QLineEdit *lineEditTurnMin;
    QLineEdit *lineEditWallKI;
    QLabel *labelKD;
    QLineEdit *lineEditWallKP;
    QLabel *labelKP;
    QLineEdit *lineEditWallBase;
    QLabel *labelMaxOut;
    QLabel *labelBaseOut;
    QLabel *labelKI;
    QPushButton *readStopPIDButton;
    QPushButton *readTurnPIDButton;
    QLabel *labelMinOut;
    QPushButton *readWallPIDButton;
    QLineEdit *lineEditTurnKI;
    QLineEdit *lineEditWallMax;
    QLineEdit *lineEditTurnMax;
    QLineEdit *lineEditWallKD;
    QPushButton *setWallPIDButton;
    QPushButton *setTurnPIDButton;
    QLineEdit *lineEditTurnKP;
    QLineEdit *lineEditTurnBase;
    QLineEdit *lineEditTurnKD;
    QLabel *labelTurnPID;
    QPushButton *setStopPIDButton;
    QLineEdit *lineEditStopBase;
    QLineEdit *lineEditStopMax;
    QLineEdit *lineEditStopMin;
    QLineEdit *lineEditStopKD;
    QLineEdit *lineEditStopKI;
    QLineEdit *lineEditStopKP;
    QLabel *labelStopPID;
    QFrame *frameFirmware;
    QGridLayout *gridLayout_14;
    QLabel *labelFirmware;
    QLabel *labelSoftwareVersion;
    QLabel *labelFirmwareVersion;
    QLabel *labelSoftware;
    QWidget *Communication;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *plainTextEdit;
    QPushButton *SendCommandButton;
    QPushButton *aliveButton;
    QComboBox *comboBoxSendCommand;
    QLabel *labelCommand;
    QWidget *Maze;
    QGridLayout *gridLayout_10;
    QFrame *frameMazeViews;
    QGridLayout *gridLayout_29;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QGridLayout *gridLayout_28;
    QFrame *frameDisplayIntersection;
    QGridLayout *gridLayout_20;
    QQuickWidget *qmlDisplayWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_27;
    QFrame *frameRadar;
    QGridLayout *gridLayout_15;
    QWidget *widgetRadar;
    QWidget *widget;
    QGridLayout *gridLayout_17;
    QWidget *page;
    QFrame *frameTarget;
    QGridLayout *gridLayout_19;
    QTabWidget *tabWidget;
    QWidget *StartTab;
    QGridLayout *gridLayout_26;
    QSpinBox *spinBoxStartY;
    QLabel *labelStartDir;
    QSpinBox *spinBoxStartX;
    QLabel *labelMazeStart;
    QComboBox *comboBoxStartDir;
    QLabel *labelStartY;
    QLabel *labelStartX;
    QPushButton *buttonSetStart;
    QWidget *TargetTab;
    QGridLayout *gridLayout_25;
    QLabel *labelMazeTarget;
    QSpinBox *spinBoxTargetX;
    QSpinBox *spinBoxTargetY;
    QLabel *labelTargetX;
    QLabel *labelTargetY;
    QPushButton *buttonSetTargetXY;
    QFrame *frameCurrentAction;
    QGridLayout *gridLayout_21;
    QLabel *labelRunTime;
    QLabel *labelCurrentActionState;
    QLabel *labelCurrentDirection;
    QLabel *labelCurrentDirectionValue;
    QLabel *labelCurrentAction;
    QLabel *labelRunTimeValue;
    QFrame *frameControl;
    QGridLayout *gridLayout_23;
    QPushButton *buttonStartExploration;
    QPushButton *buttonStopRobot;
    QPushButton *buttonStartRun;
    QLabel *labelRobotControl;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QForm1)
    {
        if (QForm1->objectName().isEmpty())
            QForm1->setObjectName("QForm1");
        QForm1->resize(1000, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QForm1->sizePolicy().hasHeightForWidth());
        QForm1->setSizePolicy(sizePolicy);
        QForm1->setMinimumSize(QSize(750, 600));
        QForm1->setMaximumSize(QSize(16777215, 16777215));
        QForm1->setCursor(QCursor(Qt::ArrowCursor));
        QForm1->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 229);\n"
"background-color: rgb(33, 37, 40);"));
        centralwidget = new QWidget(QForm1);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 49, 55);\n"
"border: 0px;\n"
"color: rgb(46, 49, 55);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 1, 1, 1);

        frameHourAndPathfinder = new QFrame(centralwidget);
        frameHourAndPathfinder->setObjectName("frameHourAndPathfinder");
        frameHourAndPathfinder->setStyleSheet(QString::fromUtf8("color: rgb(227, 227, 229);\n"
"background-color: rgb(57, 63, 68);"));
        frameHourAndPathfinder->setFrameShape(QFrame::NoFrame);
        frameHourAndPathfinder->setFrameShadow(QFrame::Plain);
        frameHourAndPathfinder->setLineWidth(0);
        gridLayout_24 = new QGridLayout(frameHourAndPathfinder);
        gridLayout_24->setSpacing(0);
        gridLayout_24->setObjectName("gridLayout_24");
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        labelPathfinderTop = new QLabel(frameHourAndPathfinder);
        labelPathfinderTop->setObjectName("labelPathfinderTop");
        sizePolicy.setHeightForWidth(labelPathfinderTop->sizePolicy().hasHeightForWidth());
        labelPathfinderTop->setSizePolicy(sizePolicy);
        labelPathfinderTop->setMinimumSize(QSize(0, 20));
        labelPathfinderTop->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Montserrat Alternates\";\n"
"color: rgb(96, 100, 103);\n"
"background-color: rgb(57, 63, 68);"));
        labelPathfinderTop->setLineWidth(0);
        labelPathfinderTop->setAlignment(Qt::AlignCenter);

        gridLayout_24->addWidget(labelPathfinderTop, 1, 1, 1, 1);

        labelHour = new QLabel(frameHourAndPathfinder);
        labelHour->setObjectName("labelHour");
        sizePolicy.setHeightForWidth(labelHour->sizePolicy().hasHeightForWidth());
        labelHour->setSizePolicy(sizePolicy);
        labelHour->setMinimumSize(QSize(0, 20));
        labelHour->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Siemens Sans\";\n"
"font: 700 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(227, 227, 229);\n"
"background-color: rgb(57, 63, 68);\n"
"margin-right: 1px;\n"
""));
        labelHour->setFrameShadow(QFrame::Plain);
        labelHour->setLineWidth(0);
        labelHour->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelHour->setMargin(0);
        labelHour->setIndent(-1);

        gridLayout_24->addWidget(labelHour, 1, 2, 1, 1);

        labelVoid = new QLabel(frameHourAndPathfinder);
        labelVoid->setObjectName("labelVoid");
        labelVoid->setLineWidth(0);

        gridLayout_24->addWidget(labelVoid, 1, 0, 1, 1);


        gridLayout->addWidget(frameHourAndPathfinder, 1, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(5, -1, 5, -1);
        OpenPortButton = new QPushButton(centralwidget);
        OpenPortButton->setObjectName("OpenPortButton");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(OpenPortButton->sizePolicy().hasHeightForWidth());
        OpenPortButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        OpenPortButton->setFont(font);
        OpenPortButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(222, 223, 225);"));
        OpenPortButton->setFlat(false);

        gridLayout_2->addWidget(OpenPortButton, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 1, 1, 1);

        comboBoxCommunication = new QComboBox(centralwidget);
        comboBoxCommunication->setObjectName("comboBoxCommunication");
        sizePolicy1.setHeightForWidth(comboBoxCommunication->sizePolicy().hasHeightForWidth());
        comboBoxCommunication->setSizePolicy(sizePolicy1);
        comboBoxCommunication->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        comboBoxCommunication->setFrame(true);

        gridLayout_2->addWidget(comboBoxCommunication, 1, 0, 1, 1);

        OpenWifiButton = new QPushButton(centralwidget);
        OpenWifiButton->setObjectName("OpenWifiButton");
        sizePolicy1.setHeightForWidth(OpenWifiButton->sizePolicy().hasHeightForWidth());
        OpenWifiButton->setSizePolicy(sizePolicy1);
        OpenWifiButton->setFont(font);
        OpenWifiButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(222, 223, 225);"));
        OpenWifiButton->setFlat(false);

        gridLayout_2->addWidget(OpenWifiButton, 4, 2, 1, 1);

        WifiLineEdit = new QLineEdit(centralwidget);
        WifiLineEdit->setObjectName("WifiLineEdit");
        sizePolicy1.setHeightForWidth(WifiLineEdit->sizePolicy().hasHeightForWidth());
        WifiLineEdit->setSizePolicy(sizePolicy1);
        WifiLineEdit->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        WifiLineEdit->setMaxLength(32767);

        gridLayout_2->addWidget(WifiLineEdit, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer, 3, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 1, 1, 1);

        navigationBar = new QFrame(centralwidget);
        navigationBar->setObjectName("navigationBar");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(navigationBar->sizePolicy().hasHeightForWidth());
        navigationBar->setSizePolicy(sizePolicy2);
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

        verticalSpacer_3 = new QSpacerItem(20, 89, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        homeTabButton = new QPushButton(navigationBar);
        homeTabButton->setObjectName("homeTabButton");
        homeTabButton->setMinimumSize(QSize(80, 80));
        homeTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"font: 700 13pt \"Century Gothic\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));

        verticalLayout->addWidget(homeTabButton);

        viewTabButton = new QPushButton(navigationBar);
        viewTabButton->setObjectName("viewTabButton");
        viewTabButton->setMinimumSize(QSize(80, 80));
        viewTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"font: 700 13pt \"Century Gothic\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));

        verticalLayout->addWidget(viewTabButton);

        telemetryTabButton = new QPushButton(navigationBar);
        telemetryTabButton->setObjectName("telemetryTabButton");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(telemetryTabButton->sizePolicy().hasHeightForWidth());
        telemetryTabButton->setSizePolicy(sizePolicy3);
        telemetryTabButton->setMinimumSize(QSize(80, 80));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Century Gothic")});
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setItalic(false);
        telemetryTabButton->setFont(font2);
        telemetryTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"font: 700 13pt \"Century Gothic\";\n"
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
"font: 700 13pt \"Century Gothic\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));

        verticalLayout->addWidget(PIDTabButton);

        debugTabButton = new QPushButton(navigationBar);
        debugTabButton->setObjectName("debugTabButton");
        sizePolicy3.setHeightForWidth(debugTabButton->sizePolicy().hasHeightForWidth());
        debugTabButton->setSizePolicy(sizePolicy3);
        debugTabButton->setMinimumSize(QSize(80, 80));
        debugTabButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Siemens Sans\";\n"
"font: 700 13pt \"Century Gothic\";\n"
"background-color: rgb(46, 49, 55);\n"
"color: rgb(222, 223, 225);\n"
"border: 0px;"));
        debugTabButton->setFlat(true);

        verticalLayout->addWidget(debugTabButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        heartbeatLight = new QRadioButton(navigationBar);
        heartbeatLight->setObjectName("heartbeatLight");
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(heartbeatLight->sizePolicy().hasHeightForWidth());
        heartbeatLight->setSizePolicy(sizePolicy4);
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
"	font: 700 12pt \"Century Gothic\";\n"
"	font-weight: bold;\n"
"	color: rgb(227, 227, 229);\n"
"	background: transparent;\n"
"}"));
        heartbeatLight->setCheckable(true);

        verticalLayout->addWidget(heartbeatLight);


        gridLayout->addWidget(navigationBar, 0, 0, 8, 1);

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
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(227, 227, 229);\n"
"background-color: rgb(57, 63, 68);"));
        labelCommunication->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelCommunication);


        gridLayout->addWidget(frameCommunication, 3, 1, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("QWidget#stackedWidget{\n"
"border: 0px solid rgb(150, 150, 150);\n"
"}"));
        Home = new QWidget();
        Home->setObjectName("Home");
        gridLayout_8 = new QGridLayout(Home);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setContentsMargins(6, 0, 6, 0);
        labelHomeGS = new QLabel(Home);
        labelHomeGS->setObjectName("labelHomeGS");
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(labelHomeGS->sizePolicy().hasHeightForWidth());
        labelHomeGS->setSizePolicy(sizePolicy5);
        labelHomeGS->setStyleSheet(QString::fromUtf8("font: 50pt \"Ethnocentric\";\n"
"color: rgb(96, 100, 103);"));
        labelHomeGS->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(labelHomeGS, 3, 0, 1, 1);

        label = new QLabel(Home);
        label->setObjectName("label");
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);
        label->setStyleSheet(QString::fromUtf8("font: 700 30pt \"Montserrat Alternates\";\n"
"color: rgb(96, 100, 103);"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_8->addWidget(label, 5, 0, 1, 1);

        viewer3D = new QQuickWidget(Home);
        viewer3D->setObjectName("viewer3D");
        sizePolicy.setHeightForWidth(viewer3D->sizePolicy().hasHeightForWidth());
        viewer3D->setSizePolicy(sizePolicy);
        viewer3D->setStyleSheet(QString::fromUtf8(""));
        viewer3D->setResizeMode(QQuickWidget::SizeRootObjectToView);

        gridLayout_8->addWidget(viewer3D, 0, 0, 1, 1);

        stackedWidget->addWidget(Home);
        Telemetry = new QWidget();
        Telemetry->setObjectName("Telemetry");
        gridLayout_7 = new QGridLayout(Telemetry);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(6, 0, 6, 0);
        frameAccelerometer = new QFrame(Telemetry);
        frameAccelerometer->setObjectName("frameAccelerometer");
        sizePolicy1.setHeightForWidth(frameAccelerometer->sizePolicy().hasHeightForWidth());
        frameAccelerometer->setSizePolicy(sizePolicy1);
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
        gridLayout_4->setContentsMargins(0, 3, 0, 0);
        labelSpeedZ = new QLabel(frameAccelerometer);
        labelSpeedZ->setObjectName("labelSpeedZ");
        labelSpeedZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"color: rgb(124, 252, 0);\n"
""));
        labelSpeedZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedZ, 5, 2, 1, 1);

        labelZ_A = new QLabel(frameAccelerometer);
        labelZ_A->setObjectName("labelZ_A");
        labelZ_A->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelZ_A->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelZ_A, 12, 2, 1, 1);

        labelPosY = new QLabel(frameAccelerometer);
        labelPosY->setObjectName("labelPosY");
        labelPosY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 165, 0);"));
        labelPosY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosY, 7, 1, 1, 1);

        checkBoxAccelerometer = new QCheckBox(frameAccelerometer);
        checkBoxAccelerometer->setObjectName("checkBoxAccelerometer");
        checkBoxAccelerometer->setLayoutDirection(Qt::RightToLeft);
        checkBoxAccelerometer->setStyleSheet(QString::fromUtf8("/* 1. El texto y el margen que ya ten\303\255as */\n"
"QCheckBox {\n"
"    font: 13pt \"Century Gothic\";\n"
"    font-weight: bold;\n"
"    color: rgb(222, 223, 225);\n"
"    background-color: transparent;\n"
"    margin-right: 8px;\n"
"}\n"
"\n"
"/* 2. El recuadro vac\303\255o (apagado) */\n"
"QCheckBox::indicator {\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border: 2px solid #393F44; /* El gris de tus bordes */\n"
"    border-radius: 3px;\n"
"    background-color: #22262a; /* El color de tu powerBar */\n"
"}\n"
"\n"
"/* 3. El recuadro cuando pasas el mouse por encima (hover) */\n"
"QCheckBox::indicator:hover {\n"
"    border: 2px solid #00FA9A; /* Se ilumina en verde menta */\n"
"}\n"
"\n"
"/* 4. El recuadro cuando est\303\241 activado (tildado) */\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #00FA9A; /* Se llena de verde menta */\n"
"    border: 2px solid #00FA9A;\n"
"}"));

        gridLayout_4->addWidget(checkBoxAccelerometer, 0, 2, 1, 1);

        labelPosition = new QLabel(frameAccelerometer);
        labelPosition->setObjectName("labelPosition");
        sizePolicy1.setHeightForWidth(labelPosition->sizePolicy().hasHeightForWidth());
        labelPosition->setSizePolicy(sizePolicy1);
        labelPosition->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);\n"
"color: rgb(255, 165, 0);"));
        labelPosition->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosition, 6, 0, 1, 3);

        labelAccX = new QLabel(frameAccelerometer);
        labelAccX->setObjectName("labelAccX");
        labelAccX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccX, 3, 0, 1, 1);

        labelAccZ = new QLabel(frameAccelerometer);
        labelAccZ->setObjectName("labelAccZ");
        labelAccZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccZ, 3, 2, 1, 1);

        labelAccY = new QLabel(frameAccelerometer);
        labelAccY->setObjectName("labelAccY");
        labelAccY->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAccY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAccY, 3, 1, 1, 1);

        labelSpeed = new QLabel(frameAccelerometer);
        labelSpeed->setObjectName("labelSpeed");
        sizePolicy1.setHeightForWidth(labelSpeed->sizePolicy().hasHeightForWidth());
        labelSpeed->setSizePolicy(sizePolicy1);
        labelSpeed->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"color: rgb(255, 136, 0);\n"
"color: rgb(124, 252, 0);"));
        labelSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeed, 4, 0, 1, 3);

        labelX_A = new QLabel(frameAccelerometer);
        labelX_A->setObjectName("labelX_A");
        labelX_A->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelX_A->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelX_A, 12, 0, 1, 1);

        labelSpeedY = new QLabel(frameAccelerometer);
        labelSpeedY->setObjectName("labelSpeedY");
        labelSpeedY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"color: rgb(124, 252, 0);"));
        labelSpeedY->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedY, 5, 1, 1, 1);

        labelPosZ = new QLabel(frameAccelerometer);
        labelPosZ->setObjectName("labelPosZ");
        labelPosZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 165, 0);"));
        labelPosZ->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosZ, 7, 2, 1, 1);

        labelY_A = new QLabel(frameAccelerometer);
        labelY_A->setObjectName("labelY_A");
        labelY_A->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelY_A->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelY_A, 12, 1, 1, 1);

        labelPosX = new QLabel(frameAccelerometer);
        labelPosX->setObjectName("labelPosX");
        labelPosX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(192, 76, 216);\n"
"background-color: transparent;\n"
"color: rgb(255, 165, 0);"));
        labelPosX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelPosX, 7, 0, 1, 1);

        labelAcceleration = new QLabel(frameAccelerometer);
        labelAcceleration->setObjectName("labelAcceleration");
        labelAcceleration->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(79, 216, 218);\n"
"background-color: transparent;\n"
"color: rgb(0, 255, 255);"));
        labelAcceleration->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelAcceleration, 1, 0, 1, 3);

        labelSpeedX = new QLabel(frameAccelerometer);
        labelSpeedX->setObjectName("labelSpeedX");
        labelSpeedX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(225, 104, 81);\n"
"background-color: transparent;\n"
"color: rgb(124, 252, 0);"));
        labelSpeedX->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelSpeedX, 5, 0, 1, 1);

        labelMotion = new QLabel(frameAccelerometer);
        labelMotion->setObjectName("labelMotion");
        labelMotion->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelMotion->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelMotion->setMargin(0);
        labelMotion->setIndent(10);

        gridLayout_4->addWidget(labelMotion, 0, 0, 1, 2);


        gridLayout_7->addWidget(frameAccelerometer, 0, 0, 1, 1);

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
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        labelY_G = new QLabel(frameGyroscope);
        labelY_G->setObjectName("labelY_G");
        labelY_G->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelY_G->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelY_G, 5, 1, 1, 1);

        labelAngularPosition = new QLabel(frameGyroscope);
        labelAngularPosition->setObjectName("labelAngularPosition");
        labelAngularPosition->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 102);\n"
"color: rgb(255, 255, 0);"));
        labelAngularPosition->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelAngularPosition, 3, 0, 1, 3);

        labelGyroY = new QLabel(frameGyroscope);
        labelGyroY->setObjectName("labelGyroY");
        labelGyroY->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelGyroY->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelGyroY, 2, 1, 1, 1);

        labelPitch = new QLabel(frameGyroscope);
        labelPitch->setObjectName("labelPitch");
        labelPitch->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 255, 0);"));
        labelPitch->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelPitch, 4, 1, 1, 1);

        labelGyroX = new QLabel(frameGyroscope);
        labelGyroX->setObjectName("labelGyroX");
        labelGyroX->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelGyroX->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelGyroX, 2, 0, 1, 1);

        labelGyroZ = new QLabel(frameGyroscope);
        labelGyroZ->setObjectName("labelGyroZ");
        labelGyroZ->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 0, 255);"));
        labelGyroZ->setFrameShape(QFrame::NoFrame);
        labelGyroZ->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelGyroZ, 2, 2, 1, 1);

        labelGyroscope = new QLabel(frameGyroscope);
        labelGyroscope->setObjectName("labelGyroscope");
        sizePolicy1.setHeightForWidth(labelGyroscope->sizePolicy().hasHeightForWidth());
        labelGyroscope->setSizePolicy(sizePolicy1);
        labelGyroscope->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelGyroscope->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelGyroscope->setIndent(10);

        gridLayout_22->addWidget(labelGyroscope, 0, 0, 1, 2);

        labelYaw = new QLabel(frameGyroscope);
        labelYaw->setObjectName("labelYaw");
        labelYaw->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 255, 0);"));
        labelYaw->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelYaw, 4, 2, 1, 1);

        checkBoxGyro = new QCheckBox(frameGyroscope);
        checkBoxGyro->setObjectName("checkBoxGyro");
        checkBoxGyro->setLayoutDirection(Qt::RightToLeft);
        checkBoxGyro->setStyleSheet(QString::fromUtf8("/* 1. El texto y el margen que ya ten\303\255as */\n"
"QCheckBox {\n"
"    font: 13pt \"Century Gothic\";\n"
"    font-weight: bold;\n"
"    color: rgb(222, 223, 225);\n"
"    background-color: transparent;\n"
"    margin-right: 8px;\n"
"}\n"
"\n"
"/* 2. El recuadro vac\303\255o (apagado) */\n"
"QCheckBox::indicator {\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border: 2px solid #393F44; /* El gris de tus bordes */\n"
"    border-radius: 3px;\n"
"    background-color: #22262a; /* El color de tu powerBar */\n"
"}\n"
"\n"
"/* 3. El recuadro cuando pasas el mouse por encima (hover) */\n"
"QCheckBox::indicator:hover {\n"
"    border: 2px solid #00FA9A; /* Se ilumina en verde menta */\n"
"}\n"
"\n"
"/* 4. El recuadro cuando est\303\241 activado (tildado) */\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #00FA9A; /* Se llena de verde menta */\n"
"    border: 2px solid #00FA9A;\n"
"}"));

        gridLayout_22->addWidget(checkBoxGyro, 0, 2, 1, 1);

        labelX_G = new QLabel(frameGyroscope);
        labelX_G->setObjectName("labelX_G");
        labelX_G->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelX_G->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelX_G, 5, 0, 1, 1);

        labelRoll = new QLabel(frameGyroscope);
        labelRoll->setObjectName("labelRoll");
        labelRoll->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(255, 255, 0);"));
        labelRoll->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelRoll, 4, 0, 1, 1);

        labelZ_G = new QLabel(frameGyroscope);
        labelZ_G->setObjectName("labelZ_G");
        labelZ_G->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelZ_G->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelZ_G, 5, 2, 1, 1);

        labelAngularSpeed = new QLabel(frameGyroscope);
        labelAngularSpeed->setObjectName("labelAngularSpeed");
        labelAngularSpeed->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"color: rgb(50, 205, 50);\n"
"color: rgb(255, 0, 255);"));
        labelAngularSpeed->setAlignment(Qt::AlignCenter);

        gridLayout_22->addWidget(labelAngularSpeed, 1, 0, 1, 3);


        gridLayout_7->addWidget(frameGyroscope, 0, 3, 1, 1);

        frameEngines = new QFrame(Telemetry);
        frameEngines->setObjectName("frameEngines");
        sizePolicy1.setHeightForWidth(frameEngines->sizePolicy().hasHeightForWidth());
        frameEngines->setSizePolicy(sizePolicy1);
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
        checkBoxEngines = new QCheckBox(frameEngines);
        checkBoxEngines->setObjectName("checkBoxEngines");
        checkBoxEngines->setLayoutDirection(Qt::RightToLeft);
        checkBoxEngines->setStyleSheet(QString::fromUtf8("/* 1. El texto y el margen que ya ten\303\255as */\n"
"QCheckBox {\n"
"    font: 13pt \"Century Gothic\";\n"
"    font-weight: bold;\n"
"    color: rgb(222, 223, 225);\n"
"    background-color: transparent;\n"
"    margin-right: 8px;\n"
"	margin-top: 2px;\n"
"}\n"
"\n"
"/* 2. El recuadro vac\303\255o (apagado) */\n"
"QCheckBox::indicator {\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border: 2px solid #393F44; /* El gris de tus bordes */\n"
"    border-radius: 3px;\n"
"    background-color: #22262a; /* El color de tu powerBar */\n"
"}\n"
"\n"
"/* 3. El recuadro cuando pasas el mouse por encima (hover) */\n"
"QCheckBox::indicator:hover {\n"
"    border: 2px solid #00FA9A; /* Se ilumina en verde menta */\n"
"}\n"
"\n"
"/* 4. El recuadro cuando est\303\241 activado (tildado) */\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #00FA9A; /* Se llena de verde menta */\n"
"    border: 2px solid #00FA9A;\n"
"}"));

        gridLayout_5->addWidget(checkBoxEngines, 1, 1, 1, 1);

        leftEngineLabel = new QLabel(frameEngines);
        leftEngineLabel->setObjectName("leftEngineLabel");
        sizePolicy1.setHeightForWidth(leftEngineLabel->sizePolicy().hasHeightForWidth());
        leftEngineLabel->setSizePolicy(sizePolicy1);
        leftEngineLabel->setMinimumSize(QSize(108, 0));
        leftEngineLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        leftEngineLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(leftEngineLabel, 3, 0, 1, 1);

        rightEngineDial = new QDial(frameEngines);
        rightEngineDial->setObjectName("rightEngineDial");
        rightEngineDial->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 100, 103);"));

        gridLayout_5->addWidget(rightEngineDial, 5, 1, 1, 1);

        powerButton = new QPushButton(frameEngines);
        powerButton->setObjectName("powerButton");
        sizePolicy1.setHeightForWidth(powerButton->sizePolicy().hasHeightForWidth());
        powerButton->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Century Gothic")});
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(false);
        powerButton->setFont(font3);
        powerButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_5->addWidget(powerButton, 8, 0, 1, 2);

        leftEngineDial = new QDial(frameEngines);
        leftEngineDial->setObjectName("leftEngineDial");
        leftEngineDial->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 100, 103);"));
        leftEngineDial->setMaximum(100);
        leftEngineDial->setInvertedAppearance(false);
        leftEngineDial->setWrapping(false);

        gridLayout_5->addWidget(leftEngineDial, 5, 0, 1, 1);

        leftEnginePowerLabel = new QLabel(frameEngines);
        leftEnginePowerLabel->setObjectName("leftEnginePowerLabel");
        leftEnginePowerLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        leftEnginePowerLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(leftEnginePowerLabel, 6, 0, 1, 1);

        rightEnginePowerLabel = new QLabel(frameEngines);
        rightEnginePowerLabel->setObjectName("rightEnginePowerLabel");
        rightEnginePowerLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        rightEnginePowerLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(rightEnginePowerLabel, 6, 1, 1, 1);

        rightEngineLabel = new QLabel(frameEngines);
        rightEngineLabel->setObjectName("rightEngineLabel");
        sizePolicy1.setHeightForWidth(rightEngineLabel->sizePolicy().hasHeightForWidth());
        rightEngineLabel->setSizePolicy(sizePolicy1);
        rightEngineLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        rightEngineLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(rightEngineLabel, 3, 1, 1, 1);

        enginesLabel = new QLabel(frameEngines);
        enginesLabel->setObjectName("enginesLabel");
        sizePolicy1.setHeightForWidth(enginesLabel->sizePolicy().hasHeightForWidth());
        enginesLabel->setSizePolicy(sizePolicy1);
        enginesLabel->setMinimumSize(QSize(0, 25));
        enginesLabel->setMaximumSize(QSize(16777215, 25));
        enginesLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"margin-top: 2px;"));
        enginesLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        enginesLabel->setIndent(10);

        gridLayout_5->addWidget(enginesLabel, 1, 0, 1, 1);


        gridLayout_7->addWidget(frameEngines, 2, 0, 1, 1);

        frameInfrared = new QFrame(Telemetry);
        frameInfrared->setObjectName("frameInfrared");
        sizePolicy1.setHeightForWidth(frameInfrared->sizePolicy().hasHeightForWidth());
        frameInfrared->setSizePolicy(sizePolicy1);
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
        labelNameIR5 = new QLabel(frameInfrared);
        labelNameIR5->setObjectName("labelNameIR5");
        sizePolicy1.setHeightForWidth(labelNameIR5->sizePolicy().hasHeightForWidth());
        labelNameIR5->setSizePolicy(sizePolicy1);
        labelNameIR5->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR5, 1, 1, 1, 1);

        labelValueIR3 = new QLabel(frameInfrared);
        labelValueIR3->setObjectName("labelValueIR3");
        labelValueIR3->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR3, 3, 3, 1, 1);

        labelNameIR2 = new QLabel(frameInfrared);
        labelNameIR2->setObjectName("labelNameIR2");
        sizePolicy1.setHeightForWidth(labelNameIR2->sizePolicy().hasHeightForWidth());
        labelNameIR2->setSizePolicy(sizePolicy1);
        labelNameIR2->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR2, 1, 4, 1, 1);

        labelValueIR2 = new QLabel(frameInfrared);
        labelValueIR2->setObjectName("labelValueIR2");
        labelValueIR2->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR2, 3, 4, 1, 1);

        labelValueIR7 = new QLabel(frameInfrared);
        labelValueIR7->setObjectName("labelValueIR7");
        labelValueIR7->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR7->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR7, 5, 0, 1, 1);

        labelNameIR8 = new QLabel(frameInfrared);
        labelNameIR8->setObjectName("labelNameIR8");
        sizePolicy1.setHeightForWidth(labelNameIR8->sizePolicy().hasHeightForWidth());
        labelNameIR8->setSizePolicy(sizePolicy1);
        labelNameIR8->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR8->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR8, 4, 2, 1, 1);

        labelNameIR1 = new QLabel(frameInfrared);
        labelNameIR1->setObjectName("labelNameIR1");
        sizePolicy1.setHeightForWidth(labelNameIR1->sizePolicy().hasHeightForWidth());
        labelNameIR1->setSizePolicy(sizePolicy1);
        labelNameIR1->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR1, 4, 4, 1, 1);

        labelNameIR7 = new QLabel(frameInfrared);
        labelNameIR7->setObjectName("labelNameIR7");
        sizePolicy1.setHeightForWidth(labelNameIR7->sizePolicy().hasHeightForWidth());
        labelNameIR7->setSizePolicy(sizePolicy1);
        labelNameIR7->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR7->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR7, 4, 0, 1, 1);

        labelValueIR6 = new QLabel(frameInfrared);
        labelValueIR6->setObjectName("labelValueIR6");
        labelValueIR6->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR6, 3, 0, 1, 1);

        labelValueIR4 = new QLabel(frameInfrared);
        labelValueIR4->setObjectName("labelValueIR4");
        labelValueIR4->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR4, 3, 2, 1, 1);

        labelValueIR1 = new QLabel(frameInfrared);
        labelValueIR1->setObjectName("labelValueIR1");
        labelValueIR1->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR1, 5, 4, 1, 1);

        labelNameIR6 = new QLabel(frameInfrared);
        labelNameIR6->setObjectName("labelNameIR6");
        sizePolicy1.setHeightForWidth(labelNameIR6->sizePolicy().hasHeightForWidth());
        labelNameIR6->setSizePolicy(sizePolicy1);
        labelNameIR6->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelNameIR6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR6, 1, 0, 1, 1);

        labelValueIR5 = new QLabel(frameInfrared);
        labelValueIR5->setObjectName("labelValueIR5");
        labelValueIR5->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR5, 3, 1, 1, 1);

        labelNameIR4 = new QLabel(frameInfrared);
        labelNameIR4->setObjectName("labelNameIR4");
        sizePolicy1.setHeightForWidth(labelNameIR4->sizePolicy().hasHeightForWidth());
        labelNameIR4->setSizePolicy(sizePolicy1);
        labelNameIR4->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR4, 1, 2, 1, 1);

        labelNameIR3 = new QLabel(frameInfrared);
        labelNameIR3->setObjectName("labelNameIR3");
        sizePolicy1.setHeightForWidth(labelNameIR3->sizePolicy().hasHeightForWidth());
        labelNameIR3->setSizePolicy(sizePolicy1);
        labelNameIR3->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background: transparent;"));
        labelNameIR3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelNameIR3, 1, 3, 1, 1);

        labelValueIR8 = new QLabel(frameInfrared);
        labelValueIR8->setObjectName("labelValueIR8");
        labelValueIR8->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelValueIR8->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelValueIR8, 5, 2, 1, 1);

        checkBoxIR = new QCheckBox(frameInfrared);
        checkBoxIR->setObjectName("checkBoxIR");
        checkBoxIR->setLayoutDirection(Qt::RightToLeft);
        checkBoxIR->setStyleSheet(QString::fromUtf8("/* 1. El texto y el margen que ya ten\303\255as */\n"
"QCheckBox {\n"
"    font: 13pt \"Century Gothic\";\n"
"    font-weight: bold;\n"
"    color: rgb(222, 223, 225);\n"
"    background-color: transparent;\n"
"    margin-right: 8px;\n"
"	margin-top: 2px;\n"
"}\n"
"\n"
"/* 2. El recuadro vac\303\255o (apagado) */\n"
"QCheckBox::indicator {\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border: 2px solid #393F44; /* El gris de tus bordes */\n"
"    border-radius: 3px;\n"
"    background-color: #22262a; /* El color de tu powerBar */\n"
"}\n"
"\n"
"/* 3. El recuadro cuando pasas el mouse por encima (hover) */\n"
"QCheckBox::indicator:hover {\n"
"    border: 2px solid #00FA9A; /* Se ilumina en verde menta */\n"
"}\n"
"\n"
"/* 4. El recuadro cuando est\303\241 activado (tildado) */\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #00FA9A; /* Se llena de verde menta */\n"
"    border: 2px solid #00FA9A;\n"
"}"));

        gridLayout_6->addWidget(checkBoxIR, 0, 3, 1, 2);

        buttonInfrared = new QPushButton(frameInfrared);
        buttonInfrared->setObjectName("buttonInfrared");
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(buttonInfrared->sizePolicy().hasHeightForWidth());
        buttonInfrared->setSizePolicy(sizePolicy6);
        buttonInfrared->setLayoutDirection(Qt::LeftToRight);
        buttonInfrared->setAutoFillBackground(false);
        buttonInfrared->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 13pt \"Century Gothic\";\n"
"	font-weight: bold;\n"
"	color: rgb(222, 223, 225);\n"
"	background-color: rgb(57, 63, 68);\n"
"	margin-top: 2px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	color:  #00FA9A;\n"
"}"));
        buttonInfrared->setAutoDefault(false);
        buttonInfrared->setFlat(true);

        gridLayout_6->addWidget(buttonInfrared, 0, 0, 1, 1);


        gridLayout_7->addWidget(frameInfrared, 2, 3, 1, 1);

        stackedWidget->addWidget(Telemetry);
        PID = new QWidget();
        PID->setObjectName("PID");
        gridLayout_9 = new QGridLayout(PID);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setContentsMargins(6, 0, 6, 0);
        frameThresholds = new QFrame(PID);
        frameThresholds->setObjectName("frameThresholds");
        frameThresholds->setStyleSheet(QString::fromUtf8("QWidget#frameThresholds{ \n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"border: 2px solid rgb(150, 150, 150);\n"
"}"));
        frameThresholds->setFrameShape(QFrame::StyledPanel);
        frameThresholds->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frameThresholds);
        gridLayout_18->setObjectName("gridLayout_18");
        gridLayout_18->setContentsMargins(-1, 9, -1, -1);
        labelDiagonalThreshold = new QLabel(frameThresholds);
        labelDiagonalThreshold->setObjectName("labelDiagonalThreshold");
        labelDiagonalThreshold->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_18->addWidget(labelDiagonalThreshold, 3, 0, 1, 1);

        spinBox_5 = new QSpinBox(frameThresholds);
        spinBox_5->setObjectName("spinBox_5");
        sizePolicy1.setHeightForWidth(spinBox_5->sizePolicy().hasHeightForWidth());
        spinBox_5->setSizePolicy(sizePolicy1);
        spinBox_5->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBox_5->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(spinBox_5, 2, 1, 1, 1);

        spinBox = new QSpinBox(frameThresholds);
        spinBox->setObjectName("spinBox");
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBox->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(spinBox, 4, 1, 1, 1);

        labelFrontThreshold = new QLabel(frameThresholds);
        labelFrontThreshold->setObjectName("labelFrontThreshold");
        labelFrontThreshold->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_18->addWidget(labelFrontThreshold, 2, 0, 1, 1);

        labelLeftThreshold = new QLabel(frameThresholds);
        labelLeftThreshold->setObjectName("labelLeftThreshold");
        labelLeftThreshold->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelLeftThreshold->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(labelLeftThreshold, 1, 1, 1, 1);

        spinBox_4 = new QSpinBox(frameThresholds);
        spinBox_4->setObjectName("spinBox_4");
        sizePolicy1.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy1);
        spinBox_4->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBox_4->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(spinBox_4, 3, 1, 1, 1);

        labelLateralThreshold = new QLabel(frameThresholds);
        labelLateralThreshold->setObjectName("labelLateralThreshold");
        labelLateralThreshold->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_18->addWidget(labelLateralThreshold, 4, 0, 1, 1);

        labelRightThreshold = new QLabel(frameThresholds);
        labelRightThreshold->setObjectName("labelRightThreshold");
        labelRightThreshold->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelRightThreshold->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(labelRightThreshold, 1, 2, 1, 1);

        spinBox_2 = new QSpinBox(frameThresholds);
        spinBox_2->setObjectName("spinBox_2");
        sizePolicy1.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy1);
        spinBox_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBox_2->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(spinBox_2, 2, 2, 1, 1);

        spinBox_3 = new QSpinBox(frameThresholds);
        spinBox_3->setObjectName("spinBox_3");
        sizePolicy1.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy1);
        spinBox_3->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBox_3->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(spinBox_3, 3, 2, 1, 1);

        spinBox_6 = new QSpinBox(frameThresholds);
        spinBox_6->setObjectName("spinBox_6");
        sizePolicy1.setHeightForWidth(spinBox_6->sizePolicy().hasHeightForWidth());
        spinBox_6->setSizePolicy(sizePolicy1);
        spinBox_6->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBox_6->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(spinBox_6, 4, 2, 1, 1);

        readThresholdButton = new QPushButton(frameThresholds);
        readThresholdButton->setObjectName("readThresholdButton");
        sizePolicy1.setHeightForWidth(readThresholdButton->sizePolicy().hasHeightForWidth());
        readThresholdButton->setSizePolicy(sizePolicy1);
        readThresholdButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        readThresholdButton->setFlat(true);

        gridLayout_18->addWidget(readThresholdButton, 5, 1, 1, 1);

        setThresholdButton = new QPushButton(frameThresholds);
        setThresholdButton->setObjectName("setThresholdButton");
        sizePolicy1.setHeightForWidth(setThresholdButton->sizePolicy().hasHeightForWidth());
        setThresholdButton->setSizePolicy(sizePolicy1);
        setThresholdButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_18->addWidget(setThresholdButton, 5, 2, 1, 1);

        changeThresholdUnitButton = new QPushButton(frameThresholds);
        changeThresholdUnitButton->setObjectName("changeThresholdUnitButton");
        sizePolicy1.setHeightForWidth(changeThresholdUnitButton->sizePolicy().hasHeightForWidth());
        changeThresholdUnitButton->setSizePolicy(sizePolicy1);
        changeThresholdUnitButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        changeThresholdUnitButton->setFlat(true);

        gridLayout_18->addWidget(changeThresholdUnitButton, 1, 0, 1, 1);

        labelThresholds = new QLabel(frameThresholds);
        labelThresholds->setObjectName("labelThresholds");
        labelThresholds->setFocusPolicy(Qt::NoFocus);
        labelThresholds->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_18->addWidget(labelThresholds, 0, 0, 1, 2);


        gridLayout_9->addWidget(frameThresholds, 3, 0, 1, 2);

        frameSoftwareConfig = new QFrame(PID);
        frameSoftwareConfig->setObjectName("frameSoftwareConfig");
        sizePolicy1.setHeightForWidth(frameSoftwareConfig->sizePolicy().hasHeightForWidth());
        frameSoftwareConfig->setSizePolicy(sizePolicy1);
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
        gridLayout_13->setContentsMargins(-1, 9, -1, -1);
        pwmPrescalerConfig = new QLineEdit(frameSoftwareConfig);
        pwmPrescalerConfig->setObjectName("pwmPrescalerConfig");
        sizePolicy1.setHeightForWidth(pwmPrescalerConfig->sizePolicy().hasHeightForWidth());
        pwmPrescalerConfig->setSizePolicy(sizePolicy1);
        pwmPrescalerConfig->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        pwmPrescalerConfig->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(pwmPrescalerConfig, 1, 1, 1, 1);

        labelPrescaler = new QLabel(frameSoftwareConfig);
        labelPrescaler->setObjectName("labelPrescaler");
        sizePolicy1.setHeightForWidth(labelPrescaler->sizePolicy().hasHeightForWidth());
        labelPrescaler->setSizePolicy(sizePolicy1);
        labelPrescaler->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelPrescaler->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(labelPrescaler, 1, 0, 1, 1);

        labelPeriod = new QLabel(frameSoftwareConfig);
        labelPeriod->setObjectName("labelPeriod");
        sizePolicy1.setHeightForWidth(labelPeriod->sizePolicy().hasHeightForWidth());
        labelPeriod->setSizePolicy(sizePolicy1);
        labelPeriod->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelPeriod->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(labelPeriod, 3, 0, 1, 1);

        pwmPeriodConfig = new QLineEdit(frameSoftwareConfig);
        pwmPeriodConfig->setObjectName("pwmPeriodConfig");
        sizePolicy1.setHeightForWidth(pwmPeriodConfig->sizePolicy().hasHeightForWidth());
        pwmPeriodConfig->setSizePolicy(sizePolicy1);
        pwmPeriodConfig->setCursor(QCursor(Qt::IBeamCursor));
        pwmPeriodConfig->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        pwmPeriodConfig->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(pwmPeriodConfig, 3, 1, 1, 1);

        labelResultingFrequency = new QLabel(frameSoftwareConfig);
        labelResultingFrequency->setObjectName("labelResultingFrequency");
        sizePolicy1.setHeightForWidth(labelResultingFrequency->sizePolicy().hasHeightForWidth());
        labelResultingFrequency->setSizePolicy(sizePolicy1);
        labelResultingFrequency->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_13->addWidget(labelResultingFrequency, 6, 0, 1, 1);

        labelTimerFreqResult = new QLabel(frameSoftwareConfig);
        labelTimerFreqResult->setObjectName("labelTimerFreqResult");
        sizePolicy1.setHeightForWidth(labelTimerFreqResult->sizePolicy().hasHeightForWidth());
        labelTimerFreqResult->setSizePolicy(sizePolicy1);
        labelTimerFreqResult->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelTimerFreqResult->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(labelTimerFreqResult, 6, 1, 1, 1);

        pwmConfigButton = new QPushButton(frameSoftwareConfig);
        pwmConfigButton->setObjectName("pwmConfigButton");
        sizePolicy1.setHeightForWidth(pwmConfigButton->sizePolicy().hasHeightForWidth());
        pwmConfigButton->setSizePolicy(sizePolicy1);
        pwmConfigButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_13->addWidget(pwmConfigButton, 7, 1, 1, 1);

        changeConfigWidgetButton = new QPushButton(frameSoftwareConfig);
        changeConfigWidgetButton->setObjectName("changeConfigWidgetButton");
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(changeConfigWidgetButton->sizePolicy().hasHeightForWidth());
        changeConfigWidgetButton->setSizePolicy(sizePolicy7);
        changeConfigWidgetButton->setCursor(QCursor(Qt::ArrowCursor));
        changeConfigWidgetButton->setFocusPolicy(Qt::NoFocus);
        changeConfigWidgetButton->setAutoFillBackground(false);
        changeConfigWidgetButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
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

        gridLayout_13->addWidget(changeConfigWidgetButton, 0, 0, 1, 2);


        gridLayout_9->addWidget(frameSoftwareConfig, 4, 0, 1, 2);

        frameBatteryLevel = new QFrame(PID);
        frameBatteryLevel->setObjectName("frameBatteryLevel");
        sizePolicy1.setHeightForWidth(frameBatteryLevel->sizePolicy().hasHeightForWidth());
        frameBatteryLevel->setSizePolicy(sizePolicy1);
        frameBatteryLevel->setStyleSheet(QString::fromUtf8("QWidget#frameBatteryLevel{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameBatteryLevel->setFrameShape(QFrame::StyledPanel);
        frameBatteryLevel->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(frameBatteryLevel);
        gridLayout_16->setObjectName("gridLayout_16");
        batteryVoltageSpinBox = new QDoubleSpinBox(frameBatteryLevel);
        batteryVoltageSpinBox->setObjectName("batteryVoltageSpinBox");
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(batteryVoltageSpinBox->sizePolicy().hasHeightForWidth());
        batteryVoltageSpinBox->setSizePolicy(sizePolicy8);
        batteryVoltageSpinBox->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        batteryVoltageSpinBox->setAlignment(Qt::AlignCenter);
        batteryVoltageSpinBox->setMinimum(3.000000000000000);
        batteryVoltageSpinBox->setMaximum(9.000000000000000);
        batteryVoltageSpinBox->setSingleStep(0.100000000000000);
        batteryVoltageSpinBox->setValue(7.600000000000000);

        gridLayout_16->addWidget(batteryVoltageSpinBox, 1, 0, 1, 1);

        setBatteryVoltageButton = new QPushButton(frameBatteryLevel);
        setBatteryVoltageButton->setObjectName("setBatteryVoltageButton");
        sizePolicy8.setHeightForWidth(setBatteryVoltageButton->sizePolicy().hasHeightForWidth());
        setBatteryVoltageButton->setSizePolicy(sizePolicy8);
        setBatteryVoltageButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_16->addWidget(setBatteryVoltageButton, 2, 0, 1, 1);

        label_2 = new QLabel(frameBatteryLevel);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_16->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_9->addWidget(frameBatteryLevel, 5, 0, 1, 1);

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
        labelWallPID = new QLabel(framePID);
        labelWallPID->setObjectName("labelWallPID");
        sizePolicy1.setHeightForWidth(labelWallPID->sizePolicy().hasHeightForWidth());
        labelWallPID->setSizePolicy(sizePolicy1);
        labelWallPID->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelWallPID->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelWallPID, 2, 3, 1, 2);

        labelPIDValues = new QLabel(framePID);
        labelPIDValues->setObjectName("labelPIDValues");
        sizePolicy1.setHeightForWidth(labelPIDValues->sizePolicy().hasHeightForWidth());
        labelPIDValues->setSizePolicy(sizePolicy1);
        labelPIDValues->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_12->addWidget(labelPIDValues, 0, 0, 1, 5);

        lineEditWallMin = new QLineEdit(framePID);
        lineEditWallMin->setObjectName("lineEditWallMin");
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(lineEditWallMin->sizePolicy().hasHeightForWidth());
        lineEditWallMin->setSizePolicy(sizePolicy9);
        lineEditWallMin->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallMin->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallMin, 6, 3, 1, 2);

        lineEditTurnMin = new QLineEdit(framePID);
        lineEditTurnMin->setObjectName("lineEditTurnMin");
        sizePolicy9.setHeightForWidth(lineEditTurnMin->sizePolicy().hasHeightForWidth());
        lineEditTurnMin->setSizePolicy(sizePolicy9);
        lineEditTurnMin->setMinimumSize(QSize(79, 0));
        lineEditTurnMin->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnMin->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnMin, 6, 1, 1, 2);

        lineEditWallKI = new QLineEdit(framePID);
        lineEditWallKI->setObjectName("lineEditWallKI");
        sizePolicy9.setHeightForWidth(lineEditWallKI->sizePolicy().hasHeightForWidth());
        lineEditWallKI->setSizePolicy(sizePolicy9);
        lineEditWallKI->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallKI, 4, 3, 1, 2);

        labelKD = new QLabel(framePID);
        labelKD->setObjectName("labelKD");
        sizePolicy1.setHeightForWidth(labelKD->sizePolicy().hasHeightForWidth());
        labelKD->setSizePolicy(sizePolicy1);
        labelKD->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKD->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKD, 5, 0, 1, 1);

        lineEditWallKP = new QLineEdit(framePID);
        lineEditWallKP->setObjectName("lineEditWallKP");
        sizePolicy9.setHeightForWidth(lineEditWallKP->sizePolicy().hasHeightForWidth());
        lineEditWallKP->setSizePolicy(sizePolicy9);
        lineEditWallKP->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallKP, 3, 3, 1, 2);

        labelKP = new QLabel(framePID);
        labelKP->setObjectName("labelKP");
        sizePolicy1.setHeightForWidth(labelKP->sizePolicy().hasHeightForWidth());
        labelKP->setSizePolicy(sizePolicy1);
        labelKP->setLayoutDirection(Qt::LeftToRight);
        labelKP->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKP, 3, 0, 1, 1);

        lineEditWallBase = new QLineEdit(framePID);
        lineEditWallBase->setObjectName("lineEditWallBase");
        sizePolicy9.setHeightForWidth(lineEditWallBase->sizePolicy().hasHeightForWidth());
        lineEditWallBase->setSizePolicy(sizePolicy9);
        lineEditWallBase->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallBase->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallBase, 9, 3, 1, 2);

        labelMaxOut = new QLabel(framePID);
        labelMaxOut->setObjectName("labelMaxOut");
        labelMaxOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelMaxOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelMaxOut, 7, 0, 1, 1);

        labelBaseOut = new QLabel(framePID);
        labelBaseOut->setObjectName("labelBaseOut");
        labelBaseOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelBaseOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelBaseOut, 9, 0, 1, 1);

        labelKI = new QLabel(framePID);
        labelKI->setObjectName("labelKI");
        sizePolicy1.setHeightForWidth(labelKI->sizePolicy().hasHeightForWidth());
        labelKI->setSizePolicy(sizePolicy1);
        labelKI->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelKI, 4, 0, 1, 1);

        readStopPIDButton = new QPushButton(framePID);
        readStopPIDButton->setObjectName("readStopPIDButton");
        sizePolicy8.setHeightForWidth(readStopPIDButton->sizePolicy().hasHeightForWidth());
        readStopPIDButton->setSizePolicy(sizePolicy8);
        readStopPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        readStopPIDButton->setFlat(true);

        gridLayout_12->addWidget(readStopPIDButton, 11, 5, 1, 1);

        readTurnPIDButton = new QPushButton(framePID);
        readTurnPIDButton->setObjectName("readTurnPIDButton");
        sizePolicy8.setHeightForWidth(readTurnPIDButton->sizePolicy().hasHeightForWidth());
        readTurnPIDButton->setSizePolicy(sizePolicy8);
        readTurnPIDButton->setMinimumSize(QSize(0, 0));
        readTurnPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        readTurnPIDButton->setFlat(true);

        gridLayout_12->addWidget(readTurnPIDButton, 11, 1, 1, 1);

        labelMinOut = new QLabel(framePID);
        labelMinOut->setObjectName("labelMinOut");
        labelMinOut->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelMinOut->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelMinOut, 6, 0, 1, 1);

        readWallPIDButton = new QPushButton(framePID);
        readWallPIDButton->setObjectName("readWallPIDButton");
        sizePolicy8.setHeightForWidth(readWallPIDButton->sizePolicy().hasHeightForWidth());
        readWallPIDButton->setSizePolicy(sizePolicy8);
        readWallPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        readWallPIDButton->setFlat(true);

        gridLayout_12->addWidget(readWallPIDButton, 11, 3, 1, 1);

        lineEditTurnKI = new QLineEdit(framePID);
        lineEditTurnKI->setObjectName("lineEditTurnKI");
        sizePolicy9.setHeightForWidth(lineEditTurnKI->sizePolicy().hasHeightForWidth());
        lineEditTurnKI->setSizePolicy(sizePolicy9);
        lineEditTurnKI->setMinimumSize(QSize(79, 0));
        lineEditTurnKI->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKI, 4, 1, 1, 2);

        lineEditWallMax = new QLineEdit(framePID);
        lineEditWallMax->setObjectName("lineEditWallMax");
        sizePolicy9.setHeightForWidth(lineEditWallMax->sizePolicy().hasHeightForWidth());
        lineEditWallMax->setSizePolicy(sizePolicy9);
        lineEditWallMax->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallMax->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditWallMax, 7, 3, 1, 2);

        lineEditTurnMax = new QLineEdit(framePID);
        lineEditTurnMax->setObjectName("lineEditTurnMax");
        sizePolicy9.setHeightForWidth(lineEditTurnMax->sizePolicy().hasHeightForWidth());
        lineEditTurnMax->setSizePolicy(sizePolicy9);
        lineEditTurnMax->setMinimumSize(QSize(79, 0));
        lineEditTurnMax->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnMax->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnMax, 7, 1, 1, 2);

        lineEditWallKD = new QLineEdit(framePID);
        lineEditWallKD->setObjectName("lineEditWallKD");
        sizePolicy9.setHeightForWidth(lineEditWallKD->sizePolicy().hasHeightForWidth());
        lineEditWallKD->setSizePolicy(sizePolicy9);
        lineEditWallKD->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditWallKD->setFrame(true);
        lineEditWallKD->setAlignment(Qt::AlignCenter);
        lineEditWallKD->setClearButtonEnabled(false);

        gridLayout_12->addWidget(lineEditWallKD, 5, 3, 1, 2);

        setWallPIDButton = new QPushButton(framePID);
        setWallPIDButton->setObjectName("setWallPIDButton");
        sizePolicy8.setHeightForWidth(setWallPIDButton->sizePolicy().hasHeightForWidth());
        setWallPIDButton->setSizePolicy(sizePolicy8);
        setWallPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(setWallPIDButton, 11, 4, 1, 1);

        setTurnPIDButton = new QPushButton(framePID);
        setTurnPIDButton->setObjectName("setTurnPIDButton");
        sizePolicy8.setHeightForWidth(setTurnPIDButton->sizePolicy().hasHeightForWidth());
        setTurnPIDButton->setSizePolicy(sizePolicy8);
        setTurnPIDButton->setMinimumSize(QSize(0, 0));
        setTurnPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(setTurnPIDButton, 11, 2, 1, 1);

        lineEditTurnKP = new QLineEdit(framePID);
        lineEditTurnKP->setObjectName("lineEditTurnKP");
        sizePolicy9.setHeightForWidth(lineEditTurnKP->sizePolicy().hasHeightForWidth());
        lineEditTurnKP->setSizePolicy(sizePolicy9);
        lineEditTurnKP->setMinimumSize(QSize(79, 0));
        lineEditTurnKP->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKP, 3, 1, 1, 2);

        lineEditTurnBase = new QLineEdit(framePID);
        lineEditTurnBase->setObjectName("lineEditTurnBase");
        sizePolicy9.setHeightForWidth(lineEditTurnBase->sizePolicy().hasHeightForWidth());
        lineEditTurnBase->setSizePolicy(sizePolicy9);
        lineEditTurnBase->setMinimumSize(QSize(79, 0));
        lineEditTurnBase->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnBase->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnBase, 9, 1, 1, 2);

        lineEditTurnKD = new QLineEdit(framePID);
        lineEditTurnKD->setObjectName("lineEditTurnKD");
        sizePolicy9.setHeightForWidth(lineEditTurnKD->sizePolicy().hasHeightForWidth());
        lineEditTurnKD->setSizePolicy(sizePolicy9);
        lineEditTurnKD->setMinimumSize(QSize(79, 0));
        lineEditTurnKD->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditTurnKD->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditTurnKD, 5, 1, 1, 2);

        labelTurnPID = new QLabel(framePID);
        labelTurnPID->setObjectName("labelTurnPID");
        sizePolicy1.setHeightForWidth(labelTurnPID->sizePolicy().hasHeightForWidth());
        labelTurnPID->setSizePolicy(sizePolicy1);
        labelTurnPID->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelTurnPID->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelTurnPID, 2, 1, 1, 2);

        setStopPIDButton = new QPushButton(framePID);
        setStopPIDButton->setObjectName("setStopPIDButton");
        sizePolicy8.setHeightForWidth(setStopPIDButton->sizePolicy().hasHeightForWidth());
        setStopPIDButton->setSizePolicy(sizePolicy8);
        setStopPIDButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_12->addWidget(setStopPIDButton, 11, 6, 1, 1);

        lineEditStopBase = new QLineEdit(framePID);
        lineEditStopBase->setObjectName("lineEditStopBase");
        sizePolicy9.setHeightForWidth(lineEditStopBase->sizePolicy().hasHeightForWidth());
        lineEditStopBase->setSizePolicy(sizePolicy9);
        lineEditStopBase->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditStopBase->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditStopBase, 9, 5, 1, 2);

        lineEditStopMax = new QLineEdit(framePID);
        lineEditStopMax->setObjectName("lineEditStopMax");
        sizePolicy9.setHeightForWidth(lineEditStopMax->sizePolicy().hasHeightForWidth());
        lineEditStopMax->setSizePolicy(sizePolicy9);
        lineEditStopMax->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditStopMax->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditStopMax, 7, 5, 1, 2);

        lineEditStopMin = new QLineEdit(framePID);
        lineEditStopMin->setObjectName("lineEditStopMin");
        sizePolicy9.setHeightForWidth(lineEditStopMin->sizePolicy().hasHeightForWidth());
        lineEditStopMin->setSizePolicy(sizePolicy9);
        lineEditStopMin->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditStopMin->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditStopMin, 6, 5, 1, 2);

        lineEditStopKD = new QLineEdit(framePID);
        lineEditStopKD->setObjectName("lineEditStopKD");
        sizePolicy9.setHeightForWidth(lineEditStopKD->sizePolicy().hasHeightForWidth());
        lineEditStopKD->setSizePolicy(sizePolicy9);
        lineEditStopKD->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditStopKD->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditStopKD, 5, 5, 1, 2);

        lineEditStopKI = new QLineEdit(framePID);
        lineEditStopKI->setObjectName("lineEditStopKI");
        sizePolicy9.setHeightForWidth(lineEditStopKI->sizePolicy().hasHeightForWidth());
        lineEditStopKI->setSizePolicy(sizePolicy9);
        lineEditStopKI->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditStopKI->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditStopKI, 4, 5, 1, 2);

        lineEditStopKP = new QLineEdit(framePID);
        lineEditStopKP->setObjectName("lineEditStopKP");
        sizePolicy9.setHeightForWidth(lineEditStopKP->sizePolicy().hasHeightForWidth());
        lineEditStopKP->setSizePolicy(sizePolicy9);
        lineEditStopKP->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        lineEditStopKP->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(lineEditStopKP, 3, 5, 1, 2);

        labelStopPID = new QLabel(framePID);
        labelStopPID->setObjectName("labelStopPID");
        labelStopPID->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));
        labelStopPID->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(labelStopPID, 2, 5, 1, 2);


        gridLayout_9->addWidget(framePID, 3, 2, 2, 3);

        frameFirmware = new QFrame(PID);
        frameFirmware->setObjectName("frameFirmware");
        sizePolicy1.setHeightForWidth(frameFirmware->sizePolicy().hasHeightForWidth());
        frameFirmware->setSizePolicy(sizePolicy1);
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
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelFirmware->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(labelFirmware, 1, 0, 1, 1);

        labelSoftwareVersion = new QLabel(frameFirmware);
        labelSoftwareVersion->setObjectName("labelSoftwareVersion");
        labelSoftwareVersion->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelSoftwareVersion->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(labelSoftwareVersion, 3, 0, 1, 1);

        labelFirmwareVersion = new QLabel(frameFirmware);
        labelFirmwareVersion->setObjectName("labelFirmwareVersion");
        labelFirmwareVersion->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_14->addWidget(labelFirmwareVersion, 0, 0, 1, 1);

        labelSoftware = new QLabel(frameFirmware);
        labelSoftware->setObjectName("labelSoftware");
        labelSoftware->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_14->addWidget(labelSoftware, 2, 0, 1, 1);


        gridLayout_9->addWidget(frameFirmware, 5, 1, 1, 2);

        stackedWidget->addWidget(PID);
        Communication = new QWidget();
        Communication->setObjectName("Communication");
        gridLayout_3 = new QGridLayout(Communication);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(6, 0, 6, 0);
        plainTextEdit = new QPlainTextEdit(Communication);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy10);
        plainTextEdit->setToolTipDuration(-1);
        plainTextEdit->setStyleSheet(QString::fromUtf8("QWidget#plainTextEdit{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font: 10pt \"Courier New\";\n"
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
        sizePolicy3.setHeightForWidth(SendCommandButton->sizePolicy().hasHeightForWidth());
        SendCommandButton->setSizePolicy(sizePolicy3);
        SendCommandButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_3->addWidget(SendCommandButton, 1, 1, 1, 1);

        aliveButton = new QPushButton(Communication);
        aliveButton->setObjectName("aliveButton");
        sizePolicy3.setHeightForWidth(aliveButton->sizePolicy().hasHeightForWidth());
        aliveButton->setSizePolicy(sizePolicy3);
        aliveButton->setFocusPolicy(Qt::StrongFocus);
        aliveButton->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_3->addWidget(aliveButton, 1, 2, 1, 1);

        comboBoxSendCommand = new QComboBox(Communication);
        comboBoxSendCommand->setObjectName("comboBoxSendCommand");
        comboBoxSendCommand->setStyleSheet(QString::fromUtf8("font: 10pt \"Siemens Sans\";\n"
"font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_3->addWidget(comboBoxSendCommand, 1, 0, 1, 1);

        labelCommand = new QLabel(Communication);
        labelCommand->setObjectName("labelCommand");
        labelCommand->setMinimumSize(QSize(0, 25));
        labelCommand->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 13pt \"Century Gothic\";\n"
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
        gridLayout_10->setContentsMargins(6, 0, 6, 0);
        frameMazeViews = new QFrame(Maze);
        frameMazeViews->setObjectName("frameMazeViews");
        sizePolicy9.setHeightForWidth(frameMazeViews->sizePolicy().hasHeightForWidth());
        frameMazeViews->setSizePolicy(sizePolicy9);
        frameMazeViews->setStyleSheet(QString::fromUtf8("QWidget#frameMazeViews{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameMazeViews->setFrameShape(QFrame::NoFrame);
        frameMazeViews->setFrameShadow(QFrame::Plain);
        frameMazeViews->setLineWidth(0);
        gridLayout_29 = new QGridLayout(frameMazeViews);
        gridLayout_29->setObjectName("gridLayout_29");
        gridLayout_29->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(frameMazeViews);
        tabWidget_2->setObjectName("tabWidget_2");
        QSizePolicy sizePolicy11(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy11);
        tabWidget_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: rgb(57, 63, 68);;\n"
"margin-top: 0px;"));
        tabWidget_2->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_28 = new QGridLayout(tab);
        gridLayout_28->setObjectName("gridLayout_28");
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        frameDisplayIntersection = new QFrame(tab);
        frameDisplayIntersection->setObjectName("frameDisplayIntersection");
        QSizePolicy sizePolicy12(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(frameDisplayIntersection->sizePolicy().hasHeightForWidth());
        frameDisplayIntersection->setSizePolicy(sizePolicy12);
        frameDisplayIntersection->setMinimumSize(QSize(0, 0));
        frameDisplayIntersection->setMaximumSize(QSize(16777215, 16777215));
        frameDisplayIntersection->setStyleSheet(QString::fromUtf8(""));
        frameDisplayIntersection->setFrameShape(QFrame::NoFrame);
        frameDisplayIntersection->setFrameShadow(QFrame::Plain);
        gridLayout_20 = new QGridLayout(frameDisplayIntersection);
        gridLayout_20->setObjectName("gridLayout_20");
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        qmlDisplayWidget = new QQuickWidget(frameDisplayIntersection);
        qmlDisplayWidget->setObjectName("qmlDisplayWidget");
        sizePolicy12.setHeightForWidth(qmlDisplayWidget->sizePolicy().hasHeightForWidth());
        qmlDisplayWidget->setSizePolicy(sizePolicy12);
        qmlDisplayWidget->setStyleSheet(QString::fromUtf8("QWidget#qmlDisplayWidget{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"border-radius: 5px;\n"
"}"));
        qmlDisplayWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        gridLayout_20->addWidget(qmlDisplayWidget, 0, 0, 1, 1);


        gridLayout_28->addWidget(frameDisplayIntersection, 0, 0, 1, 1);

        tabWidget_2->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_27 = new QGridLayout(tab_3);
        gridLayout_27->setSpacing(6);
        gridLayout_27->setObjectName("gridLayout_27");
        gridLayout_27->setContentsMargins(0, 0, 0, 0);
        frameRadar = new QFrame(tab_3);
        frameRadar->setObjectName("frameRadar");
        sizePolicy12.setHeightForWidth(frameRadar->sizePolicy().hasHeightForWidth());
        frameRadar->setSizePolicy(sizePolicy12);
        frameRadar->setMinimumSize(QSize(370, 300));
        frameRadar->setStyleSheet(QString::fromUtf8(""));
        frameRadar->setFrameShape(QFrame::NoFrame);
        frameRadar->setFrameShadow(QFrame::Plain);
        gridLayout_15 = new QGridLayout(frameRadar);
        gridLayout_15->setObjectName("gridLayout_15");
        gridLayout_15->setVerticalSpacing(6);
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        widgetRadar = new QWidget(frameRadar);
        widgetRadar->setObjectName("widgetRadar");
        widgetRadar->setEnabled(true);
        sizePolicy1.setHeightForWidth(widgetRadar->sizePolicy().hasHeightForWidth());
        widgetRadar->setSizePolicy(sizePolicy1);
        widgetRadar->setMinimumSize(QSize(305, 200));
        widgetRadar->setStyleSheet(QString::fromUtf8("border-radius: 0px;"));

        gridLayout_15->addWidget(widgetRadar, 0, 1, 4, 2);


        gridLayout_27->addWidget(frameRadar, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_3, QString());

        gridLayout_29->addWidget(tabWidget_2, 0, 0, 1, 1);


        gridLayout_10->addWidget(frameMazeViews, 1, 0, 1, 1);

        widget = new QWidget(Maze);
        widget->setObjectName("widget");
        gridLayout_17 = new QGridLayout(widget);
        gridLayout_17->setObjectName("gridLayout_17");
        gridLayout_17->setContentsMargins(0, 0, 0, 0);

        gridLayout_10->addWidget(widget, 1, 1, 1, 1);

        gridLayout_10->setColumnStretch(0, 2);
        stackedWidget->addWidget(Maze);
        page = new QWidget();
        page->setObjectName("page");
        frameTarget = new QFrame(page);
        frameTarget->setObjectName("frameTarget");
        frameTarget->setEnabled(true);
        frameTarget->setGeometry(QRect(670, 80, 229, 179));
        sizePolicy1.setHeightForWidth(frameTarget->sizePolicy().hasHeightForWidth());
        frameTarget->setSizePolicy(sizePolicy1);
        frameTarget->setStyleSheet(QString::fromUtf8("QWidget#frameTarget{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameTarget->setFrameShape(QFrame::StyledPanel);
        frameTarget->setFrameShadow(QFrame::Raised);
        gridLayout_19 = new QGridLayout(frameTarget);
        gridLayout_19->setObjectName("gridLayout_19");
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(frameTarget);
        tabWidget->setObjectName("tabWidget");
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: rgb(57, 63, 68);;\n"
"margin-top: 2px;"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        StartTab = new QWidget();
        StartTab->setObjectName("StartTab");
        gridLayout_26 = new QGridLayout(StartTab);
        gridLayout_26->setObjectName("gridLayout_26");
        spinBoxStartY = new QSpinBox(StartTab);
        spinBoxStartY->setObjectName("spinBoxStartY");
        sizePolicy1.setHeightForWidth(spinBoxStartY->sizePolicy().hasHeightForWidth());
        spinBoxStartY->setSizePolicy(sizePolicy1);
        spinBoxStartY->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBoxStartY->setAlignment(Qt::AlignCenter);
        spinBoxStartY->setMaximum(5);

        gridLayout_26->addWidget(spinBoxStartY, 2, 1, 1, 1);

        labelStartDir = new QLabel(StartTab);
        labelStartDir->setObjectName("labelStartDir");
        labelStartDir->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelStartDir->setAlignment(Qt::AlignCenter);

        gridLayout_26->addWidget(labelStartDir, 1, 2, 1, 1);

        spinBoxStartX = new QSpinBox(StartTab);
        spinBoxStartX->setObjectName("spinBoxStartX");
        sizePolicy1.setHeightForWidth(spinBoxStartX->sizePolicy().hasHeightForWidth());
        spinBoxStartX->setSizePolicy(sizePolicy1);
        spinBoxStartX->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBoxStartX->setAlignment(Qt::AlignCenter);
        spinBoxStartX->setMaximum(7);

        gridLayout_26->addWidget(spinBoxStartX, 2, 0, 1, 1);

        labelMazeStart = new QLabel(StartTab);
        labelMazeStart->setObjectName("labelMazeStart");
        labelMazeStart->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"margin-top: 2px;"));

        gridLayout_26->addWidget(labelMazeStart, 0, 0, 1, 3);

        comboBoxStartDir = new QComboBox(StartTab);
        comboBoxStartDir->addItem(QString());
        comboBoxStartDir->addItem(QString());
        comboBoxStartDir->addItem(QString());
        comboBoxStartDir->addItem(QString());
        comboBoxStartDir->setObjectName("comboBoxStartDir");
        sizePolicy1.setHeightForWidth(comboBoxStartDir->sizePolicy().hasHeightForWidth());
        comboBoxStartDir->setSizePolicy(sizePolicy1);

        gridLayout_26->addWidget(comboBoxStartDir, 2, 2, 1, 1);

        labelStartY = new QLabel(StartTab);
        labelStartY->setObjectName("labelStartY");
        labelStartY->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelStartY->setAlignment(Qt::AlignCenter);

        gridLayout_26->addWidget(labelStartY, 1, 1, 1, 1);

        labelStartX = new QLabel(StartTab);
        labelStartX->setObjectName("labelStartX");
        labelStartX->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelStartX->setAlignment(Qt::AlignCenter);

        gridLayout_26->addWidget(labelStartX, 1, 0, 1, 1);

        buttonSetStart = new QPushButton(StartTab);
        buttonSetStart->setObjectName("buttonSetStart");
        sizePolicy8.setHeightForWidth(buttonSetStart->sizePolicy().hasHeightForWidth());
        buttonSetStart->setSizePolicy(sizePolicy8);
        buttonSetStart->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_26->addWidget(buttonSetStart, 3, 0, 1, 3);

        tabWidget->addTab(StartTab, QString());
        TargetTab = new QWidget();
        TargetTab->setObjectName("TargetTab");
        gridLayout_25 = new QGridLayout(TargetTab);
        gridLayout_25->setObjectName("gridLayout_25");
        labelMazeTarget = new QLabel(TargetTab);
        labelMazeTarget->setObjectName("labelMazeTarget");
        labelMazeTarget->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"margin-top: 2px;"));

        gridLayout_25->addWidget(labelMazeTarget, 0, 0, 1, 2);

        spinBoxTargetX = new QSpinBox(TargetTab);
        spinBoxTargetX->setObjectName("spinBoxTargetX");
        sizePolicy8.setHeightForWidth(spinBoxTargetX->sizePolicy().hasHeightForWidth());
        spinBoxTargetX->setSizePolicy(sizePolicy8);
        spinBoxTargetX->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBoxTargetX->setWrapping(false);
        spinBoxTargetX->setAlignment(Qt::AlignCenter);
        spinBoxTargetX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxTargetX->setMaximum(7);

        gridLayout_25->addWidget(spinBoxTargetX, 2, 0, 1, 1);

        spinBoxTargetY = new QSpinBox(TargetTab);
        spinBoxTargetY->setObjectName("spinBoxTargetY");
        sizePolicy8.setHeightForWidth(spinBoxTargetY->sizePolicy().hasHeightForWidth());
        spinBoxTargetY->setSizePolicy(sizePolicy8);
        spinBoxTargetY->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        spinBoxTargetY->setAlignment(Qt::AlignCenter);
        spinBoxTargetY->setMaximum(5);

        gridLayout_25->addWidget(spinBoxTargetY, 2, 1, 1, 1);

        labelTargetX = new QLabel(TargetTab);
        labelTargetX->setObjectName("labelTargetX");
        labelTargetX->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelTargetX->setAlignment(Qt::AlignCenter);

        gridLayout_25->addWidget(labelTargetX, 1, 0, 1, 1);

        labelTargetY = new QLabel(TargetTab);
        labelTargetY->setObjectName("labelTargetY");
        labelTargetY->setStyleSheet(QString::fromUtf8("font: 13pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"background-color: transparent;"));
        labelTargetY->setAlignment(Qt::AlignCenter);

        gridLayout_25->addWidget(labelTargetY, 1, 1, 1, 1);

        buttonSetTargetXY = new QPushButton(TargetTab);
        buttonSetTargetXY->setObjectName("buttonSetTargetXY");
        buttonSetTargetXY->setEnabled(true);
        sizePolicy8.setHeightForWidth(buttonSetTargetXY->sizePolicy().hasHeightForWidth());
        buttonSetTargetXY->setSizePolicy(sizePolicy8);
        buttonSetTargetXY->setStyleSheet(QString::fromUtf8("font: 10pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));
        buttonSetTargetXY->setLocale(QLocale(QLocale::Spanish, QLocale::Argentina));

        gridLayout_25->addWidget(buttonSetTargetXY, 3, 0, 1, 2);

        tabWidget->addTab(TargetTab, QString());

        gridLayout_19->addWidget(tabWidget, 0, 1, 1, 1);

        frameCurrentAction = new QFrame(page);
        frameCurrentAction->setObjectName("frameCurrentAction");
        frameCurrentAction->setGeometry(QRect(390, 150, 196, 271));
        sizePolicy1.setHeightForWidth(frameCurrentAction->sizePolicy().hasHeightForWidth());
        frameCurrentAction->setSizePolicy(sizePolicy1);
        frameCurrentAction->setStyleSheet(QString::fromUtf8("QWidget#frameCurrentAction{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameCurrentAction->setFrameShape(QFrame::StyledPanel);
        frameCurrentAction->setFrameShadow(QFrame::Raised);
        gridLayout_21 = new QGridLayout(frameCurrentAction);
        gridLayout_21->setObjectName("gridLayout_21");
        labelRunTime = new QLabel(frameCurrentAction);
        labelRunTime->setObjectName("labelRunTime");
        labelRunTime->setStyleSheet(QString::fromUtf8("font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_21->addWidget(labelRunTime, 2, 0, 1, 1);

        labelCurrentActionState = new QLabel(frameCurrentAction);
        labelCurrentActionState->setObjectName("labelCurrentActionState");
        labelCurrentActionState->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"color: rgb(0, 250, 154);\n"
"background-color: transparent;"));
        labelCurrentActionState->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(labelCurrentActionState, 0, 1, 1, 2);

        labelCurrentDirection = new QLabel(frameCurrentAction);
        labelCurrentDirection->setObjectName("labelCurrentDirection");
        sizePolicy1.setHeightForWidth(labelCurrentDirection->sizePolicy().hasHeightForWidth());
        labelCurrentDirection->setSizePolicy(sizePolicy1);
        labelCurrentDirection->setStyleSheet(QString::fromUtf8("font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_21->addWidget(labelCurrentDirection, 1, 0, 1, 1);

        labelCurrentDirectionValue = new QLabel(frameCurrentAction);
        labelCurrentDirectionValue->setObjectName("labelCurrentDirectionValue");
        labelCurrentDirectionValue->setStyleSheet(QString::fromUtf8("font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"color: rgb(0, 250, 154);\n"
"background-color: transparent;"));
        labelCurrentDirectionValue->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(labelCurrentDirectionValue, 1, 1, 1, 2);

        labelCurrentAction = new QLabel(frameCurrentAction);
        labelCurrentAction->setObjectName("labelCurrentAction");
        labelCurrentAction->setStyleSheet(QString::fromUtf8("font: 13pt \"Siemens Sans\";\n"
"font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;"));

        gridLayout_21->addWidget(labelCurrentAction, 0, 0, 1, 1);

        labelRunTimeValue = new QLabel(frameCurrentAction);
        labelRunTimeValue->setObjectName("labelRunTimeValue");
        labelRunTimeValue->setStyleSheet(QString::fromUtf8("font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(96, 100, 103);\n"
"color: rgb(0, 250, 154);\n"
"background-color: transparent;"));
        labelRunTimeValue->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(labelRunTimeValue, 2, 1, 1, 2);

        frameControl = new QFrame(page);
        frameControl->setObjectName("frameControl");
        frameControl->setGeometry(QRect(180, 100, 174, 301));
        sizePolicy1.setHeightForWidth(frameControl->sizePolicy().hasHeightForWidth());
        frameControl->setSizePolicy(sizePolicy1);
        frameControl->setStyleSheet(QString::fromUtf8("QWidget#frameControl{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}"));
        frameControl->setFrameShape(QFrame::StyledPanel);
        frameControl->setFrameShadow(QFrame::Raised);
        gridLayout_23 = new QGridLayout(frameControl);
        gridLayout_23->setObjectName("gridLayout_23");
        buttonStartExploration = new QPushButton(frameControl);
        buttonStartExploration->setObjectName("buttonStartExploration");
        sizePolicy8.setHeightForWidth(buttonStartExploration->sizePolicy().hasHeightForWidth());
        buttonStartExploration->setSizePolicy(sizePolicy8);
        buttonStartExploration->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_23->addWidget(buttonStartExploration, 4, 0, 1, 1);

        buttonStopRobot = new QPushButton(frameControl);
        buttonStopRobot->setObjectName("buttonStopRobot");
        sizePolicy8.setHeightForWidth(buttonStopRobot->sizePolicy().hasHeightForWidth());
        buttonStopRobot->setSizePolicy(sizePolicy8);
        buttonStopRobot->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_23->addWidget(buttonStopRobot, 5, 0, 1, 1);

        buttonStartRun = new QPushButton(frameControl);
        buttonStartRun->setObjectName("buttonStartRun");
        sizePolicy8.setHeightForWidth(buttonStartRun->sizePolicy().hasHeightForWidth());
        buttonStartRun->setSizePolicy(sizePolicy8);
        buttonStartRun->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout_23->addWidget(buttonStartRun, 3, 0, 1, 1);

        labelRobotControl = new QLabel(frameControl);
        labelRobotControl->setObjectName("labelRobotControl");
        sizePolicy1.setHeightForWidth(labelRobotControl->sizePolicy().hasHeightForWidth());
        labelRobotControl->setSizePolicy(sizePolicy1);
        labelRobotControl->setStyleSheet(QString::fromUtf8("font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"color: rgb(222, 223, 225);\n"
"background-color: transparent;\n"
"margin-top: 2px;"));

        gridLayout_23->addWidget(labelRobotControl, 0, 0, 1, 1);

        stackedWidget->addWidget(page);

        gridLayout->addWidget(stackedWidget, 7, 1, 1, 1);

        QForm1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QForm1);
        statusbar->setObjectName("statusbar");
        QForm1->setStatusBar(statusbar);

        retranslateUi(QForm1);

        telemetryTabButton->setDefault(false);
        stackedWidget->setCurrentIndex(4);
        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QForm1);
    } // setupUi

    void retranslateUi(QMainWindow *QForm1)
    {
        QForm1->setWindowTitle(QCoreApplication::translate("QForm1", "Pathfinder HMI 3.7", nullptr));
        labelPathfinderTop->setText(QCoreApplication::translate("QForm1", "PATHFINDER", nullptr));
        labelHour->setText(QCoreApplication::translate("QForm1", "00:00:00", nullptr));
        labelVoid->setText(QString());
        OpenPortButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        comboBoxCommunication->setPlaceholderText(QCoreApplication::translate("QForm1", "USB/UART", nullptr));
        OpenWifiButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        WifiLineEdit->setInputMask(QString());
        WifiLineEdit->setText(QString());
        WifiLineEdit->setPlaceholderText(QCoreApplication::translate("QForm1", "Wifi Port", nullptr));
        labelName->setText(QCoreApplication::translate("QForm1", "GS", nullptr));
        homeTabButton->setText(QCoreApplication::translate("QForm1", "Home", nullptr));
        viewTabButton->setText(QCoreApplication::translate("QForm1", "View", nullptr));
        telemetryTabButton->setText(QCoreApplication::translate("QForm1", "Sensors", nullptr));
        PIDTabButton->setText(QCoreApplication::translate("QForm1", "Config", nullptr));
        debugTabButton->setText(QCoreApplication::translate("QForm1", "Debug", nullptr));
        heartbeatLight->setText(QCoreApplication::translate("QForm1", "Alive", nullptr));
        labelCommunication->setText(QCoreApplication::translate("QForm1", "Communication", nullptr));
        labelHomeGS->setText(QCoreApplication::translate("QForm1", "GS", nullptr));
        label->setText(QCoreApplication::translate("QForm1", "PATHFINDER", nullptr));
        labelSpeedZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelZ_A->setText(QCoreApplication::translate("QForm1", "Z", nullptr));
        labelPosY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        checkBoxAccelerometer->setText(QCoreApplication::translate("QForm1", "Read", nullptr));
        labelPosition->setText(QCoreApplication::translate("QForm1", "Position", nullptr));
        labelAccX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelAccZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelAccY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelSpeed->setText(QCoreApplication::translate("QForm1", "Speed", nullptr));
        labelX_A->setText(QCoreApplication::translate("QForm1", "X", nullptr));
        labelSpeedY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelPosZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelY_A->setText(QCoreApplication::translate("QForm1", "Y", nullptr));
        labelPosX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelAcceleration->setText(QCoreApplication::translate("QForm1", "Acceleration", nullptr));
        labelSpeedX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelMotion->setText(QCoreApplication::translate("QForm1", "Accelerometer", nullptr));
        labelY_G->setText(QCoreApplication::translate("QForm1", "Y", nullptr));
        labelAngularPosition->setText(QCoreApplication::translate("QForm1", "Angular Position [\302\260]", nullptr));
        labelGyroY->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelPitch->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroX->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroZ->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelGyroscope->setText(QCoreApplication::translate("QForm1", "Gyroscope", nullptr));
        labelYaw->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        checkBoxGyro->setText(QCoreApplication::translate("QForm1", "Read", nullptr));
        labelX_G->setText(QCoreApplication::translate("QForm1", "X", nullptr));
        labelRoll->setText(QCoreApplication::translate("QForm1", "0.000", nullptr));
        labelZ_G->setText(QCoreApplication::translate("QForm1", "Z", nullptr));
        labelAngularSpeed->setText(QCoreApplication::translate("QForm1", "Angular Speed [\302\260/s]", nullptr));
        checkBoxEngines->setText(QCoreApplication::translate("QForm1", "Read", nullptr));
        leftEngineLabel->setText(QCoreApplication::translate("QForm1", "Left", nullptr));
        powerButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        leftEnginePowerLabel->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        rightEnginePowerLabel->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        rightEngineLabel->setText(QCoreApplication::translate("QForm1", "Right", nullptr));
        enginesLabel->setText(QCoreApplication::translate("QForm1", "Engines", nullptr));
        labelNameIR5->setText(QCoreApplication::translate("QForm1", "5", nullptr));
        labelValueIR3->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR2->setText(QCoreApplication::translate("QForm1", "2", nullptr));
        labelValueIR2->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR7->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR8->setText(QCoreApplication::translate("QForm1", "8", nullptr));
        labelNameIR1->setText(QCoreApplication::translate("QForm1", "1", nullptr));
        labelNameIR7->setText(QCoreApplication::translate("QForm1", "7", nullptr));
        labelValueIR6->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR4->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelValueIR1->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR6->setText(QCoreApplication::translate("QForm1", "6", nullptr));
        labelValueIR5->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        labelNameIR4->setText(QCoreApplication::translate("QForm1", "4", nullptr));
        labelNameIR3->setText(QCoreApplication::translate("QForm1", "3", nullptr));
        labelValueIR8->setText(QCoreApplication::translate("QForm1", "0", nullptr));
        checkBoxIR->setText(QCoreApplication::translate("QForm1", "Read", nullptr));
        buttonInfrared->setText(QCoreApplication::translate("QForm1", "Infrared", nullptr));
        labelDiagonalThreshold->setText(QCoreApplication::translate("QForm1", "Diagonal", nullptr));
        labelFrontThreshold->setText(QCoreApplication::translate("QForm1", "Front", nullptr));
        labelLeftThreshold->setText(QCoreApplication::translate("QForm1", "Left", nullptr));
        labelLateralThreshold->setText(QCoreApplication::translate("QForm1", "Lateral", nullptr));
        labelRightThreshold->setText(QCoreApplication::translate("QForm1", "Right", nullptr));
        readThresholdButton->setText(QCoreApplication::translate("QForm1", "READ", nullptr));
        setThresholdButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        changeThresholdUnitButton->setText(QCoreApplication::translate("QForm1", "RAW", nullptr));
        labelThresholds->setText(QCoreApplication::translate("QForm1", "Thresholds", nullptr));
        labelPrescaler->setText(QCoreApplication::translate("QForm1", "Prescaler", nullptr));
        labelPeriod->setText(QCoreApplication::translate("QForm1", "Period", nullptr));
        labelResultingFrequency->setText(QCoreApplication::translate("QForm1", "Resulting Frequency", nullptr));
        labelTimerFreqResult->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        pwmConfigButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        changeConfigWidgetButton->setText(QCoreApplication::translate("QForm1", "Engines Timer Configuration", nullptr));
        batteryVoltageSpinBox->setSuffix(QCoreApplication::translate("QForm1", " Volts", nullptr));
        setBatteryVoltageButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        label_2->setText(QCoreApplication::translate("QForm1", "Update Current Voltage", nullptr));
        labelWallPID->setText(QCoreApplication::translate("QForm1", "Wall PID", nullptr));
        labelPIDValues->setText(QCoreApplication::translate("QForm1", "PID Values", nullptr));
        labelKD->setText(QCoreApplication::translate("QForm1", "KD", nullptr));
        labelKP->setText(QCoreApplication::translate("QForm1", "KP", nullptr));
        labelMaxOut->setText(QCoreApplication::translate("QForm1", "Max. Out", nullptr));
        labelBaseOut->setText(QCoreApplication::translate("QForm1", "Base Out", nullptr));
        labelKI->setText(QCoreApplication::translate("QForm1", "KI", nullptr));
        readStopPIDButton->setText(QCoreApplication::translate("QForm1", "READ", nullptr));
        readTurnPIDButton->setText(QCoreApplication::translate("QForm1", "READ", nullptr));
        labelMinOut->setText(QCoreApplication::translate("QForm1", "Min. Out", nullptr));
        readWallPIDButton->setText(QCoreApplication::translate("QForm1", "READ", nullptr));
        setWallPIDButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        setTurnPIDButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        labelTurnPID->setText(QCoreApplication::translate("QForm1", "Turn PID", nullptr));
        setStopPIDButton->setText(QCoreApplication::translate("QForm1", "SET", nullptr));
        labelStopPID->setText(QCoreApplication::translate("QForm1", "Stop PID", nullptr));
        labelFirmware->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        labelSoftwareVersion->setText(QCoreApplication::translate("QForm1", "3.7", nullptr));
        labelFirmwareVersion->setText(QCoreApplication::translate("QForm1", "Firmware Version", nullptr));
        labelSoftware->setText(QCoreApplication::translate("QForm1", "HMI Software Version", nullptr));
        SendCommandButton->setText(QCoreApplication::translate("QForm1", "SEND", nullptr));
        aliveButton->setText(QCoreApplication::translate("QForm1", "ALIVE", nullptr));
        labelCommand->setText(QCoreApplication::translate("QForm1", "Command", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QCoreApplication::translate("QForm1", "3D View", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("QForm1", "2D View", nullptr));
        labelStartDir->setText(QCoreApplication::translate("QForm1", "Direction", nullptr));
        labelMazeStart->setText(QCoreApplication::translate("QForm1", "Maze Start", nullptr));
        comboBoxStartDir->setItemText(0, QCoreApplication::translate("QForm1", "NORTH", nullptr));
        comboBoxStartDir->setItemText(1, QCoreApplication::translate("QForm1", "EAST", nullptr));
        comboBoxStartDir->setItemText(2, QCoreApplication::translate("QForm1", "SOUTH", nullptr));
        comboBoxStartDir->setItemText(3, QCoreApplication::translate("QForm1", "WEST", nullptr));

        labelStartY->setText(QCoreApplication::translate("QForm1", " Start Y ", nullptr));
        labelStartX->setText(QCoreApplication::translate("QForm1", " Start X ", nullptr));
        buttonSetStart->setText(QCoreApplication::translate("QForm1", "SET START", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(StartTab), QCoreApplication::translate("QForm1", "Start", nullptr));
        labelMazeTarget->setText(QCoreApplication::translate("QForm1", "Maze Target", nullptr));
        spinBoxTargetX->setSpecialValueText(QString());
        labelTargetX->setText(QCoreApplication::translate("QForm1", "Target X", nullptr));
        labelTargetY->setText(QCoreApplication::translate("QForm1", "Target Y", nullptr));
        buttonSetTargetXY->setText(QCoreApplication::translate("QForm1", "SET TARGET", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TargetTab), QCoreApplication::translate("QForm1", "Target", nullptr));
        labelRunTime->setText(QCoreApplication::translate("QForm1", "Run Time", nullptr));
        labelCurrentActionState->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        labelCurrentDirection->setText(QCoreApplication::translate("QForm1", "Current Direction", nullptr));
        labelCurrentDirectionValue->setText(QCoreApplication::translate("QForm1", "-", nullptr));
        labelCurrentAction->setText(QCoreApplication::translate("QForm1", "Current Action", nullptr));
        labelRunTimeValue->setText(QCoreApplication::translate("QForm1", "00:00", nullptr));
        buttonStartExploration->setText(QCoreApplication::translate("QForm1", "START EXPLORATION", nullptr));
        buttonStopRobot->setText(QCoreApplication::translate("QForm1", "STOP", nullptr));
        buttonStartRun->setText(QCoreApplication::translate("QForm1", "START RUN", nullptr));
        labelRobotControl->setText(QCoreApplication::translate("QForm1", "Robot Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QForm1: public Ui_QForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORM1_H
