class MatrizSim
{
private:
    int numOrd; // Número de linhas e colunas (Ordem da matriz)
    float *vet;
    int detInd(int i, int j);

public:
    MatrizSim(int n);
    ~MatrizSim();
    float get(int i, int j);
    void set(int i, int j, float val);
};