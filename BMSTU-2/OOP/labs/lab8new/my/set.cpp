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

bool fl(Elem *c)
{
    // return (dynamic_cast<ElemInt *>(c) != nullptr);
    return (typeid(*c) == typeid(ElemInt));
}

class set
{
protected:
    Elem *st = nullptr;

public:
    set();
    ~set();
    bool contains(Elem *cn);
    void add(Elem *nw);
    void del(Elem *dt);
    void print();
};

class setP : public set
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

set::set()
{
    cout << "Set init\n";
};

set::~set()
{
    cout << "Set delete\n";
};

bool set::contains(Elem *cn)
{
    Elem *tmp = st;
    bool isInt = fl(cn);

    while (tmp)
    {
        bool isTmpInt = fl(tmp);
        if (isInt == isTmpInt)
        {
            if (isInt)
            {
                if (dynamic_cast<ElemInt *>(cn)->getElem() ==
                    dynamic_cast<ElemInt *>(tmp)->getElem())
                    return true;
            }
            else
            {
                if (dynamic_cast<ElemChar *>(cn)->getElem() ==
                    dynamic_cast<ElemChar *>(tmp)->getElem())
                    return true;
            }
        }
        tmp = tmp->next;
    };
    return false;
};
void set::add(Elem *nw)
{
    if (!contains(nw))
    {
        nw->next = st;
        st = nw;
    }
};
void set::del(Elem *dt)
{
    Elem *tmp = st;
    Elem *tm = st;
    bool isInt = fl(dt);

    while (tmp)
    {
        bool isTmpInt = fl(tmp);
        if (isInt == isTmpInt)
        {
            if (isInt)
            {
                if (dynamic_cast<ElemInt *>(dt)->getElem() ==
                    dynamic_cast<ElemInt *>(tmp)->getElem())
                {
                    tm->next = tmp->next;
                    tmp = tm;
                    return;
                }
            }
            else
            {
                if (dynamic_cast<ElemChar *>(dt)->getElem() ==
                    dynamic_cast<ElemChar *>(tmp)->getElem())
                {
                    tm->next = tmp->next;
                    tmp = tm;
                    return;
                }
            }
        }
        tm = tmp;
        tmp = tmp->next;
    }
};
void set::print()
{
    Elem *tmp = st;
    while (tmp)
    {
        tmp->print();
        tmp = tmp->next;
    };
};

int setP::power()
{
    Elem *tmp = st;
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
    setP gh;

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

    gh.print();
    cout << "int3 (12) in set: " << gh.contains(&int3) << "\n";
    gh.del(&int3);
    cout << "int3 (12) in set: " << gh.contains(&int3) << "\n";
    gh.print();
    cout << gh.power() << "\n";
    return 0;
}