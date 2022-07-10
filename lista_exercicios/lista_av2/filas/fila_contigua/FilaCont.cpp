#include <iostream>
#include "FilaCont.h"

using namespace std;

FilaCont::FilaCont(int tam)
{
    max = tam;
    inicio = 0;
    fim = 0;
    vet = new int[max];
}

FilaCont::~FilaCont()
{
    delete[] vet;
}

void FilaCont::dobraCapacidade()
{
    int novoMax = max * 2;
    int *novoVet = new int[novoMax];
    for (int i = inicio; i < fim; i++)
        novoVet[i - inicio] = vet[i];
    int *aux = vet;
    vet = novoVet;
    max = novoMax;
    fim = fim - inicio;
    inicio = 0;
    delete[] aux;
}

int FilaCont::getInicio()
{
    if (!vazia())
        return vet[inicio];
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaCont::enfileira(int val)
{
    if (fim == max)
        dobraCapacidade();
    vet[fim] = val;
    fim++;
}

int FilaCont::desenfileira()
{
    if (vazia())
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
    else
    {
        inicio++;
        return vet[inicio - 1];
    }
}

bool FilaCont::vazia()
{
    return (inicio == fim);
}
