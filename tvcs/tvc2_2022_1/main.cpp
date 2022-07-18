#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"
#include "ListaCont.h"
#include "ListaDupla.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q3
// Celso Gabriel Dutra Almeida Malosto
void caminho()
{
     PilhaEncad *caminho = new PilhaEncad();
     PilhaEncad *volta = new PilhaEncad();
     char direcao;

     cin >> direcao;
     while (direcao != 'q')
     {
          if (direcao == 'n' || direcao == 's' || direcao == 'l' || direcao == 'o')
               caminho->empilha(direcao);

          cin >> direcao;
     }

     while (!caminho->vazia())
     {
          char dirContraria;
          switch (caminho->desempilha())
          {
          case 'n':
               dirContraria = 's';
               break;
          case 's':
               dirContraria = 'n';
               break;
          case 'l':
               dirContraria = 'o';
               break;
          case 'o':
               dirContraria = 'l';
               break;
          default:
               break;
          }
          volta->empilha(dirContraria);
     }

     while (!volta->vazia()) // Inverte caminho de volta
     {
          caminho->empilha(volta->desempilha());
     }
     cout << "Caminho de volta: ";
     while (!caminho->vazia())
     {
          cout << (char)caminho->desempilha();
     }
     cout << endl;

     delete caminho;
     delete volta;
}
//-Q3
// ----------------------------------------------------------------------------

void reinicializaLista(ListaCont *l)
{
     l->limpar();
     l->insereFinal(3);
     l->insereFinal(2);
     l->insereFinal(5);
     l->insereFinal(7);
     l->insereFinal(9);
}

int main()
{
     srand(0);

     /// ************* TESTES QUEST�O 1 *************** ///
     cout << "==== TESTES QUESTAO 1 ====" << endl
          << endl;
     bool result;
     int vetA[] = {1, 1}, vetB[] = {1, 1, 1, 1};
     ListaCont l(8);
     reinicializaLista(&l);
     result = l.insereValores(0, 2, vetA);
     cout << "Testando insereValores(0, 2, [1, 1]):" << endl;
     cout << "Resultado esperado: [1, 1, 3, 2, 5, 7, 9] (true)" << endl
          << "Resultado obtido:   ";
     l.imprime();
     cout << boolalpha << " (" << result << ")" << endl
          << endl;
     reinicializaLista(&l);
     result = l.insereValores(5, 2, vetA);
     cout << "Testando insereValores(5, 2, [1, 1]):" << endl;
     cout << "Resultado esperado: [3, 2, 5, 7, 9, 1, 1] (true)" << endl
          << "Resultado obtido:   ";
     l.imprime();
     cout << " (" << result << ")" << endl
          << endl;
     reinicializaLista(&l);
     result = l.insereValores(5, 4, vetB);
     cout << "Testando insereValores(5, 4, [1, 1, 1, 1]):" << endl;
     cout << "Resultado esperado: [3, 2, 5, 7, 9] (false)" << endl
          << "Resultado obtido:   ";
     l.imprime();
     cout << " (" << result << ")" << endl
          << endl;
     reinicializaLista(&l);
     result = l.insereValores(3, 2, vetA);
     cout << "Testando insereValores(3, 2, [1, 1]):" << endl;
     cout << "Resultado esperado: [3, 2, 5, 1, 1, 7, 9] (true)" << endl
          << "Resultado obtido:   ";
     l.imprime();
     cout << " (" << result << ")" << endl
          << endl;
     reinicializaLista(&l);
     result = l.insereValores(7, 2, vetA);
     cout << "Testando insereValores(7, 2, [1, 1]):" << endl;
     cout << "Resultado esperado: [3, 2, 5, 7, 9] (false)" << endl
          << "Resultado obtido:   ";
     l.imprime();
     cout << " (" << result << ")" << endl
          << endl;
     reinicializaLista(&l);
     result = l.insereValores(2, 4, vetB);
     cout << "Testando insereValores(2, 4, [1, 1, 1, 1]):" << endl;
     cout << "Resultado esperado: [3, 2, 5, 7, 9] (false)" << endl
          << "Resultado obtido:   ";
     l.imprime();
     cout << " (" << result << ")" << endl;

     cout << endl
          << endl;

     /// ************* TESTES QUEST�O 2 *************** ///
     cout << "==== TESTES QUESTAO 2 ====" << endl
          << endl;
     ListaDupla ld;
     cout << "Testando com a lista: [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]" << endl;
     for (int i = 0; i < 10; i++)
          ld.insereInicio(i);
     cout << "Resultado esperado: [9, 1, 7, 6, 5, 4, 3, 2, 8, 0]" << endl;
     ld.trocaSegundoPenultimo();
     cout << "Resultado obtido:   ";
     ld.imprime();
     cout << endl;

     cout << "Testando com a lista: [3, 2, 1, 0]" << endl;
     ListaDupla ldAte4;
     for (int i = 0; i < 4; i++)
          ldAte4.insereInicio(i);
     cout << "Resultado esperado:" << endl
          << "ERRO: A lista tem menos de 5 nos!" << endl
          << "[3, 2, 1, 0]" << endl;
     cout << "Resultado obtido:" << endl;
     ldAte4.trocaSegundoPenultimo();
     ldAte4.imprime();

     cout << endl
          << endl;

     /// ************* TESTES QUEST�O 3 *************** ///
     cout << "==== TESTES QUESTAO 3 ====" << endl
          << endl;

     cout << endl
          << endl;
     cout << "Testando a funcao caminho():" << endl
          << "Quando solicitado, digite a sequencia nlnnonlllls." << endl
          << "A saida esperada eh: nooooslssos" << endl;
     caminho();

     return 0;
}
