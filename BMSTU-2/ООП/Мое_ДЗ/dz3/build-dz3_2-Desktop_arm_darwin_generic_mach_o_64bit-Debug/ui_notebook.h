/********************************************************************************
** Form generated from reading UI file 'notebook.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEBOOK_H
#define UI_NOTEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_notebook
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *choose;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBox;
    QPushButton *save;
    QPushButton *save_as;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *notebook)
    {
        if (notebook->objectName().isEmpty())
            notebook->setObjectName("notebook");
        notebook->resize(826, 600);
        centralwidget = new QWidget(notebook);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(400, 0));

        horizontalLayout_3->addWidget(lineEdit);

        choose = new QPushButton(centralwidget);
        choose->setObjectName("choose");
        choose->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(choose);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        fontComboBox = new QFontComboBox(centralwidget);
        fontComboBox->setObjectName("fontComboBox");

        horizontalLayout->addWidget(fontComboBox);

        save = new QPushButton(centralwidget);
        save->setObjectName("save");

        horizontalLayout->addWidget(save);

        save_as = new QPushButton(centralwidget);
        save_as->setObjectName("save_as");

        horizontalLayout->addWidget(save_as);


        verticalLayout_2->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout_2->addWidget(plainTextEdit);

        notebook->setCentralWidget(centralwidget);

        retranslateUi(notebook);

        QMetaObject::connectSlotsByName(notebook);
    } // setupUi

    void retranslateUi(QMainWindow *notebook)
    {
        notebook->setWindowTitle(QCoreApplication::translate("notebook", "notebook", nullptr));
        label->setText(QCoreApplication::translate("notebook", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        choose->setText(QCoreApplication::translate("notebook", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214...", nullptr));
        save->setText(QCoreApplication::translate("notebook", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        save_as->setText(QCoreApplication::translate("notebook", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class notebook: public Ui_notebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEBOOK_H
