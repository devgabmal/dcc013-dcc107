#include <iostream>
#include "ListaEncadDupla.h"

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
    case 6:
        cout << "Tentativa de adicao de elemento fora da lista!";
        break;
    default:
        break;
    }

    if (erro < 0)
        exit(erro);
}

ListaEncadDupla::ListaEncadDupla()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncadDupla::~ListaEncadDupla()
{
    NoDuplo *p = primeiro;
    while (p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaEncadDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo; // Aloca espaço para novo nó
    p->setInfo(val);          // Define informação
    p->setProx(primeiro);     // Define o atual primeiro nó como posterior ao novo
    p->setAnt(NULL);          // Define nó anterior ao novo como NULL
    n++;                      // Incrementa quantidade de nós registrada

    if (n == 1)     // Há apenas um elemento
        ultimo = p; // Define novo nó como o último da lista
    else
        primeiro->setAnt(p); // Define nó anterior do atual primeiro como o novo adicionado

    primeiro = p; // Define novo nó como o primeiro da lista
}

void ListaEncadDupla::insereFinal(int val)
{
    NoDuplo *novo = new NoDuplo; // Aloca espaço para novo nó
    novo->setInfo(val);          // Define informação
    novo->setProx(NULL);
    novo->setAnt(ultimo);

    if (primeiro == NULL)
        primeiro = novo;
    else
        ultimo->setProx(novo);
    ultimo = novo;
    n++;
}

void ListaEncadDupla::insereK(int k, int val)
{
    if (k < 0)
        rotina_erro(-2);
    if (k > n)
        rotina_erro(-6);
    if (primeiro == NULL || k == 0) // Se não houver nós ou o índice for igual a 0...
        insereInicio(val);
    else // Se houver nós..
    {
        NoDuplo *p = primeiro;
        NoDuplo *penultimo = NULL;
        int i = 0;
        for (i = 0; p != NULL && i < k; i++) // Caminha até o nó K
        {
            penultimo = p;
            p = p->getProx(); // Caminha para próximo nó
        }

        if (i == n) // Adicionando ao final
        {
            insereFinal(val);
        }
        else
        {
            NoDuplo *novo = new NoDuplo; // Aloca espaço para novo nó
            novo->setInfo(val);          // Define informação
            novo->setProx(p);
            novo->setAnt(penultimo);
            penultimo->setProx(novo); // Adiciona nó após o último
            p->setAnt(novo);
            n++;
        }
    }
}

void ListaEncadDupla::removeInicio()
{
    if (primeiro != NULL)
    {
        NoDuplo *p = primeiro;
        primeiro = primeiro->getProx();
        if (primeiro != NULL)
            primeiro->setAnt(NULL);
        delete p;

        n--;
        if (n == 0)
            ultimo = NULL;
    }
    else
        rotina_erro(1);
}

void ListaEncadDupla::removeFinal()
{
    if (primeiro != NULL)
    {
        NoDuplo *p = primeiro;
        NoDuplo *penultimo = NULL;
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

        ultimo = penultimo;
        delete p;
        n--;
    }
    else
        rotina_erro(1);
}

void ListaEncadDupla::removeK(int k)
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
        ultimo = NULL;
        n--;
        return;
    }

    NoDuplo *p = primeiro;
    NoDuplo *penultimo = NULL;
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
    if (penultimo == NULL)
    {                                   // Há mais de um nó na lista, mas o índice a apagar é 0
        primeiro = primeiro->getProx(); // Define o primeiro nó como o próximo
        primeiro->setAnt(NULL);
    }
    else
    {                                     // Há mais de um nó na lista e o índice a apagar é maior que 0
        penultimo->setProx(p->getProx()); // Desencadeia o nó
        if (p->getProx() != NULL)
            p->getProx()->setAnt(penultimo);
        if (i == n - 1)
            ultimo = penultimo;
    }
    delete p; // Deleta da memória o nó
    n--;
}

int ListaEncadDupla::get(int k)
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

    NoDuplo *p = primeiro;
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

void ListaEncadDupla::set(int k, int val)
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

    NoDuplo *p = primeiro;
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

bool ListaEncadDupla::busca(int val)
{
    NoDuplo *p = primeiro;
    while (p != NULL)
    {
        if (p->getInfo() == val)
            return true;
        p = p->getProx(); // Caminha para próximo nó
    }
    return false;
}

void ListaEncadDupla::imprime()
{
    NoDuplo *p = primeiro;
    while (p != NULL)
    {
        cout << p->getInfo() << "\t";
        p = p->getProx(); // Caminha para próximo nó
    }
}

void ListaEncadDupla::imprimeReverso()
{
    NoDuplo *p = ultimo;
    while (p != NULL)
    {
        cout << p->getInfo() << "\t";
        p = p->getAnt(); // Caminha para o nó anterior
    }
}

void ListaEncadDupla::imprimeAntProx()
{
    NoDuplo *p = primeiro;
    while (p != NULL)
    {
        int ant;
        if (p->getAnt() == NULL)
            ant = -1;
        else
            ant = p->getAnt()->getInfo();
        int prox;
        if (p->getProx() == NULL)
            prox = -1;
        else
            prox = p->getProx()->getInfo();
        cout << ant << " > " << p->getInfo() << " > " << prox << endl;

        p = p->getProx(); // Caminha para próximo nó
    }
    cout << "N: " << n;
}

int ListaEncadDupla::contaNos()
{
    int num = 0;
    for (NoDuplo *p = primeiro; p != NULL; p = p->getProx())
        num++;
    return num;
}