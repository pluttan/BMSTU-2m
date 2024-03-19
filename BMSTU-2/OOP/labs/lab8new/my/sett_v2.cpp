#include "iostream"
#include "typeinfo"
using std::cout;

class Elem
{
public:
    Elem *next;
    Elem(Elem *next = nullptr) : next(next){};
    virtual void print();
};

class ElemInt : public Elem
{
protected:
    int i;

public:
    ElemInt(int i, Elem *next = nullptr) : Elem(next), i(i){};
    void print();
    int getElem();
};

class ElemChar : public Elem
{
protected:
    char c;

public:
    ElemChar(char c, Elem *next = nullptr) : Elem(next), c(c){};
    void print();
    char getElem();
};

template <class element>
class set
{
protected:
    element *st = nullptr;

public:
    set();
    ~set();
    bool contains(element *cn);
    void add(element *nw);
    void del(element *dt);
    void print();
};

template <class element>
class setP : public set<element>
{
public:
    int power();
};

void Elem::print()
{
    cout << "parent elem class";
};

void ElemInt::print()
{
    cout << "(int)" << i << "\n";
};

int ElemInt::getElem()
{
    return i;
};

void ElemChar::print()
{
    cout << "(char)" << c << "\n";
};

char ElemChar::getElem()
{
    return c;
};

// class ElemFloat : public Elem
// {
// protected:
//     float f;

// public:
//     ElemFloat(float f, Elem *next = nullptr) : Elem(next), f(f){};
//     void print();
//     float getElem();
// };

// void ElemFloat::print()
// {
//     cout << "(float)" << f << "\n";
// };

// float ElemFloat::getElem()
// {
//     return f;
// };

template <class element>
set<element>::set()
{
    cout << "Set init\n";
};

template <class element>
set<element>::~set()
{
    cout << "Set delete\n";
};

template <class element>
bool set<element>::contains(element *cn)
{
    element *tmp = st;

    while (tmp)
    {
        if (cn == tmp)
            return true;
        tmp = tmp->next;
    };
    return false;
};

template <class element>
void set<element>::add(element *nw)
{
    if (!contains(nw))
    {
        nw->next = st;
        st = nw;
    }
};

template <class element>
void set<element>::del(element *dt)
{
    element *tmp = st;
    element *tm = st;

    while (tmp)
    {
        if (dt == tmp)
        {
            tm->next = tmp->next;
            tmp = tm;
            return;
        }
        tm = tmp;
        tmp = tmp->next;
    }
};

template <class element>
void set<element>::print()
{
    element *tmp = st;
    while (tmp)
    {
        tmp->print();
        tmp = tmp->next;
    };
};

template <class element>
int setP<element>::power()
{
    element *tmp = this->st;
    int count{};
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    };
    return count;
}

int main()
{
    setP<Elem> gh;

    ElemInt int1(10);
    ElemInt int2(11);
    ElemInt int3(12);
    ElemInt int4(13);
    ElemInt int5(14);
    ElemChar char1('a');
    ElemChar char2('b');
    ElemChar char3('c');
    ElemChar char4('d');
    ElemChar char5('e');
    // ElemFloat float1(10.1);
    // ElemFloat float2(10.2);
    // ElemFloat float3(10.3);
    // ElemFloat float4(10.4);
    // ElemFloat float5(10.5);

    gh.add(&int1);
    gh.add(&int1);
    gh.add(&int2);
    gh.add(&char1);
    gh.add(&char2);
    gh.add(&int3);
    gh.add(&int4);
    gh.add(&int5);
    gh.add(&char3);
    gh.add(&char4);
    gh.add(&char5);
    // gh.add(&float1);
    // gh.add(&float2);
    // gh.add(&float3);
    // gh.add(&float4);
    // gh.add(&float5);

    gh.print();
    cout << "int3 (12) in set: " << gh.contains(&int3) << "\n";
    gh.del(&int3);
    cout << "int3 (12) in set: " << gh.contains(&int3) << "\n";
    // cout << "float4 (10.4) in set: " << gh.contains(&float4) << "\n";
    // gh.del(&float4);
    // cout << "float4 (10.4) in set: " << gh.contains(&float4) << "\n";
    gh.print();
    cout << gh.power() << "\n";
    return 0;
}
