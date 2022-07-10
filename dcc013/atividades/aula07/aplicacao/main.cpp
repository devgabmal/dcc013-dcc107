// 45 minutos
#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "Polinomio.h"

#define TAM 5

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

Polinomio *soma(Polinomio *p1, Polinomio *p2)
{
    Polinomio *pSoma;
    int n1 = p1->getNumTermos();
    int n2 = p2->getNumTermos();
    int n;
    if (n1 > n2)
    {
        pSoma = new Polinomio(n1);
        for (int i = n2 + 1; i <= n1; i++)
            pSoma->insereTermo(p1->getPorOrdem(i), i);
        n = n2;
    }
    else
    {
        pSoma = new Polinomio(n2);
        for (int i = n1 + 1; i <= n2; i++)
            pSoma->insereTermo(p2->getPorOrdem(i), i);
        n = n1;
    }

    for (int i = n; i >= 0; i--)
    {
        float somaTermos = p1->getPorOrdem(i) + p2->getPorOrdem(i);
        pSoma->insereTermo(somaTermos, i);
    }

    return pSoma;
}

int main()
{
    srand(time(NULL));

    Polinomio *polinomio = new Polinomio(TAM);
    Polinomio *polinomio2 = new Polinomio(TAM / 1.5);

    for (int i = 0; i < TAM; i++)
        polinomio->insereTermo(numAleatorio(-9, 9) / (float)2, i);
    for (int i = 0; i < TAM / 1.5; i++)
        polinomio2->insereTermo(numAleatorio(-9, 9) / 2, i);

    polinomio->insereTermo(-7, 7);
    polinomio->insereTermo(0, 0);
    polinomio->insereTermo(7, 2);
    polinomio->insereTermo(-4, 9);
    polinomio->removeTermo(4);

    cout << "Polinomios: " << endl;
    polinomio->imprime();
    polinomio2->imprime();
    cout << endl;

    // Ex02
    cout << "Soma: " << endl;
    Polinomio *polinomioSoma = soma(polinomio, polinomio2);
    polinomioSoma->imprime();

    int x = 4;
    cout << "Calculo em " << x << ": " << polinomio2->calculaEmX(x);

    delete polinomio;
    return 0;
}