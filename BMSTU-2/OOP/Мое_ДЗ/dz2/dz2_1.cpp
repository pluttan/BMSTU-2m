#include "iostream"
#include "regex"
#include <chrono>
using std::cin, std::cout,
    std::regex, std::string,
    std::regex_replace, std::regex_search;

//   abc  def f    sdf

string regexDesition(string str)
{
    auto start_time = std::chrono::steady_clock::now();
    regex re1("\\s[a-zA-Z1-9]\\s"), re2("\\s\\s"), re3("^\\s"), re4("\\s$");
    while (regex_search(str, re1) or
           regex_search(str, re2) or
           regex_search(str, re3) or
           regex_search(str, re4))
        str =
            regex_replace(
                regex_replace(
                    regex_replace(
                        regex_replace(
                            str, re4, ""),
                        re3, ""),
                    re2, " "),
                re1, " ");
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "Time:" << elapsed_ns.count() << " ns\n";
    return str;
}

int strSpace(int c)
{
    return c == 32;
}

string strGetSub(string str, int start, int end)
{
    string subStr;
    for (int i = start; i < end; i++)
        subStr = subStr + str[i];
    return subStr;
}

string strDelete(string str, int start, int step)
{
    return strGetSub(str, 0, start) +
           strGetSub(str, start + step, str.length());
}

string myDesition(string str)
{
    auto start_time = std::chrono::steady_clock::now();
    int i = 0;
    while (i < str.length())
    {
        if (strSpace(str[i]) and strSpace(str[i + 1]))
        {
            str = strDelete(str, i + 1, 1);
            i = 0;
        };
        if (strSpace(str[i]) and strSpace(str[i + 2]))
        {
            str = strDelete(str, i + 1, 2);
            i = 0;
        };
        if (i == 0 and strSpace(str[i]))
        {
            str = strDelete(str, i, 1);
            i = 0;
        };
        if (i == str.length() - 1 and strSpace(str[i]))
        {
            str = strDelete(str, i, 1);
            i = 0;
        };
        i++;
    };
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "Time:" << elapsed_ns.count() << " ns\n";
    return str;
}

int main()
{
    string str;
    while (true)
    {
        cout << "\n\nВведите строку: ";
        getline(cin, str);
        if (str != "0")
        {
            cout << "Input:" << str << "\n\n";
            cout << "My desition:\n"
                 << myDesition(str) << "%\n\n";
            cout << "Desition with regex:\n"
                 << regexDesition(str) << "%\n";
        }
        else
            break;
    };
    return 0;
}