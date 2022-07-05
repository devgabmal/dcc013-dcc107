#include <iostream>

using namespace std;

void imprimeIntervalo(int a, int b, int inc)
{
    if(a > b)
        return;
    else
    {
        cout << a << " ";
        imprimeIntervalo(a + inc, b, inc);
    }
}

int main()
{
    int ini, fim, intervalo;
    cout << "Inicio: ";
    cin >> ini;
    cout << "Fim: ";
    cin >> fim;
    cout << "Intervalo: ";
    cin >> intervalo;

    imprimeIntervalo(ini, fim, intervalo);

    return 0;
}
