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
    // Par *getPorIndice(int k);
    float getPorOrdem(int ordem);
    int getNumTermos();
    float calculaEmX(float x);

private:
    Par *primeiro; // Ponteiro para o primeiro nó
    int n;
};

#endif // POLINOMIO_H