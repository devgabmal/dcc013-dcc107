#ifndef LISTACONT_H_INCLUDED
#define LISTACONT_H_INCLUDED

class ListaCont
{
public:
    ListaCont (int tam);
    ~ListaCont ();
    void insereFinal (int val);
    void imprime ();
    void limpar ();

    bool insereValores(int k, int tam, int v[]);

private:
    int max;  //...
    int n;  //numero de nós da lista
    int *vet; //vetoro...
};

#endif
