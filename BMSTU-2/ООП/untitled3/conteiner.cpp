#include "conteiner.h"

void conteiner::print(QListWidget *list)
{
    list->clear();
    for (int i=0;i<boolmas.size();i++)
    {
        if (boolmas[i]>0){

            list->addItem(QString::number(intmas[boolmas[i]-1]));


        }
        else if (boolmas[i]<0){
            list->addItem((QString)charmas[abs(boolmas[i]+1)]);

        }
    }
}
void sort_conteiner::sort()
{
    for (int i = 0; i<intmas.size();i++)
        for (int j = i+1; j<intmas.size();j++)
            if (intmas[i]<intmas[j]){
                int b=intmas[i];
                intmas[i]=intmas[j];
                intmas[j]=b;
            }


    std::sort(charmas.begin(), charmas.end());
}
QString conteiner::operator[](int index)

{
    if (boolmas[index]>0) return QString::number(intmas[boolmas[index]-1]);
    else return QString(QChar(charmas[abs(boolmas[index])-1]));

}
