#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using std::ifstream, std::string, std::ofstream,
    std::cout, std::cin,
    std::getline, std::copy, std::getline, std::stoi;

string cutStr(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
            if (count == 4)
            {
                str = str.substr(0, i - 3);
                break;
            }
        }
        else
        {
            count = 0;
        }
    }
    return str;
}

string cutStrInv(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
            if (count == 4)
            {
                str = str.substr(i, str.length());
                break;
            }
        }
        else
        {
            count = 0;
        }
    }
    return str;
}

int getSize()
{
    ifstream file("book_titles.txt");
    string line;
    int i = 0;
    while (getline(file, line))
    {
        i++;
    }
    cout << "Найден размер файла: " << i << " строк\n";
    file.close();
    return i;
}

string *readFile(int i)
{
    string *mas = new string[i];
    ifstream file("book_titles.txt");
    int j = 0;
    while (getline(file, mas[j]))
    {
        j++;
    };
    file.close();
    cout << "Файл прочитан\n";
    return mas;
}

int partition(string arr[], int ims[], int low, int high)
{
    string pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            string temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            int tm = ims[i];
            ims[i] = ims[j];
            ims[j] = tm;
        }
    }
    string temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    int tm = ims[i + 1];
    ims[i + 1] = ims[high];
    ims[high] = tm;
    return i + 1;
}

void quickSort(string arr[], int ims[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, ims, low, high);
        quickSort(arr, ims, low, pi - 1);
        quickSort(arr, ims, pi + 1, high);
    }
}

void indFile(int *iMas, int size)
{
    ofstream file("index.txt");
    for (int i = 1; i < size; i++)
    {
        file << iMas[i] << "\n";
    }
    file << iMas[size];
    file.close();
    cout << "Индексы сохранены"
         << "\n";
}

int binarySearch(string arr[], int left, int right, string x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        string sh = cutStr(arr[mid]);
        if (sh == x)
        {
            while (sh == x)
                sh = cutStr(arr[--mid]);
            return mid;
        }
        if (sh > x)
        {
            return binarySearch(arr, left, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int searchInt(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

string fileSearch(int x)
{
    ifstream file("book_titles.txt");
    string line;
    int i = 0;
    while (getline(file, line))
    {
        if (i == x)
            break;
        i++;
    }
    file.close();
    return line;
}

int fileSearchInd(int x)
{
    ifstream file("index.txt");
    string line;
    int i = 0;
    while (getline(file, line))
    {
        if (i == x)
            break;
        i++;
    }
    file.close();
    return stoi(line);
}

int fileSearchIndInv(int x)
{
    ifstream file("index.txt");
    string line;
    int i = 0;
    while (getline(file, line))
    {
        if (stoi(line) == x)
            break;
        i++;
    }
    file.close();
    return i + 1;
}

int binarySearchFile(int left, int right, string x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        string sh = cutStr(fileSearch(fileSearchInd(mid)));
        if (sh == x)
        {
            while (sh == x)
                sh = cutStr(fileSearch(fileSearchInd(--mid)));
            return mid;
        }
        if (sh > x)
        {
            return binarySearchFile(left, mid - 1, x);
        }
        return binarySearchFile(mid + 1, right, x);
    }
    return -1;
}

auto now()
{
    return std::chrono::steady_clock::now();
}

auto out(std::__1::chrono::steady_clock::time_point start_time)
{
    std::cout << "Время: "
              << (std::chrono::duration_cast<std::chrono::nanoseconds>(now() - start_time)).count()
              << " ns\n";
}

int main()
{
    const int size = getSize();
    string *ms = readFile(size);
    int ims[size];
    for (int i = 0; i < size; i++)
        ims[i] = i;
    quickSort(ms, ims, 0, size);
    cout << "Файл отсортирован"
         << "\n";
    indFile(ims, size);

    string inp = "";
    while (true)
    {
        cout << "\n\nВведите название книги для поиска или 0 чтобы выйти: ";
        getline(cin, inp);
        if (inp != "0")
        {
            auto start_time = now();
            int outSort = binarySearch(ms, 0, size - 1, inp);
            cout << "Индекс: " << outSort
                 << " | Номер строки в файле: " << searchInt(ims, size, outSort)
                 << " | Год выхода: " << cutStrInv(ms[outSort])
                 << "гг | Массивы в лок. памяти | ";
            out(start_time);

            start_time = now();
            outSort = binarySearchFile(0, size - 1, inp) + 1;
            cout << "Индекс: " << outSort
                 << " | Номер строки в файле: " << fileSearchIndInv(outSort)
                 << " | Год выхода: " << cutStrInv(ms[outSort])
                 << "гг | Массивы в файлах| ";
            out(start_time);
        }
        else
            break;
    };

    return 0;
}