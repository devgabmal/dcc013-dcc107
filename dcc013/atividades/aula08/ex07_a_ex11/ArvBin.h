#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"
#include "FilaEncad.h"

class ArvBin
{
public:
  ArvBin();
  ~ArvBin();
  int getRaiz();
  void cria(int x, ArvBin *sae, ArvBin *sad);
  void anulaRaiz();
  bool vazia(); // verifica se a �rvore est� vazia
  bool busca(int x);
  void preOrdem();
  void montaArvore();
  void insere(int x);
  int altura();
  int nNos();
  int nFolhas();
  bool ehCheia();
  void removeFolhas();
  int nNosK(int k);

private:
  NoArv *raiz; // ponteiro para o No raiz da �rvore

  NoArv *libera(NoArv *p);
  bool auxBusca(NoArv *p, int x);
  void auxPreOrdem(NoArv *p);
  NoArv *auxMontaArvore();
  void auxImpNivel(NoArv *p, int atual, int k);
  void auxInverte(NoArv *p);
  NoArv *auxInsere(NoArv *p, int x);
  int auxAltura(NoArv *p);
  int auxNNos(NoArv *p);
  int auxNFolhas(NoArv *p);
  void auxEhCheia(NoArv *p, int *hp, int *nf);
  NoArv *auxRemoveFolhas(NoArv *p);
  int auxNNosK(NoArv *p, int kp, int k);
};

#endif // ARVBIN_H_INCLUDED
