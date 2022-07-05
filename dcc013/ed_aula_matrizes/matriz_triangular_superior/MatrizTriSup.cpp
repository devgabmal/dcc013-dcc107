#include <iostream>
#include "MatrizTriSup.h"

using namespace std;

MatrizTriSup::MatrizTriSup(int n)
{
    numOrd = n;
    int numElems = (n + 1) * n / 2;
    vet = new float[numElems];
}

MatrizTriSup::~MatrizTriSup()
{
    delete[] vet;
}

int MatrizTriSup::detInd(int i, int j)
{
    if (i >= 0 && i < numOrd && j >= 0 && j < numOrd)
    {
        return ((j + 1) * j / 2) + i;
    }
    else
    {
        cout << "ERRO: Indice invalido!";
        exit(1);
    }
}

float MatrizTriSup::get(int i, int j)
{
    int k = detInd(i, j);
    if (j >= i)
        return vet[k];
    else
        return 0;
}

void MatrizTriSup::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if (j >= i)
        vet[k] = val;
    else
    {
        if (val != 0)
        {
            cout << "ERRO: Nao e possivel alterar o valor fora da parte triangular inferior!";
            exit(1);
        }
    }
}