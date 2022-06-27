#include <iostream>
#include "ListaEncadDupla.h"

using namespace std;

int main()
{
    ListaEncadDupla l;
    int n, val;

    // cout << "Quantidade de nos: ";
    //  cin >> n;
    n = 4;

    for (int i = 0; i < n; i++)
    {
        // cout << "Valor do no: ";
        //  cin >> val;
        val = (i + 1);
        l.insereFinal(val);
    }

    //   l.removeK(2);
    //   l.removeFinal();
    //   l.removeInicio();
    //   l.insereK(4, -1);

    l.insereK(0, 42);
    l.removeK(1);
    // l.imprimeAntProx();
    l.imprimeReverso();
    // l.imprime();
    /* cout << endl
         << l.ultimo->getInfo() << " | " << l.n;*/

    return 0;
}