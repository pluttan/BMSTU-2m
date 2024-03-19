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
    if (mx - mn < 1)
    {
        cout << (mx % 3 == 2);
        return 0;
    }
    if (mn < 0)
    {
        k = mx;
        int p = (mx - 2) / 3 + 1;
        int q = (abs(mn) - 2) / 3 + 1;
        cout << q + p;
    }
    else
    {
        k = mx - mn;
        int q = 2 - abs(mn % 3);
        cout << (k - q) / 3 + 1;
    }
    return 0;
}