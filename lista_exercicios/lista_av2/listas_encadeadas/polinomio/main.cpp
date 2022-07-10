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

int main()
{
    srand(time(NULL));

    Polinomio *polinomio = new Polinomio(TAM);

    for (int i = 0; i < TAM; i++)
    {
        polinomio->insereTermo(numAleatorio(-9, 9) / (float)2, i);
    }

    polinomio->imprime();

    polinomio->insereTermo(-7, 7);
    polinomio->insereTermo(0, 0);
    polinomio->insereTermo(7, 2);
    polinomio->insereTermo(-4, 9);

    polinomio->removeTermo(4);

    cout
        << "Polinomio: " << endl;
    polinomio->imprime();

    delete polinomio;
    return 0;
}