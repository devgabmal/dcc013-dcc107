#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "FilaEncad.h"
#include "PilhaEncad.h"
#include "ListaCirc.h"
#include "FilaCirc.h"

#define NUM_NOS 12

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

void preencherFilaEncad(FilaEncad *f, int numNos)
{
    cout << "Inserindo valores: ";
    for (int i = 1; i <= numNos; i++)
    {
        int val = numAleatorio(0, 50); /// cria um valor aleatório entre 0 e 50
        cout << val << ", ";
        f->enfileira(val);
    }
    cout << endl;
}

void preencherPilha(PilhaEncad *p, int numNos, int inicio, int fim)
{
    cout << "Inserindo valores: ";
    for (int i = 1; i <= numNos; i++)
    {
        int val = numAleatorio(inicio, fim); /// cria um valor aleatório entre 0 e 50
        cout << val << ", ";
        p->empilha(val);
    }
    cout << endl;
}

void preencherFilaCirc(FilaCirc *f, int numNos, int inicio, int fim)
{
    cout << "Inserindo valores: ";
    for (int i = 1; i <= numNos; i++)
    {
        int val = numAleatorio(inicio, fim); /// cria um valor aleatório entre 0 e 50
        cout << val << ", ";
        f->enfileira(val);
    }
    cout << endl;
}

// Ex 01
FilaEncad *inverte(FilaEncad *fila)
{
    FilaEncad *novaFila = new FilaEncad();
    PilhaEncad p;

    while (!fila->vazia())
        p.empilha(fila->desenfileira());

    while (!p.vazia())
        novaFila->enfileira(p.desempilha());

    return novaFila;
}

// Ex 02
ListaCirc *montaListaCircular(PilhaEncad *pilha)
{
    ListaCirc *lista = new ListaCirc();
    while (!pilha->vazia())
        lista->insereFinal(pilha->desempilha());
    return lista;
}

// Ex 03
FilaCirc montaFilaCircular(FilaEncad *filaEncad)
{
    FilaCirc filaCirc(500);
    while (!filaEncad->vazia())
        filaCirc.enfileira(filaEncad->desenfileira());
    return filaCirc;
}

// Ex 04
FilaEncad montaFilaEncadeada(FilaCirc *filaCirc)
{
    FilaEncad filaEncad;
    while (!filaCirc->vazia())
        filaEncad.enfileira(filaCirc->desenfileira());
    return filaEncad;
}

// Ex05
void separaNumeros(PilhaEncad *pilha, FilaCirc *fNeg, FilaCirc *fPos)
{
    while (!pilha->vazia())
    {
        int val = pilha->desempilha();
        if (val < 0)
            fNeg->enfileira(val);
        else
            fPos->enfileira(val);
    }
}

// Ex06
void leValoresFilaEncadeada(FilaEncad *fila)
{
    cout << "Lendo valores para fila: (0 para sair)" << endl;
    int val;
    cin >> val;
    while (val != 0)
    {
        if (val > 0)
            fila->enfileira(val);
        else if (!fila->vazia())
            fila->desenfileira();
        cin >> val;
    }
    fila->imprime();
}

void ex01()
{
    FilaEncad f;
    preencherFilaEncad(&f, NUM_NOS);
    f.imprime();

    f = *inverte(&f);
    f.imprime();
}

void ex02()
{
    PilhaEncad p;
    preencherPilha(&p, NUM_NOS, 0, 50);
    p.imprime();

    ListaCirc *l = montaListaCircular(&p);
    p.imprime();
    l->imprime(1);
}

void ex03()
{
    FilaEncad f;
    preencherFilaEncad(&f, NUM_NOS);
    f.imprime();

    FilaCirc filaCirc = montaFilaCircular(&f);
    filaCirc.imprime(1);
}

void ex04()
{
    FilaCirc f(500);
    preencherFilaCirc(&f, NUM_NOS, 0, 50);
    f.imprime(1);

    FilaEncad filaEncad = montaFilaEncadeada(&f);
    filaEncad.imprime();
}

void ex05()
{
    PilhaEncad p;
    FilaCirc f1(100);
    FilaCirc f2(100);

    preencherPilha(&p, 100, -50, 50);
    p.imprime();

    separaNumeros(&p, &f1, &f2);

    p.imprime();
    f1.imprime(1);
    f2.imprime(1);
}

void ex06()
{
    FilaEncad f;
    leValoresFilaEncadeada(&f);
}

int main()
{
    srand(time(NULL));

    // Ex 01
    // ex01();

    // Ex 02
    // ex02();

    // Ex 03
    // ex03();

    // Ex 04
    // ex04();

    // Ex 05
    // ex05();

    // Ex06
    ex06();

    return 0;
}