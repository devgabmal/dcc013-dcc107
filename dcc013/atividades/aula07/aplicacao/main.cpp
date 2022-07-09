#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaOrdEncad.h"

#define TAM 10

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
    srand(time(NULL));

    ListaOrdEncad *lista = new ListaOrdEncad();

    for (int i = 0; i < TAM; i++)
    {
        lista->insere(numAleatorio(-9, 9), i);
    }

    lista->imprime();

    lista->insere(0, 0);
    lista->insere(7, 2);
    lista->insere(-4, 9);

    lista->remove(4);

    cout << "Polinomio: " << endl;
    lista->imprime();
    // cout << lista->get(5)->getCoef();
    // cout << lista->get(4)->getCoef();

    delete lista;
    return 0;
}