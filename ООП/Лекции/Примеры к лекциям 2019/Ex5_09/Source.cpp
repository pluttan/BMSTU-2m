#include <iostream>
class A {
public:    void func(int ch);
};
class B : public A {
public:
	void func(const char *str);
	using A::func;    // ���������� B::func
};
void A::func(int ch) {   // ����� �������� ������
	std::cout << "Symbol\n";
}
void B::func(const char *str) { // ����� ������������ ������
	std::cout << "String\n";
}
int main() {
	B b;
	b.func(25);     // �����  A::func()
	b.func("ccc");  // �����  B::func() 
	return 0;
}
