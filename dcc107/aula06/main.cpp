#include <iostream>
#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

#define TAM 2

/*
void testesQ1_3()
{
    ListaCont l(10);
    ListaCont l1(50);
    ListaCont l2(50);
    ListaCont l3(50);
    int valores[3];

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);
    // l.insereValores(3, valores);
    l.imprime();
    cout << "Num de nos: " << l.numNos() << endl;
    cout << "Maior que " << 24 << "? " << l.buscaMaior(24) << endl;
    cout << "Maior que " << 123 << "? " << l.buscaMaior(123) << endl;

    for (int i = 0; i < 50; i++)
    {
        l1.insereFinal(rand() % 1999 + (-999));
    }

    l1.imprime();

    for (int i = 0; i < 25; i++)
    {
        l2.insereFinal(l1.get(0));
        l1.removeInicio();
    }

    for (int i = 0; i < 13; i++)
    {
        l3.insereFinal(l2.get(0));
        l2.removeInicio();
    }

    // l1.imprime();
    l2.imprime();
    l3.imprime();
}
*/

int main()
{
    // testesQ1_3();

    ListaCont l(TAM);

    for (int i = 0; i < TAM; i++)
    {
        l.insereFinal(Ponto(rand() % 100 + 1, rand() % 100 + 1));
    }

    // l.set(3, Ponto(4, 7));
    // l.set(TAM - 1, Ponto(9, 9));
    // l.removeFinal();
    // l.insereFinal(Ponto());
    // l.removeInicio();
    // l.insereK(1, Ponto(2, 2));

    // l.insereValores(TAM);

    l.imprime();
    cout << endl
         << "\t";
    for (int i = 0; i < l.numNos(); i++)
        cout << "(" << l.get(i).getX() << ", " << l.get(i).getY() << ")"
             << "\t";
    cout << endl;
    for (int i = 0; i < l.numNos(); i++)
    {
        cout << "(" << l.get(i).getX() << ", " << l.get(i).getY() << ")"
             << "\t";
        for (int j = 0; j < l.numNos(); j++)
        {
            Ponto origem = l.get(i);
            Ponto destino = l.get(j);
            cout << origem.distancia(&destino) << "\t";
        }
        cout << endl;
    }

    return 0;
}
