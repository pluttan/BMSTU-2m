#include "iostream"
using std::cout, std::cin;
int main()
{
    cout << "Enter the number of seconds : ";
    long long seconds;
    int days, hours, minutes;
    cin >> seconds;
    cout << seconds << " seconds = "
         << (days = seconds / (60 * 60 * 24)) << " days, "
         << (hours = (seconds / (60 * 60)) % 24) << " hours, "
         << (minutes = (seconds / 60) % 60) << " minutes, "
         << (seconds % 60) << " seconds\n";
    return 0;
}