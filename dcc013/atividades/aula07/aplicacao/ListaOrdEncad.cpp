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
    case 4:
        cout << "Tentativa de busca de elemento fora da lista!";
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
    Par *p = primeiro;
    while (p != NULL)
    {
        Par *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaOrdEncad::insere(int val, int ordem)
{
    Par *ant = NULL;
    Par *p = primeiro;

    while (p != NULL && p->getOrd() < ordem)
    {
        ant = p;
        p = p->getProx();
    }

    if (p != NULL && p->getOrd() == ordem)
    {
        p->setCoef(p->getCoef() + val);
    }
    else
    {
        Par *novo = new Par();
        novo->setCoef(val);
        novo->setOrd(ordem);

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
}

void ListaOrdEncad::remove(int ord)
{
    Par *ant = NULL;
    Par *p = primeiro;

    if (primeiro == NULL)
        rotina_erro(-1);

    while (p != NULL)
    {
        if (p->getOrd() == ord)
        {
            if (ant == NULL)
            {
                primeiro = p;
                delete ant;
            }
            else
            {
                Par *prox = p->getProx();
                ant->setProx(prox);
                delete p;
                return;
            }
        }
        ant = p;
        p = p->getProx(); // Caminha para próximo nó
    }
}

Par *ListaOrdEncad::get(int k)
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
        return primeiro;
    }

    Par *p = primeiro;
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
        return p;
}

void ListaOrdEncad::imprime()
{
    Par *p = primeiro;
    while (p != NULL)
    {
        cout << p->getCoef() << "x^" << p->getOrd();
        if (p->getProx() != NULL)
            cout << " +";
        cout << " ";
        p = p->getProx(); // Caminha para próximo nó
    }
    cout << endl;
}
