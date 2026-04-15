#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMap>
#include <QVector>
#include <QPointF>

class QListWidgetItem;
class QCPGraph;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void setSignalData(const QMap<QString, QVector<QPointF>>& data);

    void addLiveTelemetry(const QString& signalName, double x, double y);

    void refreshPlot();

signals:
    void requestResetTimer();
    // void takeDeg(int8_t servDeg);

    // void powEng(int32_t eng1, int32_t eng2);

    // void configMaxMin(uint16_t min, uint16_t max);

    // void readMaxMin();

public slots:
    // void displayMaxMin(uint16_t min, uint16_t max);

private slots:

    void onSignalSelectionChanged(QListWidgetItem *item);

private:
    Ui::Dialog *ui;

    QMap<QString, QVector<QPointF>> m_data;
    QMap<QString, QCPGraph*> m_activeGraphs;

    QVector<QColor> m_colors;
    int m_colorIndex;
};

#endif // DIALOG_H
