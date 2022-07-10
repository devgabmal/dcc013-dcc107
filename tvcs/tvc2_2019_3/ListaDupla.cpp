#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    // OMITIDO
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(primeiro);
    p->setAnt(NULL);

    if (n == 0)
    {
        ultimo = p;
    }
    else
    {
        primeiro->setAnt(p);
    }
    primeiro = p;
    n = n + 1;
}

void ListaDupla::imprime()
{
    cout << "[";
    for (NoDuplo *p = primeiro; p != NULL; p = p->getProx())
    {
        cout << p->getInfo();
        if (p->getProx() != NULL)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
// Q3 - 15 minutos e 28 segundos

void ListaDupla::removeMaior()
{
    if (primeiro == NULL)
    {
        cout << "ERRO: Lista vazia!" << endl;
        return;
    }

    NoDuplo *maior = primeiro;
    NoDuplo *p = primeiro->getProx();
    while (p != NULL)
    {
        if (p->getInfo() > maior->getInfo())
            maior = p;
        p = p->getProx();
    }

    NoDuplo *ant = maior->getAnt();
    NoDuplo *prox = maior->getProx();

    if (maior != primeiro)
        ant->setProx(prox);
    else
        primeiro = prox;

    if (maior != ultimo)
        prox->setAnt(ant);
    else
        ultimo = ant;

    delete maior;
}

//-Q3
// ----------------------------------------------------------------------------
