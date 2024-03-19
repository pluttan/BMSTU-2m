#include "iostream"
using std::cout, std::cin;

int LightYearsToAstronomicalUnits(float LightYears);

int main()
{
    float LightYears;
    cout << "Enter the number of light years: ";
    cin >> LightYears;
    cout << LightYears << " light years = "
         << LightYearsToAstronomicalUnits(LightYears)
         << " astronomical units\n";
};

int LightYearsToAstronomicalUnits(float LightYears)
{
    return (int)63240 * LightYears;
}
