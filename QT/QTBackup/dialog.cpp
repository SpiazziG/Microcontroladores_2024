#include "dialog.h"
#include "ui_dialog.h"
#include "qcustomplot.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_colorIndex(0)
{
    ui->setupUi(this);

    // ui->listWidgetSignals->setStyle(QStyleFactory::create("Fusion"));

    // Hacemos que los ítems fluyan de izquierda a derecha y salten a la siguiente línea
    ui->listWidgetSignals->setFlow(QListView::LeftToRight);
    ui->listWidgetSignals->setWrapping(true);
    ui->listWidgetSignals->setResizeMode(QListView::Adjust);
    ui->listWidgetSignals->setSpacing(5); // Un pequeño espacio entre elementos

    // --- LAS 3 LÍNEAS SALVAVIDAS ---

    // 2. PROHIBIDO RECORTAR TEXTO: Esto apaga los "..." para siempre
    ui->listWidgetSignals->setTextElideMode(Qt::ElideNone);

    // 3. FORZAR LA CUADRÍCULA: (Ancho, Alto)
    // 140px de ancho suele ser suficiente para "IR Sensor X", ajústalo si es necesario.
    ui->listWidgetSignals->setGridSize(QSize(140, 40));

    // 1. LOS COLORES DE TUS LÍNEAS (Tus "Textos en color")
    m_colors << QColor(0, 255, 255)   // Cyan
             << QColor(124, 252, 0)   // Verde claro
             << QColor(255, 165, 0)   // Naranja
             << QColor(255, 0, 255)   // Magenta
             << QColor(255, 255, 0)   // Amarillo
             << QColor(0, 250, 154);  // Verde Menta

    // 2. PALETA DE LA INTERFAZ
    QColor fondoOscuro(33, 37, 40);   // Fondo de la ventana
    QColor fondoMedio(46, 49, 55);    // Fondo del área del gráfico
    QColor fondoClaro(57, 63, 68);    // Fondo de la leyenda
    QColor textoNormal(222, 223, 225);
    QColor textoMuteado(96, 100, 103);

    // Fondos
    ui->customPlot->setBackground(QBrush(fondoOscuro));
    ui->customPlot->axisRect()->setBackground(QBrush(fondoMedio));

    // Lápices para dibujar los ejes y la cuadrícula
    QPen penEjes(textoMuteado, 1);
    // Cuadrícula: Mismo color muteado pero punteado
    QPen penGrid(textoMuteado, 1, Qt::DotLine);

    // EJE X (Abajo)
    ui->customPlot->xAxis->setBasePen(penEjes);
    ui->customPlot->xAxis->setTickPen(penEjes);
    ui->customPlot->xAxis->setSubTickPen(penEjes);
    ui->customPlot->xAxis->setTickLabelColor(textoNormal); // Los números
    ui->customPlot->xAxis->setLabelColor(textoNormal);     // El nombre del eje
    ui->customPlot->xAxis->grid()->setPen(penGrid);        // La cuadrícula interna

    // EJE Y (Izquierda)
    ui->customPlot->yAxis->setBasePen(penEjes);
    ui->customPlot->yAxis->setTickPen(penEjes);
    ui->customPlot->yAxis->setSubTickPen(penEjes);
    ui->customPlot->yAxis->setTickLabelColor(textoNormal);
    ui->customPlot->yAxis->setLabelColor(textoNormal);
    ui->customPlot->yAxis->grid()->setPen(penGrid);

    // Ejes superiores y derechos (Para cerrar el "cuadrado" visualmente)
    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->xAxis2->setBasePen(penEjes);
    ui->customPlot->xAxis2->setTickPen(penEjes);
    ui->customPlot->xAxis2->setSubTickPen(penEjes);

    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setBasePen(penEjes);
    ui->customPlot->yAxis2->setTickPen(penEjes);
    ui->customPlot->yAxis2->setSubTickPen(penEjes);

    // Leyenda (El cuadrito que te dice qué color es qué sensor)
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setBrush(QBrush(fondoClaro)); // Fondo
    ui->customPlot->legend->setBorderPen(penEjes);        // Borde
    ui->customPlot->legend->setTextColor(textoNormal);    // Letras

    // 2. Configurar QCustomPlot
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); // Zoom y arrastre con ratón
    ui->customPlot->legend->setVisible(true); // Mostrar leyenda

    // 3. Conectar la lista de la interfaz con nuestro slot
    connect(ui->listWidgetSignals, &QListWidget::itemChanged, this, &Dialog::onSignalSelectionChanged);

    connect(ui->buttonClear, &QPushButton::clicked, this, [this](){
        // 1. Limpiamos los vectores de datos internos del diálogo
        for(auto it = m_data.begin(); it != m_data.end(); ++it) {
            it.value().clear();
        }

        // 2. Limpiamos los datos de los gráficos que están activos ahora mismo
        for(QCPGraph* graph : m_activeGraphs.values()) {
            graph->data()->clear();
        }

        // 3. Refrescamos el gráfico para que se vea vacío
        ui->customPlot->replot();


        // Avisamos a la ventana principal que reinicie el tiempo
        emit requestResetTimer();
    });
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::setSignalData(const QMap<QString, QVector<QPointF>>& data){
    m_data = data;
    ui->listWidgetSignals->clear();
    ui->customPlot->clearGraphs();
    m_activeGraphs.clear();
    m_colorIndex = 0;

    // 1. El orden físico exacto de tu micromouse
    // Usamos "HUECO" como palabra clave para los espacios vacíos
    QStringList ordenFisico = {
        "IR Sensor 6", "IR Sensor 5", "IR Sensor 4", "IR Sensor 3", "IR Sensor 2",
        "IR Sensor 7", "HUECO",       "IR Sensor 8", "HUECO",       "IR Sensor 1"
    };

    // 2. Insertamos los ítems en ese orden estricto
    for (const QString& signalName : ordenFisico) {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidgetSignals);

        if (signalName == "HUECO") {
            // --- ÍTEM FANTASMA ---
            // Le quitamos todos los flags para que no tenga checkbox ni se pueda seleccionar
            item->setFlags(Qt::NoItemFlags);
            item->setText("");
        }
        else if (m_data.contains(signalName)) {
            // --- SENSOR REAL ---
            item->setText(signalName);
            item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
            item->setCheckState(Qt::Unchecked);
        }
    }

    // 3. RESPALDO: Por si envías otros datos que no sean IR (ej: Gyro X, Batería)
    // Los agregará al final para no romper tu diseño visual.
    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        if (!ordenFisico.contains(it.key())) {
            QListWidgetItem *item = new QListWidgetItem(it.key(), ui->listWidgetSignals);
            item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
            item->setCheckState(Qt::Unchecked);
        }
    }

    ui->customPlot->replot();
}

