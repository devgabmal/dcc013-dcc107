#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "FilaEncad.h"

#define TAM 10

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

int compara(FilaEncad *f1, FilaEncad *f2)
{
    if (f1->getNumNos() < f2->getNumNos())
        return -1;
    else if (f1->getNumNos() > f2->getNumNos())
        return 1;
    else
        return 0;
}

FilaEncad *geraFilaPositiva(FilaEncad *fila)
{
    FilaEncad *novaFila = new FilaEncad;
    while (!fila->vazia())
    {
        int val = fila->desenfileira();
        if (val >= 0)
            novaFila->enfileira(val);
    }
    return novaFila;
}

int main()
{
    srand(time(NULL));

    FilaEncad f, f2, f3;

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
    cout << endl;

    // Ex19 - 11 minutos e 11 segundos
    cout << "Enfileirando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = numAleatorio(-50, 50);
        f3.enfileira(val);
        cout << val << "\t";
    }
    cout << endl;
    FilaEncad *f4 = geraFilaPositiva(&f3);
    cout << "Imprimindo:" << endl;
    while (!f4->vazia())
        cout << f4->desenfileira() << "\t";
    cout << endl;

    return 0;
}