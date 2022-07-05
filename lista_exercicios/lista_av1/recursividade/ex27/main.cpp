// 5 minutos e 20 segundos
#include <iostream>

using namespace std;

int numDigitos(int n)
{
    // Garante que o número seja positivo
    if (n < 0)
    {
        n = n * -1;
    }

    if (n < 10)
        return 1;
    else
    {
        return numDigitos(n / 10) + 1;
    }
}

int main()
{
    int n, nDig;

    cout << "Num: ";
    cin >> n;

    nDig = numDigitos(n);

    cout << "Numero de digitos: " << nDig << endl;
    return 0;
}