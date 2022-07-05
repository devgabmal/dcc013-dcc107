#include "Aluno.h"

Aluno::Aluno(string n, string m)
{
    cout << "Criando aluno" << endl;
    nome = n;
    matricula = m;
}

Aluno::~Aluno()
{
    cout << "Destruindo objeto aluno" << endl;
}

// ----------------------------------------------------------------------------
// Exercicio 1
// ----------------------------------------------------------------------------

void Aluno::leNotas()
{
    for (int i = 0; i < 7; i++)
    {
        cout << "Digite a " << i + 1 << "ª nota: ";
        cin >> notas[i];
    }
}

double Aluno::calculaMedia()
{
    double soma = 0;

    for (int i = 0; i < 7; i++)
    {
        soma += notas[i];
    }
    return (soma / (double)7);
}

// ----------------------------------------------------------------------------

void Aluno::setNome(string novo)
{
    nome = novo;
}

string Aluno::getNome()
{
    return nome;
}

// ----------------------------------------------------------------------------
// Exercicio 2
// ----------------------------------------------------------------------------

void Aluno::setIdade(int novo)
{
    idade = novo;
}

int Aluno::getIdade()
{
    return idade;
}

void Aluno::setMatricula(string novo)
{
    matricula = novo;
}

string Aluno::getMatricula()
{
    return matricula;
}

// ----------------------------------------------------------------------------
// Exercicio 3
// ----------------------------------------------------------------------------

void Aluno::printDados()
{
    cout << endl
         << "== REGISTRO DO ALUNO ==" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Matricula: " << matricula << endl;
}

// ----------------------------------------------------------------------------
// Exercicio 5
// ----------------------------------------------------------------------------

void Aluno::leFrequencia()
{
    cout << "Digite a Frequência de cada disciplina:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << "a: ";
        cin >> frequencia[i];
    }
}

// ----------------------------------------------------------------------------
// Exercicio 6
// ----------------------------------------------------------------------------

void Aluno::relatorio()
{
    cout << "== RELATORIO ==" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Matricula: " << matricula << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "Disciplina " << i + 1 << endl;
        cout << "  ";
        if (frequencia[i])
            cout << "Frequente";
        else
            cout << "Infrequente";
        cout << endl;
        cout << "  ";
        if (notas[i] >= 60)
            cout << "Aprovado";
        else
            cout << "Reprovado";
        cout << endl;
    }
}