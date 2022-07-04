#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"

class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();
    bool busca(int val);      /// retorna true caso val esteja na lista e false caso contrario
    int get(int k);           /// retorna o valor do k-�simo elemento
    void set(int k, int val); /// altera o valor do k-�simo elemento
    void insere(int val);     /// insere um novo No contendo val de forma ordenada
    void removeInicio();      /// remove o primeiro No da lista
    void removeFinal();       /// remove o �ltimo No da lista

    void imprime();
    int numNos();
    int buscaMaior(int val);
    void limpar();
    float calculaMedia();
    void concatena(ListaEncad *l2);
    ListaEncad *partir(int x);

private:
    No *primeiro; /// ponteiro para o primeiro No da lista
    No *ultimo;   /// ponteiro para o ultimo No da lista
    int n;        /// numero de nos na lista
};
#endif
