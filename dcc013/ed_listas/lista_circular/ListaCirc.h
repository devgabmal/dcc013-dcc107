#include "NoDuplo.h"

class ListaCirc
{
public:
    ListaCirc();
    ~ListaCirc();

    void insereInicio(int val);
    void insereFinal(int val);
    void insereK(int k, int val);
    void removeK(int k);
    void removeInicio();
    void removeFinal();
    bool busca(int val);
    int get(int k);
    void set(int k, int val);
    int contaNos();
    void imprime(int vezes);
    void imprimeAntProx(int vezes);
    void imprimeReverso(int vezes);

private:
    NoDuplo *primeiro; // Ponteiro para o primeiro nó
    NoDuplo *ultimo;   // Ponteiro para o último nó
    int n;             // Total de nós
};