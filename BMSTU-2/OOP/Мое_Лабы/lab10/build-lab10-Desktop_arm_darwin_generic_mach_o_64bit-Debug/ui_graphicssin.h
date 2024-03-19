/********************************************************************************
** Form generated from reading UI file 'graphicssin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSSIN_H
#define UI_GRAPHICSSIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicsSin
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GraphicsSin)
    {
        if (GraphicsSin->objectName().isEmpty())
            GraphicsSin->setObjectName("GraphicsSin");
        GraphicsSin->resize(800, 600);
        centralwidget = new QWidget(GraphicsSin);
        centralwidget->setObjectName("centralwidget");
        GraphicsSin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GraphicsSin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        GraphicsSin->setMenuBar(menubar);
        statusbar = new QStatusBar(GraphicsSin);
        statusbar->setObjectName("statusbar");
        GraphicsSin->setStatusBar(statusbar);

        retranslateUi(GraphicsSin);

        QMetaObject::connectSlotsByName(GraphicsSin);
    } // setupUi

    void retranslateUi(QMainWindow *GraphicsSin)
    {
        GraphicsSin->setWindowTitle(QCoreApplication::translate("GraphicsSin", "GraphicsSin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphicsSin: public Ui_GraphicsSin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSSIN_H
