// 7 minutos
#include <iostream>

using namespace std;

int soma(int n)
{
    if (n == 1)
        return 1;
    else if (n > 1)
        return soma(n - 1) + n;
    else if (n == 0)
        return 0;
    else
    {
        cout << "ERRO: O numero fornecido e invalido!" << endl;
        exit(1);
    }
}

int main()
{
    int n, som;

    cout << "Numero natural: ";
    cin >> n;

    som = soma(n);

    cout << "SOMA: " << som << endl;
    return 0;
}