#ifndef LISTAORDENCAD_H
#define LISTAORDENCAD_H

#include "Par.h"

class ListaOrdEncad
{

public:
    ListaOrdEncad();
    ~ListaOrdEncad();

    void insere(int val, int ordem);
    void remove(int ordem);
    void imprime();
    Par *get(int k); // Busca par no índice indicado
    ListaOrdEncad *soma(ListaOrdEncad *poli2);

private:
    Par *primeiro; // Ponteiro para o primeiro nó
};

#endif // LISTAORDENCAD_H