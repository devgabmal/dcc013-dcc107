class Ponto2D
{
private:
    float x;
    float y;

public:
    Ponto2D(float xp, float yp);
    ~Ponto2D();
    float getX();
    float getY();
    void imprimeX();
    void imprimeY();
    float distancia(Ponto2D pontoFim);
};