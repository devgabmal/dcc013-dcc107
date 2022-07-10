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

void PilhaCont::dobraCapacidade()
{
    int novoMax = max * 2;
    int *novoVet = new int[novoMax];
    for (int i = 0; i < topo; i++)
        novoVet[i] = vet[i];
    int *aux = vet;
    vet = novoVet;
    max = novoMax;
    delete[] aux;
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
        dobraCapacidade();
    topo++;
    vet[topo] = val;
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
