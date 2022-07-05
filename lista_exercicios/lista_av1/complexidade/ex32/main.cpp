// 11 minutos e 44 segundos
#include <iostream>

using namespace std;

int f(int n)
{ // O(n)
    int soma = 0;
    for (int i = 1; i <= n; ++i)
        soma = soma + i;
    return soma;
}

int f1(int n)
{ // O(1)
    return n * (n + 1) / 2;
}

int main()
{
    int n;
    cout << "Num natural: ";
    cin >> n;

    cout << "f: " << n << " = " << f(n) << endl;

    cout << "f1: " << n << " = " << f1(n) << endl;

    return 0;
}