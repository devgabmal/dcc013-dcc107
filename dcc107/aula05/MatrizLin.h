#ifndef MatrizLin_H_INCLUDED
#define MatrizLin_H_INCLUDED

class MatrizLin
{
private:
    int nl, nc; // numero de is e js
    float *vet; // vetor de tamanho nl*nc
    int detInd(int i, int j);

public:
    MatrizLin(int mm, int nn);
    ~MatrizLin();
    void set(int i, int j, float val);
    float get(int i, int j);
    void imprime();
    MatrizLin *transposta();
    int getNl();
    int getNc();
};

#endif // MatrizLin0_H_INCLUDED
