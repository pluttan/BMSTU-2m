#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QtSQL>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class table; }
QT_END_NAMESPACE

class table : public QMainWindow
{
    Q_OBJECT

public:
    table(QWidget *parent = nullptr);
    ~table();
    QSqlDatabase db;

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::table *ui;
};
#endif // TABLE_H
