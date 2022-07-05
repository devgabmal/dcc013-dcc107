#include <iostream>

using namespace std;

void imprimeDecrescente(int n)
{
    if(n < 0)
        return;
    else
    {
        cout << n << " ";
        imprimeDecrescente(n - 1);
    }
}

int main()
{
    int num;
    cout << "Fim: ";
    cin >> num;

    imprimeDecrescente(num);

    return 0;
}
