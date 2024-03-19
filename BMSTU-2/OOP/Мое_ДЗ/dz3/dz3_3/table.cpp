#include "table.h"
#include "ui_table.h"

table::table(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::table)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/pluttan/Desktop/_Сем2/BMSTU-2/OOP/Мое_ДЗ/dz3/dz3_2/tableDB.db");
    if (db.open()){
        QMessageBox::information(this,"connection","connect");
    }

}

table::~table()
{
    delete ui;
}


void table::on_pushButton_clicked()
{
    QSqlQuery que;
    if (que.exec("CREATE TABLE IF NOT EXISTS " +
                 ui->lineEdit_4->text() +
                 " (name varchar(50) PRIMARY KEY, price int, count int);")){

    } else QMessageBox::information(this,"error","Something went wrong :(");

    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery* q = new QSqlQuery(db);
    q->prepare("select * from " + ui->lineEdit_4->text());
    if(q->exec()){
        modal->setQuery(*q);
        ui -> tableView -> setModel(modal);
    }else QMessageBox::information(this,"error","Something went wrong :(");
}


void table::on_pushButton_2_clicked()
{
    QSqlQuery que;

    QRegularExpression re("\\d+");
    QRegularExpressionMatch match1 = re.match(ui->lineEdit_2->text());
    QRegularExpressionMatch match2 = re.match(ui->lineEdit_3->text());
    if (!(match1.hasMatch() and match2.hasMatch())) {
        QMessageBox::information(this,"error","Type error :(");
        return;
    }

    if (que.exec("REPLACE INTO "+ui->lineEdit_4->text()+
                 " (name, price, count) VALUES ('"+ui->lineEdit->text()+
                 "', "+ui->lineEdit_2->text()+", "+ui->lineEdit_3->text()+
                 ");")){

    } else QMessageBox::information(this,"error","Something went wrong :(");
    on_pushButton_clicked();
}

