#include <QCoreApplication>
#include <QSet>
#include <QString>
#include <QFile>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <QElapsedTimer>
using std::set, std::string, std::rand;

QString generateWords()
{
    srand(time(NULL));
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString word = "";
    for (int j = 0; j < arc4random() % 10000; j++)
    {
        int length = arc4random() % 10 + 1;
        for (int i = 0; i < length; i++)
        {
            int index = arc4random() % 26;
            char letter = alphabet[index];
            word += letter;
        }
        word += ' ';
    }
    return word;
}

void dofiles()
{
    QFile fileF("F");
    QFile fileG("G");
    if (fileF.open(QIODevice::WriteOnly | QIODevice::Text) &&
        fileG.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writeStreamF(&fileF);
        QTextStream writeStreamG(&fileG);
        writeStreamF << generateWords();
        writeStreamG << generateWords();
        fileF.close();
        fileG.close();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    set<string> fsset;
    set<string> gsset;
    QSet<QString> fqset;
    QSet<QString> gqset;
    dofiles();
    QFile fileF("F");
    QFile fileG("G");
    if (fileF.open(QIODevice::ReadOnly | QIODevice::Text) &&
        fileG.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream readStreamF(&fileF);
        QTextStream readStreamG(&fileG);
        QString Qfstr = readStreamF.readLine();
        QString Qgstr = readStreamG.readLine();

        string fstr = Qfstr.toStdString();
        string gstr = Qgstr.toStdString();

        QElapsedTimer timer1;
        timer1.start();

        int last{};
        for (int i = 0; i < fstr.length(); i++)
        {
            if (fstr[i] == ' ')
            {
                fsset.insert(fstr.substr(last + 1, i - last - 1));
                last = i;
            };
        }
        last = 0;
        for (int i = 0; i < gstr.length(); i++)
        {
            if (fstr[i] == ' ')
            {
                gsset.insert(gstr.substr(last + 1, i - last - 1));
                last = i;
            };
        }
        for (const auto &element : fsset)
        {
            if (gsset.find(element) == gsset.end())
            {
                qDebug() << QString::fromStdString(element) << " ";
            }
        }
        int t1 = timer1.nsecsElapsed();

        QElapsedTimer timer2;
        timer2.start();

        last = 0;
        for (int i = 0; i < Qfstr.length(); i++)
        {
            if (fstr[i] == ' ')
            {
                fqset.insert(Qfstr.mid(last + 1, i - last - 1));
                last = i;
            };
        }
        last = 0;
        for (int i = 0; i < Qgstr.length(); i++)
        {
            if (fstr[i] == ' ')
            {
                gqset.insert(Qgstr.mid(last + 1, i - last - 1));
                last = i;
            };
        };
        qDebug() << '\n';
        for (const auto &element : fqset)
        {
            if (gqset.find(element) == gqset.end())
            {
                qDebug() << element;
            }
        }

        fileF.close();
        fileG.close();
        qDebug() << t1 << " ns " << timer2.nsecsElapsed() << " ns";
    }

    return a.exec();
}

#include <QCoreApplication>
#include <QSet>
#include <QString>
#include <QFile>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <QElapsedTimer>
using std::set, std::string, std::rand;

// Функция, генерирующая слова
QString generateWords()
{
    srand(time(NULL));
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString word = "";
    for (int j = 0; j < (int)arc4random() % 10000 + 100; j++)
    {
        int length = arc4random() % 10 + 1;
        for (int i = 0; i < length; i++)
        {
            int index = arc4random() % 26;
            char letter = alphabet[index];
            word += letter;
        }
        word += ' ';
    }
    return word;
}

// Функции, перобразующие слова с заглавными буквами в слова со всеми прописными
string toLowercase(string s)
{
    string result = "";
    for (int i = 0; i < (int)s.length(); i++)
        result += tolower(s[i]);
    return result;
}

QString toLowercase(QString s)
{
    QString result = s.toLower();
    return result;
}

// Функция, генерирующая файлы
void dofiles()
{
    QFile fileF("F");
    QFile fileG("G");
    if (fileF.open(QIODevice::WriteOnly | QIODevice::Text) &&
        fileG.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writeStreamF(&fileF);
        QTextStream writeStreamG(&fileG);
        writeStreamF << generateWords();
        writeStreamG << generateWords();
        fileF.close();
        fileG.close();
    }
}

// Функции сравнения
void comparison(set<string> &fsset, set<string> &gsset)
{
    for (const auto &elementF : fsset)
    {
        bool fl = 1;
        for (const auto &elementG : gsset)
            if (toLowercase(elementF) == toLowercase(elementG))
            {
                fl = 0;
                break;
            }
        if (fl)
            qDebug() << QString::fromStdString(elementF) << " ";
    }
}

void comparison(QSet<QString> &fqset, QSet<QString> gqset)
{
    qDebug() << fqset << " ";
    for (auto elementF : fqset)
    {
        qDebug() << elementF << " ";
        bool fl = 1;
        for (auto elementG : gqset)
            if (toLowercase(elementF) == toLowercase(elementG))
            {
                fl = 0;
                break;
            }
        qDebug() << elementF << " ";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    set<string> fsset;
    set<string> gsset;
    QSet<QString> fqset;
    QSet<QString> gqset;
    dofiles();
    QFile fileF("F");
    QFile fileG("G");
    if (fileF.open(QIODevice::ReadOnly | QIODevice::Text) &&
        fileG.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream readStreamF(&fileF);
        QTextStream readStreamG(&fileG);
        QString Qfstr = readStreamF.readLine();
        QString Qgstr = readStreamG.readLine();

        string fstr = Qfstr.toStdString();
        string gstr = Qgstr.toStdString();

        //        Начало реализации с помощью stl::set

        QElapsedTimer timer1;
        timer1.start();

        //        Добавляем все слова из файла F в stl::set

        int last{};
        for (int i = 0; i < fstr.length(); i++)
        {
            if (fstr[i] == ' ')
            {
                fsset.insert(fstr.substr(last + 1, i - last - 1));
                last = i;
            };
        }

        //        Добавляем все слова из файла G в stl::set

        last = 0;
        for (int i = 0; i < gstr.length(); i++)
        {
            if (fstr[i] == ' ')
            {
                gsset.insert(gstr.substr(last + 1, i - last - 1));
                last = i;
            };
        }

        comparison(fsset, gsset);

        int t1 = timer1.nsecsElapsed();

        //        Начало реализации с помощью QSet

        QElapsedTimer timer2;
        timer2.start();

        //        Добавляем все слова из файла F в QSet

        last = 0;
        for (int i = 0; i < Qfstr.length(); i++)
        {
            if (fstr[i] == ' ')
            {
                fqset.insert(Qfstr.mid(last + 1, i - last - 1));
                last = i;
            };
        }

        //        Добавляем все слова из файла G в QSet

        last = 0;
        for (int i = 0; i < Qgstr.length(); i++)
        {
            if (fstr[i] == ' ')
            {
                gqset.insert(Qgstr.mid(last + 1, i - last - 1));
                last = i;
            };
        };
        qDebug() << gqset << '\n';

        comparison(fqset, gqset);

        //        Выводим значения с таймера

        qDebug() << t1 << " ns " << timer2.nsecsElapsed() << " ns";
    }
    fileF.close();
    fileG.close();

    return a.exec();
}
