#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDataVisualization>
#include <QFile>
#include <QObject>
#include <QTextStream>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

