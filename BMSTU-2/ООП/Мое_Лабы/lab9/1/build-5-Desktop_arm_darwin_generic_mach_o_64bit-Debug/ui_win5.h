/********************************************************************************
** Form generated from reading UI file 'win5.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN5_H
#define UI_WIN5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_win5
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *win5)
    {
        if (win5->objectName().isEmpty())
            win5->setObjectName("win5");
        win5->resize(800, 600);
        centralwidget = new QWidget(win5);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(textEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");

        verticalLayout->addWidget(textEdit_2);

        win5->setCentralWidget(centralwidget);
        menubar = new QMenuBar(win5);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        win5->setMenuBar(menubar);
        statusbar = new QStatusBar(win5);
        statusbar->setObjectName("statusbar");
        win5->setStatusBar(statusbar);

        retranslateUi(win5);

        QMetaObject::connectSlotsByName(win5);
    } // setupUi

    void retranslateUi(QMainWindow *win5)
    {
        win5->setWindowTitle(QCoreApplication::translate("win5", "win5", nullptr));
        pushButton->setText(QCoreApplication::translate("win5", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class win5: public Ui_win5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN5_H
