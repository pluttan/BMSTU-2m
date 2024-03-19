#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);  // �������� �������-����������

	QWidget win;                  // �������� ������� ���������� �����
	win.setWindowTitle("Hello"); // ��������� ��������� ����

	QLabel *helloLabel = new QLabel("Hello!", &win); // �������� �����
	QPushButton *exitButton = new QPushButton("Close", &win); // �������� ������

	QHBoxLayout *layout = new QHBoxLayout(&win); // �������� ���������
							// ���������� ��� ���������� ����������� ����� � ������ � ���� win
	layout->addWidget(helloLabel);    // ���������� ����� � ������������
	layout->addWidget(exitButton);    // ���������� ������  � ������������

	// ����� ������� ������� ������ � ��������� ���� win
	QObject::connect(exitButton, SIGNAL(clicked(bool)),
		&win, SLOT(close()));

	win.show();    // ������������ ���� win 
	app.exec();     // ������ ����� ��������� ��������� ����������
}