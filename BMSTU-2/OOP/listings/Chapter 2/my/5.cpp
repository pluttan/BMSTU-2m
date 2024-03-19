#include "iostream"
using std::cin, std::cout;

int CelsiusToFahrenheit(int Celsius)
{
    return 1.8 * Celsius + 32;
};

int main()
{
    int Celsius;
    cout << "Please enter a celsius value: ";
    cin >> Celsius;
    cout << Celsius << " degrees of celsius is "
         << CelsiusToFahrenheit(Celsius) << " degrees of fahrenheit\n";
    return 0;
}