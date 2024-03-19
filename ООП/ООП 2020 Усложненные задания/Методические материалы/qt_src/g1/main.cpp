/** 
 @mainpage ������������ ������������ ����������� �����������
           � ������� �������� �������� ����������, ������� ��������� 
           ������������ ����������� ����������� � ������������� ��������� 
           ������������ ���������� Qt - ������� QPainter � QPainterPath.
 @file main.cpp
 @brief ������ ����������.
 @details ��������� ���� �� ������ Painter. 
 ������������ ������ ����� ��������� ����������. 
*/
#include <QApplication>
#include "painter.h"

int main(int argc, char *argv[])
{    
  QApplication app(argc, argv);
  Painter painter;
  painter.show();
  return app.exec();
}

