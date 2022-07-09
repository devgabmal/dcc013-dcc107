#include <iostream>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    delete[] vet;
}

bool indiceValido(int k, int n)
{
    if (k >= 0 && k < n)
        return true;
    else
        return false;
}

int ListaCont::get(int k)
{
    if (indiceValido(k, n))
        return vet[k];
    else
    {
        cout << "Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::set(int k, int val)
{
    if (indiceValido(k, n))
        vet[k] = val;
    else
    {
        cout << "Indice invalido!" << endl;
        exit(2);
    }
}

void ListaCont::insereFinal(int val)
{
    if (n == max)
    {
        cout << "Vetor Cheio!" << endl;
        exit(3);
    }
    vet[n] = val;
    n++;
}

void ListaCont::removeFinal()
{
    if (n == 0)
    {
        cout << "Lista Vazia!" << endl;
        exit(6);
    }
    n--;
}

void ListaCont::insereK(int k, int val)
{
    if (n == max)
    {
        cout << "Vetor Cheio!" << endl;
        exit(3);
    }
    if (indiceValido(k, n))
    {
        for (int i = n - 1; i >= k; i--)
            vet[i + 1] = vet[i];

        vet[k] = val;
        n++;
    }
    else
    {
        cout << "Indice invalido!" << endl;
        exit(4);
    }
}

void ListaCont::removeK(int k)
{
    if (indiceValido(k, n))
    {
        for (int i = k; i < n - 1; i++)
            vet[i] = vet[i + 1];

        n--;
    }
    else
    {
        cout << "Indice invalido!" << endl;
        exit(5);
    }
}

void ListaCont::imprime()
{
    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << "\t";
    }
    cout << endl;
}