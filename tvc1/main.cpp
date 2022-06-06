#include <iostream>
#include <cmath>
#include "MatrizEspecial.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q1
// Celso Gabriel Dutra Almeida Malosto
// 202176002
void trocaMaior(int vet[], int n, int *m)
{
    // Implemente aqui sua solucao!

    // Declara o maior valor como o primeiro elemento
    int indMaior = 0;
    *m = *vet;

    // Se houver elemento cujo conteúdo é maior que o valor previamente definido...
    // Então, definir o conteúdo do maior valor como o conteúdo da atual posição do vetor
    for (int i = 1; i < n; i++)
    {
        if (*(vet + i) > *m)
        {
            *m = *(vet + i);
            indMaior = i;
        }
    }

    // Trocar o conteúdo da primeira posição do vetor com o conteúdo da posição que guarda o maior valor
    int aux = *vet;
    *vet = *m;
    *(vet + indMaior) = aux;
}
//-Q1
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q2
float avalia(float x, int coefs[], int n)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.

    if (n == 1)
        return coefs[n - 1];
    else
    {
        return coefs[0] * powf(x, n - 1) + avalia(x, coefs + 1, n - 1);
    }
}
//-Q2
// ----------------------------------------------------------------------------

int main()
{
    // TESTES PARA A QUESTAO 1 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 1" << endl;
    cout << "Resultado esperado: 25 1 2 10 19 20 23 ==> Maior valor: 25" << endl;
    cout << "Resultado obtido: ";
    int v[] = {2, 1, 25, 10, 19, 20, 23}, maior;
    trocaMaior(v, 7, &maior);
    for (int i = 0; i < 7; i++)
        cout << v[i] << " ";
    cout << " ==> Maior valor: " << maior << endl;
    cout << endl;

    cout << "Resultado esperado: 42 10 -5 0 -50 34 12 8 12 11 ==> Maior valor: 42" << endl;
    cout << "Resultado obtido: ";
    int v2[] = {12, 10, -5, 0, -50, 34, 12, 8, 42, 11};
    trocaMaior(v2, 10, &maior);
    for (int i = 0; i < 10; i++)
        cout << v2[i] << " ";
    cout << " ==> Maior valor: " << maior << endl;
    cout << endl;
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 2 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 2" << endl;
    cout << "Polinomios:" << endl;
    int coefs[] = {2, 1, 0, 2, 7};
    cout << "2x^4 + x^3 + 2x + 7" << endl;
    cout << "Para x = 3 ==> Esperado: 202\tObtido: " << avalia(3, coefs, 5) << endl;
    cout << "Para x = 8 ==> Esperado: 8727\tObtido: " << avalia(8, coefs, 5) << endl;
    cout << endl;

    int coefs2[] = {3, -4, 1};
    cout << "3x^2 - 4x + 1" << endl;
    cout << "Para x = 0 ==> Esperado: 1\tObtido: " << avalia(0, coefs2, 3) << endl;
    cout << "Para x = -2 ==> Esperado: 21\tObtido: " << avalia(-2, coefs2, 3) << endl;
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 3 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 3" << endl;
    cout << "Matriz 5x5 do enunciado da questao:" << endl;
    int dim = 5;
    MatrizEspecial matEnunciado(dim);
    matEnunciado.set(0, 0, 5);
    matEnunciado.set(0, 1, -6);
    matEnunciado.set(0, 2, 3);
    matEnunciado.set(0, 3, -9);
    matEnunciado.set(0, 4, 1);
    matEnunciado.set(1, 3, -3);
    matEnunciado.set(2, 2, 4);
    matEnunciado.set(3, 1, 1);
    matEnunciado.imprimir();
    // ------------------------------------------------------------------------

    return 0;
}
