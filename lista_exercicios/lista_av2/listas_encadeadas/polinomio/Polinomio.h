#ifndef POLINOMIO_H
#define POLINOMIO_H

#include "Par.h"

class Polinomio
{

public:
    Polinomio(int tam);
    ~Polinomio();

    void insereTermo(float val, int ordem);
    void removeTermo(int ordem);
    void imprime();
    // Polinomio *soma(Polinomio *poli2);

private:
    Par *primeiro; // Ponteiro para o primeiro nó
};

#endif // POLINOMIO_H