// 1
// -1
// 0
// 1
// 1
// 0
// 0
// 1
// 3
#include <iostream>
using std::cout, std::cin;

float getx(float a1, float a2,
           float b1, float b2,
           float c1, float c2)
{
    return (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
};

float gety(float a1, float a2,
           float b1, float b2,
           float c1, float c2)
{

    return (c2 * a1 - c1 * a2) / (a1 * b2 - a2 * b1);
};

int main()
{
    float a1, b1, c1, a2, b2, c2, a3, b3, c3;
    cout << "Введите a, b, c для каждого уравнения\n";
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3;
    if ((a1 / a2 != b1 / b2) &&
        (a1 / a3 != b1 / b3) &&
        (a2 / a3 != b2 / b3))
    {
        float y1 = gety(a1, a2, b1, b2, c1, c2);
        float x1 = getx(a1, a2, b1, b2, c1, c2);
        float y2 = gety(a1, a3, b1, b3, c1, c3);
        float x2 = getx(a1, a3, b1, b3, c1, c3);
        float y3 = gety(a2, a3, b2, b3, c2, c3);
        float x3 = getx(a2, a3, b2, b3, c2, c3);
        int s = abs(((y1 + y2) / 2) * (x2 - x1) +
                    ((y2 + y3) / 2) * (x3 - x2) +
                    ((y1 + y3) / 2) * (x3 - x1)) /
                2;
        cout << "Площадь равна " << s << "\n";
    }
    else
    {
        cout << "Прямые не образуют треугольник \n";
    };
}