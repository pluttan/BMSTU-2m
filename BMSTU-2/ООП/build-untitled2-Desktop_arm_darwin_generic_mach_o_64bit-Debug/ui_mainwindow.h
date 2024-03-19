/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(800, 600);
        pushButton = new QPushButton(mainwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 240, 751, 24));
        pushButton_2 = new QPushButton(mainwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 280, 751, 24));
        pushButton_3 = new QPushButton(mainwindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 320, 751, 24));
        pushButton_4 = new QPushButton(mainwindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 360, 751, 24));
        pushButton_5 = new QPushButton(mainwindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 550, 751, 24));
        lineEdit = new QLineEdit(mainwindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 410, 751, 24));
        spinBox = new QSpinBox(mainwindow);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(30, 500, 751, 25));
        label = new QLabel(mainwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 460, 81, 20));
        verticalLayoutWidget = new QWidget(mainwindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 20, 751, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QDialog *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "mainwindow", nullptr));
        pushButton->setText(QCoreApplication::translate("mainwindow", "print", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mainwindow", "clean conteiner", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mainwindow", "sort", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mainwindow", "clear", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mainwindow", "close", nullptr));
        label->setText(QCoreApplication::translate("mainwindow", "input index", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
