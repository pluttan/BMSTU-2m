#include "iostream"
#include "string"
using std::cin, std::cout, std::getline, std::stoi, std::string;

struct list
{
    int val;
    list *next;
    list *pred;
    list() : val(0), next(nullptr), pred(nullptr) {}
    list(int val) : val(val), next(nullptr), pred(nullptr) {}
    list(int val, list *next) : val(val), next(next), pred(nullptr) {}
    list(int val, list *next, list *pred) : val(val), next(next), pred(pred) {}
};

list *add(int val, list *prd = nullptr)
{
    list *ts = new list(val, prd);
    if (prd)
        prd->pred = ts;
    return ts;
}
void del(list *prd)
{
    while (prd)
    {
        list *tmp = prd->pred;
        delete prd;
        prd = tmp;
    }
}

int main()
{
    string s;
    getline(cin, s);
    int pr{};
    list *ts = nullptr;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ts = add(stoi(s.substr(pr, i - pr)), ts);
            pr = i;
        }
    }
    ts = add(stoi(s.substr(pr, s.length() - pr)), ts);
    int d1, d2;
    cin >> d1 >> d2;
    while (ts)
    {
        cout << ts->val;
        if (ts->val >= d1 && ts->val <= d2)
        {
            cout << "+";
        }
        cout << "\n";
        ts = ts->next;
    }
    del(ts);
    return 0;
}