#include "iostream"
using std::string, std::getline, std::cin, std::cout;

class Word
{
public:
    string text;
    int length, consChars;
    int getConsChars();
    Word(string t, int len)
    {
        text = t;
        length = len;
        getConsChars();
    }
};
int Word::getConsChars()
{
    char cons[] = {'a', 'e', 'y', 'u', 'i', 'o'};
    consChars = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (text[i] == cons[j])
            {
                consChars++;
            }
        }
    }
    return consChars;
}

struct Node
{
    Word data;
    Node *left;
    Node *right;
};

Node *insert(Node *root, Word val)
{
    if (root == NULL)
    {
        return new Node{val, nullptr, nullptr};
    }
    if (val.text < root->data.text)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node *root, string val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data.text == val)
    {
        return true;
    }
    if (val < root->data.text)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

int count;

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if ((root->data.length - root->data.consChars) > root->data.consChars)
        count++;
    preorder(root->left);
    preorder(root->right);
}

int z1(string sentence, int len, string *toSearch, int lenToSearch)
{
    Node *splitSentence = NULL;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (sentence[i] == ' ')
        {
            Word word(sentence.substr(j, i - j), i - j);
            splitSentence = insert(splitSentence, word);

            j = i;
        }
    };
    Word word(sentence.substr(j, len - j), len - j);
    splitSentence = insert(splitSentence, word);
    preorder(splitSentence);
    for (int i = 0; i < lenToSearch; i++)
    {
        cout << toSearch[i] << ": " << search(splitSentence, toSearch[i]) << "\n";
    }
    return count;
}

int main()
{
    string sentence;
    getline(cin, sentence);
    string toSearch[]{"hello", "123"};
    cout << z1(sentence, sentence.length(), toSearch, sizeof(toSearch) / sizeof(toSearch[0]));
    return 0;
}