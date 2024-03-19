#include "iostream"
using std::cout, std::cin;
int main()
{
    cout << "Enter your length foots: ";
    short lengthFoots{};
    cin >> lengthFoots;

    cout << "Enter your length inches: ";
    short lengthInches{};
    cin >> lengthInches;

    cout << "Enter your weight in funts: ";
    short weightInFuts{};
    cin >> weightInFuts;

    short lengthInInches{};
    cout << "Enter your length in inches: "
         << (lengthInInches = lengthFoots * 12 + lengthInches);

    float lengthInMeters{};
    cout << "\nEnter your length in meters: "
         << (lengthInMeters = lengthInInches * 0.0254);

    float weigthInKilo{};
    cout << "\nEnter your weigth in kilo: "
         << (weigthInKilo = weightInFuts / 2.2);

    float BMI{};
    cout << "\nBMI: "
         << (BMI = weigthInKilo / (lengthInMeters * lengthInMeters));
}