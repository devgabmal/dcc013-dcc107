#include <iostream>
#include "ListaOrdCont.h"

#define TAM 10

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

int main()
{

    ListaOrdCont l(TAM);

    for (int i = 0; i < TAM; i++)
    {
        l.insere(numAleatorio(-9, 50));
    }

    l.imprime();

    l.remove(38);
    // l.remove(24);
    l.remove(-5);

    l.imprime();

    cout << boolalpha << l.busca(-1) << endl;
    cout << boolalpha << l.busca(9) << endl;

    return 0;
}