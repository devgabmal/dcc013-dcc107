#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class No
{
public:
    No ()                 	{ };
    ~No ()                  { };
    void setInfo (int val)  { info = val; };
    void setProx (No* p)    { prox = p; };
    int  getInfo ()         { return info; };
    No*  getProx ()         { return prox; };

private:
    int info;
    No *prox;
};

#endif
