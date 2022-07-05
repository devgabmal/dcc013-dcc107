#include <iostream>
#include "FilaCirc.h"

using namespace std;

FilaCirc::FilaCirc(int tam)
{
    max = tam;
    inicio = 0;
    fim = 0;
    n = 0;
    vet = new int[max];
}

FilaCirc::~FilaCirc()
{
    delete[] vet;
}

int FilaCirc::inc(int ind)
{
    if (ind == max - 1)
        return 0;
    else
        return ind + 1;
}

int FilaCirc::getInicio()
{
    if (!vazia())
        return vet[inicio];
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaCirc::enfileira(int val)
{
    if (n == max)
    {
        cout << "ERRO: Fila cheia!" << endl;
        exit(2);
    }
    else
    {
        vet[fim] = val;
        fim = inc(fim);
        n++;
    }
}

int FilaCirc::desenfileira()
{
    if (vazia())
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
    else
    {
        int info = vet[inicio];
        inicio = inc(inicio);
        n--;
        return info;
    }
}

bool FilaCirc::vazia()
{
    return (n == 0);
}

void FilaCirc::imprime(int vezes)
{
    int i = 0;
    int ind = 0;
    int vez = 1;
    while (i < n * vezes)
    {
        cout << vet[ind] << "\t";
        i++;
        ind++;
        if (i == n * vez) // Quebra linha após chegar ao fim da lista
        {
            cout << endl;
            vez++;
            ind = 0;
        }
    }
}