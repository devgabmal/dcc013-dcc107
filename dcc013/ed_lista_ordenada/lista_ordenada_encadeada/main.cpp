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
    // srand(time(NULL));

    ListaOrdEncad *lista = new ListaOrdEncad();
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int valor;
    //     cin >> valor;
    //     lista->insere(valor);
    // }

    // Ex02
    for (int i = 0; i < TAM; i++)
        lista->insere(numAleatorio(-9, 9));

    cout << "Lista Ordenada: " << endl;
    lista->imprime();

    // Ex03
    cout << boolalpha << lista->busca(-7) << endl;

    lista->remove(-7);

    lista->imprime();

    delete lista;
    return 0;
}