#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

#define TAM 12

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

// Ex03
int *inverte(int *vet, int n)
{
    PilhaEncad p;
    for (int i = 0; i < n; i++)
        p.empilha(vet[i]);
    for (int i = 0; i < n; i++)
        vet[i] = p.desempilha();
    return vet;
}

void imprimeVet(int *vet, int n)
{
    for (int i = 0; i < n; i++)
        cout << vet[i] << "\t";
    cout << endl;
}

// Ex04
FilaEncad *inverteFila(FilaEncad *fila)
{
    FilaEncad *novaFila = new FilaEncad();
    PilhaEncad p;

    while (!fila->vazia())
        p.empilha(fila->desenfileira());

    while (!p.vazia())
        novaFila->enfileira(p.desempilha());

    return novaFila;
}

// Ex05
FilaEncad *concatena(FilaEncad *f1, FilaEncad *f2)
{
    FilaEncad *filaNova = new FilaEncad;
    while (!f1->vazia())
        filaNova->enfileira(f1->desenfileira());
    while (!f2->vazia())
        filaNova->enfileira(f2->desenfileira());
    return filaNova;
}

// Ex06
void removeDaPilha(PilhaEncad *p, int x)
{
    PilhaEncad pilhaAux;
    int i = 0;
    while (!p->vazia())
    {
        int val = p->desempilha();
        if (val != x)
            pilhaAux.empilha(val);
        i++;
    }
    while (!pilhaAux.vazia())
        p->empilha(pilhaAux.desempilha());
}

int main()
{
    /// TESTE COM PILHA
    PilhaEncad p;

    for (int i = 0; i < 5; i++)
        p.empilha(i);
    cout << "Pilha apos inserir 5 valores" << endl;
    /// p.imprime();

    for (int i = 20; i < 25; i++)
    {
        // if (i == 22)
        //     p.empilha(2);
        // else
        p.empilha(i);
    }
    cout << "Pilha apos inserir mais 5 valores" << endl;
    /// p.imprime();

    // Ex02
    // cout << "Tamanho: " << p.tamanho() << endl;

    // Ex03
    // int *vet = new int[TAM];
    // for (int i = 0; i < TAM; i++)
    //     vet[i] = numAleatorio(0, 50);
    // imprimeVet(vet, TAM);
    // inverte(vet, TAM);
    // imprimeVet(vet, TAM);

    /// TESTE COM FILA

    FilaEncad f;
    for (int i = 0; i < 5; i++)
        f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    /// f.imprime();

    for (int i = 20; i < 25; i++)
        f.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    /// f.imprime();

    // Ex04
    // f.imprime();
    // f = *inverteFila(&f);
    // f.imprime();

    // Ex05
    // FilaEncad *f2 = new FilaEncad;
    // for (int i = 5; i < 10; i++)
    //     f2->enfileira(i);
    // cout << "Fila apos inserir 5 valores" << endl;
    // f.imprime();
    // f2->imprime();
    // FilaEncad f3 = *concatena(&f, f2);
    // f.imprime();
    // f2->imprime();
    // f3.imprime();

    // Ex06
    p.imprime();
    removeDaPilha(&p, 2);
    p.imprime();

    return 0;
}
