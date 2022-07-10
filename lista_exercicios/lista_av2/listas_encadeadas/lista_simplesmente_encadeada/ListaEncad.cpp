#include <iostream>
#include "ListaEncad.h"

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
        rotina_erro(1);
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
        rotina_erro(1);
}

void ListaEncad::removeK(int k)
{
    if (primeiro == NULL) // Lista vazia
    {
        rotina_erro(-1);
    }
    if (k < 0) // Índice negativo
    {
        rotina_erro(-2);
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
        rotina_erro(-3);
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

void ListaEncad::set(int k, int val)
{
    if (primeiro == NULL) // Lista vazia
    {
        rotina_erro(-1);
    }
    if (k < 0) // Índice negativo
    {
        rotina_erro(-2);
    }
    if (k == 0)
    {
        primeiro->setInfo(val);
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
        rotina_erro(-5);
    }
    else // Há mais de um nó na lista e o índice a buscar é maior que 0
        p->setInfo(val);
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
    cout << endl;
}

int ListaEncad::getComprimento()
{
    int i = 0;
    No *p = primeiro;
    while (p != NULL)
    {
        i++;
        p = p->getProx();
    }
    return i;
}

int ListaEncad::contaMaiores(int val)
{
    int i = 0;
    No *p = primeiro;
    while (p != NULL)
    {
        if (p->getInfo() > val)
            i++;
        p = p->getProx();
    }
    return i;
}

void ListaEncad::insereOrdenado(int val)
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

bool ListaEncad::igual(ListaEncad *l2)
{
    No *p1 = primeiro;
    No *p2 = l2->primeiro;

    while (p1 != NULL && p2 != NULL && p1->getInfo() == p2->getInfo())
    {
        p1 = p1->getProx();
        p2 = p2->getProx();
    }
    if (p1 == NULL && p2 == NULL)
        return true;
    else
        return false;
}

void ListaEncad::removeValor(int val)
{
    if (primeiro == NULL) // Lista vazia
    {
        rotina_erro(-1);
    }
    No *p = primeiro;
    No *ant = NULL;

    while (p != NULL && p->getInfo() != val)
    {
        ant = p;
        p = p->getProx(); // Caminha para próximo nó
    }

    if (p != NULL) // Encontrou tal valor
    {
        ant->setProx(p->getProx());
        delete p;
    }
    else
    {
        cout << "ERRO: Valor nao encontrado!" << endl;
    }
}