#include <iostream>
#include "Polinomio.h"

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

Polinomio::Polinomio(int tam)
{
    primeiro = new Par();
    primeiro->setOrd(tam);

    Par *ant = primeiro;

    for (int i = tam - 1; i >= 0; i--)
    {
        Par *novo = new Par();
        novo->setOrd(i);
        ant->setProx(novo);
        ant = novo;
    }
}

Polinomio::~Polinomio()
{
    Par *p = primeiro;
    while (p != NULL)
    {
        Par *t = p->getProx();
        delete p;
        p = t;
    }
}

void Polinomio::insereTermo(float val, int ordem)
{
    Par *ant = NULL;
    Par *p = primeiro;

    if (ordem > p->getOrd())
    {
        primeiro = new Par();
        primeiro->setOrd(ordem);
        primeiro->setCoef(val);
        ant = primeiro;
        int i = ordem - 1;
        Par *novo = NULL;
        while (i > p->getOrd())
        {
            novo = new Par();
            novo->setOrd(i);
            ant->setProx(novo);
            ant = novo;
            i--;
        }
        novo->setProx(p);
        return;
    }

    while (p != NULL && p->getOrd() > ordem)
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

void Polinomio::removeTermo(int ordem)
{
    Par *ant = NULL;
    Par *p = primeiro;

    if (primeiro == NULL)
        rotina_erro(-1);

    while (p != NULL)
    {
        if (p->getOrd() == ordem)
        {
            p->setCoef(0);
        }
        ant = p;
        p = p->getProx(); // Caminha para próximo nó
    }
}

void Polinomio::imprime()
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
