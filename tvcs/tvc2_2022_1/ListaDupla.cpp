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
//Q2
void ListaDupla::trocaSegundoPenultimo()
{
    if (n <= 4)
    {
        cout << "ERRO: A lista tem menos de 5 nos!" << endl;
        return;
    }

    NoDuplo *segundo = primeiro->getProx();
    NoDuplo *terceiro = segundo->getProx();
    NoDuplo *penultimo = ultimo->getAnt();
    NoDuplo *antepenultimo = penultimo->getAnt();

    primeiro->setProx(penultimo);
    terceiro->setAnt(penultimo);
    penultimo->setAnt(primeiro);
    penultimo->setProx(terceiro);

    antepenultimo->setProx(segundo);
    ultimo->setAnt(segundo);
    segundo->setAnt(antepenultimo);
    segundo->setProx(ultimo);
}
//-Q2
// ----------------------------------------------------------------------------
