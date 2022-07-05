#include <iostream>
#include <cstdlib>

#include "MatrizLin.h"

using namespace std;

MatrizLin::MatrizLin(int mm, int nn)
{
    cout << "Criando um objeto MatrizLin" << endl;
    nl = mm;
    nc = nn;
    vet = new float[nl * nc];
}

MatrizLin::~MatrizLin()
{
    cout << "Destruindo um objeto MatrizLin" << endl;
    delete[] vet;
}

int MatrizLin::detInd(int i, int j)
{
    if (i >= 0 && i < nl && j >= 0 && j < nc)
    {
        return i * nc + j;
    }
    else
        return -1; // índice inválido
}

float MatrizLin::get(int i, int j)
{
    int ind = detInd(i, j);
    if (ind != -1)
        return vet[ind];
    else
    {
        cout << "ERRO: Índice invalido" << endl;
        exit(1);
    }
}

void MatrizLin::set(int i, int j, float val)
{
    int ind = detInd(i, j);
    if (ind != -1)
        vet[ind] = val;
    else
    {
        cout << "ERRO: Índice invalido" << endl;
        exit(1);
    }
}

void MatrizLin::imprime()
{
    for (int i = 0; i < nl * nc; i++)
    {
        cout << vet[i] << "\t";
        if ((i + 1) % nc == 0)
            cout << endl;
    }
}

MatrizLin *MatrizLin::transposta()
{
    MatrizLin *matTransp = new MatrizLin(nc, nl);

    for (int i = 0; i < nc; i++)
    {
        for (int j = 0; j < nl; j++)
        {
            int indIJ = matTransp->detInd(i, j);
            int indJI = detInd(j, i);
            matTransp->vet[indIJ] = vet[indJI];
        }
    }

    return matTransp;
}

int MatrizLin::getNl()
{
    return nl;
}

int MatrizLin::getNc()
{
    return nc;
}