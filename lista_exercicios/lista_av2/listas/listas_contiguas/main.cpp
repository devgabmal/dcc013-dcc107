#include <iostream>
#include "ListaCont.h"

using namespace std;

int main()
{
    ListaCont l(10);

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);

    // l.set(0, 34);
    l.insereK(2, 56);
    l.insereK(0, -7);
    l.insereK(6, -98);
    l.insereFinal(5);
    l.insereFinal(23);

    // l.insereFinal(-3);

    l.imprime();

    // Ex01
    cout << boolalpha << l.troca(2, 6) << endl;
    // cout << boolalpha << l.troca(0, 10) << endl;
    // cout << boolalpha << l.troca(-1, 1) << endl;

    l.imprime();

    // Ex02 - 11 minutos e 16 segundos
    l.aumentaCapacidade(11);
    l.insereFinal(4);
    l.aumentaCapacidade(13);
    l.insereFinal(-8);
    l.aumentaCapacidade(13);
    l.aumentaCapacidade(9);

    l.imprime();

    return 0;
}