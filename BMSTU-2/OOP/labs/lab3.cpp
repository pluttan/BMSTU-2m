#include "iostream"
using namespace std;

// Функция, проверяющая является ли число палиндромом
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

    // В цикле проверяем все числа от 1 до введенного на совпадание по условию
    // (само число и его квадрат палиндром)
    for (int i = 1; i < n; i++)
    {
        if (check_palin(i) and check_palin(i * i))
        {
            cout << i << " " << i * i << "\n";
            counter++;
        };
    }

    // Выводим количество найденных чисел
    cout << counter;
    return 0;
};