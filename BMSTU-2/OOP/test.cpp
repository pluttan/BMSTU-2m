#pragma GCC optimize("unroll-loops", "O3")
#include "iostream"
// #include "vector"
// #include "algorithm"
#include "math.h"
using std::cout, std::cin;
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    bool fla = (a > 0 ? 0 : 1), flb = (b > 0 ? 0 : 1);
    a = abs(a);
    b = abs(b);
    long long mx = std::min(a, b);
    for (long long i = 1; i <= sqrt(mx); i++)
    {
        if (!(a % (mx / i)) and !(b % (mx / i)))
        {
            a /= mx / i;
            b /= mx / i;
            break;
        }
    }
    cout << (fla ? -1 : 1) * a << " " << (flb ? -1 : 1) * b;
    return 0;
}