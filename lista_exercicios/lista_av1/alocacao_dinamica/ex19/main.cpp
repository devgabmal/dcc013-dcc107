// 4 minutos
#include <iostream>

using namespace std;

float calculaMedia(int n, float *vet)
{
    float soma, media;

    soma = 0;
    media = 0;

    for (int i = 0; i < n; i++)
    {
        soma = soma + vet[i];
    }

    if (n > 0)
    {
        media = soma / (float)n;
    }

    return media;
}

int main()
{
    int n;
    float *vet;

    cout << "Digite um numero natural: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "ERRO: Numero invalido!" << endl;
        exit(1);
    }

    // Aloca vetor de reais dinamicamente
    vet = new float[n];

    // Preenche vetor de reais
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "o num: ";
        cin >> vet[i];
    }

    cout << "Media: " << calculaMedia(n, vet) << endl;

    delete[] vet;

    return 0;
}