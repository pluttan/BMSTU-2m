#include "iostream"
using std::cin, std::cout;
int main()
{
    //     Enter the world ' s population : 6898758899
    // Enter the population of the US : 310783781
    // The population of the US is 4 . 50492% of the world population .
    long long populationWorld, populationUSA;
    cout << "Enter the world's population: ";
    cin >> populationWorld;
    cout << "Enter the population of the US: ";
    cin >> populationUSA;
    cout << "The population of the US is "
         << (float(populationUSA) / populationWorld) * 100
         << "\% of the world population.\n";
}