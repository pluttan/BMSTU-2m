#include <iostream>
#include <string.h>
using namespace std;

class TA
{
protected:	char c;
public: TA(char ac) :c(ac) {}
		void func() { cout << c << endl; }
		virtual void Print() {}
};
class TB :public TA
{
	char S[10];
public: TB(const char *aS) :TA(aS[0]) { strcpy(S, aS); }
		void func() { cout << c << ' ' << S << endl; }
};

int main()
{
	TA *pA = new TA('A'), *pC = new TB("AB");
	TB *pB = new TB("AC");

	// ����������
	((TA *)pB)->func();
	reinterpret_cast<TA *>(pB)->func();
	static_cast<TA *>(pB)->func();
	dynamic_cast<TA *>(pB)->func();

	// ����������
	((TB *)pC)->func();
	((TB *)pA)->func();
	reinterpret_cast<TB *>(pC)->func(); // ���������-���������, ������������ ��� -> ���������
	reinterpret_cast<TB *>(pA)->func(); // ��� ��������, ���������� ����
	static_cast<TB *>(pC)->func();      // ����� ��� � �����
	static_cast<TB *>(pA)->func();      // ��� ��������, ���������� ����
	dynamic_cast<TB *>(pC)->func();     // ������� ������� ����������� ������� � ��������� /GR, �� ��������� �������� ���� ��� ������������� ������������
	//dynamic_cast<TB *>(pA)->func();   // ��������� �������������� NULL
	if (TB *pD = dynamic_cast<TB *>(pA)) pD->func();
	else cout << "Cast Error" << endl;
	return 0;
}
