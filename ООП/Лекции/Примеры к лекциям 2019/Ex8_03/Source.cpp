#include <fstream>
#include <iostream>
using namespace std;
void main()
{
	char h;
	ofstream out("Test.txt", ios::app); // ��� ����������
	cin >> h;
	out << h << endl; // ��������� ������
	out.close();
	ifstream  in("Test.txt");  // ��� ����� �� �����
	if (!in)       // ���� ���� �� ������
		cout << "File is not open.\n";
	else
	{
		in >> h;
		while (!in.eof())
		{
			cout << h << endl;
			in >> h;
		}
	}
	in.close();
}

