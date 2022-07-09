#ifndef LISTAORDCONT_H
#define LISTAORDCONT_H

class ListaOrdCont
{
public:
    ListaOrdCont(int tam);
    ~ListaOrdCont();
    int get(int k);
    void insere(int val); // insere na ordem
    void remove(int val); // remove valor
    void imprime();
    bool busca(int val);

private:
    int max;  // capacidade maxima de elementos
    int n;    // quantidade de nos na lista
    int *vet; // vetor que armazena a lista
    int buscaBinaria(int val);
};

#endif // LISTAORDCONT_H
