#include <iostream>
#include "MatrizTriInf.h"

using namespace std;

MatrizTriInf::MatrizTriInf(int n)
{
    numOrd = n;
    int numElems = (n + 1) * n / 2;
    vet = new float[numElems];
}

MatrizTriInf::~MatrizTriInf()
{
    delete[] vet;
}

int MatrizTriInf::detInd(int i, int j)
{
    if (i >= 0 && i < numOrd && j >= 0 && j < numOrd)
    {
        return ((i + 1) * i / 2) + j;
    }
    else
    {
        cout << "ERRO: Indice invalido!";
        exit(1);
    }
}

float MatrizTriInf::get(int i, int j)
{
    int k = detInd(i, j);
    if (i >= j)
        return vet[k];
    else
        return 0;
}

void MatrizTriInf::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if (i >= j)
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