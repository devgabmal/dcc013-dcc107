// 8 minutos e 30 segundos
#include <iostream>

#define NUM 5

using namespace std;

float *alocaVetorF(int n)
{
    float *vet;
    // Verifica se tamanho é válido
    if (n <= 0)
    {
        cout << "ERRO: Nao e possivel alocar vetor com tamanho nulo ou negativo!" << endl;
        exit(1);
    }
    // Aloca vetor dinamicamente
    vet = new float[n];
    // Verifica se foi alocado com sucesso
    if (vet == NULL)
    {
        cout << "ERRO: O vetor nao pode ser alocado!" << endl;
        exit(1);
    }
    return vet;
}

void preencheVetorF(int n, float *vet)
{
    cout << "Preenchendo o vetor" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "o num: ";
        cin >> vet[i];
    }
}

float *calculaSoma(int n, float vetA[], float vetB[])
{
    float *result;
    result = new float[n];

    for (int i = 0; i < n; i++)
    {
        result[i] = vetA[i] + vetB[i];
    }

    return result;
}

int main()
{
    float *vet1, *vet2, *soma;

    // Inicialização
    vet1 = alocaVetorF(NUM);
    vet2 = alocaVetorF(NUM);

    preencheVetorF(NUM, vet1);
    preencheVetorF(NUM, vet2);

    // Testes
    soma = calculaSoma(NUM, vet1, vet2);

    cout << "SOMA" << endl;
    for (int i = 0; i < NUM; i++)
    {
        cout << soma[i] << endl;
    }

    delete[] vet1;
    delete[] vet2;
    delete[] soma;

    return 0;
}