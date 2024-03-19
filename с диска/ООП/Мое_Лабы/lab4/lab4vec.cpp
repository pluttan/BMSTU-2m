#include "iostream"
#include "string"
#include "vector"
using namespace std;

// 5
// halo nanga gave magana vin

struct chr
{
    char ch;
    int num;
};

int main()
{
    int numch;
    vector<string> masstr;
    cin >> numch;
    int max = 1;
    for (int i = 0; i < numch; i++)
    {
        string tmp;
        cin >> tmp;
        masstr.push_back(tmp);
    };
    vector<chr> mas;
    int chaword = 0;
    for (int q = 0; q < int(masstr.size()); q++)
    {
        string str = masstr[q];
        for (int i = 0; i < int(str.size()); i++)
        {
            if (char(str[i]) == char('a'))
            {
                chaword++;
                bool flag = 1;
                for (int j = 0; j < int(mas.size()); j++)
                {
                    if (str[i - 1] == mas[j].ch)
                    {
                        mas[j].num++;
                        flag = 0;
                        if (mas[j].num > max)
                            max = mas[j].num;
                    };
                };
                if (flag)
                {
                    chr tmp;
                    tmp.ch = str[i - 1];
                    tmp.num = 1;
                    mas.push_back(tmp);
                };
            };
        };
        if (chaword > 2)
        {
            cout << &mas << "\n";
        };
        chaword = 0;
    };
    for (int j = max; j > 0; j--)
    {
        for (int i = 0; i < int(mas.size()); i++)
        {
            if (mas[i].num == j)
                cout << mas[i].ch << " " << mas[i].num << "\n";
        };
    };
};