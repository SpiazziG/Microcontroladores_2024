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
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLabel *label_6;
    QLCDNumber *lcdIR3;
    QLCDNumber *lcdIR1;
    QLabel *label_5;
    QLCDNumber *lcdDistance;
    QPushButton *powerButton;
    QSlider *RightEngineSlide;
    QPushButton *aliveButton;
    QLabel *label_3;
    QSlider *LeftEngineSlide;
    QLCDNumber *lcdIR2;
    QLabel *label_4;
    QLabel *label_8;
    QPushButton *pushButtonUDP;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_10;
    QFrame *line;
    QLabel *label_9;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QFrame *line_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QForm1)
    {
        if (QForm1->objectName().isEmpty())
            QForm1->setObjectName("QForm1");
        QForm1->resize(620, 450);
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
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, -1);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        plainTextEdit->setToolTipDuration(-1);
        plainTextEdit->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setLineWidth(1);
        plainTextEdit->setCursorWidth(1);

        verticalLayout_3->addWidget(plainTextEdit);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_7, 3, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_6, 3, 1, 1, 1);

        lcdIR3 = new QLCDNumber(centralwidget);
        lcdIR3->setObjectName("lcdIR3");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lcdIR3->sizePolicy().hasHeightForWidth());
        lcdIR3->setSizePolicy(sizePolicy2);
        lcdIR3->setMinimumSize(QSize(89, 23));
        lcdIR3->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR3->setFrameShape(QFrame::Box);
        lcdIR3->setFrameShadow(QFrame::Sunken);
        lcdIR3->setDigitCount(1);
        lcdIR3->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_4->addWidget(lcdIR3, 5, 2, 1, 1);

        lcdIR1 = new QLCDNumber(centralwidget);
        lcdIR1->setObjectName("lcdIR1");
        sizePolicy2.setHeightForWidth(lcdIR1->sizePolicy().hasHeightForWidth());
        lcdIR1->setSizePolicy(sizePolicy2);
        lcdIR1->setMinimumSize(QSize(108, 23));
        lcdIR1->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR1->setFrameShape(QFrame::Box);
        lcdIR1->setFrameShadow(QFrame::Sunken);
        lcdIR1->setDigitCount(1);
        lcdIR1->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_4->addWidget(lcdIR1, 5, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        lcdDistance = new QLCDNumber(centralwidget);
        lcdDistance->setObjectName("lcdDistance");
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lcdDistance->sizePolicy().hasHeightForWidth());
        lcdDistance->setSizePolicy(sizePolicy4);
        QFont font;
        font.setBold(false);
        lcdDistance->setFont(font);
        lcdDistance->setFocusPolicy(Qt::NoFocus);
        lcdDistance->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdDistance->setFrameShape(QFrame::Box);
        lcdDistance->setFrameShadow(QFrame::Sunken);
        lcdDistance->setDigitCount(3);
        lcdDistance->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_4->addWidget(lcdDistance, 0, 1, 1, 1);

        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName("powerButton");
        sizePolicy4.setHeightForWidth(powerButton->sizePolicy().hasHeightForWidth());
        powerButton->setSizePolicy(sizePolicy4);
        powerButton->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Sans Serif\";\n"
"font-weight: bold;\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        gridLayout_4->addWidget(powerButton, 1, 2, 2, 1);

        RightEngineSlide = new QSlider(centralwidget);
        RightEngineSlide->setObjectName("RightEngineSlide");
        sizePolicy3.setHeightForWidth(RightEngineSlide->sizePolicy().hasHeightForWidth());
        RightEngineSlide->setSizePolicy(sizePolicy3);
        RightEngineSlide->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background-color: rgb(196,219,50);\n"
"	height: 7px;\n"
"    width: 90px;\n"
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

        gridLayout_4->addWidget(RightEngineSlide, 2, 1, 1, 1);

        aliveButton = new QPushButton(centralwidget);
        aliveButton->setObjectName("aliveButton");
        sizePolicy4.setHeightForWidth(aliveButton->sizePolicy().hasHeightForWidth());
        aliveButton->setSizePolicy(sizePolicy4);
        aliveButton->setFocusPolicy(Qt::StrongFocus);
        aliveButton->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Sans Serif\";\n"
