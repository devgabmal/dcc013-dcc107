#include <iostream>
#include "ListaOrdCont.h"

using namespace std;

ListaOrdCont::ListaOrdCont(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaOrdCont::~ListaOrdCont()
{
    delete[] vet;
}

bool verificaIndice(int k, int num)
{
    if (k >= 0 && k < num)
        return true;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

bool verificaTamanhoLivre(int n, int tam)
{
    if (n < tam)
        return true;
    else
    {
        cout << "ERRO: Lista cheia!" << endl;
        exit(2);
    }
}

int ListaOrdCont::get(int k)
{
    if (verificaIndice(k, n))
        return vet[k];
    else
        exit(1);
}

void ListaOrdCont::insere(int val)
{
    if (verificaTamanhoLivre(n, max))
    {
        int i;
        for (i = n - 1; i >= 0 && vet[i] >= val; i--)
            vet[i + 1] = vet[i];
        vet[i + 1] = val;
        n++;
    }
}

int ListaOrdCont::buscaBinaria(int val) // Retorna índice da posição procurada
{
    int esq = 0;
    int dir = n - 1;

    while (esq <= dir)
    {
        int meio = (esq + dir) / 2;
        if (vet[meio] < val) // Valor está depois do meio
            esq = meio + 1;
        else if (vet[meio] > val) //  Valor está antes do meio
            dir = meio - 1;
        else // Valor está no meio exato
            return meio;
    }
    return -1; // Valor não encontrado
}

bool ListaOrdCont::busca(int val)
{
    int k = buscaBinaria(val);
    return k >= 0 && k < n; // Returna true se buscaBinaria retornou índice válido
}

void ListaOrdCont::remove(int val)
{
    int k = buscaBinaria(val);
    if (verificaIndice(k, n))
    {
        for (int i = k; i < n - 1; i++)
            vet[i] = vet[i + 1];
        n--;
    }
    else
        exit(1);
}

void ListaOrdCont::imprime()
{
    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << "\t";
    }
    cout << endl;
}