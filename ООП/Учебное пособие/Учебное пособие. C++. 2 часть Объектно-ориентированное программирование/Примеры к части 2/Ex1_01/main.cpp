#include "first.h"

void main()
{
	int i=3;
	First a,  // ������ ������ First
          *b,     // ��������� �� ������ ������ First
          c[4];     // ������ � �� ������� �������� ������ First
	First d = {'A',3,4},
          e[4] = {{'A',1,4},{'B',3,5},{'C',2,6},{'D',1,3}};
	a.set('A',3,4);    // ����������� ������
	b=new First; 
	b->set('B',3,4);   // ������������ ������
	delete b;
	c[i].set('C',3,4); // ������ ��������

}
