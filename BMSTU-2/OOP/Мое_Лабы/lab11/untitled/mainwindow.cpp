#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMessageBox"

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

void MainWindow::replaceVal1(){
    ui->dial->setValue(val1);
    ui->spinBox->setValue(val1);
    ui->textEdit->insertPlainText("\n"+QString::number(val1));
}

void MainWindow::on_dial_valueChanged(int value)
{
    if (abs(val1 - value) > 5){
        val1 = value;
        replaceVal1();
    }
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
        val1 = arg1;
        replaceVal1();
}
void MainWindow::on_pushButton_clicked()
{
     if( QMessageBox::question ( this, QString(), "Завершить приложение?", QMessageBox::Yes|QMessageBox::No) ==
     QMessageBox::Yes )
     exit(0);
     else show();
}

void MainWindow::replaceVal2(){
    ui->dial_2->setValue(val2);
    ui->spinBox_2->setValue(val2);
    ui->textEdit_2->insertPlainText("\n"+QString::number(val2));
}

void MainWindow::on_dial_2_valueChanged(int value)
{
    if (abs(val2 - value) > 5){
        val2 = value;
        replaceVal2();
    }
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
        val2 = arg1;
        replaceVal2();
}


void MainWindow::on_pushButton_2_clicked()
{
     if( QMessageBox::question ( this, QString(), "Завершить приложение?", QMessageBox::Yes|QMessageBox::No) ==
     QMessageBox::Yes )
     exit(0);
     else show();
}
