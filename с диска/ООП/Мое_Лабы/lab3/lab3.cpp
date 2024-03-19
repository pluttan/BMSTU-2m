#include "iostream"
using namespace std;
bool check_palin(int n)
{
    int n1 = n;
    int n2 = 0;
    int i = 0;
    while (n1 > 0)
    {
        n2 = (n1 % 10) + n2 * 10;
        i++;
        n1 /= 10;
    };
    return n2 == n;
};
int main()
{
    int n;
    int counter = 0;
    cout << "Введите n (1, n):\n";
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (check_palin(i) and check_palin(i * i))
        {
            cout << i << " " << i * i << "\n";
            counter++;
        };
    }
    cout << counter;
    return 0;
};