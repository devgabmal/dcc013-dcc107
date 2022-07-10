#include "No.h"

class ListaEncad
{

public:
    ListaEncad();
    ~ListaEncad();

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
    int getComprimento();
    int contaMaiores(int val);
    void insereOrdenado(int val);
    bool igual(ListaEncad *l2);
    void removeValor(int val);

private:
    No *primeiro; // Ponteiro para o primeiro nó
};