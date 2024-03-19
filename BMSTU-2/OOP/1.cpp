#include "iostream"

int main()
{
    int a[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            std::cin >> a[i][j];
    int mx{}, ix{};
    for (int i = 1; i < 4; i++)
    {
        if (a[i - 1][i - 1] * a[i][i] > mx)
        {
            mx = a[i - 1][i - 1] * a[i][i];
            ix = i;
        }
    }
    std::cout << "\n";
    std::cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            std::cout << a[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << a[ix][ix] << " " << ix + 1 << " " << &a[ix][ix];
    return 0;
}