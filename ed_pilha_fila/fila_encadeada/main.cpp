#include <iostream>
#include "FilaEncad.h"

#define TAM 10

using namespace std;

int main()
{
    FilaEncad f;

    cout << "Enfileirando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = rand() % 100;
        f.enfileira(val);
        cout << val << "\t";
    }
    cout << endl;

    cout << "Imprimindo:" << endl;
    for (int i = 0; i < TAM; i++)
        cout << f.desenfileira() << "\t";

    return 0;
}