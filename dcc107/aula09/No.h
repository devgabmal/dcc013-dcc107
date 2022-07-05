#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class No
{
private:
    int info;
    No* prox;
public:
    No()                    {};
    ~No()                   {};
    void setInfo(int val)   { info = val; };
    void setProx(No* p)     { prox = p; };
    int getInfo()           { return info; };
    No * getProx()          { return prox; };
};

#endif // NO_H_INCLUDED
