#ifndef FILAENCAD_H_INCLUDED
#define FILAENCAD_H_INCLUDED
#include "No.h"

using namespace std;

class FilaEncad
{
private:
    No *inicio;
    No *fim; /// ponteiros para os No's extremos
public:
    FilaEncad();
    ~FilaEncad();
    int getInicio();         /// retorna valor do primeiro No
    void enfileira(int val); /// insere No no fim
    int desenfileira();      /// elimina No do inicio
    bool vazia();            /// verifica se fila esta vazia
    void imprime();
};

#endif // FILAENCAD_H_INCLUDED
