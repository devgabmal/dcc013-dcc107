#include <iostream>
#include "MatrizFlex.h"

using namespace std;

MatrizFlex::MatrizFlex(int li, int lf, int ci, int cf)
{
    lil = li;
    lfl = lf;
    lic = ci;
    lfc = cf;

    m = lfl - lil + 1;
    n = lfc - lic + 1;

    vet = new float[m * n];
}

MatrizFlex::~MatrizFlex()
{
    delete[] vet;
}

int MatrizFlex::detInd(int i, int j)
{
    if (i >= lil && i <= lfl && j >= lic && j <= lfc)
        return (i - lil) * n + (j - lic);
    else
        return -1;
}

float MatrizFlex::get(int i, int j)
{
    int k = detInd(i, j);
    if (k != -1)
        return vet[k];
    else
    {
        cout << "Indice invalido: get" << endl;
        exit(1);
    }
}

void MatrizFlex::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if (k != -1)
        vet[k] = val;
    else
    {
        cout << "Indice invalido: set" << endl;
        exit(1);
    }
}