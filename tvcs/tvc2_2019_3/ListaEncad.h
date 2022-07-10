#ifndef LISTAORDENCAD_H_INCLUDED
#define LISTAORDENCAD_H_INCLUDED

#include "No.h"

class ListaEncad
{
public:
    ListaEncad ();
    ~ListaEncad ();
    void insereInicio(int val);
    void imprime ();
    void limpar ();

    void removeBloco(int a, int b);

private:
    No* primeiro;
};

#endif
