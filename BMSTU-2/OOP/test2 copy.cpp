#pragma GCC optimize("unroll-loops", "O3")
#include "iostream"
using std::cout, std::cin;
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    long long mx, mn, k;
    cin >> mx >> mn;
    if (mx < mn)
    {
        mx += mn;
        mn = mx - mn;
        mx -= mn;
    };
    if (mx < 0)
        mx = -1 * mx;
    k = mx - mn;
    int q = 2 - mn % 3;
    return (k - q) / 3 + 1;
}