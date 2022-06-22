#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED
#include <cmath>

using namespace std;

class Ponto
{
private:
    float x, y;
public:
    Ponto() {};
    Ponto(float xx, float yy) { x = xx; y = yy; };
    ~Ponto() {};
    float getX() { return x; };
    float getY() { return y; };
    void setX(float xx) { x = xx; };
    void setY(float yy) { y = yy; };
    float distancia(Ponto *p2) { return sqrt(pow(x - p2->x, 2) + pow(y - p2->y, 2)); };
};

#endif // PONTO_H_INCLUDED
