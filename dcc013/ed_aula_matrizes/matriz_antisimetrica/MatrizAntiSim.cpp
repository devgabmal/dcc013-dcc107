#include <iostream>
#include "MatrizAntiSim.h"

using namespace std;

MatrizAntiSim::MatrizAntiSim(int n)
{
    numOrd = n;
    int numElems = (n) * (n - 1) / 2;
    vet = new float[numElems];
}

MatrizAntiSim::~MatrizAntiSim()
{
    delete[] vet;
}

int MatrizAntiSim::detInd(int i, int j)
{
    if (i >= 0 && i < numOrd && j >= 0 && j < numOrd)
    {
        return (j * (j - 1) / 2) + i;
    }
    else
    {
        cout << "ERRO: Indice invalido!";
        exit(1);
    }
}

float MatrizAntiSim::get(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    else
    {
        int k;
        if (i > j)
            k = detInd(j, i);
        else
            k = detInd(i, j);
        return vet[k];
    }
}

void MatrizAntiSim::set(int i, int j, float val)
{
    if (i == j)
    {
        cout << "ERRO: Nao e possivel alterar o valor da diagonal principal!";
        exit(1);
    }
    else
    {
        int k;
        if (i > j)
            k = detInd(j, i);
        else
            k = detInd(i, j);
        vet[k] = val;
    }
}