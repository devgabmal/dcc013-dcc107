#ifndef PAR_H
#define PAR_H

class Par
{
public:
    Par();
    ~Par();

    int getOrd();
    int getCoef();
    Par *getProx();
    void setOrd(int val);
    void setCoef(int val);
    void setProx(Par *p);

private:
    int coef;
    int ord;
    Par *prox; // Ponteiro para o próximo par
};

#endif // PAR_H
