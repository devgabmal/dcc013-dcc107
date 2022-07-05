#include <iostream>
#include "PilhaCont.h"

using namespace std;

PilhaCont::PilhaCont(int tam)
{
    max = tam;
    topo = -1;
    vet = new int[max];
}

PilhaCont::~PilhaCont()
{
    delete[] vet;
}

int PilhaCont::getTopo()
{
    if (topo != -1)
        return vet[topo];
    else
    {
        cout << "ERRO: Pilha Vazia!" << endl;
        exit(1);
    }
}

void PilhaCont::empilha(int val)
{
    if (topo == max - 1)
    {
        cout << "ERRO: Pilha cheia!" << endl;
        exit(2);
    }
    else
    {
        topo++;
        vet[topo] = val;
    }
}

int PilhaCont::desempilha()
{
    if (topo == -1)
    {
        cout << "ERRO: Pilha Vazia!" << endl;
        exit(1);
    }
    else
    {
        topo--;
        return vet[topo + 1];
    }
}

bool PilhaCont::vazia()
{
    return (topo == -1);
}
