#include <iostream>
#include "PilhaEncad.h"

#define TAM 10

using namespace std;

int main()
{
    PilhaEncad p;

    cout << "Empilhando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = rand() % 100;
        p.empilha(val);
        cout << val << "\t";
    }
    cout << endl;

    cout << "Imprimindo:" << endl;
    for (int i = 0; i < TAM; i++)
        cout << p.desempilha() << "\t";

    return 0;
}