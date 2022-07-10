#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"

using namespace std;

PilhaEncad::PilhaEncad ()
{
    topo = NULL;
}

PilhaEncad::~PilhaEncad ()
{
    // OMITIDO
}

void PilhaEncad::empilha (int val)
{
    No* p = new No ();
    p->setInfo (val);
    p->setProx (topo);
    topo = p;
}

int PilhaEncad::desempilha ()
{
    No* p;
    if (topo != NULL)
    {
        p = topo;
        topo = p->getProx ();
        int val = p->getInfo ();
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Pilha vazia!" << endl;
        exit (1);
    }
}

int PilhaEncad::getTopo ()
{
    if (topo != NULL)
    {
        return topo->getInfo ();
    }
    else
    {
        cout << "Pilha vazia!" << endl;
        exit (1);
    }
}

bool PilhaEncad::vazia ()
{
    if (topo == NULL)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

void PilhaEncad::imprime ()
{
    if (vazia ())
    {
        cout << "PilhaEncad vazia." << endl;
    }
    else
    {
        for (No *p = topo; p != NULL; p = p->getProx ())
        {
            cout << p->getInfo () << "\t";
        }
        cout << endl;
    }
}
