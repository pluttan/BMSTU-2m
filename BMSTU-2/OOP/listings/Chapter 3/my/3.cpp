#include "iostream"
using std::cout, std::cin;
int main()
{
    cout << "Enter а latitude in degrees, minutes, and seconds :\n";
    cout << "First, enter the degrees : ";
    short degrees, minutes, seconds;
    cin >> degrees;
    cout << "Next, enter the minutes of arc : ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc : ";
    cin >> seconds;
    cout << degrees << " degrees, "
         << minutes << " minutes, "
         << seconds << " seconds = "
         << degrees + float(minutes) / 60 + float(seconds) / 3600 << " degrees'n";
    return 0;
}