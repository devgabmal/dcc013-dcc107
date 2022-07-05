// 6 minutos
#include <iostream>

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

double *alocaVetorD(int n)
{
    double *vet;
    // Verifica se tamanho é válido
    if (n <= 0)
    {
        cout << "ERRO: Nao e possivel alocar vetor com tamanho nulo ou negativo!" << endl;
        exit(1);
    }
    // Aloca vetor dinamicamente
    vet = new double[n];
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

void preencheVetorD(int n, double *vet)
{
    cout << "Preenchendo o vetor" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "o num: ";
        cin >> vet[i];
    }
}

int main()
{
    float *vetF;
    double *vetD;

    // Testes
    // vetF = alocaVetorF(0);
    // vetD = alocaVetorD(0);

    // vetF = alocaVetorF(-2);
    // vetD = alocaVetorD(-23);

    // vetF = alocaVetorF(2.5);
    //  vetD = alocaVetorD(-2.3);

    vetF = alocaVetorF(100);
    vetD = alocaVetorD(1000);

    preencheVetorF(100, vetF);
    preencheVetorD(100, vetD);

    delete[] vetF;
    delete[] vetD;

    return 0;
}