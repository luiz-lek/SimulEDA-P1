#include "../TAB.h"

TAB *TAB_inicializa(void){
  return NULL;
}

TAB *TAB_cria(int raiz, TAB *esq, TAB *dir){
  TAB *novo = (TAB *) malloc(sizeof(TAB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

TAB *TAB_busca(TAB *a, int elem){
  if((!a) || (a->info == elem)) return a;
  TAB *resp = TAB_busca(a->esq, elem);
  if(resp) return resp;
  return TAB_busca(a->dir, elem);
}

void TAB_imp_pre(TAB *a){
  if(a){
    printf("%d ", a->info);
    TAB_imp_pre(a->esq);
    TAB_imp_pre(a->dir);
  }
}

void TAB_imp_pos(TAB *a){
  if(a){
    TAB_imp_pos(a->esq);
    TAB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TAB_imp_sim(TAB *a){
  if(a){
    TAB_imp_sim(a->esq);
    printf("%d ", a->info);
    TAB_imp_sim(a->dir);
  }
}

void imp_aux(TAB *a, int andar){
  int j;
  if(a){
    imp_aux(a->dir, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->info);
    imp_aux(a->esq, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TAB_imp_ident(TAB *a){
  imp_aux(a, 0);
}

void TAB_libera(TAB *a){
  if(a){
    TAB_libera(a->esq);
    TAB_libera(a->dir);
    free(a);
  }
}

int maior(int x, int y){
  if(x >= y) return x;
  return y;
}

int TAB_altura(TAB *a){
  if(!a) return -1;
  return maior(TAB_altura(a->esq), TAB_altura(a->dir)) + 1;
}
void aux(TAB* a, int* soma, int nivel) {
  if (!a) return;

  aux(a->esq, soma, !nivel);

  if (nivel) *soma += a->info;
  if (!nivel) *soma -= a->info;

  aux(a->dir, soma, !nivel);

}
int misc1(TAB *a) {
  int soma = 0;
  aux(a, &soma, 1);
  return soma;
}

void aux_med(TAB* a, int nivel, int* vet, int* quant ) {
  if (!a) return;
  aux_med(a->esq, nivel+1, vet, quant);
  vet[nivel] += a->info;
  quant[nivel]++;
  aux_med(a->dir, nivel+1, vet, quant);
}

int *media(TAB *a, int *tam_vet) {
  if (!a) return NULL;
  *tam_vet = TAB_altura(a) + 1;
  printf("%d ", *tam_vet);
  int* vet = (int*)calloc((*tam_vet),sizeof(int));
  if (!vet) {
    perror("MALLOC FALHOU!");
    return NULL;
  }

  int* quant = (int*)calloc((*tam_vet),sizeof(int));
  if (!quant) {
    perror("MALLOC FALHOU!");
    return NULL;
  }
  aux_med(a, 0, vet, quant);
  for (int i = 0; i < *tam_vet; i++)
    vet[i] = vet[i] / quant[i];
  free(quant);
  return vet;
}

// void printv(int* vet) {
//   if (!vet) return;
//   printf("[ ");
//   int tam = sizeof(vet) / sizeof(typeof(vet[0]));
//   for (int i = 0; i < tam; i++)
//     printf("%d ", vet[i]);
//   printf("]\n");
// }

void camaux(TAB *a, int N, int Soma, int *cams) {
  if (!a) return;
  Soma += a->info;
  camaux(a->esq, N, Soma, cams);
  if ((a->info + Soma) == N)
    (*cams)++;
  camaux(a->dir, N, Soma, cams);
}

int quant_caminhos(TAB *a, int N) {
  if (!a) return 0;
  int resp = 0;
  camaux(a, N, 0, &resp);
  return resp;
}