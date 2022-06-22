#ifndef MATRIZESPECIAL_H_INCLUDED
#define MATRIZESPECIAL_H_INCLUDED

class MatrizEspecial
{
    public:
        MatrizEspecial(int nn);
        ~MatrizEspecial();

        float get(int i, int j);
        void set(int i, int j,  float val);
        void imprimir();

    private:
        int n;
        float *vet;

        bool verificaIndice(int i, int j);
};

#endif // MATRIZESPECIAL_H_INCLUDED
