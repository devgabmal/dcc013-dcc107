#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleat�rio entre a e b
}

int main()
{
    ListaEncad l;  /// cria lista vazia
    ListaEncad l2; /// cria lista vazia

    int NumNos = 12;
    int NumNosL2 = 5;

    srand(time(NULL));
    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores L1: ";
    for (int i = 1; i <= NumNos; i++)
    {
        int val = numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
        cout << val << ", ";
        l.insere(val);
    }
    cout << endl;
    cout << "Inserindo valores L2: ";
    for (int i = 1; i <= NumNosL2; i++)
    {
        int val = numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
        cout << val << ", ";
        l2.insere(val);
    }
    cout << endl;

    l.imprime();
    l2.imprime();

    // l.concatena(&l2);
    ListaEncad *l3 = l.partir(4);
    l.imprime();
    l3->imprime();
    // cout << "Num nós: " << l.numNos() << endl;
    // cout << "Índice busca maior: " << l.buscaMaior(42) << endl;
    // // l.limpar();
    // // l.imprime();
    // cout << "Média: " << l.calculaMedia() << endl;

    // bool existe = l.busca(20);
    // cout << "O valor 20 esta na lista? ";
    // if (existe)
    //     cout << "Sim" << endl;
    // else
    //     cout << "Nao" << endl;

    return 0;
};
