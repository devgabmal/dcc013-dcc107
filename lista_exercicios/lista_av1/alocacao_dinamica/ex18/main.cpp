#include <iostream>

using namespace std;

int main()
{
    int n;
    float soma, media;
    float *vet;

    soma = 0;
    media = 0;

    cout << "Digite um numero natural: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "ERRO: Numero invalido!" << endl;
        exit(1);
    }

    vet = new float[n];

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "o num: ";
        cin >> vet[i];
    }

    for (int i = 0; i < n; i++)
    {
        soma = soma + vet[i];
    }

    if (n > 0)
    {
        media = soma / (float)n;
    }

    cout << "Media: " << media << endl;

    delete[] vet;

    return 0;
}