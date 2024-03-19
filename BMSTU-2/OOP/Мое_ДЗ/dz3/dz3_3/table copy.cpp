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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::table *ui;
};
#endif // TABLE_H
