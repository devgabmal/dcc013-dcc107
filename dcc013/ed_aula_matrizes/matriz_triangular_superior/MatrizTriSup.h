class MatrizTriSup
{
private:
    int numOrd; // Número de linhas e colunas (Ordem da matriz)
    float *vet;
    int detInd(int i, int j);

public:
    MatrizTriSup(int n);
    ~MatrizTriSup();
    float get(int i, int j);
    void set(int i, int j, float val);
};