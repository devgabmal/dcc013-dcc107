#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    // OMITIDO
}

void ListaCont::insereFinal(int val)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::imprime()
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i + 1 < n)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
// Q2 - 30 minutos e 25 segundos

bool ListaCont::insereIntervalo(int a, int b)
{
    bool aumentou = false;
    int qtd = b - a + 1;
    int posicoesLivres = max - n;

    if (qtd > posicoesLivres)
    {
        int novoMaximo = max + qtd - posicoesLivres;
        int *novoVetor = new int[novoMaximo];

        for (int i = 0; i < n; i++)
        {
            novoVetor[i] = vet[i];
        }

        int *vetAux = vet;
        vet = novoVetor;
        delete[] vetAux;

        max = novoMaximo;
        aumentou = true;
    }

    int j = 0;
    for (int i = n; i < qtd + n; i++)
    {
        vet[i] = a + j;
        j++;
    }
    n = n + qtd;

    return aumentou;
}
//-Q2
// ----------------------------------------------------------------------------
