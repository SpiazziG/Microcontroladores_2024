/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QSpinBox *spinBox_minMS;
    QSpinBox *spinBox_maxMS;
    QLabel *label_5;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLCDNumber *lcdNumber_maxMS;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLCDNumber *lcdNumber_minMS;
    QPushButton *pushButton_read;
    QPushButton *pushButton_maxMS;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(549, 198);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 31, 49);"));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 1, 1, 1, 1);

        spinBox_minMS = new QSpinBox(Dialog);
        spinBox_minMS->setObjectName("spinBox_minMS");
        spinBox_minMS->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));

        gridLayout_2->addWidget(spinBox_minMS, 2, 1, 1, 1);

        spinBox_maxMS = new QSpinBox(Dialog);
        spinBox_maxMS->setObjectName("spinBox_maxMS");
        spinBox_maxMS->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));

        gridLayout_2->addWidget(spinBox_maxMS, 2, 2, 1, 1);

        label_5 = new QLabel(Dialog);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 1, 2, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName("spinBox");
        spinBox->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));

        gridLayout_2->addWidget(spinBox, 2, 0, 1, 1);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        gridLayout_2->addWidget(pushButton, 3, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(Dialog);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));

        horizontalLayout_5->addWidget(label_6);

        lcdNumber_maxMS = new QLCDNumber(Dialog);
        lcdNumber_maxMS->setObjectName("lcdNumber_maxMS");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lcdNumber_maxMS->sizePolicy().hasHeightForWidth());
        lcdNumber_maxMS->setSizePolicy(sizePolicy2);
        lcdNumber_maxMS->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdNumber_maxMS->setFrameShape(QFrame::NoFrame);
        lcdNumber_maxMS->setFrameShadow(QFrame::Sunken);
        lcdNumber_maxMS->setDigitCount(4);

        horizontalLayout_5->addWidget(lcdNumber_maxMS);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(Dialog);
        label_7->setObjectName("label_7");
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));

        horizontalLayout_6->addWidget(label_7);

        lcdNumber_minMS = new QLCDNumber(Dialog);
        lcdNumber_minMS->setObjectName("lcdNumber_minMS");
        sizePolicy2.setHeightForWidth(lcdNumber_minMS->sizePolicy().hasHeightForWidth());
        lcdNumber_minMS->setSizePolicy(sizePolicy2);
        lcdNumber_minMS->setStyleSheet(QString::fromUtf8("color: rgb(0, 232, 0);\n"
"background-color: rgb(0, 0, 0);"));
        lcdNumber_minMS->setFrameShape(QFrame::NoFrame);
        lcdNumber_minMS->setFrameShadow(QFrame::Sunken);
        lcdNumber_minMS->setDigitCount(4);

        horizontalLayout_6->addWidget(lcdNumber_minMS);


        verticalLayout_4->addLayout(horizontalLayout_6);

        pushButton_read = new QPushButton(Dialog);
        pushButton_read->setObjectName("pushButton_read");
        pushButton_read->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        verticalLayout_4->addWidget(pushButton_read);


        gridLayout_2->addLayout(verticalLayout_4, 1, 3, 3, 1);

        pushButton_maxMS = new QPushButton(Dialog);
        pushButton_maxMS->setObjectName("pushButton_maxMS");
        pushButton_maxMS->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        gridLayout_2->addWidget(pushButton_maxMS, 3, 1, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_3);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"color: rgb(172, 173, 183);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        spinBox_2 = new QSpinBox(Dialog);
        spinBox_2->setObjectName("spinBox_2");
        sizePolicy3.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy3);
        spinBox_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));

        horizontalLayout_8->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(Dialog);
        spinBox_3->setObjectName("spinBox_3");
        sizePolicy3.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy3);
        spinBox_3->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(0, 0 ,0);\n"
"color: rgb(0, 232, 0);"));

        horizontalLayout_8->addWidget(spinBox_3);


        verticalLayout_5->addLayout(horizontalLayout_8);

        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 9pt \"MS Sans Serif\";\n"
"background-color: rgb(189, 206, 214);\n"
"color: rgb(47, 55, 77);"));

        verticalLayout_5->addWidget(pushButton_2);


        verticalLayout->addLayout(verticalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "SET MIN MS", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "SET MAX MS", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "SERVO ANGLE", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "SEND ANGLE", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "MAX MS", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "MIN MS", nullptr));
        pushButton_read->setText(QCoreApplication::translate("Dialog", "READ MAX && MIN", nullptr));
        pushButton_maxMS->setText(QCoreApplication::translate("Dialog", "SET MAX && MIN MS", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "ENGINE 2 POWER", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "ENGINE 1 POWER", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "SEND POWER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
