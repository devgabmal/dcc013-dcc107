class Matriz2D
{
private:
    int nl, nc;
    float **mat;

    bool verifica(int i, int j);

public:
    Matriz2D(int nlp, int ncp);
    ~Matriz2D();
    void set(int i, int j, float valor);
    float get(int i, int j);
};