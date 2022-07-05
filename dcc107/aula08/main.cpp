#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleat�rio entre a e b
}

int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 10;

    ListaDupla l2; /// cria lista vazia
    int NumNos2 = 4;

    srand(time(NULL));

    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for (int i = 1; i <= NumNos; i++)
    {
        int val = numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
        cout << val << ", ";
        if (i == 6)
            val = 27;
        l.insereInicio(val);
    }
    cout << endl;
    // for (int i = 1; i <= NumNos2; i++)
    // {
    //     int val = numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
    //     cout << val << ", ";
    //     l2.insereInicio(val);
    // }
    // cout << endl;

    l.insereFinal(27);
    l.insereInicio(27);
    // l.removeFinal();
    l.imprime();
    // l.imprimeReverso();
    // ListaDupla *l3 = l.concatena(&l2);
    // l3->imprime();
    // ListaDupla *l4 = l.partir(10);
    // l.imprime();
    // l4->imprime();
    l.removeOcorrencias(27);
    l.imprime();

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if (existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    return 0;
};
