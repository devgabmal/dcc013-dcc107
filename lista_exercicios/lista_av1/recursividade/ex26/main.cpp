// 5 minutos e 50 segundos
#include <iostream>

using namespace std;

int soma(int n1, int n2)
{
    if (n2 == n1)
        return n1;
    else
    {
        // Garante que n2 seja maior que n1
        if (n1 > n2)
        {
            int aux = n1;
            n1 = n2;
            n2 = aux;
        }
        return soma(n1, n2 - 1) + n2;
    }
}

int main()
{
    int n1, n2, som;

    cout << "N1: ";
    cin >> n1;
    cout << "N2: ";
    cin >> n2;

    som = soma(n1, n2);

    cout << "SOMA: " << som << endl;
    return 0;
}