#include <iostream>
#include "ListaOrdEncad.h"

using namespace std;

void rotina_erro(int erro)
{

    cout << "ERRO: ";
    switch (abs(erro))
    {
    case 1:
        cout << "Lista Vazia!";
        break;
    case 2:
        cout << "Indice negativo!";
        break;
    case 3:
        cout << "Tentativa de delecao de elemento fora da lista!";
        break;
    case 4:
        cout << "Tentativa de busca de elemento fora da lista!";
        break;
    case 5:
        cout << "Tentativa de edicao de elemento fora da lista!";
        break;
    default:
        break;
    }

    if (erro < 0)
        exit(erro);
}

ListaOrdEncad::ListaOrdEncad()
{
    primeiro = NULL;
}

ListaOrdEncad::~ListaOrdEncad()
{
    No *p = primeiro;
    while (p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaOrdEncad::insere(int val)
{
    No *novo = new No();
    novo->setInfo(val);

    No *ant = NULL;
    No *p = primeiro;

    while (p != NULL && p->getInfo() < val)
    {
        ant = p;
        p = p->getProx();
    }

    if (ant == NULL) // Adicionará ao começo
    {
        novo->setProx(primeiro);
        primeiro = novo;
    }
    else
    {
        ant->setProx(novo);
        novo->setProx(p);
    }
}

void ListaOrdEncad::remove(int val)
{
    if (primeiro != NULL)
    {
        No *p = primeiro;
        primeiro = primeiro->getProx();
        delete p;
    }
    else
        rotina_erro(1);
}

int ListaOrdEncad::get(int k)
{
    if (primeiro == NULL) // Lista vazia
    {
        rotina_erro(-1);
        return 0;
    }
    if (k < 0) // Índice negativo
    {
        rotina_erro(-2);
        return 0;
    }
    if (k == 0)
    {
        return primeiro->getInfo();
    }

    No *p = primeiro;
    int i = 0;

    // Caminha até o final
    for (i = 0; p->getProx() != NULL && i < k; i++)
    {
        p = p->getProx(); // Caminha para próximo nó
    }
    if (p->getProx() == NULL && (i < k)) // Chegou ao fim da lista, e o índice mais um é superior ao tamanho da lista
    {
        rotina_erro(-4);
        return 0;
    }
    else // Há mais de um nó na lista e o índice a buscar é maior que 0
        return p->getInfo();
}

bool ListaOrdEncad::busca(int val)
{
    No *p = primeiro;
    while (p != NULL)
    {
        if (p->getInfo() == val)
            return true;
        p = p->getProx(); // Caminha para próximo nó
    }
    return false;
}

void ListaOrdEncad::imprime()
{
    No *p = primeiro;
    while (p != NULL)
    {
        cout << p->getInfo() << "\t";
        p = p->getProx(); // Caminha para próximo nó
    }
    cout << endl;
}