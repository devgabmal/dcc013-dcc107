#include <iostream>
#include "MatrizSim.h"

using namespace std;

MatrizSim::MatrizSim(int n)
{
    numOrd = n;
    int numElems = (n + 1) * n / 2;
    vet = new float[numElems];
}

MatrizSim::~MatrizSim()
{
    delete[] vet;
}

int MatrizSim::detInd(int i, int j)
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

float MatrizSim::get(int i, int j)
{
    int k;
    if (i > j)
        k = detInd(j, i);
    else
        k = detInd(i, j);

    return vet[k];
}

void MatrizSim::set(int i, int j, float val)
{
    int k;
    if (i > j)
        k = detInd(j, i);
    else
        k = detInd(i, j);
    vet[k] = val;
}