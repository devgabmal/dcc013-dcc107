#include <iostream>
#include <cstdlib>
#include "MatrizDistancias.h"

using namespace std;

// ----------------------------------------------------------------------------
// Q4
// 35 minutos e 10 segundos
MatrizDistancias::MatrizDistancias(int ordem)
{
    // Implemente aqui sua solução para a questão 4 letra A.
    // Se necessário, remova o código abaixo.
    n = ordem;
    int tamVet = (n * (n - 1)) / 2;
    vet = new int[tamVet];
}

MatrizDistancias::~MatrizDistancias()
{
    // Implemente aqui sua solução para a questão 4 letra A.
    delete[] vet;
}

int MatrizDistancias::detInd(int i, int j)
{
    // Implemente aqui sua solução para a questão 4 letra B.
    // Se necessário, remova o código abaixo.
    if (i >= 0 && i < n && j >= 0 && j < n)
    {
        if (i == j)
            return -2;
        else if (j > i)
            return (i * (j - 1)) / 2 + j;
        else
            return (j * (i - 1)) / 2 + i;
    }
    else
        return -1;
}

int MatrizDistancias::get(int i, int j)
{
    // Implemente aqui sua solução para a questão 4 letra C.
    // Se necessário, remova o código abaixo.
    int k = detInd(i, j);
    if (k == -1)
    {
        cout << "ERRO: Indices invalidos!";
        exit(1);
    }
    else if (k == -2)
        return 0;
    else
        return vet[k];
}

void MatrizDistancias::set(int i, int j, int val)
{
    // Implemente aqui sua solução para a questão 4 letra C.
    int k = detInd(i, j);
    if (k < 0)
    {
        cout << "ERRO: Indices invalidos!";
        exit(1);
    }
    vet[k] = val;
}
//-Q4
// ----------------------------------------------------------------------------

void MatrizDistancias::imprime()
{
    cout << "Matriz " << n << " x " << n << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << get(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
}
