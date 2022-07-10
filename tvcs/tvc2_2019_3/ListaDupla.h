#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED

#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla ();
    ~ListaDupla ();
    void insereInicio (int val);
    void imprime ();

    void removeMaior();

private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int n;
};

#endif
