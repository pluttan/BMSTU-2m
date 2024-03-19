#pragma GCC optimize("unroll-loops", "O3")
#include "iostream"
using std::cout, std::cin;
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    long long mx, mn, k;
    cin >> mx >> mn;
    if (mx < 0 and mn < 0)
    {
        mx = -1 * mx;
        mn = -1 * mn;
    }
    if (mx < mn)
    {
        mx += mn;
        mn = mx - mn;
        mx -= mn;
    };
    if (abs(mx - mn) < 1)
    {
        cout << (mx % 3 == 2);
        return 0;
    }
    if (mn < 0)
    {
        cout << (abs(mn) - 2) / 3 + 1 + (mx - 2) / 3 + 1;
    }
    else
    {
        cout << (mx - mn - (2 - abs(mn % 3))) / 3 + 1;
    }
    return 0;
}
