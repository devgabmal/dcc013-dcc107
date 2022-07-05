class No
{
public:
    No();
    ~No();

    int getInfo();
    No *getProx();
    void setInfo(int val);
    void setProx(No *p);

private:
    int info; // Informação guardada
    No *prox; // Ponteiro para o próximo nó
};