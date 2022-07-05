#include <iostream>

using namespace std;

float menor(int n, float vet[])
{
    if(n == 1)
        return vet[n - 1];

    float x = menor(n - 1, vet);

    if(vet[n - 1] < x)
        return vet[n - 1];
    else
        return x;
}

int main()
{
    float vet[] = {1.2, 4, 6, 1, 65.8, 2, 6, 0.2, 3, 4};
    int tam = 10;
    float men;

    men = menor(tam, vet);

    cout << "Menor: " << men << endl;

    return 0;
}
