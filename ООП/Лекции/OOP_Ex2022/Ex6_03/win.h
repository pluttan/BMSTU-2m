#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>

class Win:public QWidget      // ����� ����
{
    Q_OBJECT  // ������ Qt ��� ���������� �������� � ������
protected:
    QTextCodec *codec;       // ��������������
    QFrame *frame;           // �����
    QLabel *inputLabel;      // ����� �����
    QLineEdit *inputEdit;    // �������� �������� �����
    QLabel *outputLabel;     // ����� ������
    QLineEdit *outputEdit;   // �������� �������� ������
    QPushButton *nextButton; // ������ ���������
    QPushButton *exitButton; // ������ �����
public:
    Win(QWidget *parent = nullptr); // �����������
public slots:
    void begin();      // ������������� ����������
    void calc();       // ���������� ����������
};
class StrValidator:public QValidator // ����� �������� �����
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    State validate(QString &str,int &pos)const override;
};

#endif
