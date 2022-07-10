#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    primeiro = NULL;
}

ListaEncad::~ListaEncad()
{
    // OMITIDO
}

void ListaEncad::insereInicio(int val)
{
    No *novo = new No();
    novo->setInfo(val);
    novo->setProx(primeiro);
    primeiro = novo;
}

void ListaEncad::imprime()
{
    cout << "[";
    for (No *p = primeiro; p != NULL; p = p->getProx())
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
// Q4 - 33 minutos e 03 segundos

void ListaEncad::removeBloco(int a, int b)
{
    No *p = primeiro;
    No *ant = NULL;

    while (p != NULL && p->getInfo() != a) // Encontra A
    {
        ant = p;
        p = p->getProx();
    }
    while (p != NULL && p->getInfo() != b)
    {
        No *aux = p;
        p = p->getProx();
        delete aux;
    }
    if (p != NULL && p->getInfo() == b)
    {
        No *aux = p;
        p = p->getProx();
        delete aux;
    }

    if (ant != NULL)
        ant->setProx(p);
    else
        primeiro = p;
}

//-Q4
// ----------------------------------------------------------------------------
