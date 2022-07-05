#include "No.h"

class PilhaEncad
{
public:
    PilhaEncad();
    ~PilhaEncad();
    int getTopo();
    void empilha(int val);
    int desempilha();
    bool vazia();
    void imprime();

private:
    No *topo;
};