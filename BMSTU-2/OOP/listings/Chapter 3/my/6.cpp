#include "iostream"
using std::cin, std::cout;
int main()
{
    //     Enter the world ' s population : 6898758899
    // Enter the population of the US : 310783781
    // The population of the US is 4 . 50492% of the world population .
    int miles, gallon;
    cout << "Enter the miles: ";
    cin >> miles;
    cout << "Enter the gallon: ";
    cin >> gallon;
    cout << "Miles of gallons: " << float(miles) / gallon << "\n";
}