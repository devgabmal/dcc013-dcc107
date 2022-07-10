#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"
#include "ListaCont.h"
#include "ListaEncad.h"
#include "ListaDupla.h"

using namespace std;

// ----------------------------------------------------------------------------
// Q1

bool balanceado(char vet[], int n)
{
     PilhaEncad *pilha = new PilhaEncad;
     for (int i = 0; i < n; i++)
     {
          char carac = vet[i];
          if (!pilha->vazia() && ((carac == ']' && pilha->getTopo() == '[') || (carac == '}' && pilha->getTopo() == '{')))
               pilha->desempilha();
          else
               pilha->empilha(carac);
     }
     return (pilha->vazia());
}

//-Q1 - 21 minutos e 39 segundos
// ----------------------------------------------------------------------------

int main()
{
     srand(0);

     /// ************* TESTES QUEST�O 1 *************** ///
     cout << "==== TESTES QUESTAO 1 ====" << endl
          << endl;
     cout << "[[{}]{{}}]\n\tResultado esperado: Balanceado\n\tResultado obtido: " << (balanceado("[[{}]{{}}]", 10) ? "Balanceado" : "NAO Balanceado") << endl;
     cout << "STRING VAZIA\n\tResultado esperado: Balanceado\n\tResultado obtido: " << (balanceado("", 0) ? "Balanceado" : "NAO Balanceado") << endl;
     cout << "[[{}{}}]\n\tResultado esperado: NAO Balanceado\n\tResultado obtido: " << (balanceado("[[{}{}}]", 8) ? "Balanceado" : "NAO Balanceado") << endl;
     cout << "[[{{[{\n\tResultado esperado: NAO Balanceado\n\tResultado obtido: " << (balanceado("[[{{[{", 6) ? "Balanceado" : "NAO Balanceado") << endl;
     // cout << "]]}}]}\n\tResultado esperado: NAO Balanceado\n\tResultado obtido: " << (balanceado("]]}}]}", 6) ? "Balanceado" : "NAO Balanceado") << endl;
     cout << "{}[[}[]}]]\n\tResultado esperado: NAO Balanceado\n\tResultado obtido: " << (balanceado("{}[[}[]}]]", 10) ? "Balanceado" : "NAO Balanceado") << endl;
     cout << "[]}\n\tResultado esperado: NAO Balanceado\n\tResultado obtido: " << (balanceado("[]}", 3) ? "Balanceado" : "NAO Balanceado") << endl;

     cout << endl
          << endl;
     cout << "==== TESTES QUESTAO 2 ====" << endl
          << endl;
     ListaCont l(20);
     for (int i = 0; i < 10; i++)
     {
          l.insereFinal(rand() % 10);
     }

     bool resultado;
     cout << "Inserindo intervalo [3, 7]:\n\tLista original: ";
     l.imprime();
     resultado = l.insereIntervalo(3, 7);
     cout << "\n\tLista alterada: ";
     l.imprime();
     cout << "\nHouve alteracao na capacidade? Resposta correta: NAO - Resposta obtida: " << (resultado ? "SIM" : "NAO") << endl
          << endl;

     cout << "Inserindo intervalo [10, 12]:\n\tLista original: ";
     l.imprime();
     resultado = l.insereIntervalo(10, 12);
     cout << "\n\tLista alterada: ";
     l.imprime();
     cout << "\nHouve alteracao na capacidade? Resposta correta: NAO - Resposta obtida: " << (resultado ? "SIM" : "NAO") << endl
          << endl;

     cout << "Inserindo intervalo [20, 27]:\n\tLista original: ";
     l.imprime();
     resultado = l.insereIntervalo(20, 27);
     cout << "\n\tLista alterada: ";
     l.imprime();
     cout << "\nHouve alteracao na capacidade? Resposta correta: SIM - Resposta obtida: " << (resultado ? "SIM" : "NAO") << endl
          << endl;

     cout << endl
          << endl;
     cout << "==== TESTES QUESTAO 3 ====" << endl
          << endl;

     ListaDupla l2a, l2b;
     for (int i = 0; i < 10; i++)
     {
          l2a.insereInicio(rand() % 100);
     }
     cout << "\nLista original: ";
     l2a.imprime();
     l2a.removeMaior();
     cout << "\nLista alterada: ";
     l2a.imprime();

     cout << "\nLista original: ";
     l2b.imprime();
     l2b.removeMaior();
     cout << "\nLista alterada: ";
     l2b.imprime();

     //     l2a.insereInicio(101);
     //     cout << "\nLista original: ";
     //     l2a.imprime();
     //     l2a.removeMaior();
     //     cout << "\nLista alterada: ";
     //     l2a.imprime();

     //     l2b.insereInicio(1);
     //     cout << "\nLista original: ";
     //     l2b.imprime();
     //     l2b.removeMaior();
     //     cout << "\nLista alterada: ";
     //     l2b.imprime();

     cout << endl
          << endl;
     cout << "==== TESTES QUESTAO 4 ====" << endl
          << endl;

     ListaEncad l3;
     for (int i = 0; i < 10; i++)
     {
          l3.insereInicio(i);
     }
     cout << "\nLista original: ";
     l3.imprime();
     l3.removeBloco(5, 2);
     cout << "\nApos remover o bloco [5,2]: ";
     l3.imprime();
     l3.removeBloco(10, 0);
     cout << "\nApos remover o bloco [10,0]: ";
     l3.imprime();
     l3.removeBloco(7, 0);
     cout << "\nApos remover o bloco [7,-2]: ";
     l3.imprime();
     l3.removeBloco(9, 8);
     cout << "\nApos remover o bloco [9,8]: ";
     l3.imprime();
     // l3.removeBloco(6, 6);
     // cout << "\nApos remover o bloco [6,6]: ";
     // l3.imprime();

     cout << endl
          << endl;

     return 0;
}
