#include "table.h"
#include "ui_table.h"
#include "string"
#include "unordered_map"
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts>
#include <QVBoxLayout>
#include <QVector>

QChartView* createHistogram(std::unordered_map<std::string, int> data)
{
    // Создаем объекты для данных гистограммы


    // Создаем объект гистограммы и добавляем данные
    QBarSeries *series = new QBarSeries();
    for(auto i:data){
        QBarSet *set = new QBarSet(QString::fromUtf8(i.first));
        *set << i.second;
        series->append(set);
    }


    // Создаем объект диаграммы и добавляем на него гистограмму
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Гистограмма стадионов");

    // Устанавливаем оси координат
//    QCategoryAxis *axisX = new QCategoryAxis();
      int count{}, mx{};
      for(auto i:data){
          count++;
//          axisX->append(QString::fromUtf8(i.first),count);
          if (i.second > mx) mx = i.second;
          qDebug()<<QString::fromUtf8(i.first)<< QString::number(i.second);
      }
//    axisX->setLabelsAngle(30);
//    chart->addAxis(axisX, Qt::AlignBottom);
//    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Количество игр");
    axisY->setLabelFormat("%d");
    axisY->setTickCount(mx+1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Создаем объект отображения гистограммы и устанавливаем его в макет
    QChartView *chartView = new QChartView(chart);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(chartView);

    // Устанавливаем макет для главного окна и возвращаем объект отображения гистограммы
    QWidget *window = new QWidget;
    window->setLayout(layout);
    window->resize(1200, 600);
    window->show();

    return chartView;
}

table::table(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::table)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/pluttan/Desktop/_Сем2/BMSTU-2/OOP/Мое_прак/pr3/pr3.db");
    if (db.open()){
        QMessageBox::information(this,"connection","connect");
    }
    on_pushButton_7_clicked();
}

table::~table()
{
    delete ui;
}


void table::on_pushButton_6_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery* q = new QSqlQuery(db);
    q->prepare(ui->lineEdit_7->text());
    if(q->exec()){
        modal->setQuery(*q);
        ui -> tableView -> setModel(modal);
    }else QMessageBox::information(this,"error","Something went wrong :(");
}


void table::on_pushButton_5_clicked()
{
    QSqlQuery que;
    if (que.exec("INSERT INTO games (stadium, team1, team2, score1, score2) VALUES ('"
                + ui->lineEdit_2->text() + "','" + ui->lineEdit_3->text() + "','"
                + ui->lineEdit_4->text() + "'," + ui->lineEdit_5->text() + ","
                + ui->lineEdit_6->text() + ')')){

    } else QMessageBox::information(this,"error","Something went wrong :(");
    on_pushButton_7_clicked();
}


void table::on_pushButton_clicked()
{
    QModelIndexList selected_indexes = ui->tableView->selectionModel()->selectedIndexes();
    if (!selected_indexes.isEmpty()) {
        QModelIndex model_index = selected_indexes.first();
        QSqlQuery que;
        if (que.exec("DELETE FROM games WHERE id = " + QString::number(model_index.row()+1))){

        } else QMessageBox::information(this,"error","Something went wrong :(");
        on_pushButton_7_clicked();
    }
}


void table::on_pushButton_3_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery* q = new QSqlQuery(db);
    q->prepare(QString::fromUtf8(
               (std::string)"SELECT team, COUNT(*) as wins FROM " +
               (std::string)"(SELECT team1 as team, score1, score2 "+
               (std::string)"FROM games UNION ALL SELECT team2 as "+
               (std::string)"team, score2, score1 FROM games) as games "+
               (std::string)"WHERE score1 > score2 GROUP BY team HAVING wins >= ") +
               ui->lineEdit->text());
    if(q->exec()){
        modal->setQuery(*q);
        ui -> tableView -> setModel(modal);
    }else QMessageBox::information(this,"error","Something went wrong :(");
}


void table::on_pushButton_7_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery* q = new QSqlQuery(db);
    q->prepare("select stadium, team1, team2, score1, score2 from games");
    if(q->exec()){
        modal->setQuery(*q);
        ui -> tableView -> setModel(modal);
    }else QMessageBox::information(this,"error","Something went wrong :(");
    modal = new QSqlQueryModel();
    q = new QSqlQuery(db);
    q->prepare("SELECT DISTINCT team1 as team FROM games UNION SELECT DISTINCT team2 as team FROM games");
    if(q->exec()){
        modal->setQuery(*q);
        ui -> listView -> setModel(modal);
    }else QMessageBox::information(this,"error","Something went wrong :(");
}


void table::on_pushButton_4_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery* q = new QSqlQuery(db);
    q->prepare("SELECT stadium, team1, team2, score1, score2 FROM games where score1 = score2");
    if(q->exec()){
        modal->setQuery(*q);
        ui -> tableView -> setModel(modal);
    }else QMessageBox::information(this,"error","Something went wrong :(");
}


void table::on_pushButton_2_clicked()
{
    QModelIndexList selected_indexes = ui->listView->selectionModel()->selectedIndexes();
    if (!selected_indexes.isEmpty()) {
        QModelIndex model_index = selected_indexes.first();
        int row = model_index.row();
        QAbstractItemModel* model = ui->listView->model();
        QVariant data = model->data(model->index(row, 0));
        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery* q = new QSqlQuery(db);
        q->prepare("SELECT stadium, team1, team2, score1, score2 FROM games where team1 = '" + data.toString() +
                   "' or team2 = '" + data.toString() + "'");
        if(q->exec()){
            modal->setQuery(*q);
            ui -> tableView -> setModel(modal);
        }else QMessageBox::information(this,"error","Something went wrong :(");

    }
}


void table::on_pushButton_8_clicked()
{
    std::unordered_map<std::string, int> sel;
    QSqlQuery query("SELECT stadium FROM games");
    while (query.next()) {
        std::string name = query.value(0).toString().toStdString();
        sel[name]++;
    };
    QChartView* chartView = createHistogram(sel);
    chartView->resize(800, 600);
    chartView->show();

}

