#include <iostream>
#include <typeinfo>
using std::cout;

struct setST
{
    int val;
    bool isChar;
    setST *next;
    setST() : val(0), next(0), isChar(false) {}
    setST(int val) : val(val), next(0), isChar(false) {}
    setST(int val, bool isChar) : val(val), next(0), isChar(isChar) {}
    setST(int val, setST *next) : val(val), next(next), isChar(false) {}
    setST(int val, bool isChar, setST *next) : val(val), next(next), isChar(isChar) {}
};

class set
{
public:
    setST *st = nullptr;
    set();
    ~set();
    bool contains(int elem);
    void add(int elem);
    void del(int elem);
    bool contains(char elem);
    void add(char elem);
    void del(char elem);
    void print();
};
set::set()
{
    st = new setST;
}
set::~set()
{
    while (st)
    {
        setST *tmp = st;
        st = st->next;
        delete tmp;
    }
}
bool set::contains(int elem)
{
    setST *tmp = st;
    while (tmp)
    {
        if (tmp->val == elem and !tmp->isChar)
            return true;
        tmp = tmp->next;
    }
    return false;
};
void set::add(int elem)
{
    if (!contains(elem))
        st = new setST(elem, 0, st);
};
void set::del(int elem)
{
    setST *tmp = st;
    setST *tmp2 = st;
    while (tmp)
    {
        if (tmp->val == elem and !tmp->isChar)
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
bool set::contains(char elem)
{
    setST *tmp = st;
    while (tmp)
    {
        if (tmp->val == elem and tmp->isChar)
            return true;
        tmp = tmp->next;
    }
    return false;
};
void set::add(char elem)
{
    if (!contains(elem))
        st = new setST(elem, 1, st);
};
void set::del(char elem)
{
    setST *tmp = st;
    setST *tmp2 = st;
    while (tmp)
    {
        if (tmp->val == elem and tmp->isChar)
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
void set::print()
{
    setST *tmp = st;
    while (tmp)
    {
        if (tmp->next == NULL and tmp->val == 0)
            break;
        if (tmp->isChar)
            cout << char(tmp->val);
        else
            cout << tmp->val;
        cout << ' ';
        tmp = tmp->next;
    };
    cout << '\n';
};
class setP : public set
{
public:
    int power()
    {
        setST *tmp = st;
        int i{};
        while (tmp)
        {
            i++;
            tmp = tmp->next;
        }
        return i;
    }
};
int main()
{
    setP st;
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