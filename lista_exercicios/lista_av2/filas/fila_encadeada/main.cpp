#include <iostream>
#include "FilaEncad.h"

#define TAM 10

using namespace std;

int compara(FilaEncad *f1, FilaEncad *f2)
{
    if (f1->getNumNos() < f2->getNumNos())
        return -1;
    else if (f1->getNumNos() > f2->getNumNos())
        return 1;
    else
        return 0;
}

int main()
{
    FilaEncad f, f2;

    cout << "Enfileirando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = rand() % 100;
        f.enfileira(val);
        cout << val << "\t";
    }
    cout << endl;

    cout << "Enfileirando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = rand() % 100;
        f2.enfileira(val);
        cout << val << "\t";
    }
    cout << endl;

    // Ex15 - 10 minutos
    cout << compara(&f, &f2) << endl;

    cout << "Imprimindo:" << endl;
    for (int i = 0; i < TAM; i++)
        cout << f.desenfileira() << "\t";

    return 0;
}