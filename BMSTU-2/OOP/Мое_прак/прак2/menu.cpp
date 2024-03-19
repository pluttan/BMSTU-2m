#include <termios.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>

using std::string, std::stringstream, std::random_device,
    std::mt19937, std::uniform_int_distribution,
    std::oct, std::to_string, std::hex,
    std::cout;

class Number
{
private:
    int randomInt(int min, int max)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(min, max);
        int randomNum = dis(gen);
        return randomNum;
    }

public:
    string value;
    int base;
    Number()
    {
        stringstream ss;
        srand(time(NULL));
        base = randomInt(0, 2);
        switch (base)
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

class Color
{
public:
    void setCyanBackground()
    {
        cout << "\033[46m";
    }

    void resetColor()
    {
        cout << "\033[0m";
    }

    void printRed(std::string str)
    {
        cout << "\033[1;31m" << str << "\033[0m";
    }

    void printGreen(std::string str)
    {
        cout << "\033[1;32m" << str << "\033[0m";
    }

    void printYellow(std::string str)
    {
        cout << "\033[1;33m" << str << "\033[0m";
    }

    void printBlue(std::string str)
    {
        cout << "\033[1;34m" << str << "\033[0m";
    }

    void printMagenta(std::string str)
    {
        cout << "\033[1;35m" << str << "\033[0m";
    }

    void printCyan(std::string str)
    {
        cout << "\033[1;36m" << str << "\033[0m";
    }
    void print(std::string str)
    {
        cout << str;
    }
};

class Game : Color, Number
{
private:
    int getch()
    {
        int ch;
        struct termios t;
        tcgetattr(STDIN_FILENO, &t);
        t.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &t);
        ch = getchar();
        t.c_lflag |= ICANON | ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &t);
        return ch;
    }

public:
    int mainMenu()
    {
        char ch;
        int poz{};
        do
        {
            system("clear");
            printCyan("-----------------------\n");
            printCyan("|");
            if (poz == 0)
                setCyanBackground();
            printBlue("     Начать игру     ");
            resetColor();
            printCyan("|\n|");
            if (poz == 1)
                setCyanBackground();
            printBlue("    Правила игры     ");
            resetColor();
            printCyan("|\n|");
            if (poz == 2)
                setCyanBackground();
            printRed("        Выйти        ");
            resetColor();
            printCyan("|\n");
            printCyan("-----------------------");
            ch = getch();
            if (ch == '\033')
            {                 // символ ESC (0x1B)
                ch = getch(); // пропускаем символ [
                if (ch == 27)
                    return 1;
                ch = getch(); // считываем код клавиши
                if (ch == 'A')
                {
                    if (poz > 0)
                        poz--;
                }
                else if (ch == 'B')
                {
                    if (poz < 2)
                        poz++;
                }
                else if (ch == 27)
                {
                    return 1;
                }
            }
            if (ch == '\n')
            {
                if (poz == 2)
                {
                    system("clear");
                    return 1;
                }
                if (poz == 1)
                    mainRools();

                if (poz == 0)
                    mainGame();
            }
        } while (ch != 27);
        return 0;
    }
    int mainGame()
    {
        char ch;
        Number n;
        string us;
        string nums{"0123456789abcdef"};
        bool n1{}, n2{}, n3{};
        do
        {
            system("clear");
            printMagenta("Загаданное число: ");
            if (n1)
                printGreen(string{1, n.value[0]});
            else
                printRed("_");
            if (n2)
                printGreen(string{1, n.value[1]});
            else
                printRed("_");
            if (n3)
                printGreen(string{1, n.value[2]});
            else
                printRed("_");
            cout << "\n";
            printMagenta("Основание числа: ");
            cout << (n.base == 0 ? 8 : (n.base == 1 ? 10 : (n.base == 2 ? 16 : 0))) << "\n";
            printYellow("Количество попыток: ");
            cout << us.length() << "\n";
            printBlue("Использованные числа: ");
            for (unsigned long i = 0; i < us.length(); i++)
                cout << us[i] << ' ';
            cout << "\n";
            if (not(n1 && n2 && n3))
                printCyan("Введите число\n");
            else
                printGreen("Игра окончена\n");
            printCyan("Нажмите ");
            printRed("esc");
            printCyan(" для выхода");
            ch = getch();
            if (ch == '\033')
            {
                return 1;
            }
            if (not(n1 && n2 && n3))
            {
                for (unsigned long i = 0; i < nums.length(); i++)
                {
                    if (ch == nums[i])
                    {
                        us += ch;
                        if (n.value[0] == ch)
                            n1 = true;
                        if (n.value[1] == ch)
                            n2 = true;
                        if (n.value[2] == ch)
                            n3 = true;
                    }
                }
            }
        } while (ch != 27);
        return 0;
    }
    int mainRools()
    {
        system("clear");
        printCyan("--------------------------------------------------------------------------------------\n");
        printCyan("|");
        printGreen("                                Угадай число                                        ");
        printCyan("|\n|");
        cout << "    Программа “задумывает” трехзначное число восьмеричной, десятичной или шест-     ";
        printCyan("|\n|");
        cout << "    надцатеричной систем счисления и рисует на экране три прочерка. Играющий за     ";
        printCyan("|\n|");
        cout << "      один ход вводит одну цифру. Если она входит в запись числа, то ставится       ";
        printCyan("|\n|");
        cout << "    вместо прочерка. Необходимо угадать число за наименьшее количество попыток.     ";
        printCyan("|\n");
        printCyan("--------------------------------------------------------------------------------------\n");
        printCyan("Нажмите любую клавишу для выхода");
        getch();
        return 0;
    }
    Game()
    {
        mainMenu();
    }
};

int main()
{
    Game game;
    return 0;
}