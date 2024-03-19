#include "iostream"
using std::cout, std::cin;

int main()
{
    int Age;
    cout << "Enter your age: ";
    cin >> Age;
    cout << "Your age in month is " << Age * 12;
    return 0;
}