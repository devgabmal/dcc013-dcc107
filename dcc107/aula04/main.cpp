#include <iostream>
#include "Aluno.h"
#include "Prova.h"

using namespace std;

int main()
{
    int idade;
    string matricula, nome;

    // Aluno aluno("Andre", "2022010005");
    // aluno.leNotas();

    // cout << "Media: " << aluno.calculaMedia() << endl;

    // INTERFACE
    cout << "== CADASTRO DO ALUNO ==" << endl;
    cout << "Digite o nome: ";
    cin >> nome;
    cout << "Digite a idade: ";
    cin >> idade;
    cout << "Digite a matricula: ";
    cin >> matricula;

    Aluno aluno(nome, matricula);
    aluno.setIdade(idade);
    aluno.setMatricula(matricula);

    // aluno.leFrequencia();
    // aluno.leNotas();

    aluno.relatorio();

    Prova prova(5);

    prova.leNotas();

    prova.calculaNotaFinal();

    cout << "Nota Final:  " << prova.obtemNotaFinal() << endl;

    return 0;
}
