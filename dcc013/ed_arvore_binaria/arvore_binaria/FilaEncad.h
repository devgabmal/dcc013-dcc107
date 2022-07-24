#ifndef FILAENCAD_H_INCLUDED
#define FILAENCAD_H_INCLUDED

#include "No.h"
#include "NoArv.h"

class FilaEncad
{
private:
    No *inicio, *fim; // ponteiros para os extremos
public:
    FilaEncad();
    ~FilaEncad();
    NoArv *getInicio();
    void enfileira(NoArv *p); // insere no fim da fila
    NoArv *desenfileira();    // elimina do início da fila
    bool vazia();             // verifica se fila está vazia
};

#endif // FILAENCAD_H_INCLUDED
