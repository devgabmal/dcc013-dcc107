// Ex12, ex14
#include <iostream>
#include "PilhaCont.h"

#define TAM 10

using namespace std;

int main()
{
    PilhaCont p(TAM);

    for (int i = 0; i < TAM; i++)
        p.empilha(rand() % 100);

    for (int i = 0; i < TAM; i++)
        p.empilha(rand() % 100);

    for (int i = 0; i < TAM; i++)
        cout << p.desempilha() << "\t";

    return 0;
}