#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[12]; // �����
	int decimal, sign; // ������� ���. ����� � ����
	int count=10; // ���������� ��������
	int err; // ��� ������

	err = _ecvt_s(buf, 12, 3.1415926535, count, &decimal, &sign);
	printf("Converted value to string: %s\n", buf);
	printf("Decimal= %d, Sign= %d.", decimal, sign);

	return 0;
}
