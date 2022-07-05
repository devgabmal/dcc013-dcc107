#include <iostream>
#include <cmath>
#include "Caminho.h"

using namespace std;

// ----------------------------------------------------------------------------
// Q3
// 1 hora, 00 minutos e 21 segundos
Caminho::Caminho(int nn)
{
    // Implemente aqui sua solução para a questão 3 letra A.
    // Se necessário, remova o código abaixo.
    n = nn;
    vet = new int[n];

    for (int i = 0; i < n; i++)
    {
        vet[i] = i;
    }
}

Caminho::~Caminho()
{
    // Implemente aqui sua solução para a questão 3 letra A.
    delete[] vet;
}

int Caminho::calculaDistanciaPercorrida(int **distancias)
{
    // Implemente aqui sua solução para a questão 3 letra B.
    // Se necessário, remova o código abaixo.
    int distTotal = 0;

    for (int i = 0; i < n - 1; i++)
    {
        distTotal = distTotal + distancias[vet[i]][vet[i + 1]];
    }

    return distTotal;

    return 0;
}

void Caminho::buscaGulosa(int **distancias)
{
    // Implemente aqui sua solução para a questão 3 letra C.
    int maisProx = 0;
    int *ord = new int[n - 1];

    vet[0] = 0;

    for (int i = 1; i < n; i++)
    {
        ordem(distancias, maisProx, ord);
        // Percorre vetor ord
        for (int j = 0; j < n; j++)
        {
            int naoExiste = true;
            // Percorre cidades bem preenchidas no vetor vet
            for (int k = 0; k < i; k++)
            {
                if (ord[j] == vet[k])
                {
                    naoExiste = false;
                    break;
                }
            }
            if (naoExiste)
            {
                maisProx = ord[j];
                break;
            }
        }

        vet[i] = maisProx;
    }

    delete[] ord;
}
//-Q3
// ----------------------------------------------------------------------------

void Caminho::ordem(int **distancias, int i, int *ordem)
{
    int cid = 0;
    for (int j = 0; j < n; j++)
        if (i != j)
            ordem[cid++] = j;
    for (cid = 0; cid < n - 2; cid++)
    {
        int j = cid + 1;
        int pivo = ordem[j];
        while (j > 0 && distancias[i][pivo] < distancias[i][ordem[j - 1]])
        {
            ordem[j] = ordem[j - 1];
            j--;
        }
        ordem[j] = pivo;
    }
}

void Caminho::imprimirCaminho()
{
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << " --> ";
    }
}
