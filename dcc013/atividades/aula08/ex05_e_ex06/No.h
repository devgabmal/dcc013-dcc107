#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "NoArv.h"

class No
{
private:
    NoArv *info; // ponteiro para um nó da árvore
    No *prox;    // ponteiro para o próximo nó da fila
public:
    No()
    {
        info = 0;
        prox = NULL;
    };
    ~No(){};
    void setInfo(NoArv *p) { info = p; };
    void setProx(No *p) { prox = p; };
    NoArv *getInfo() { return info; };
    No *getProx() { return prox; };
};

#endif // NO_H_INCLUDED
