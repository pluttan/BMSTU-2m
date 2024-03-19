#include "iostream"
#include "string"

using std::cout, std::string, std::cin, std::stoi;

// Готовим структуру для реализации двусвязного списка
struct vect2
{
    int inf;
    vect2 *p;
    vect2 *n;
};

// Функция, возвращающая сумму цифр числа
int colinch(int ch)
{
    int col = 0;
    while (ch != 0)
    {
        col += ch % 10;
        ch /= 10;
    };
    return col;
};

// Функция инициализации двусвязного списка
vect2 *init(int info)
{
    vect2 *fst = new vect2;
    fst->inf = info;
    fst->p = NULL;
    fst->n = NULL;
    return fst;
};

// Функция добавления элемента в двусвязный список
vect2 *addelem(vect2 *lst, int info)
{
    vect2 *pr;
    vect2 *temp = new vect2;
    pr = lst->n;
    lst->n = temp;
    temp->inf = info;
    temp->n = pr;
    temp->p = lst;
    if (pr != NULL)
        pr->p = temp;
    return (temp);
}

int main()
{
    string str, tmp;
    int predi = 0;
    getline(cin, str);
    str += " 70000 ";
    vect2 *fst = nullptr;
    vect2 *tlst = fst;
    vect2 *ptlst = fst;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (isspace(str[i]))
        {
            tmp = "";
            for (int j = predi; j < i; j++)
                tmp += str[j];
            int itmp = stoi(tmp);

            if (predi == 0)
            {
                fst = init(itmp);
            }
            else
            {
                tlst = fst;
                ptlst = fst;
                while (tlst != NULL and tlst->inf < itmp)
                {
                    ptlst = tlst;
                    tlst = tlst->n;
                };
                addelem(ptlst, itmp);
            };
            predi = i + 1;
        };
    };
    if (fst->inf > fst->n->inf)
    {
        int itmp = fst->inf;
        fst = fst->n;
        tlst = fst;
        ptlst = fst;
        while (tlst != NULL and tlst->inf < itmp)
        {
            tlst = tlst->n;
            ptlst = tlst;
        };
        addelem(ptlst->p, itmp);
    };
    tlst = fst;
    int ch;
    int count = 0;
    cin >> ch;
    while (tlst->n != NULL)
    {
        if (ch < colinch(tlst->inf))
            count++;
        cout << tlst->inf << " ";
        tlst = tlst->n;
    };
    cout << "\n"
         << count << "\n";
};