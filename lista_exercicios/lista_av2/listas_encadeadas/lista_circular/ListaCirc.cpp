#include <iostream>
#include <string>
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
    Vertice *p = primeiro;
    while (p != NULL && p != ultimo)
    {
        Vertice *t = p->getProx();
        delete p;
        p = t;
    }
    if (ultimo != NULL)
        delete ultimo;
    primeiro = NULL;
    ultimo = NULL;
}

void ListaCirc::insereInicio(int valX, int valY)
{
    Vertice *p = new Vertice; // Aloca espaço para novo nó
    p->setX(valX);
    p->setY(valY);

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

void ListaCirc::insereFinal(int valX, int valY)
{
    Vertice *p = new Vertice; // Aloca espaço para novo nó
    p->setX(valX);
    p->setY(valY);

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

void ListaCirc::insereK(int k, int valX, int valY)
{
    if (k < 0)
        rotina_erro(-2);
    if (k > n)
        rotina_erro(-6);
    if (primeiro == NULL || k == 0) // Se não houver nós ou o índice for igual a 0...
        insereInicio(valX, valY);
    else // Se houver nós..
    {
        Vertice *p = primeiro;
        int i = 0;
        for (i = 0; i < k; i++) // Caminha até o nó K
        {
            p = p->getProx(); // Caminha para próximo nó
        }

        if (i == n) // Adicionando ao final
        {
            insereFinal(valX, valY);
        }
        else
        {
            Vertice *penultimo = p->getAnt();
            Vertice *novo = new Vertice; // Aloca espaço para novo nó
            novo->setX(valX);
            novo->setY(valY);
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
        Vertice *p = primeiro;
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
        Vertice *p = ultimo;
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
        Vertice *p = primeiro;
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
            Vertice *penultimo = p->getAnt();
            penultimo->setProx(p->getProx());
            p->getProx()->setAnt(penultimo);
            delete p;
            n--;
        }
    }
}

Vertice *ListaCirc::get(int k)
{
    if (k < 0) // Índice negativo
        rotina_erro(-2);
    if (k >= n) // Índice fora da lista
        rotina_erro(-4);
    if (primeiro == NULL) // Se não houver nós
        exit(-1);
    if (k == 0) // Primeiro
        return primeiro;
    else // Se houver nós e se desejar deletar após o primeiro..
    {
        Vertice *p = primeiro;
        int i = 0;
        for (i = 0; i < k; i++) // Caminha até o nó K
        {
            p = p->getProx(); // Caminha para próximo nó
        }

        if (i == n - 1) // Final
        {
            return ultimo;
        }
        else
        {
            return p;
        }
    }
}

void ListaCirc::set(int k, int valX, int valY)
{
    if (k < 0) // Índice negativo
        rotina_erro(-2);
    if (k >= n) // Índice fora da lista
        rotina_erro(-5);
    if (primeiro == NULL) // Se não houver nós
        exit(-1);
    if (k == 0) // Primeiro
    {
        primeiro->setX(valX);
        primeiro->setY(valY);
    }
    else // Se houver nós e se desejar deletar após o primeiro..
    {
        Vertice *p = primeiro;
        int i = 0;
        for (i = 0; i < k; i++) // Caminha até o nó K
        {
            p = p->getProx(); // Caminha para próximo nó
        }

        if (i == n - 1) // Final
        {
            ultimo->setX(valX);
            ultimo->setY(valY);
        }
        else
        {
            p->setX(valX);
            p->setY(valY);
        }
    }
}

void ListaCirc::imprime(int vezes)
{
    Vertice *p = primeiro;
    int i = 0;
    int vez = 1;
    while (p != NULL && i < n * vezes)
    {
        cout << "(" << p->getX() << ", " << p->getY() << ")"
             << " ";
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
    Vertice *p = ultimo;
    int i = 0;
    int vez = 1;
    while (p != NULL && i < n * vezes)
    {
        cout << "(" << p->getX() << ", " << p->getY() << ")"
             << " ";
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
    Vertice *p = primeiro;
    int i = 0;
    int vez = 1;
    while (p != NULL && i < n * vezes)
    {
        string ant;
        if (p->getAnt() == NULL)
            ant = "-1";
        else
            ant = "(" + to_string(p->getAnt()->getX()) + ", " + to_string(p->getAnt()->getY()) + ")";
        string prox;
        if (p->getProx() == NULL)
            prox = "-1";
        else
            prox = "(" + to_string(p->getProx()->getX()) + ", " + to_string(p->getProx()->getY()) + ")";
        cout << ant << " > "
             << "(" << p->getX() << ", " << p->getY() << ")"
             << " > " << prox << endl;

        p = p->getProx(); // Caminha para próximo nó
        i++;
        if (i == n * vez) // Quebra linha após chegar ao fim da lista
        {
            cout << endl;
            vez++;
        }
    }
    cout << "N: " << n << endl;
}

int ListaCirc::contaNos()
{
    int num = 0;

    for (Vertice *p = primeiro; p != ultimo; p = p->getProx())
        num++;
    if (ultimo != NULL)
        num++;
    return num;
}