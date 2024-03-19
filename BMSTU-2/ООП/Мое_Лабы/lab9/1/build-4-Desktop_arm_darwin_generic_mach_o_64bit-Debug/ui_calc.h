/********************************************************************************
** Form generated from reading UI file 'calc.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALC_H
#define UI_CALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calc
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *butDel;
    QPushButton *butCE;
    QPushButton *butC;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *but7;
    QPushButton *but8;
    QPushButton *but9;
    QPushButton *butDevide;
    QPushButton *butDeg;
    QPushButton *but4;
    QPushButton *but5;
    QPushButton *but6;
    QPushButton *butMultiply;
    QPushButton *butLog;
    QPushButton *but1;
    QPushButton *but2;
    QPushButton *but3;
    QPushButton *butMin;
    QPushButton *butSin;
    QPushButton *but0;
    QPushButton *butPM;
    QPushButton *butFloat;
    QPushButton *butSum;
    QPushButton *butCos;
    QPushButton *butEqually;

    void setupUi(QMainWindow *calc)
    {
        if (calc->objectName().isEmpty())
            calc->setObjectName("calc");
        calc->resize(374, 296);
        centralwidget = new QWidget(calc);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        QFont font;
        font.setPointSize(20);
        textEdit->setFont(font);

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        butDel = new QPushButton(centralwidget);
        butDel->setObjectName("butDel");

        horizontalLayout->addWidget(butDel);

        butCE = new QPushButton(centralwidget);
        butCE->setObjectName("butCE");

        horizontalLayout->addWidget(butCE);

        butC = new QPushButton(centralwidget);
        butC->setObjectName("butC");

        horizontalLayout->addWidget(butC);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        but7 = new QPushButton(centralwidget);
        but7->setObjectName("but7");

        gridLayout->addWidget(but7, 0, 0, 1, 1);

        but8 = new QPushButton(centralwidget);
        but8->setObjectName("but8");

        gridLayout->addWidget(but8, 0, 1, 1, 1);

        but9 = new QPushButton(centralwidget);
        but9->setObjectName("but9");

        gridLayout->addWidget(but9, 0, 2, 1, 1);

        butDevide = new QPushButton(centralwidget);
        butDevide->setObjectName("butDevide");

        gridLayout->addWidget(butDevide, 0, 3, 1, 1);

        butDeg = new QPushButton(centralwidget);
        butDeg->setObjectName("butDeg");

        gridLayout->addWidget(butDeg, 0, 4, 1, 1);

        but4 = new QPushButton(centralwidget);
        but4->setObjectName("but4");

        gridLayout->addWidget(but4, 1, 0, 1, 1);

        but5 = new QPushButton(centralwidget);
        but5->setObjectName("but5");

        gridLayout->addWidget(but5, 1, 1, 1, 1);

        but6 = new QPushButton(centralwidget);
        but6->setObjectName("but6");

        gridLayout->addWidget(but6, 1, 2, 1, 1);

        butMultiply = new QPushButton(centralwidget);
        butMultiply->setObjectName("butMultiply");

        gridLayout->addWidget(butMultiply, 1, 3, 1, 1);

        butLog = new QPushButton(centralwidget);
        butLog->setObjectName("butLog");

        gridLayout->addWidget(butLog, 1, 4, 1, 1);

        but1 = new QPushButton(centralwidget);
        but1->setObjectName("but1");

        gridLayout->addWidget(but1, 2, 0, 1, 1);

        but2 = new QPushButton(centralwidget);
        but2->setObjectName("but2");

        gridLayout->addWidget(but2, 2, 1, 1, 1);

        but3 = new QPushButton(centralwidget);
        but3->setObjectName("but3");

        gridLayout->addWidget(but3, 2, 2, 1, 1);

        butMin = new QPushButton(centralwidget);
        butMin->setObjectName("butMin");

        gridLayout->addWidget(butMin, 2, 3, 1, 1);

        butSin = new QPushButton(centralwidget);
        butSin->setObjectName("butSin");

        gridLayout->addWidget(butSin, 2, 4, 1, 1);

        but0 = new QPushButton(centralwidget);
        but0->setObjectName("but0");

        gridLayout->addWidget(but0, 3, 0, 1, 1);

        butPM = new QPushButton(centralwidget);
        butPM->setObjectName("butPM");

        gridLayout->addWidget(butPM, 3, 1, 1, 1);

        butFloat = new QPushButton(centralwidget);
        butFloat->setObjectName("butFloat");

        gridLayout->addWidget(butFloat, 3, 2, 1, 1);

        butSum = new QPushButton(centralwidget);
        butSum->setObjectName("butSum");

        gridLayout->addWidget(butSum, 3, 3, 1, 1);

        butCos = new QPushButton(centralwidget);
        butCos->setObjectName("butCos");

        gridLayout->addWidget(butCos, 3, 4, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        butEqually = new QPushButton(centralwidget);
        butEqually->setObjectName("butEqually");

        horizontalLayout_2->addWidget(butEqually);


        verticalLayout->addLayout(horizontalLayout_2);

        calc->setCentralWidget(centralwidget);

        retranslateUi(calc);

        QMetaObject::connectSlotsByName(calc);
    } // setupUi

    void retranslateUi(QMainWindow *calc)
    {
        calc->setWindowTitle(QCoreApplication::translate("calc", "calc", nullptr));
        textEdit->setHtml(QCoreApplication::translate("calc", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        butDel->setText(QCoreApplication::translate("calc", "<-", nullptr));
        butCE->setText(QCoreApplication::translate("calc", "CE", nullptr));
        butC->setText(QCoreApplication::translate("calc", "C", nullptr));
        but7->setText(QCoreApplication::translate("calc", "7", nullptr));
        but8->setText(QCoreApplication::translate("calc", "8", nullptr));
        but9->setText(QCoreApplication::translate("calc", "9", nullptr));
        butDevide->setText(QCoreApplication::translate("calc", "/", nullptr));
        butDeg->setText(QCoreApplication::translate("calc", "x^y", nullptr));
        but4->setText(QCoreApplication::translate("calc", "4", nullptr));
        but5->setText(QCoreApplication::translate("calc", "5", nullptr));
        but6->setText(QCoreApplication::translate("calc", "6", nullptr));
        butMultiply->setText(QCoreApplication::translate("calc", "*", nullptr));
        butLog->setText(QCoreApplication::translate("calc", "logx(y)", nullptr));
        but1->setText(QCoreApplication::translate("calc", "1", nullptr));
        but2->setText(QCoreApplication::translate("calc", "2", nullptr));
        but3->setText(QCoreApplication::translate("calc", "3", nullptr));
        butMin->setText(QCoreApplication::translate("calc", "-", nullptr));
        butSin->setText(QCoreApplication::translate("calc", "sinx", nullptr));
        but0->setText(QCoreApplication::translate("calc", "0", nullptr));
        butPM->setText(QCoreApplication::translate("calc", "-/+", nullptr));
        butFloat->setText(QCoreApplication::translate("calc", ".", nullptr));
        butSum->setText(QCoreApplication::translate("calc", "+", nullptr));
        butCos->setText(QCoreApplication::translate("calc", "cosx", nullptr));
        butEqually->setText(QCoreApplication::translate("calc", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calc: public Ui_calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALC_H
