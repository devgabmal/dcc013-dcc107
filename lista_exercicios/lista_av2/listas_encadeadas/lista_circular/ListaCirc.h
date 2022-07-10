#include "Vertice.h"

class ListaCirc
{
public:
    ListaCirc();
    ~ListaCirc();

    void insereInicio(int valX, int valY);
    void insereFinal(int valX, int valY);
    void insereK(int k, int valX, int valY);
    void removeK(int k);
    void removeInicio();
    void removeFinal();
    Vertice *get(int k);
    void set(int k, int valX, int valY);
    int contaNos();
    void imprime(int vezes);
    void imprimeAntProx(int vezes);
    void imprimeReverso(int vezes);

private:
    Vertice *primeiro; // Ponteiro para o primeiro nó
    Vertice *ultimo;   // Ponteiro para o último nó
    int n;             // Total de nós
};