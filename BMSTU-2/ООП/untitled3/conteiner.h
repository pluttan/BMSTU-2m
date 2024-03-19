#ifndef CONTEINER_H
#define CONTEINER_H
#include <QListWidget>
#include <QListView>
#include <string>
#include <typeinfo>
#include <vector>
#include <algorithm>
class conteiner
{
protected:
    std::vector<int>intmas;
    std::vector<char>charmas;
    std::vector<int>boolmas;
public:
    conteiner(){};
    template <typename t> void append(t a);
    QString operator[](int index);
    void print(QListWidget *list);
    void clear(){intmas.clear();charmas.clear();boolmas.clear();}
    int size(){return boolmas.size();}

};
class sort_conteiner:public conteiner
{
public:
    void sort();

};
template <typename t>
void conteiner::append(t a)
{
    if (typeid(t)==typeid(int))
    {
        this->intmas.push_back(a);
        this->boolmas.push_back(this->intmas.size());
    }
    else if (typeid(t)==typeid(char))
    {
        this->charmas.push_back(a);
        this->boolmas.push_back(-this->charmas.size());
    }
}

#endif // CONTEINER_H
