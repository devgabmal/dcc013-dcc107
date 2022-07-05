// 6 minutos e 45 segundos
#include <iostream>

using namespace std;

int fatorial(int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return fatorial(n - 1) * n;
    else
    {
        cout << "Numero invalido!" << endl;
        exit(1);
    }
}

int main()
{
    int n, fat;
    cout << "Num natural: ";
    cin >> n;

    fat = fatorial(n);

    cout << "Fatorial: " << n << "! = " << fat << endl;

    return 0;
}