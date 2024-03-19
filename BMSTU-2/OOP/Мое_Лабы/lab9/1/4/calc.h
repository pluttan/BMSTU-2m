#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QMainWindow
{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    ~calc();
    QString clc;


private slots:
    void on_but0_clicked();

    void on_but1_clicked();

    void on_but2_clicked();

    void on_but3_clicked();

    void on_but4_clicked();

    void on_but5_clicked();

    void on_but6_clicked();

    void on_but7_clicked();

    void on_but8_clicked();

    void on_but9_clicked();

    void on_butFloat_clicked();

    void on_butSum_clicked();

    void on_butMin_clicked();

    void on_butMultiply_clicked();

    void on_butDevide_clicked();

    void on_butDeg_clicked();

    void on_butLog_clicked();

    void on_butSin_clicked();

    void on_butCos_clicked();

    void on_butPM_clicked();

    void on_butDel_clicked();

    void on_butCE_clicked();

    void on_butC_clicked();

    void on_butEqually_clicked();

private:
    Ui::calc *ui;
};
#endif // CALC_H
