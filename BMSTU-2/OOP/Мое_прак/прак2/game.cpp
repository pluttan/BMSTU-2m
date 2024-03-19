/*

Выполнить структурную декомпозицию, разработать структурную схему и алгоритмы программ. Реализовать на С++ в консольном режиме. Предусмотреть примитивный интерфейс типа меню, позволяющий выбирать нужную операцию.
”Угадай число”. Программа “задумывает” трехзначное число восьмеричной, десятичной или шестнадцатеричной систем счисления и рисует на экране три прочерка. Играющий за один ход вводит одну цифру. Если она входит в запись числа, то проставляется вместо прочерка. Необходимо угадать число за как можно меньшее количество попыток. Реализовать класс-шаблон, реализующий логику игры. Параметром шаблона должен быть класс, обеспечивающий использование чисел соответствующей системы счисления.

*/
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>

using std::string, std::stringstream, std::oct, std::to_string, std::hex, std::cout, std::random_device, std::mt19937, std::uniform_int_distribution;

int randomInt(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    int randomNum = dis(gen);
    return randomNum;
}

class Number
{
private:
    string value;

public:
    Number()
    {
        stringstream ss;
        srand(time(NULL));
        int base_choice = randomInt(0, 2);
        switch (base_choice)
        {
        case 0:
            ss << oct << randomInt(64, 512);
            value = ss.str();
            ss.str("");
            break;
        case 1:
            value = to_string(randomInt(100, 1000));
            break;
        case 2:
            ss << hex << randomInt(256, 4096);
            value = ss.str();
            ss.str("");
            break;
        default:
            value = "0";
            break;
        }
    }
    void print()
    {
        cout << "Number is: " << value << "\n";
    }
};

int main()
{
    Number n1;
    n1.print();
    Number n2;
    n2.print();
    Number n3;
    n3.print();
    return 0;
}