class MatrizAntiSim
{
private:
    int numOrd; // Número de linhas e colunas (Ordem da matriz)
    float *vet;
    int detInd(int i, int j);

public:
    MatrizAntiSim(int n);
    ~MatrizAntiSim();
    float get(int i, int j);
    void set(int i, int j, float val);
};