#include <iostream>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    primeiro = NULL;
}

ListaEncad::~ListaEncad()
{
    No *p = primeiro;
    while (p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaEncad::insereInicio(int val)
{
    No *p = new No;       // Aloca espaço para novo nó
    p->setInfo(val);      // Define informação
    p->setProx(primeiro); // Define o atual primeiro nó como posterior ao novo
    primeiro = p;         // Define novo nó como o primeiro da lista
}

void ListaEncad::insereFinal(int val)
{
    if (primeiro == NULL) // Se não houver nós...
        insereInicio(val);
    else // Se houver nós..
    {
        No *novo = new No;  // Aloca espaço para novo nó
        novo->setInfo(val); // Define informação
        novo->setProx(NULL);

        No *p = primeiro;
        while (p->getProx() != NULL) // Caminha até o final
            p = p->getProx();        // Caminha para próximo nó
        p->setProx(novo);            // Adiciona nó após o último
    }
}

void ListaEncad::insereK(int k, int val)
{
    if (primeiro == NULL || k <= 0) // Se não houver nós ou o índice for menor que 0...
        insereInicio(val);
    else // Se houver nós..
    {
        No *p = primeiro;
        No *penultimo = NULL;
        for (int i = 0; p != NULL && i < k; i++) // Caminha até o nó K
        {
            penultimo = p;
            p = p->getProx(); // Caminha para próximo nó
        }

        No *novo = new No;  // Aloca espaço para novo nó
        novo->setInfo(val); // Define informação
        novo->setProx(p);

        penultimo->setProx(novo); // Adiciona nó após o último
    }
}

void ListaEncad::removeInicio()
{
    if (primeiro != NULL)
    {
        No *p = primeiro;
        primeiro = primeiro->getProx();
        delete p;
    }
    else
        cout << "ERRO: Lista vazia!";
}

void ListaEncad::removeFinal()
{
    if (primeiro != NULL)
    {
        No *p = primeiro;
        No *penultimo = NULL;
        // Caminha até o final
        while (p->getProx() != NULL)
        {
            penultimo = p;
            p = p->getProx(); // Caminha para próximo nó
        }
        if (penultimo == NULL) // Se há apenas um nó...
            primeiro = NULL;
        else // Se há mais nós...
            penultimo->setProx(NULL);
        delete p;
    }
    else
        cout << "ERRO: Lista vazia!";
}

void ListaEncad::removeK(int k)
{
    if (primeiro == NULL) // Lista vazia
    {
        cout << "ERRO: Lista vazia!";
        return;
    }
    if (k < 0) // Índice negativo
    {
        cout << "ERRO: Indice negativo!";
        return;
    }
    if (k == 0 && primeiro->getProx() == NULL) // Há apenas um nó e deseja-se apagá-lo
    {
        delete primeiro;
        primeiro = NULL;
        return;
    }

    No *p = primeiro;
    No *penultimo = NULL;
    int i;

    // Caminha até o final
    for (i = 0; p->getProx() != NULL && i < k; i++)
    {
        penultimo = p;
        p = p->getProx(); // Caminha para próximo nó
    }
    if (p->getProx() == NULL && (i < k)) // Chegou ao fim da lista, e o índice mais um é superior ao tamanho da lista
    {
        cout << "ERRO: Tentativa de delecao de elemento fora da lista!";
        return;
    }
    if (penultimo == NULL)              // Há mais de um nó na lista, mas o índice a apagar é 0
        primeiro = primeiro->getProx(); // Define o primeiro nó como o próximo

    else                                  // Há mais de um nó na lista e o índice a apagar é maior que 0
        penultimo->setProx(p->getProx()); // Desencadeia o nó
    delete p;                             // Deleta da memória no nó
}

int ListaEncad::get(int k)
{
    if (primeiro == NULL) // Lista vazia
    {
        cout << "ERRO: Lista vazia!";
        exit(1);
    }
    if (k < 0) // Índice negativo
    {
        cout << "ERRO: Indice negativo!";
        exit(2);
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
        cout << "ERRO: Tentativa de busca de elemento fora da lista!";
        exit(3);
    }
    else // Há mais de um nó na lista e o índice a buscar é maior que 0
        return p->getInfo();
}

bool ListaEncad::busca(int val)
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

void ListaEncad::imprime()
{
    No *p = primeiro;
    while (p != NULL)
    {
        cout << p->getInfo() << "\t";
        p = p->getProx(); // Caminha para próximo nó
    }
}