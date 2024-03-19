#include "iostream"
using std::cin, std::cout;
void PrintTime(int Hour, int Minute);

int main()
{
    int Hours, Minutes;
    cout << "Enter hours: ";
    cin >> Hours;
    cout << "Enter minutes: ";
    cin >> Minutes;
    PrintTime(Hours, Minutes);
};

void PrintTime(int Hours, int Minutes)
{
    cout << "Time: " << Hours << ":" << Minutes << "\n";
};