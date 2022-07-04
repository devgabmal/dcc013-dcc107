#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class No
{
private:
    int info; /// valor armazenado no No
    No *prox; /// ponteiro para o proximo No
public:
    No()                  { };
    ~No()                 { };
    int getInfo()         { return info; };
    No* getProx()         { return prox; };
    void setInfo(int val) { info = val; };
    void setProx(No *p)   { prox = p; };
};
#endif // NO_H_INCLUDED
