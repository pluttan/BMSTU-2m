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
#include <QTranslator>
#include "painter.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	// ������������� ���� ��� ������������� �����, ������������ ������� 
	// tr() ��� translate().
	// � ������ ������� ��� ����������� � ����� painter.cpp.
	// ��������! ������, ������� ����� ����������������� ����� QTranslator 
	// ������ ��������� ������ ��������� �������!
	// ���� ru.ts ������������ �������� lupdate ../painter.cpp -ts ru.ts �
	// �������������� � Qt Linguist
	// ���� ru.qm ����������� �������� lrelease ru.ts
	QTranslator translator;
	//����, ������������ � :/ ��������, ��� ��������� ���� ��������� 
	// � �����-������� ����������. ���� �������� ������ translations/ru.qm, 
	// �� ���������� ����� ������ ���� � ����������	translations ������������ 
	// ������� ����������
	if( translator.load(":/translations/ru.qm") ) 
		qApp->installTranslator(&translator);

	Painter painter;
	painter.show();
	return app.exec();
}
