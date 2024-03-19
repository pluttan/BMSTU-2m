Задание
Дана символьная строка, состоящая из положительных целых чисел в диапазоне от 0 до 65535, разделенных пробелом. Составить программу, которая вводит строку, преобразует числа из символьного представления в целое и организует из этих чисел двунаправленный список, отсортированный по возрастанию. Определить количество элементов, сумма цифр которых больше введенного с клавиатуры числа.
Решение

1. Организуем двусвязный список, функции его инициализации и добавления элементов
   ```cpp
   struct vect2
    {
        int inf;
        vect2 *p;
        vect2 *n;
    };
    vect2 *init(int info)
    {
        vect2 *fst = new vect2;
        fst->inf = info;
        fst->p = NULL;
        fst->n = NULL;
        return fst;
    };

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
   ```
2. Читаем данные из кносоли, сортируем их и добавляем в список
   ```cpp
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
   ```
3. Последний элемент сортируем отдельно
   ```cpp
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
    ```
4. Создадим функцию которая считает сумму цифр числа
   ```cpp
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
   ```
5. Определими выведем количество элементов, сумма цифр которых больше введенного с клавиатуры числа.
   ```cpp
   while (tlst->n != NULL)
    {
        if (ch < colinch(tlst->inf))
            count++;
        cout << tlst->inf << " ";
        tlst = tlst->n;
    };
    cout << "\n"
         << count << "\n";
   ```
Вот полный код программы с отладкой:
```cpp
#include "iostream"
#include "string"

using std::cout, std::string, std::cin, std::stoi;
struct vect2
{
    int inf;
    vect2 *p;
    vect2 *n;
};

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

vect2 *init(int info)
{
    vect2 *fst = new vect2;
    fst->inf = info;
    fst->p = NULL;
    fst->n = NULL;
    return fst;
};

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
```
