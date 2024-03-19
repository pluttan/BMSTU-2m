#include "calc.h"
#include "ui_calc.h"
#include <QTextCursor>
#include "solve.cpp"
#include "cmath"

calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
}

calc::~calc()
{
    delete ui;
}


void calc::on_but0_clicked()
{
    clc += "0";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}

void calc::on_but1_clicked()
{
    clc += "1";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_but2_clicked()
{
    clc += "2";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_but3_clicked()
{
    clc += "3";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_but4_clicked()
{
    clc += "4";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_but5_clicked()
{
    clc += "5";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_but6_clicked()
{
    clc += "6";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_but7_clicked()
{
    clc += "7";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_but8_clicked()
{
    clc += "8";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_but9_clicked()
{
    clc += "9";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}





void calc::on_butFloat_clicked()
{
    clc += ".";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butSum_clicked()
{
    clc += "+";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butMin_clicked()
{
    clc += "-";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butMultiply_clicked()
{
    clc += "*";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butDevide_clicked()
{
    clc += "/";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butDeg_clicked()
{
    clc += "^";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butLog_clicked()
{
    clc = "log"+clc+"(";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butSin_clicked()
{
    clc = "sin("+clc+")";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butCos_clicked()
{
    clc = "cos("+clc+")";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butPM_clicked()
{
    if (clc.length() > 0){
        if (clc[0] == '-')
            clc = clc.mid(1, clc.length());
        else clc = "-"+clc;
    } else clc = "-";
    ui->textEdit->setText(clc);
    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}


void calc::on_butDel_clicked()
{
    if (clc.length() > 0){
        clc = clc.mid(0, clc.length()-1);
        ui->textEdit->setText(clc);
        for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
    }
}


void calc::on_butCE_clicked()
{
    clc = "";
    ui->textEdit->setText(clc);
}


void calc::on_butC_clicked()
{
    on_butCE_clicked();
}



// logic
// log sin 1 + 2 78
//    q1 q2 out
// p1 1  2  +
// p2 p1    sin
// p3 p2 78 log



void calc::on_butEqually_clicked()
{
    std::string sv = ui->textEdit->toPlainText().toStdString();
    float b{};
    if (sv.substr(0,3) == "log"){
//        log10();
        float b1{};
        int i;
        for(i = 3; i < sv.length();i++){
            if (sv[i] == '('){
                b1 = log10(stof(sv.substr(3,i-2)));
                break;
            }
        }
        qDebug()<<QString::fromStdString(sv.substr(i+1, sv.length()));
        float b2 = log10(stof(sv.substr(i+1, sv.length()-1)));

        b = b2/b1;
    }
    else{
        b = solve(&sv[0],0,sv.length());
    }
    clc = QString::number(b);
    ui->textEdit->setText(clc);

    for(auto _:clc) ui->textEdit->moveCursor(QTextCursor::Right);
}

