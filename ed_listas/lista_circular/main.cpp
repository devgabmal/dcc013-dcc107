#include <iostream>
#include "ListaCirc.h"

using namespace std;

int main()
{
    ListaCirc l;
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

    // l.insereInicio(41);
    // l.insereFinal(42);
    // l.insereK(-1, 43);
    // l.insereK(0, 44);
    // l.insereK(1, 45);
    // l.insereK(n - 1, 46);
    // l.insereK(n, 47);
    // l.insereK(n + 1, 48);

    // l.removeInicio();
    // l.removeFinal();
    // l.removeK(0);
    // l.removeK(1);
    // l.removeK(n - 2);
    // l.removeK(n - 1);
    // l.removeK(n);

    // l.imprimeAntProx(1);
    // l.imprimeAntProx(2);

    // cout << l.get(-1);
    // cout << l.get(0) << endl;
    // cout << l.get(1) << endl;
    // cout << l.get(n - 2) << endl;
    // cout << l.get(n - 1) << endl;
    // cout << l.get(n) << endl;

    // l.set(-1, 51);
    // l.set(0, 52);
    // l.set(1, 53);
    // l.set(n - 2, 54);
    // l.set(n - 1, 55);
    // l.set(n, 56);

    l.imprime(1);
    // cout << boolalpha << l.busca(0) << endl;
    // cout << boolalpha << l.busca(1) << endl;
    // cout << boolalpha << l.busca(5) << endl;
    // cout << boolalpha << l.busca(53) << endl;

    cout << l.contaNos() << endl;

    return 0;
}