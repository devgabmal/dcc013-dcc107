#ifndef PAR_H
#define PAR_H

class Par
{
public:
    Par();
    ~Par();

    int getOrd();
    float getCoef();
    Par *getProx();
    void setOrd(int val);
    void setCoef(float val);
    void setProx(Par *p);

private:
    float coef;
    int ord;
    Par *prox; // Ponteiro para o próximo par
};

#endif // PAR_H
