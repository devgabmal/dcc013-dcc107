#include <iostream>
#include "PilhaEncad.h"

#define TAM 10

using namespace std;

int getTopo(PilhaEncad *pilha)
{
    if (!pilha->vazia())
    {
        int topo = pilha->desempilha();
        pilha->empilha(topo);
        return topo;
    }
    else
    {
        cout << "ERRO: Pilha vazia!";
        exit(1);
    }
}

void exPadrao()
{
    PilhaEncad p, p2;

    cout << "Empilhando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = rand() % 100;
        p.empilha(val);
        cout << val << "\t";
    }
    cout << endl;
    cout << "Empilhando:" << endl;
    for (int i = 0; i < TAM / 2; i++)
    {
        int val = rand() % 100;
        p2.empilha(val);
        cout << val << "\t";
    }
    cout << endl;
}

void concatenaPilhas(PilhaEncad *p1, PilhaEncad *p2)
{
    while (!p2->vazia())
        p1->empilha(p2->desempilha());
}

PilhaEncad *copiaPilha(PilhaEncad *p)
{
    PilhaEncad *pNova = new PilhaEncad();
    PilhaEncad *pInversa = new PilhaEncad();

    while (!p->vazia())
        pInversa->empilha(p->desempilha());

    while (!pInversa->vazia())
    {
        int val = pInversa->desempilha();
        pNova->empilha(val);
        p->empilha(val);
    }

    delete pInversa;
    return pNova;
}

PilhaEncad *preenchePilhaCrescente()
{
    PilhaEncad *pilha = new PilhaEncad;
    int n, nTopo;
    cout << "Preenchendo pilha: " << endl;
    cin >> n;
    pilha->empilha(n);
    nTopo = n;
    for (int i = 0; i < 299; i++)
    {
        cin >> n;
        if (n > nTopo)
        {
            pilha->empilha(n);
            nTopo = n;
        }
    }
    return pilha;
}

void ex16()
{
    PilhaEncad p, p2;

    cout << "Empilhando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = rand() % 100;
        p.empilha(val);
        cout << val << "\t";
    }
    cout << endl;

    cout << "Empilhando:" << endl;
    for (int i = 0; i < TAM / 2; i++)
    {
        int val = rand() % 100;
        p2.empilha(val);
        cout << val << "\t";
    }
    cout << endl;

    // Ex16a - 3 minutos e 50 segundos
    cout << getTopo(&p) << endl;

    // Ex16b - 8 minutos
    concatenaPilhas(&p, &p2);

    cout << "Imprimindo:" << endl;
    while (!p.vazia())
        cout << p.desempilha() << "\t";
    cout << endl;
    cout << "Imprimindo:" << endl;
    while (!p2.vazia())
        cout << p2.desempilha() << "\t";
    cout << endl;

    cout << "Empilhando:" << endl;
    for (int i = 0; i < TAM; i++)
    {
        int val = rand() % 100;
        p.empilha(val);
        cout << val << "\t";
    }
    cout << endl;

    // Ex16c - 32 minutos e 19 segundos
    p2 = *copiaPilha(&p);

    cout << "Imprimindo:" << endl;
    while (!p.vazia())
        cout << p.desempilha() << "\t";
    cout << endl;
    cout << "Imprimindo:" << endl;
    while (!p2.vazia())
        cout << p2.desempilha() << "\t";
    cout << endl;
}

void ex18()
{
    // Ex18 - 10 minutos e 24 segundos
    PilhaEncad *p = preenchePilhaCrescente();
    cout << "Imprimindo:" << endl;
    while (!p->vazia())
        cout << p->desempilha() << "\t";
    cout << endl;
}

PilhaEncad *conversaoDeDecimal(int decimal, int base)
{
    PilhaEncad *pilha = new PilhaEncad;
    int resto = 0;
    while (decimal > 0)
    {
        resto = decimal % base;
        decimal = decimal / base;
        pilha->empilha(resto);
    }
    return pilha;
}

void imprimeNaBase(PilhaEncad *p, int base)
{
    while (!p->vazia())
    {
        int num = p->desempilha();
        if (base == 16 && num > 9)
            cout << (char)(num + 'A' - 10);
        else
            cout << num;
    }
    cout << endl;
}

void ex22()
{
    // Ex22 - 28 minutos e 36 segundos
    PilhaEncad *p;
    int base = 8;
    p = conversaoDeDecimal(2047, base);
    imprimeNaBase(p, base);
}

int main()
{
    exPadrao();
    ex16();
    ex18();
    ex22();

    return 0;
}