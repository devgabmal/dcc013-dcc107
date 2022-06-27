#include <iostream>
#include "ListaEncadDesc.h"

using namespace std;

int main()
{
    ListaEncadDesc l;
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

    l.removeK(2);
    //  l.removeFinal();
    //  l.removeInicio();
    //  l.insereK(4, -1);

    l.imprime();
    /* cout << endl
         << l.ultimo->getInfo() << " | " << l.n;*/

    return 0;
}