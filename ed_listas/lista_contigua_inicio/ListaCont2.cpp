#include <iostream>
#include "ListaCont2.h"

using namespace std;

ListaCont2::ListaCont2(int ini, int tam)
{
    max = tam;
    n = 0;
    inicio = ini;
    vet = new int[max];
}

ListaCont2::~ListaCont2()
{
    delete[] vet;
}

bool indiceValido(int k, int n, int inicio, int max)
{
    if (k >= 0 && k < max && k >= inicio && k < n + inicio)
        return true;
    else
        return false;
}

int ListaCont2::get(int k)
{
    if (indiceValido(k, n, inicio, max))
        return vet[k];
    else
    {
        cout << "Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont2::set(int k, int val)
{
    if (indiceValido(k, n, inicio, max))
        vet[k] = val;
    else
    {
        cout << "Indice invalido!" << endl;
        exit(2);
    }
}

void ListaCont2::insereInicio(int val)
{
    if (n == max)
    {
        cout << "Vetor Cheio!" << endl;
        exit(3);
    }
    if (inicio == 0)
    {
        cout << "Sem espaco no inicio do vetor!" << endl;
        exit(4);
    }
    vet[inicio - 1] = val;
    inicio--;
    n++;
}

void ListaCont2::removeInicio()
{
    if (n == 0)
    {
        cout << "Lista Vazia!" << endl;
        exit(5);
    }
    inicio++;
    n--;
}

void ListaCont2::insereFinal(int val)
{
    if (n == max)
    {
        cout << "Vetor Cheio!" << endl;
        exit(6);
    }
    if (n + inicio < max)
    {
        vet[n + inicio] = val;
        n++;
    }
    else
    {
        cout << "Sem espaco no final do vetor!" << endl;
        exit(7);
    }
}

void ListaCont2::removeFinal()
{
    if (n == 0)
    {
        cout << "Lista Vazia!" << endl;
        exit(8);
    }
    n--;
}

void ListaCont2::insereK(int k, int val)
{
    if (n == max)
    {
        cout << "Vetor Cheio!" << endl;
        exit(9);
    }
    if (indiceValido(k, n, inicio, max))
    {
        if (n + inicio < max)
        { // Desloca valores para a direita
            for (int i = inicio + n - 1; i >= k; i--)
                vet[i + 1] = vet[i];

            vet[k] = val;
            n++;
        }
        else
        { // Sem espaço no final do vetor, logo, há espaço no início
          // Desloca valores para a esquerda
            for (int i = inicio; i <= k; i++)
                vet[i - 1] = vet[i];

            vet[k] = val;
            n++;
            inicio--;
        }
    }
    else
    {
        cout << "Indice invalido!" << endl;
        exit(11);
    }
}

void ListaCont2::removeK(int k)
{
    if (indiceValido(k, n, inicio, max))
    {
        for (int i = k; i < n - 1 + inicio; i++)
            vet[i] = vet[i + 1];

        n--;
    }
    else
    {
        cout << "Indice invalido!" << endl;
        exit(12);
    }
}

void ListaCont2::imprime()
{
    for (int i = inicio; i < n + inicio; i++)
        cout << vet[i] << "\t";
    cout << endl;
    /*
    for (int i = inicio; i < n + inicio; i++)
        cout << i << "\t";
        */
}