"font-weight: bold;\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        gridLayout_4->addWidget(aliveButton, 0, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        LeftEngineSlide = new QSlider(centralwidget);
        LeftEngineSlide->setObjectName("LeftEngineSlide");
        sizePolicy3.setHeightForWidth(LeftEngineSlide->sizePolicy().hasHeightForWidth());
        LeftEngineSlide->setSizePolicy(sizePolicy3);
        LeftEngineSlide->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background-color: rgb(196,219,50);\n"
"	height: 7px;\n"
"    width: 90px;\n"
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
        LeftEngineSlide->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(LeftEngineSlide, 1, 1, 1, 1);

        lcdIR2 = new QLCDNumber(centralwidget);
        lcdIR2->setObjectName("lcdIR2");
        sizePolicy2.setHeightForWidth(lcdIR2->sizePolicy().hasHeightForWidth());
        lcdIR2->setSizePolicy(sizePolicy2);
        lcdIR2->setMinimumSize(QSize(84, 23));
        lcdIR2->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdIR2->setFrameShape(QFrame::Box);
        lcdIR2->setFrameShadow(QFrame::Sunken);
        lcdIR2->setDigitCount(1);
        lcdIR2->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_4->addWidget(lcdIR2, 5, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_8, 3, 2, 1, 1);

        pushButtonUDP = new QPushButton(centralwidget);
        pushButtonUDP->setObjectName("pushButtonUDP");
        sizePolicy4.setHeightForWidth(pushButtonUDP->sizePolicy().hasHeightForWidth());
        pushButtonUDP->setSizePolicy(sizePolicy4);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setItalic(false);
        pushButtonUDP->setFont(font1);
        pushButtonUDP->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Sans Serif\";\n"
"font-weight: bold;\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        gridLayout_4->addWidget(pushButtonUDP, 6, 2, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        sizePolicy4.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy4);
        lineEdit->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lineEdit->setMaxLength(32767);

        gridLayout_4->addWidget(lineEdit, 6, 0, 1, 2);


        verticalLayout_3->addLayout(gridLayout_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, -1, 0, -1);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);

        verticalLayout_8->addWidget(widget);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy6);
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Sans Serif\";\n"
"font-weight: bold;\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        verticalLayout_8->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout_8);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

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
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy7);
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

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));
        comboBox->setFrame(true);

        verticalLayout_7->addWidget(comboBox);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));
        pushButton->setFlat(false);

        verticalLayout_7->addWidget(pushButton);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_2);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));

        verticalLayout_6->addWidget(comboBox_2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        verticalLayout_6->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout_6);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 119, 76);"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 2, 0, 1, 1);

        QForm1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QForm1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 620, 21));
        QForm1->setMenuBar(menubar);
        statusbar = new QStatusBar(QForm1);
        statusbar->setObjectName("statusbar");
        QForm1->setStatusBar(statusbar);

        retranslateUi(QForm1);

        QMetaObject::connectSlotsByName(QForm1);
    } // setupUi

    void retranslateUi(QMainWindow *QForm1)
    {
        QForm1->setWindowTitle(QCoreApplication::translate("QForm1", "QForm1", nullptr));
        label_7->setText(QCoreApplication::translate("QForm1", "IR 1 (RIGHT)", nullptr));
        label_6->setText(QCoreApplication::translate("QForm1", "IR 2", nullptr));
        label_5->setText(QCoreApplication::translate("QForm1", "RIGHT ENGINE", nullptr));
        powerButton->setText(QCoreApplication::translate("QForm1", "ENGINES &&\n"
" SERVO", nullptr));
        aliveButton->setText(QCoreApplication::translate("QForm1", "ALIVE", nullptr));
        label_3->setText(QCoreApplication::translate("QForm1", "DISTANCE", nullptr));
        label_4->setText(QCoreApplication::translate("QForm1", "LEFT ENGINE", nullptr));
        label_8->setText(QCoreApplication::translate("QForm1", "IR 3 (LEFT)", nullptr));
        pushButtonUDP->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("QForm1", "Wifi", nullptr));
        pushButton_3->setText(QCoreApplication::translate("QForm1", "CLEAR", nullptr));
        label_9->setText(QCoreApplication::translate("QForm1", "MICROCONTROLADORES", nullptr));
        label->setText(QCoreApplication::translate("QForm1", "COM PORT", nullptr));
        pushButton->setText(QCoreApplication::translate("QForm1", "OPEN", nullptr));
        label_2->setText(QCoreApplication::translate("QForm1", "CMD", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QForm1", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QForm1: public Ui_QForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORM1_H
