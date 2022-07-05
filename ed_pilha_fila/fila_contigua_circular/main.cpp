#include <iostream>
#include "FilaCirc.h"

#define TAM 10

using namespace std;

int main()
{
    FilaCirc f(TAM);

    cout << "Enfileirando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = rand() % 100;
        f.enfileira(val);
        cout << val << "\t";
    }
    cout << endl;

    cout << "Imprimindo:" << endl;
    for (int i = 0; i < TAM / 2; i++)
        cout << f.desenfileira() << "\t";
    cout << endl;

    cout << "Enfileirando:" << endl;
    for (int i = 0; i < TAM / 2 - 1; i++)
    {
        int val = rand() % 100;
        f.enfileira(val);
        cout << val << "\t";
    }
    cout << endl;

    cout << "Imprimindo:" << endl;
    for (int i = 0; i < TAM / 2; i++)
        cout << f.desenfileira() << "\t";

    return 0;
}