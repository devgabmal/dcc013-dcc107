class MatrizDiag
{
private:
    int numOrd; // Número de linhas e colunas (Ordem da matriz)
    float *vet;
    int detInd(int i, int j);

public:
    MatrizDiag(int n);
    ~MatrizDiag();
    float get(int i, int j);
    void set(int i, int j, float val);
};