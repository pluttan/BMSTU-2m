#pragma GCC optimize("unroll-loops", "O3")
#include "iostream"
using std::cout, std::cin;
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    long long a;
    cin >> a;
    cout << a * (a + 1) / 2;
}