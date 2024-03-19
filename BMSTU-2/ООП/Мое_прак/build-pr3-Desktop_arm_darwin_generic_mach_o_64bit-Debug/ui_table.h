/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_table
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_6;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QListView *listView;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *table)
    {
        if (table->objectName().isEmpty())
            table->setObjectName("table");
        table->resize(776, 715);
        centralwidget = new QWidget(table);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        verticalLayout_2->addWidget(tableView);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setMinimumSize(QSize(20, 0));
        lineEdit_5->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(lineEdit_5);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        horizontalLayout->addWidget(label_6);

        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(lineEdit_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout_2->addWidget(pushButton_7);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");

        horizontalLayout_2->addWidget(pushButton_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_2->addWidget(pushButton_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");

        horizontalLayout_3->addWidget(lineEdit_7);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout_3->addWidget(pushButton_6);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(pushButton);

        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(listView);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(200, 0));
        pushButton_2->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(pushButton_2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(lineEdit);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(pushButton_4);


        horizontalLayout_5->addLayout(verticalLayout_3);

        table->setCentralWidget(centralwidget);

        retranslateUi(table);

        QMetaObject::connectSlotsByName(table);
    } // setupUi

    void retranslateUi(QMainWindow *table)
    {
        table->setWindowTitle(QCoreApplication::translate("table", "table", nullptr));
        label_2->setText(QCoreApplication::translate("table", "\320\241\321\202\320\260\320\264\320\270\320\276\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("table", "      \320\232\320\276\320\274\320\260\320\275\320\264\320\260 1", nullptr));
        label_4->setText(QCoreApplication::translate("table", " \320\232\320\276\320\274\320\260\320\275\320\264\320\260 2", nullptr));
        label_5->setText(QCoreApplication::translate("table", "\320\241\321\207\320\265\321\202         ", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("table", "\320\241\321\202\320\260\320\264\320\270\320\276\320\275", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("table", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260 1", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("table", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260 2", nullptr));
        label_6->setText(QCoreApplication::translate("table", ":", nullptr));
        pushButton_7->setText(QCoreApplication::translate("table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        pushButton_8->setText(QCoreApplication::translate("table", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\320\270\321\201\321\202\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
        pushButton_5->setText(QCoreApplication::translate("table", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("table", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\277\321\200\320\276\321\201 \320\262 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205 (SQL syntax)", nullptr));
        pushButton_6->setText(QCoreApplication::translate("table", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("table", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("table", "\320\235\320\260\320\271\321\202\320\270 \320\270\320\263\321\200\321\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("table", "\320\235\320\260\320\271\321\202\320\270 \320\272\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
        pushButton_4->setText(QCoreApplication::translate("table", "\320\234\320\260\321\202\321\207\320\270, \321\201\321\213\320\263\321\200\320\260\320\275\320\275\321\213\320\265 \320\262 \320\275\320\270\321\207\321\214\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table: public Ui_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