void Dialog::onSignalSelectionChanged(QListWidgetItem *item)
{
    QString signalName = item->text();

    if (signalName.isEmpty() || !m_data.contains(signalName)) return;

    if (item->checkState() == Qt::Checked) {
        // --- DIBUJAR LÍNEA ---
        if (!m_activeGraphs.contains(signalName)) {
            QCPGraph *graph = ui->customPlot->addGraph();
            graph->setName(signalName);

            // Asignar color y grosor
            QPen pen;
            pen.setColor(m_colors[m_colorIndex % m_colors.size()]);
            pen.setWidth(2);
            graph->setPen(pen);
            m_colorIndex++;

            // QCustomPlot pide vectores separados de X e Y (double)
            QVector<double> x, y;
            const QVector<QPointF>& points = m_data.value(signalName);
            x.reserve(points.size());
            y.reserve(points.size());

            for (const QPointF& p : points) {
                x.append(p.x());
                y.append(p.y());
            }

            graph->setData(x, y);
            m_activeGraphs.insert(signalName, graph);
        }
    } else {
        // --- BORRAR LÍNEA ---
        if (m_activeGraphs.contains(signalName)) {
            QCPGraph *graph = m_activeGraphs.take(signalName);
            ui->customPlot->removeGraph(graph);
        }
    }

    // Ajustar la vista para que todo quepa en pantalla y refrescar
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}

void Dialog::addLiveTelemetry(const QString& signalName, double x, double y)
{
    // 1. Lo guardamos en la memoria del diálogo para no perderlo si apagas y prendes el checkbox
    if (m_data.contains(signalName)) {
        m_data[signalName].append(QPointF(x, y));
    }

    // 2. Si el usuario tiene la línea encendida ahora mismo, le añadimos el punto al QCustomPlot
    if (m_activeGraphs.contains(signalName)) {
        m_activeGraphs[signalName]->addData(x, y);
    }
}

void Dialog::refreshPlot()
{
    // Esto obliga al gráfico a recalcular la cámara para que el nuevo punto no se dibuje fuera de la pantalla
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}
// void Dialog::on_pushButton_clicked()
// {

//     emit takeDeg(Deg);
// }


// void Dialog::on_pushButton_2_clicked()
// {
//     emit powEng(PowEng1, PowEng2);
// }

// void Dialog::on_pushButton_maxMS_clicked()
// {
//     emit configMaxMin(min, max);
// }


// void Dialog::on_pushButton_read_clicked()
// {
//     emit readMaxMin();
// }

// void Dialog::displayMaxMin(uint16_t min, uint16_t max){
// }

