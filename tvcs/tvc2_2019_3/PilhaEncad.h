#ifndef PILHAENCAD_H_INCLUDED
#define PILHAENCAD_H_INCLUDED

#include "No.h"

class PilhaEncad
{
public:
    PilhaEncad ();
    ~PilhaEncad ();
    int  getTopo ();
    void empilha (int val);
    int  desempilha ();
    bool vazia ();
    void imprime ();

private:
    No *topo;
};

#endif
