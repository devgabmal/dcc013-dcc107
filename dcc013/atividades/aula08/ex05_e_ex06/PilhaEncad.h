#ifndef PILHAENCAD_H_INCLUDED
#define PILHAENCAD_H_INCLUDED

#include "No.h"
#include "NoArv.h"

class PilhaEncad
{
public:
    PilhaEncad();
    ~PilhaEncad();
    NoArv *getTopo();
    void empilha(NoArv *p);
    NoArv *desempilha();
    bool vazia();

private:
    No *topo;
};

#endif // PILHAENCAD_H_INCLUDED
