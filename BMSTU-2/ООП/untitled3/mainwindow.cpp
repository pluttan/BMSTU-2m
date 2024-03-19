#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <typeinfo>
#include <cctype>
#include <QString>
#include <QChar>
#include <QLocale>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->lineEdit->setStyle(new MyProxy());
connect(ui->lineEdit, &QLineEdit::editingFinished,this,&MainWindow::Changed);
connect(ui->pushButton, &QPushButton::clicked,this,&MainWindow::click);
new Ui::MainWindow;
}

MainWindow::~MainWindow()
{
delete ui;
}
void MainWindow::click()
{
list.print(ui->listWidget);
}

void MainWindow::on_pushButton_3_clicked()
{
ui->listWidget->clear();
}


void MainWindow::on_pushButton_4_clicked()
{
list.clear();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
if (arg1<list.size() && !((arg1==0) && (list.size()==0)))
ui->listWidget->addItem(list[arg1]);
else ui->statusbar->showMessage("error index");
}


void MainWindow::Changed()

{

QString st=ui->lineEdit->text();
bool key=true;
for (int i=0;i<st.size();i++)
if (!st[i].isDigit()){
key=false;
break;
}
if (key)
list.append(st.toInt());
else
list.append((st[0]).toLatin1());
ui->spinBox->setMaximum(list.size()-1);

}




void MainWindow::on_pushButton_2_clicked()
{
list.sort();
}


void MainWindow::on_pushButton_5_clicked()
{
this->close();
}
