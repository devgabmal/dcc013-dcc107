#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED

#include "NoArv.h"

class ArvBin
{
private:
    NoArv *raiz; // ponteiro para o nó raiz da árvore
    void auxImprime(NoArv *p);
    bool auxBusca(NoArv *raiz, int val);
    NoArv *libera(NoArv *p);
    int auxAltura(NoArv *p);

public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    // cria novo nó como raiz das sub-árvores à
    // esquerda (sae) e à direita (sad)
    void cria(int val, ArvBin *sae, ArvBin *sad);
    bool vazia(); // verifica se a árvore está vazia
    void imprime();
    bool busca(int val);
    int altura();
};

#endif // ARVBIN_H_INCLUDED
