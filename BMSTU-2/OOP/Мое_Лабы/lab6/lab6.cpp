#include "iostream"
using std::cin, std::cout;

struct binTree
{
    binTree *left;
    binTree *right;
    int data;
};

binTree *insert(int item, binTree *root)
{
    binTree *p;
    p = new binTree;
    binTree *parent;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    parent = NULL;
    if (root->data == -1)
    {
        root = p;
    }
    else
    {
        binTree *ptr;
        ptr = root;
        while (ptr != NULL)
        {
            parent = ptr;
            if (item > ptr->data)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if (item < parent->data)
            parent->left = p;
        else
            parent->right = p;
    }
    return root;
}

void printBinTree(binTree *ptr, bool reverse)
{
    if (ptr != NULL)
    {
        if (reverse)
        {
            printBinTree(ptr->right, reverse);
            cout << ptr->data << " ";
            printBinTree(ptr->left, reverse);
        }
        else
        {
            printBinTree(ptr->left, reverse);
            cout << ptr->data << " ";
            printBinTree(ptr->right, reverse);
        };
    }
}

int main()
{
    binTree *b;
    b = new binTree;
    b->data = -1;
    int tmp{};
    while (tmp != -1)
    {
        cin >> tmp;
        if (tmp != -1)
            b = insert(tmp, b);
    };
    printBinTree(b, 0);
    cout << "\n";
    printBinTree(b, 1);
}