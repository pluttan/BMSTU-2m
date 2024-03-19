#include "iostream"
using std::cin, std::cout;
#define n 10

int main()
{
    // Создаем переменные для нахождения искомого числа и матрицу nxn
    int max = 0;
    int jmax{};
    int imax{};
    int mas[n][n];

    // Создадим, заполним и выведем матрицу, найдем и выведем
    // искомый элемент, а также столбец и строку, на пересечении
    // которых расположен найденный элемент
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] = rand() % 1000;
            cout << mas[i][j] << " ";
            if (i != 0 and i == j and max < mas[i][j] * mas[i - 1][j - 1])
            {
                max = mas[i][j] * mas[i - 1][j - 1];
                imax = i;
                jmax = j;
            }
        }
        cout << "\n";
    }
    cout << "max = " << max << " i = " << imax << " j = " << jmax;

    // Введем дополнительные переменные для вывода матрицы зигзагом
    int i = 0;
    int j = 0;
    bool vect = 1;
    bool right = 0;
    cout << "\n"
         << mas[i][j] << " ";

    // Цикл по выводу матрицы зигзагом
    while (i < n - 1 or j < n - 1)
    {
        if (((i == 0) and (j == (n - 1)) and n % 2 == 1) or
            ((j == 0) and (i == (n - 1)) and n % 2 == 0))
        {
            right = 1;
            vect = !vect;
        }
        if (!right)
        {
            if (vect)
            {
                j++;
                cout << mas[i][j] << " ";
                while (j != 0)
                {
                    j--;
                    i++;
                    cout << mas[i][j] << " ";
                };
            }
            else
            {
                i++;
                cout << mas[i][j] << " ";
                while (i != 0)
                {
                    j++;
                    i--;
                    cout << mas[i][j] << " ";
                };
            };
        }
        else
        {
            if (vect)
            {
                j++;
                cout << mas[i][j] << " ";
                while (j != n - 1)
                {
                    j++;
                    i--;
                    cout << mas[i][j] << " ";
                };
            }
            else
            {
                i++;
                cout << mas[i][j] << " ";
                while (i != n - 1)
                {
                    j--;
                    i++;
                    cout << mas[i][j] << " ";
                };
            };
        };
        vect = !vect;
    };
    return 0;
}