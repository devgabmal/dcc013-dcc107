#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaCont.h"
#include "ListaOrdCont.h"

#define TAM 10

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
    srand(time(NULL));

    ListaOrdCont lOrd(TAM);
    ListaOrdCont lOrd2(TAM / 2);
    ListaOrdCont *lOrdNova;
    // ListaCont l(TAM);

    // for (int i = 0; i < TAM; i++)
    //     l.insere(numAleatorio(-9, 50));

    // for (int i = 0; i < TAM; i++)
    //     l.insereFinal(numAleatorio(-9, 50));
    // l.imprime();

    // for (int i = 0; i < TAM; i++) // Complexidade O(n^2)
    //     lOrd.insere(l.get(i));

    for (int i = 0; i < TAM; i++)
        lOrd.insere(numAleatorio(-9, 50));

    for (int i = 0; i < TAM / 2; i++)
        lOrd2.insere(numAleatorio(-9, 50));

    // l.imprime();
    lOrd.imprime();
    cout << endl;
    lOrd2.imprime();
    cout << endl;

    lOrdNova = lOrd.intercala(&lOrd2); // Complexidade O(n)
    lOrdNova->imprime();

    return 0;
}