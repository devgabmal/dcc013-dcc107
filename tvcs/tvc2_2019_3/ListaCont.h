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

    bool insereIntervalo(int a, int b);

private:
    int max;
    int n;
    int *vet;
};

#endif
