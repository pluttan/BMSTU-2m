#ifndef WINDOWS_H
#define WINDOWS_H

#include "area.h"
#include <QWidget>
#include <QTextCodec>
#include <QPushButton>

class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area;         // ������� ����������� �������
    QPushButton * btn;
public:
    Window();
};
#endif
