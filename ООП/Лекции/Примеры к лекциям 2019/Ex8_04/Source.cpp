#include <iostream> 
#include <fstream>
using namespace std;
int main()
{
	int n = 50;

	ofstream out; // ������� ������ ������

	// ��������� ���� ��� ������
	out.open("Test.txt", ios::out);

	out << "Hello!\n" << n; // ������� � ���� ������ � �����

	out.close(); // ��������� ���� 
	ifstream in("Test.txt"); // ��������� ���� ��� ����� �
	if (!in)
	{
		cout << "Error.\n";
	}
	else
	{
		char str[80];
		in >> str >> n; // ������ ������ � ����� �� �����
		cout << str << " " << n << endl;
		in.close(); // ��������� ����
	}
	return 0;
}
