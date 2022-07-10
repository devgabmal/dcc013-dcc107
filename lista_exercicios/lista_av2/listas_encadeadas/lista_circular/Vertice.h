class Vertice
{
public:
    Vertice();
    ~Vertice();

    int getX();
    int getY();
    Vertice *getAnt();
    Vertice *getProx();
    void setX(int val);
    void setY(int val);
    void setAnt(Vertice *p);
    void setProx(Vertice *p);

private:
    int x;
    int y;
    Vertice *ant;  // Ponteiro para o nó anterior
    Vertice *prox; // Ponteiro para o próximo nó
};