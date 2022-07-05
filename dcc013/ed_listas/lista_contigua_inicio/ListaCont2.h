class ListaCont2
{

public:
    ListaCont2(int ini, int tam);
    ~ListaCont2();

    int get(int k);
    void set(int k, int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val);
    void removeFinal();
    void insereK(int k, int val);
    void removeK(int k);
    void imprime();

private:
    int max;    // Capacidade máxima de elementos
    int n;      // Quantidade de nós da lista
    int inicio; // Índice relativo do primeiro nó da lista
    int *vet;   // Vetor que armazena a lista
};