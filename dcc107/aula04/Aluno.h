#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>

using namespace std;

class Aluno
{
public:
    Aluno(string n, string m);
    ~Aluno();

    // operacoes
    void setNome(string n);
    string getNome();

    // exercicio 1
    void leNotas();
    double calculaMedia();

    // exercicio 2
    void setIdade(int ida);
    int getIdade();

    void setMatricula(string mat);
    string getMatricula();

    // exercicio 3
    void printDados();

    // exercicio 5
    void leFrequencia();

    // exercicio 6
    void relatorio();

private:
    int idade;
    string nome, matricula;
    double notas[7];

    // exercicio 4
    bool frequencia[7];
};

#endif // ALUNO_H
