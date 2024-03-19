#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class notebook; }
QT_END_NAMESPACE

class notebook : public QMainWindow
{
    Q_OBJECT

public:
    notebook(QWidget *parent = nullptr);
    ~notebook();

private slots:
    void on_choose_clicked();

    void on_save_as_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_save_clicked();

private:
    Ui::notebook *ui;
};
#endif // NOTEBOOK_H
