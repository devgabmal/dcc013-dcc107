#include <iostream>
#include "MatrizDiag.h"

using namespace std;

MatrizDiag::MatrizDiag(int n)
{
    numOrd = n;
    vet = new float[n];
}

MatrizDiag::~MatrizDiag()
{
    delete[] vet;
}

int MatrizDiag::detInd(int i, int j)
{
    if (i >= 0 && i < numOrd && j >= 0 && j < numOrd)
        return i;
    else
    {
        cout << "ERRO: Indice invalido!";
        exit(1);
    }
}

float MatrizDiag::get(int i, int j)
{
    int k = detInd(i, j);
    if (i == j)
        return vet[k];
    else
        return 0;
}

void MatrizDiag::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if (i == j)
        vet[k] = val;
    else
    {
        if (val != 0)
        {
            cout << "ERRO: Nao e possivel alterar o valor fora da diagonal principal!";
            exit(1);
        }
    }
}