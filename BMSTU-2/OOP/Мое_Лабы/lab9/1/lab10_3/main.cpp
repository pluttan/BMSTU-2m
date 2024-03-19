#include <QApplication>
#include <QWidget>
#include <QString>
#include <QStringLiteral>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QtDataVisualization>
#include "mainwindow.h"

void plotVectors(QVector<double> X, QVector<double> Y, QVector<double> Z)
{
    Q3DSurface *graph = new Q3DSurface();
    QWidget *container = QWidget::createWindowContainer(graph);
    container->setMinimumSize(640, 480);
    container->setWindowTitle(QStringLiteral("3D Surface Example"));

    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(X.size());
    for (int i = 0; i < X.size(); i++) {
        QSurfaceDataRow *dataRow = new QSurfaceDataRow(1);
        (*dataRow)[0].setPosition(QVector3D(X[i], Y[i], Z[i]));
        dataArray->append(dataRow);
    }

    QSurfaceDataProxy *dataProxy = new QSurfaceDataProxy();
    dataProxy->resetArray(dataArray);

    QSurface3DSeries *series = new QSurface3DSeries();
    series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    series->setFlatShadingEnabled(true);
//    series->setSu(dataProxy);

    graph->addSeries(series);

    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    hLayout->addWidget(container, 1);
    widget->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q3DSurface *graph = new Q3DSurface();
    QWidget *container = QWidget::createWindowContainer(graph);
    container->setMinimumSize(640, 480);
    container->setWindowTitle(QStringLiteral("3D Surface Example"));
    QVector<double> X{1,2,3};
    QVector<double> Y{1,2,3};
    QVector<double> Z{1,2,3};
    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(X.size());
    for (int i = 0; i < X.size(); i++) {
        QSurfaceDataRow *dataRow = new QSurfaceDataRow(1);
        (*dataRow)[0].setPosition(QVector3D(X[i], Y[i], Z[i]));
        dataArray->append(dataRow);
    }

    QSurfaceDataProxy *dataProxy = new QSurfaceDataProxy();
    dataProxy->resetArray(dataArray);

    QSurface3DSeries *series = new QSurface3DSeries();
    series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    series->setFlatShadingEnabled(true);
    series->dataProxy()->addRows(dataArray);

    graph->addSeries(series);

    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    hLayout->addWidget(container, 1);
    widget->show();
    return a.exec();
}

