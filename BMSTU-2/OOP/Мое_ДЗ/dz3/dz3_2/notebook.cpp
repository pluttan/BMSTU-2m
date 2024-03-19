#include "notebook.h"
#include "ui_notebook.h"
#include <QFileDialog>
#include <QDebug>

notebook::notebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::notebook)
{
    ui->setupUi(this);
}

notebook::~notebook()
{
    delete ui;
}


void notebook::on_choose_clicked()
{
    ui->lineEdit->setText(QFileDialog::getOpenFileName(this, "Выберите файл", QDir::currentPath()));
}


void notebook::on_save_as_clicked()
{
    ui->lineEdit->setText(QFileDialog::getSaveFileName(this, "Сохранить файл как...", QDir::currentPath()));
    on_save_clicked();
}


void notebook::on_lineEdit_textChanged(const QString &arg1)
{
    QFile file(arg1);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray t = file.readAll();
        ui->plainTextEdit->setPlainText(QString(t));
        file.close();
    }
}


void notebook::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->plainTextEdit->setFont(f);
}


void notebook::on_save_clicked()
{
    QFile file(QString(ui->lineEdit->text()));
    QByteArray a = ui->plainTextEdit->placeholderText().toLocal8Bit();
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(ui->plainTextEdit->toPlainText().toUtf8());
        file.close();
    }
}

