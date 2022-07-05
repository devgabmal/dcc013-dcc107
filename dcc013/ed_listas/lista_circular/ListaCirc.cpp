#include <iostream>
#include "ListaCirc.h"

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

ListaCirc::ListaCirc()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaCirc::~ListaCirc()
{
    NoDuplo *p = primeiro;
    while (p != NULL && p != ultimo)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
    if (ultimo != NULL)
        delete ultimo;
    primeiro = NULL;
    ultimo = NULL;
}

void ListaCirc::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo; // Aloca espaço para novo nó
    p->setInfo(val);          // Define informação

    if (n == 0) // Há apenas um elemento
    {
        p->setProx(p);
        p->setAnt(p);
        ultimo = p; // Define novo nó como o último da lista
    }
    else // Há mais elementos
    {
        p->setProx(primeiro); // Define o atual primeiro nó como posterior ao novo
        p->setAnt(ultimo);    // Define nó anterior ao novo como o último
        primeiro->setAnt(p);  // Define nó anterior do atual primeiro como o novo adicionado
        ultimo->setProx(p);   // Define o último nó como o novo adicionado
    }

    primeiro = p; // Define novo nó como o primeiro da lista
    n++;          // Incrementa quantidade de nós registrada
}

void ListaCirc::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo; // Aloca espaço para novo nó
    p->setInfo(val);          // Define informação

    if (n == 0) // Há apenas um elemento
    {
        p->setProx(p);
        p->setAnt(p);
        primeiro = p; // Define novo nó como o primeiro da lista
    }
    else // Há mais elementos
    {
        p->setProx(primeiro); // Define o atual primeiro nó como posterior ao novo
        p->setAnt(ultimo);    // Define nó anterior ao novo como o último
        primeiro->setAnt(p);  // Define nó anterior do atual primeiro como o novo adicionado
        ultimo->setProx(p);   // Define o último nó como o novo adicionado
    }

    ultimo = p; // Define novo nó como o último da lista
    n++;        // Incrementa quantidade de nós registrada
}

void ListaCirc::insereK(int k, int val)
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
        int i = 0;
        for (i = 0; i < k; i++) // Caminha até o nó K
        {
            p = p->getProx(); // Caminha para próximo nó
        }

        if (i == n) // Adicionando ao final
        {
            insereFinal(val);
        }
        else
        {
            NoDuplo *penultimo = p->getAnt();
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

void ListaCirc::removeInicio()
{
    if (primeiro != NULL) // Há elementos na lista
    {
        NoDuplo *p = primeiro;
        if (n > 1) // Há mais de 1 nó
        {
            primeiro = primeiro->getProx();
            primeiro->setAnt(ultimo);
            ultimo->setProx(primeiro);
        }
        else // Há apenas 1 nó
        {
            primeiro = NULL;
            ultimo = NULL;
        }

        delete p;
        n--;
    }
    else
        rotina_erro(1);
}

void ListaCirc::removeFinal()
{
    if (primeiro != NULL) // Há elementos na lista
    {
        NoDuplo *p = ultimo;
        if (n > 1) // Há mais de 1 nó
        {
            ultimo = ultimo->getAnt();
            primeiro->setAnt(ultimo);
            ultimo->setProx(primeiro);
        }
        else // Há apenas 1 nó
        {
            primeiro = NULL;
            ultimo = NULL;
        }

        delete p;
        n--;
    }
    else
        rotina_erro(1);
}

void ListaCirc::removeK(int k)
{
    if (k < 0) // Índice negativo
        rotina_erro(-2);
    if (k >= n) // Índice fora da lista
        rotina_erro(-3);
    if (primeiro == NULL) // Se não houver nós
        exit(-1);
    if (k == 0) // Deseja-se apagar o primeiro
        removeInicio();
    else // Se houver nós e se desejar deletar após o primeiro..
    {
        NoDuplo *p = primeiro;
        int i = 0;
        for (i = 0; i < k; i++) // Caminha até o nó K
        {
            p = p->getProx(); // Caminha para próximo nó
        }

        if (i == n - 1) // Removendo no final
        {
            removeFinal();
        }
        else
        {
            NoDuplo *penultimo = p->getAnt();
            penultimo->setProx(p->getProx());
            p->getProx()->setAnt(penultimo);
            delete p;
            n--;
        }
    }
}

int ListaCirc::get(int k)
{
    if (k < 0) // Índice negativo
        rotina_erro(-2);
    if (k >= n) // Índice fora da lista
        rotina_erro(-4);
    if (primeiro == NULL) // Se não houver nós
        exit(-1);
    if (k == 0) // Primeiro
        return primeiro->getInfo();
    else // Se houver nós e se desejar deletar após o primeiro..
    {
        NoDuplo *p = primeiro;
        int i = 0;
        for (i = 0; i < k; i++) // Caminha até o nó K
        {
            p = p->getProx(); // Caminha para próximo nó
        }

        if (i == n - 1) // Final
        {
            return ultimo->getInfo();
        }
        else
        {
            return p->getInfo();
        }
    }
}

void ListaCirc::set(int k, int val)
{
    if (k < 0) // Índice negativo
        rotina_erro(-2);
    if (k >= n) // Índice fora da lista
        rotina_erro(-5);
    if (primeiro == NULL) // Se não houver nós
        exit(-1);
    if (k == 0) // Primeiro
        primeiro->setInfo(val);
    else // Se houver nós e se desejar deletar após o primeiro..
    {
        NoDuplo *p = primeiro;
        int i = 0;
        for (i = 0; i < k; i++) // Caminha até o nó K
        {
            p = p->getProx(); // Caminha para próximo nó
        }

        if (i == n - 1) // Final
        {
            ultimo->setInfo(val);
        }
        else
        {
            p->setInfo(val);
        }
    }
}

bool ListaCirc::busca(int val)
{
    NoDuplo *p = primeiro;
    for (int i = 0; i < n; i++)
    {
        if (p->getInfo() == val)
            return true;
        p = p->getProx(); // Caminha para próximo nó
    }
    return false;
}

void ListaCirc::imprime(int vezes)
{
    NoDuplo *p = primeiro;
    int i = 0;
    int vez = 1;
    while (p != NULL && i < n * vezes)
    {
        cout << p->getInfo() << "\t";
        p = p->getProx(); // Caminha para próximo nó
        i++;
        if (i == n * vez) // Quebra linha após chegar ao fim da lista
        {
            cout << endl;
            vez++;
        }
    }
}

void ListaCirc::imprimeReverso(int vezes)
{
    NoDuplo *p = ultimo;
    int i = 0;
    int vez = 1;
    while (p != NULL && i < n * vezes)
    {
        cout << p->getInfo() << "\t";
        p = p->getAnt(); // Caminha para o nó anterior
        i++;
        if (i == n * vez) // Quebra linha após chegar ao fim da lista
        {
            cout << endl;
            vez++;
        }
    }
}

void ListaCirc::imprimeAntProx(int vezes)
{
    NoDuplo *p = primeiro;
    int i = 0;
    int vez = 1;
    while (p != NULL && i < n * vezes)
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
        i++;
        if (i == n * vez) // Quebra linha após chegar ao fim da lista
        {
            cout << endl;
            vez++;
        }
    }
    cout << "N: " << n;
}

int ListaCirc::contaNos()
{
    int num = 0;

    for (NoDuplo *p = primeiro; p != ultimo; p = p->getProx())
        num++;
    if (ultimo != NULL)
        num++;
    return num;
}