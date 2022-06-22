#ifndef LISTACONT_H_INCLUDED
#define LISTACONT_H_INCLUDED
#include "Ponto.h"

class ListaCont
{
private:
    int max;
    int n;
    Ponto *vet;

public:
    ListaCont(int tam);
    ~ListaCont();

    int get(int k);
    void set(int k, Ponto pt);
    void insereFinal(Ponto pt);
    void insereK(int k, Ponto pt);
    void insereInicio(Ponto pt);
    void removeFinal();
    void removeK(int k);
    void removeInicio();
    void imprime();
    int numNos();
    // int buscaMaior(int val);
    void limpar();
    void insereValores(int tam, Ponto vet[]);
};

#endif // LISTACONT_H_INCLUDED
