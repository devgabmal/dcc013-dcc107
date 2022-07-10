#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
    // srand(time(NULL));

    ListaEncad l;
    int n, val;

    n = 4;

    for (int i = 0; i < n; i++)
        l.insereFinal(numAleatorio(-9, 50));

    l.imprime();

    // Ex03 - 3 minutos e 48 segundos
    cout << "N. elem: " << l.getComprimento() << endl;

    // Ex04 - 2 minutos e 50 segundos
    cout << "N. elem maiores: " << l.contaMaiores(2) << endl;

    // Ex05
    l.insereOrdenado(0);
    l.insereOrdenado(7);
    l.insereOrdenado(3);
    l.imprime();

    // Ex08 - 14 minutos e 23 segundos
    ListaEncad l2;
    ListaEncad l3;
    ListaEncad l4;
    l3.insereInicio(0);
    for (int i = 0; i < l.getComprimento(); i++)
        l4.insereFinal(l.get(i));
    cout << boolalpha << l.igual(&l) << endl;
    cout << boolalpha << l.igual(&l2) << endl;
    cout << boolalpha << l.igual(&l3) << endl;
    cout << boolalpha << l.igual(&l4) << endl;

    // Ex10 - 8 minutos 42 segundos
    l.removeValor(7);
    l.imprime();

    // Ex17 - 15 minutos e 52 segundos
    int *vet = new int[n];
    for (int i = 0; i < n; i++)
        vet[i] = numAleatorio(-9, 50);

    ListaEncad *l5 = l.vetor2Lista(n, vet);
    l5->imprime();

    int *vet2 = l5->lista2Vetor(l5);
    for (int i = 0; i < n; i++)
        cout << vet[i] << "\t";
    cout << endl;

    return 0;
}