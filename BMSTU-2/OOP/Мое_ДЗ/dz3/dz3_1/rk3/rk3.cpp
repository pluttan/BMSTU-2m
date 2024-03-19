#include "iostream"
using std::cout;

class X
{
public:
    char c{};
    X(char c)
    {
        this->c = c;
    };
    virtual void out()
    {
        cout << c;
    }
};

class Y : public X
{
public:
    int a{}, b{};
    Y(char c, int a, int b) : X(c)
    {
        this->a = a;
        this->b = b;
    };
    virtual void out()
    {
        for (int i = 0; i < a + b; i++)
            cout << " ";
        cout << c;
    }
};
class Z : public Y
{
public:
    Z(char c, int a, int b) : Y(c, a, b){};
    virtual void out()
    {
        for (int i = 0; i < 10; i++)
            cout << " ";
        for (int i = 0; i < 5; i++)
            cout << c;
    }
};
void outptr(X *ptr)
{
    ptr->out();
    cout << "\n";
}

int main()
{
    X x(65);
    Y y(66, 1, 8);
    Z z(67, 1, 2);
    outptr(&x);
    outptr(&y);
    outptr(&z);
    return 0;
}