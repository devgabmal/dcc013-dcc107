class NoDuplo
{
public:
    NoDuplo();
    ~NoDuplo();

    int getInfo();
    NoDuplo *getAnt();
    NoDuplo *getProx();
    void setInfo(int val);
    void setAnt(NoDuplo *p);
    void setProx(NoDuplo *p);

private:
    int info;      // Informação guardada
    NoDuplo *ant;  // Ponteiro para o nó anterior
    NoDuplo *prox; // Ponteiro para o próximo nó
};