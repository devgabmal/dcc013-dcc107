#ifndef CAMINHO_H
#define CAMINHO_H

class Caminho
{
public:
    Caminho(int nn);
    ~Caminho();
    int calculaDistanciaPercorrida(int **distancias);
    void buscaGulosa(int **distancias);
    void imprimirCaminho();

public:
    void ordem(int **distancias, int i, int *ordem);
    int *vet;
    int n;
};

#endif // CAMINHO_H
