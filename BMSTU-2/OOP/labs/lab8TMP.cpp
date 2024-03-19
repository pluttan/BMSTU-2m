#include <iostream>
#include <typeinfo>
using std::cout;

// Шаблон класса, можно использовать целочисленные и вещественные типы
// Для нормальной работы необходимо, чтобы второй тип мог неявно
// преобразовываться в первый (sizeof(T2)<=sizeof(T1))
template <typename T1, typename T2>
class set
{
public:
    // Структура, обобщающая передаваемые типы,
    // обеспечивающая возможность связывания, для создания односвязного списка
    struct setST
    {
        T1 val;
        bool flag;
        setST *next;
        setST() : val(0), next(0), flag(false) {}
        setST(T1 val) : val(val), next(0), flag(false) {}
        setST(T1 val, bool flag) : val(val), next(0), flag(flag) {}
        setST(T1 val, setST *next) : val(val), next(next), flag(false) {}
        setST(T1 val, bool flag, setST *next) : val(val), next(next), flag(flag) {}
    };
    setST *st = nullptr;

    // Конструктор: выделяет память для односвязного списка-множества
    set();

    // Деструктор: удаляет выделенную память
    ~set();

    // Функции, возвращающие 1 если элемент содержится
    // в множестве и 0 в обратном случае
    bool contains(T1 elem);
    bool contains(T2 elem);

    // Функции добавления элементов
    void add(T1 elem);
    void add(T2 elem);

    // Функции удаления элементов
    void del(T2 elem);
    void del(T1 elem);

    // Функция печати всего множества
    void print();
};
template <typename T1, typename T2>
set<T1, T2>::set()
{
    st = new setST;
}
template <typename T1, typename T2>
set<T1, T2>::~set()
{
    while (st)
    {
        setST *tmp = st;
        st = st->next;
        delete tmp;
    }
}
template <typename T1, typename T2>
bool set<T1, T2>::contains(T1 elem)
{
    setST *tmp = st;
    while (tmp)
    {
        if (tmp->val == elem and !tmp->flag)
            return true;
        tmp = tmp->next;
    }
    return false;
};
template <typename T1, typename T2>
void set<T1, T2>::add(T1 elem)
{
    if (!contains(elem))
        st = new setST(elem, 0, st);
};
template <typename T1, typename T2>
void set<T1, T2>::del(T1 elem)
{
    setST *tmp = st;
    setST *tmp2 = st;
    while (tmp)
    {
        if (tmp->val == elem and !tmp->flag)
        {
            tmp2->next = tmp->next;
            delete tmp;
            return;
        }
        tmp2 = tmp;
        tmp = tmp->next;
    }
    return;
};
template <typename T1, typename T2>
bool set<T1, T2>::contains(T2 elem)
{
    setST *tmp = st;
    while (tmp)
    {
        if (tmp->val == elem and tmp->flag)
            return true;
        tmp = tmp->next;
    }
    return false;
};
template <typename T1, typename T2>
void set<T1, T2>::add(T2 elem)
{
    if (!contains(elem))
        st = new setST(elem, 1, st);
};
template <typename T1, typename T2>
void set<T1, T2>::del(T2 elem)
{
    setST *tmp = st;
    setST *tmp2 = st;
    while (tmp)
    {
        if (tmp->val == elem and tmp->flag)
        {
            tmp2->next = tmp->next;
            delete tmp;
            return;
        }
        tmp2 = tmp;
        tmp = tmp->next;
    }
    return;
};
template <typename T1, typename T2>
void set<T1, T2>::print()
{
    setST *tmp = st;
    while (tmp)
    {
        if (tmp->next == NULL and tmp->val == 0)
            break;
        if (tmp->flag)
            cout << char(tmp->val);
        else
            cout << tmp->val;
        cout << ' ';
        tmp = tmp->next;
    };
    cout << '\n';
};

template <typename T1, typename T2>
class setP : public set<T1, T2>
{
public:
    using typename set<T1, T2>::setST;
    // Функция, возвращающая кол-во элементов в множестве
    int power();
};

template <typename T1, typename T2>
int setP<T1, T2>::power()
{
    setST *tmp = this->st;
    int i{};
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}
int main()
{
    setP<int, char> st;
    st.add(97);
    st.add('a');
    st.add(96);
    st.add('a');
    st.add(95);
    st.add('b');
    st.print();
    cout << "Символ а содержится в множестве: " << st.contains('a')
         << "\nУдаление символа а\n";
    st.del('a');
    cout << "Символ а содержится в множестве: " << st.contains('a') << '\n';
    st.print();
    cout << st.power() << '\n';
    return 0;
}