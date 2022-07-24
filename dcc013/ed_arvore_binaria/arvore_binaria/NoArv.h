#ifndef NOARV_H_INCLUDED
#define NOARV_H_INCLUDED

class NoArv
{
private:
    NoArv *esq; // ponteiro para o filho à esquerda
    int info;   // informação do nó (int)
    NoArv *dir; // ponteiro para o filho à direita
public:
    NoArv(); // construtor e destrutor
    ~NoArv();
    void setEsq(NoArv *p); // operações setter
    void setInfo(int val);
    void setDir(NoArv *p);
    NoArv *getEsq(); // operações getter
    int getInfo();
    NoArv *getDir();
};

#endif // NOARV_H_INCLUDED
