#include "No.h"

class FilaEncad
{
private:
    No *inicio; // ponteiro para No do comeco
    No *fim;    // ponteiro para No do fim
public:
    FilaEncad();
    ~FilaEncad();
    int getInicio();         // retorna No do inicio
    void enfileira(int val); // insere No no fim
    int desenfileira();      // elimina No do inicio
    bool vazia();            // verifica se esta vazia
    void imprime();
};