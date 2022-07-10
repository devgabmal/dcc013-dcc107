// Ex12, ex14
#include <iostream>
#include <cstring>
#include "PilhaCont.h"

#define TAM 10

using namespace std;

bool ehPalindromo(int n, PilhaCont *p)
{
    PilhaCont *pInversa1 = new PilhaCont(n);
    PilhaCont *pInversa2 = new PilhaCont(n);
    PilhaCont *pCopia = new PilhaCont(n);

    for (int i = 0; i < n; i++)
    {
        int val = p->desempilha();
        pInversa1->empilha(val);
        pInversa2->empilha(val);
    }
    for (int i = 0; i < n; i++)
    {
        int val = pInversa1->desempilha();
        pCopia->empilha(val);
        p->empilha(val);
    }
    for (int i = 0; i < n; i++)
    {
        if (pCopia->getTopo() != pInversa2->getTopo())
            return false;
    }
    delete pInversa1;
    delete pInversa2;
    delete pCopia;
    return true;
}

char *inverteTexto(char *texto)
{
    int i = 0;
    int j = 0;
    int e = 0;
    PilhaCont *pilha = new PilhaCont(strlen(texto) - 1);
    char *textoInverso = new char[strlen(texto)];

    while (texto[i] != 0)
    {
        if (texto[i] == ' ' || texto[i] == '.')
        {
            while (!pilha->vazia())
            {
                textoInverso[i - j + e] = pilha->desempilha();
                j--;
            }
            textoInverso[i] = ' ';
            e++;
        }
        else
            pilha->empilha(texto[i]);
        i++;
        j++;
    }
    textoInverso[i] = '\0';
    return textoInverso;
}

void exPadrao()
{
    PilhaCont p(TAM);

    for (int i = 0; i < TAM; i++)
        p.empilha(rand() % 100);
    // p.imprime();

    for (int i = 0; i < TAM; i++)
        p.empilha(rand() % 100);
    // p.imprime();

    for (int i = 0; i < TAM; i++)
        cout << p.desempilha() << "\t";
    cout << endl;
}

void ex20()
{
    PilhaCont p(TAM);

    // Ex20 - 19 minutos
    for (int i = 1; i < TAM / 2; i++)
        p.empilha(i);
    for (int i = TAM / 2; i > 0; i--)
        p.empilha(i);
    // while (!p.vazia())
    //     cout << p.desempilha() << "\t";
    // cout << endl;

    cout << boolalpha << ehPalindromo(TAM - 1, &p) << endl;
}

void ex21()
{
    // Ex21 - 1 hora e 30 minutos
    char texto[] = "ESTE EXERCICIO E MUITO FACIL.";
    cout << inverteTexto(texto);
}

int main()
{
    exPadrao();
    ex20();
    ex21();

    return 0;
}