#include <iostream>

using namespace std;

bool ehPar(int num)
{
    if(num % 2 == 0)
        return 1;
    else
        return 0;
}

int contaPares(int n, int vet[])
{
    if(n == 0)
        return 0;
    else
    {
        if(n == 1)
            return ehPar(vet[n - 1]);
        else
        {
            return ehPar(vet[n - 1]) + contaPares(n - 1, vet);
        }
    }
}

int main()
{
    int vet[] = {1, 2, 4, 6, 1, 653, 8, 2, 6, 0, 2, 3, 4};
    int tam, numPares;

    tam = 13;

    numPares = contaPares(tam, vet);

    cout << "Num pares: " << numPares
         << endl;

    return 0;
}
