#include "Prova.h"

Prova::Prova(int nq)
{
    // implemente o construtor aqui
    cout << "Criando uma prova" << endl;
    n = nq;
    notasQuestoes = new double[nq];
}

Prova::~Prova()
{
    delete[] notasQuestoes;
}

// exercicio 7
void Prova::leNotas()
{
    for (int i = 0; i < n; i++)
    {
        cin >> notasQuestoes[i];
    }
}

void Prova::calculaNotaFinal()
{
    double notaFinalInt = 0;
    double menor = notasQuestoes[0];

    for (int i = 1; i < n; i++)
    {
        if (notasQuestoes[i] < menor)
            menor = notasQuestoes[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (notasQuestoes[i] != menor)
            notaFinalInt = notaFinalInt + notasQuestoes[i];
    }
    notaFinal = notaFinalInt;
}

double Prova::obtemNotaFinal()
{
    return notaFinal;
}