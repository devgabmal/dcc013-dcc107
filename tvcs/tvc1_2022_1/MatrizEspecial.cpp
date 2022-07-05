#include <iostream>
#include <cstdlib>
#include "MatrizEspecial.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q3
MatrizEspecial::MatrizEspecial(int nn)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    n = nn;
    int numElems = n + n - 2;
    vet = new float[numElems];
}

MatrizEspecial::~MatrizEspecial()
{
    // Implemente aqui sua solucao!
    delete[] vet;
}

bool MatrizEspecial::verificaIndice(int i, int j)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    if (i >= 0 && i < n && j >= 0 && j < n)
        return true;
    else
        return false;
}

float MatrizEspecial::get(int i, int j)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    if (verificaIndice(i, j))
    {
        if (i == 0) // Primeira linha
        {
            return vet[j];
        }
        else if (i == n - 1) // Ultima linha
        {
            return vet[j] * -1;
        }
        else if (i == n - 1 - j) // Diagonal secundaria
        {
            return vet[j + n];
        }
        else // Demais valores, igual a 0
        {
            return 0;
        }
    }
    else
    {
        cout << "Indices invalidos" << endl;
        return -1;
    }
}

void MatrizEspecial::set(int i, int j, float val)
{
    // Implemente aqui sua solucao!
    if (verificaIndice(i, j))
    {
        if (i == 0) // Primeira linha
        {
            vet[j] = val;
        }
        else if (i == n - 1) // Ultima linha
        {
            vet[j] = val * -1;
        }
        else if (i == n - 1 - j) // Diagonal secundaria
        {
            vet[j + n - 1] = val;
        }
        else // Demais valores, igual a 0
        {
            if (val != 0)
                cout << "Tentando atribuir valor nao zero em posicao impropria" << endl;
        }
    }
    else
    {
        cout << "Indices invalidos" << endl;
    }
}
//-Q3
// ----------------------------------------------------------------------------

void MatrizEspecial::imprimir()
{
    cout << "Matriz " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << get(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
}
