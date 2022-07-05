#include <iostream>
#include "MatrizTridiag.h"

using namespace std;

MatrizTridiag::MatrizTridiag(int n)
{
    numOrd = n;
    vet = new float[3 * n - 2];
}

MatrizTridiag::~MatrizTridiag()
{
    delete[] vet;
}

int MatrizTridiag::detInd(int i, int j)
{
    if (i >= 0 && i < numOrd && j >= 0 && j < numOrd)
    {
        int k;
        if (i == j - 1) // Diagonal superior
        {
            k = i;
        }
        else if (i == j) // Diagonal principal
        {
            k = numOrd - 1 + i;
        }
        else if (i == j + 1) // Diagonal inferior
        {                    // 13
            k = 2 * numOrd - 2 + i;
        }
        return k;
    }
    else
    {
        cout << "ERRO: Indice invalido!";
        exit(1);
    }
}

float MatrizTridiag::get(int i, int j)
{
    int k = detInd(i, j);
    if ((j > i + 1) || (i > j + 1))
    {
        return 0;
    }
    else
    {
        return vet[k];
    }
}

void MatrizTridiag::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if ((j + 1 >= i && i >= j - 1))
    {
        vet[k] = val;
    }
    else
    {
        if (val != 0)
        {
            cout << "ERRO: Nao e possivel alterar o valor fora das três diagonais o centro da matriz!";
            exit(1);
        }
    }
}