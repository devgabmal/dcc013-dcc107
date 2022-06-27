#include <iostream>
#include "ListaEncad.h"

using namespace std;

int main()
{
    ListaEncad l;
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

    // l.removeK(4);
    //   l.removeFinal();
    //   l.removeInicio();

    l.imprime();
    cout << endl
         << l.get(0);

    return 0;
}