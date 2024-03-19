#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <string>
#include <conteiner.h>
#include <QProxyStyle>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MyProxy:public QProxyStyle
{
public:
int style(StyleHint styleHint, const QStyleOption *opt, const QWidget * widget, QStyleHintReturn *return_data) const
{
if (styleHint==QStyle::SH_SpinBox_ClickAutoRepeatThreshold)
return 10000;
return QProxyStyle::styleHint(styleHint, opt, widget, return_data);
}

};
class MainWindow : public QMainWindow
{
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();
private slots:
void click();
void Changed();
void on_pushButton_3_clicked();

void on_pushButton_4_clicked();

void on_spinBox_valueChanged(int arg1);



void on_pushButton_2_clicked();

void on_pushButton_5_clicked();

private:
int boolean=0;
Ui::MainWindow *ui;

sort_conteiner list;
};

#endif // MAINWINDOW_H
