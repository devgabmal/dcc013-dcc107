#ifndef LISTACONT_H
#define LISTACONT_H

class ListaCont
{

public:
    ListaCont(int tam);
    ~ListaCont();

    int get(int k);
    void set(int k, int val);
    void insereFinal(int val);
    void removeFinal();
    void insereK(int k, int val);
    void removeK(int k);
    void imprime();

private:
    int max;  // Capacidade máxima de elementos
    int n;    // Quantidade de nós da lista
    int *vet; // Vetor que armazena a lista
};

#endif // LISTACONT_H