// 31 minutos e 31 segundos
#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaCirc.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
    srand(time(NULL));

    ListaCirc l;
    int n, val;

    n = 4;

    for (int i = 0; i < n; i++)
    {
        int valX = numAleatorio(-9, 9);
        int valY = numAleatorio(-9, 9);
        l.insereFinal(valX, valY);
    }

    l.insereInicio(41, 14);
    l.insereFinal(42, 21);
    // l.insereK(-1, 43, 34);
    l.insereK(0, 44, 44);
    l.insereK(1, 45, 54);
    l.insereK(n - 1, 46, 64);
    l.insereK(n, 47, 74);
    l.insereK(n + 1, 48, 84);

    l.removeInicio();
    l.removeFinal();
    l.removeK(0);
    l.removeK(1);
    l.removeK(n - 2);
    l.removeK(n - 1);
    l.removeK(n);

    // l.imprimeAntProx(1);
    // l.imprimeAntProx(2);

    // cout << l.get(-1);
    // cout << l.get(0) << endl;
    // cout << l.get(1) << endl;
    // cout << l.get(n - 2) << endl;
    // cout << l.get(n - 1) << endl;
    // cout << l.get(n) << endl;

    // l.set(-1, 51);
    // l.set(0, 52);
    // l.set(1, 53);
    // l.set(n - 2, 54);
    // l.set(n - 1, 55);
    // l.set(n, 56);

    l.imprime(1);

    // cout << l.contaNos() << endl;

    return 0;
}