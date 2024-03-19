#include "iostream"
using std::cout, std::cin;
int main()
{
    cout << "Enter your length in inches: __\b\b\a\a";
    short lengthInInches{};
    cin >> lengthInInches;
    const short kInchesToFoots = 12;
    cout << "Your length is " << lengthInInches / kInchesToFoots
         << " foots, " << lengthInInches % kInchesToFoots << " inches. \n";
}