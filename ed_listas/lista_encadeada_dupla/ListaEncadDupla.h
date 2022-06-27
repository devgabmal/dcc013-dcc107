#include "NoDuplo.h"

class ListaEncadDupla
{
public:
    ListaEncadDupla();
    ~ListaEncadDupla();

    void insereInicio(int val);
    void insereFinal(int val);
    void insereK(int k, int val);
    void removeK(int k);
    void removeInicio();
    void removeFinal();
    bool busca(int val);
    void imprime();
    int get(int k);
    void set(int k, int val);
    int contaNos();
    void imprimeAntProx();
    void imprimeReverso();

private:
    NoDuplo *primeiro; // Ponteiro para o primeiro nó
    NoDuplo *ultimo;   // Ponteiro para o último nó
    int n;             // Total de nós
};