#ifndef LISTAORDENCAD_H
#define LISTAORDENCAD_H

#include "No.h"

class ListaOrdEncad
{

public:
    ListaOrdEncad();
    ~ListaOrdEncad();

    void insere(int val);
    void remove(int val);
    bool busca(int val);
    void imprime();
    int get(int k);

private:
    No *primeiro; // Ponteiro para o primeiro nó
};

#endif // LISTAORDENCAD_H