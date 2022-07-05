#include <iostream>
#include "PilhaEncad.h"

using namespace std;

PilhaEncad::PilhaEncad()
{
    topo = NULL;
}

PilhaEncad::~PilhaEncad()
{
    No *p = topo;
    while (topo != NULL)
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

int PilhaEncad::getTopo()
{
    if (topo != NULL)
        return topo->getInfo();
    else
    {
        cout << "ERRO: Pilha Vazia!" << endl;
        exit(1);
    }
}

void PilhaEncad::empilha(int val)
{
    No *novo = new No;
    novo->setInfo(val);
    novo->setProx(topo);
    topo = novo;
}

int PilhaEncad::desempilha()
{
    int info = 0;
    if (topo == NULL)
    {
        cout << "ERRO: Pilha Vazia!" << endl;
        exit(1);
    }
    else
    {
        No *p = topo;
        info = p->getInfo();
        topo = p->getProx();
        delete p;
    }
    return info;
}

bool PilhaEncad::vazia()
{
    return (topo == NULL);
}

void PilhaEncad::imprime()
{
    if (topo == NULL)
    {
        cout << "Pilha Vazia!" << endl;
    }
    else
    {
        for (No *p = topo; p != NULL; p = p->getProx())
        {
            cout << p->getInfo() << "\t";
        }
        cout << endl;
    }
}