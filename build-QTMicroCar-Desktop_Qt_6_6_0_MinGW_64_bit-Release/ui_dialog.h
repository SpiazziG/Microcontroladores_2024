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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QFrame *framePlot;
    QGridLayout *gridLayout_2;
    QCustomPlot *customPlot;
    QListWidget *listWidgetSignals;
    QPushButton *buttonClear;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(720, 401);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMaximumSize(QSize(720, 16777215));
        Dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 37, 40);\n"
"border: 2px solid rgb(150, 150, 150);\n"
"border-radius: 5px;"));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        framePlot = new QFrame(Dialog);
        framePlot->setObjectName("framePlot");
        framePlot->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;"));
        framePlot->setFrameShape(QFrame::Panel);
        framePlot->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(framePlot);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        customPlot = new QCustomPlot(framePlot);
        customPlot->setObjectName("customPlot");
        customPlot->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(customPlot, 0, 0, 1, 1);


        gridLayout->addWidget(framePlot, 0, 0, 1, 1);

        listWidgetSignals = new QListWidget(Dialog);
        listWidgetSignals->setObjectName("listWidgetSignals");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidgetSignals->sizePolicy().hasHeightForWidth());
        listWidgetSignals->setSizePolicy(sizePolicy1);
        listWidgetSignals->setMaximumSize(QSize(16777215, 115));
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        font.setPointSize(13);
        font.setBold(true);
        listWidgetSignals->setFont(font);
        listWidgetSignals->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"border: 2px solid rgb(150, 150, 150);\n"
"background-color: rgb(57, 63, 68);\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"/* 1. El texto y el margen que ya ten\303\255as */\n"
"QListWidget:item {\n"
"    font: 13pt \"Century Gothic\";\n"
"    font-weight: bold;\n"
"    color: rgb(222, 223, 225);\n"
"    background-color: transparent;\n"
"    margin-right: 8px;\n"
"	margin-top: 2px;\n"
"}\n"
"\n"
"/* 2. El recuadro vac\303\255o (apagado) */\n"
"QListWidget::indicator {\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border: 2px solid #393F44; /* El gris de tus bordes */\n"
"    border-radius: 3px;\n"
"    background-color: #22262a; /* El color de tu powerBar */\n"
"}\n"
"\n"
"/* 3. El recuadro cuando pasas el mouse por encima (hover) */\n"
"QListWidget::indicator:hover {\n"
"    border: 2px solid #00FA9A; /* Se ilumina en verde menta */\n"
"}\n"
"\n"
"/* 4. El recuadro cuando est\303\241 activado (tildado) */\n"
"QListWidget::indicator:checked {\n"
"    background-color: #00FA9A; /* Se llena de ve"
                        "rde menta */\n"
"    border: 2px solid #00FA9A;\n"
"}"));
        listWidgetSignals->setFrameShape(QFrame::StyledPanel);
        listWidgetSignals->setFrameShadow(QFrame::Plain);
        listWidgetSignals->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidgetSignals->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidgetSignals->setLayoutMode(QListView::SinglePass);

        gridLayout->addWidget(listWidgetSignals, 1, 0, 1, 1);

        buttonClear = new QPushButton(Dialog);
        buttonClear->setObjectName("buttonClear");
        buttonClear->setStyleSheet(QString::fromUtf8("font: 12pt \"Century Gothic\";\n"
"font-weight: bold;\n"
"background-color: rgb(57, 63, 68);\n"
"color: rgb(227, 227, 229);"));

        gridLayout->addWidget(buttonClear, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        buttonClear->setText(QCoreApplication::translate("Dialog", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
