#include "PrintBook.h"
#include <stdio.h>

int main()
{
	// ���������� ������������������� �������
	CPrintBook D("J.London. Smoke Bellew",267);

	printf("%s %d %d\n",D.getName(),D.getPages(),D.getPrintPages());
	return 0;
}

