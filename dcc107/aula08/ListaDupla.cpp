#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while (p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for (p = primeiro; p != NULL; p = p->getProx())
        if (p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for (int i = 0; i < k; i++)
    {
        if (p == NULL)
            break;
        p = p->getProx();
    }
    if (p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for (int i = 0; i < k; i++)
    {
        if (p == NULL)
            break;
        p = p->getProx();
    }
    if (p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(primeiro);
    p->setAnt(NULL);

    if (n == 0)
        ultimo = p;
    else
        primeiro->setAnt(p);

    primeiro = p;
    n = n + 1;
}

void ListaDupla::removeInicio()
{
    NoDuplo *p;
    if (primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;
        n = n - 1;

        if (n == 0)
            ultimo = NULL;
        else
            primeiro->setAnt(NULL);
    }
    else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);

    if (n == 0)
        primeiro = p;
    else
        ultimo->setProx(p);

    ultimo = p;
    n = n + 1;
}

void ListaDupla::removeFinal()
{
    NoDuplo *p;
    if (ultimo != NULL)
    {
        p = ultimo;
        ultimo = p->getAnt();
        delete p;
        n = n - 1;

        if (n == 0)
            primeiro = NULL;
        else
            ultimo->setProx(NULL);
    }
    else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::imprime()
{
    if (n == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    for (NoDuplo *p = primeiro; p != NULL; p = p->getProx())
    {
        cout << p->getInfo() << "\t";
    }
    cout << endl;
}

void ListaDupla::imprimeReverso()
{
    if (n == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    for (NoDuplo *p = ultimo; p != NULL; p = p->getAnt())
    {
        cout << p->getInfo() << "\t";
    }
    cout << endl;
}

ListaDupla *ListaDupla::concatena(ListaDupla *l2)
{
    ListaDupla *lnova = new ListaDupla();
    int numNosL2 = l2->n;

    for (NoDuplo *p = primeiro; p != NULL; p = p->getProx())
        lnova->insereFinal(p->getInfo());
    for (int i = 0; i < numNosL2; i++)
        lnova->insereFinal(l2->get(i));
    return lnova;
}

ListaDupla *ListaDupla::partir(int x)
{
    if (n == 0)
    {
        cout << "ERRO: Lista vazia!" << endl;
        exit(1);
    }
    if (x >= n)
    {
        cout << "ERRO: Índice inválido!" << endl;
        exit(2);
    }
    ListaDupla *lnova = new ListaDupla();
    NoDuplo *p;
    int i = 0;
    for (p = primeiro; p != ultimo && i < x; p = p->getProx())
    {
        i++;
    }

    NoDuplo *ant = p->getAnt();

    // Lista 2
    p->setAnt(NULL);
    lnova->primeiro = p;
    lnova->ultimo = ultimo;
    lnova->n = n - x;

    // Lista 1
    n = x;
    if (n == 0)
    {
        primeiro = NULL;
    }
    else
    {
        ant->setProx(NULL);
    }
    ultimo = ant;

    return lnova;
}

void ListaDupla::removeOcorrencias(int val)
{
    NoDuplo *p = primeiro;
    while (p != NULL)
    {
        if (p->getInfo() == val)
        {
            NoDuplo *ant = p->getAnt();
            NoDuplo *prox = p->getProx();
            if (ant == NULL)
            {
                primeiro = prox;
            }
            else
            {
                ant->setProx(prox);
            }
            if (prox == NULL)
            {
                ultimo = ant;
            }
            else
            {
                prox->setAnt(ant);
            }

            NoDuplo *aux = p;
            p = p->getProx();
            delete aux;
        }
        else
            p = p->getProx();
    }
}