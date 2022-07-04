#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    cout << "Criando objeto ListaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad()
{
    cout << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while (p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaEncad::busca(int val)
{
    No *p;
    for (p = primeiro; p != NULL; p = p->getProx())
        if (p->getInfo() == val)
            return true;
    return false;
}

int ListaEncad::get(int k)
{
    No *p = primeiro;
    int i = 0;
    while (i < k && p != NULL)
    {
        i++;
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

void ListaEncad::set(int k, int val)
{
    No *p = primeiro;
    int i = 0;
    while (i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if (p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaEncad::insereInicio(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;

    n++;
    if (n == 1)
        ultimo = p;
}

void ListaEncad::insereFinal(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);

    if (ultimo != NULL)
        ultimo->setProx(p);
    ultimo = p;

    n++;
    if (n == 1)
        primeiro = p;
}

void ListaEncad::removeInicio()
{
    No *p;
    if (primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if (n == 0)
            ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
    No *p;
    if (ultimo != NULL)
    {
        if (primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while (p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::imprime()
{
    cout << "Impressão da lista" << endl;
    if (primeiro == NULL)
        cout << "Lista vazia";
    else
        for (No *p = primeiro; p != NULL; p = p->getProx())
        {
            cout << p->getInfo() << "\t";
        }
    cout << endl;
}

int ListaEncad::numNos()
{
    return n;
}

int ListaEncad::buscaMaior(int val)
{
    int index = 0;
    for (No *p = primeiro; p != NULL; p = p->getProx())
    {
        if (p->getInfo() > val)
            return index;
        index++;
    }
    return -1;
}

void ListaEncad::limpar()
{
    if (primeiro == NULL)
        cout << "Lista vazia";
    else
    {
        No *p = primeiro;
        while (p != NULL)
        {
            No *prox = p->getProx();
            delete p;
            p = prox;
        }
        primeiro = NULL;
        ultimo = NULL;
        n = 0;
    }
}

float ListaEncad::calculaMedia()
{
    if (primeiro == NULL)
        return 0;

    int soma = 0;
    for (No *p = primeiro; p != NULL; p = p->getProx())
    {
        soma += p->getInfo();
    }
    return soma / (float)n;
}

void ListaEncad::concatena(ListaEncad *l2)
{
    int numNosL2 = l2->numNos();
    int ind = 0;
    No *ant = ultimo;

    while (ind < numNosL2)
    {
        No *novo = new No();
        int infoNoL2 = l2->get(ind);
        novo->setInfo(infoNoL2);

        ant->setProx(novo);
        novo->setProx(NULL);

        ant = novo;
        ind++;
    }

    ultimo = ant;
}

ListaEncad *ListaEncad::partir(int x)
{
    ListaEncad *novaLista = new ListaEncad();
    ;
    No *ant = NULL;

    No *p = primeiro;
    int i = 0;
    while (i < x && p != NULL)
    {
        i++;
        ant = p;
        p = p->getProx();
    }
    if (p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
    {
        ant->setProx(NULL);
        ultimo = ant;
        n = x;

        while (p != NULL)
        {
            novaLista->insereFinal(p->getInfo());
            No *prox = p->getProx();
            delete p;
            p = prox;
        }
    }
    return novaLista;
}