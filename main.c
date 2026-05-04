// #include "TABB.h"
//
// int main(void){
//   TABB *a = TABB_inicializa();
//   int n;
//
//   while(1){
//     scanf("%d", &n);
//     if(n < 0) break;
//     a = TABB_insere(a, n);
//   }
//   TABB_imp_ident(a);
//   int sz;
//   //int* vet = maioresN(a, 5, &sz);
//   //printv(vet, sz);
//
//   while(1){
//     scanf("%d", &n);
//     if(n < 0) break;
//     a = TABB_retira(a, n);
//     TABB_imp_ident(a);
//   }
//
//   encadeador(a);
//   imprime_lista(a);
//
//   TABB_libera(a);
//   return 0;
// }

#include "TG.h"
#include "TAB.h"
#include "gabarito/headers/q5.h"
#include "gabarito/headers/q6.h"
#include "gabarito/headers/q8.h"


 /*------------------------------------------ main grafo ------------------------------------------*/

int main(void){
    TG *g = TG_inicializa();
    int n;

    printf("Digite nos do grafo... Pare quando o no for menor ou igual a zero...\n");
    do{
        scanf("%d", &n);
        if(n <= 0) break;
        g = TG_ins_no(g, n);
    }while(1);
    TG_imp_rec(g);

    int m;
    printf("Digite arestas do grafo... Pare quando os nos forem menores ou iguais a zero...\n");
    do{
        scanf("%d%d", &n, &m);
        if((n <= 0) || (m <= 0)) break;
        TG_ins_aresta(g, n, m);
    }while(1);
    TG_imp_rec(g);

    int origem, destino;
    printf("Origem: ");
    scanf("%d", &origem);
    printf("Destino: ");
    scanf("%d", &destino);

    TLSE* l = menor_caminho(g, origem, destino);
    TLSE_imprime(l);

    TLSE_libera(l);
    TG_libera(g);

    return 0;
}


/*
1
2
3
4
5
6
7
8
9
1 2
1 3
1 7
2 4
2 5
2 6
3 7
3 8
7 9
5 9
0 0
 */

/*------------------------------------------ main TAB ------------------------------------------*/

// TAB *maior_elem(TAB *a){
//  if(!a) return a;
//  TAB *esq = maior_elem(a->esq), *dir = maior_elem(a->dir), *resp = a;
//  if((esq) && (resp->info < esq->info)) resp = esq;
//  if((dir) && (resp->info < dir->info)) resp = dir;
//  return resp;
// }
//
// int main(void){
//  int no, pai;
//  printf("Digite a raiz da arvore... ");
//  scanf("%d", &no);
//  TAB *a = TAB_cria(no, NULL, NULL), *resp;
//  char repete;
//  do{
//   char lado[2];
//   printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
//   scanf(" %c", &repete);
//   if((repete == 'N') || (repete == 'n')) break;
//   printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
//   scanf("%d%d%s", &pai, &no, lado);
//   resp = TAB_busca(a, pai);
//   if(!resp){
//    TAB_libera(a);
//    return 0;
//   }
//   if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
//   else resp->dir = TAB_cria(no, NULL, NULL);
//  }while(1);
//  TAB_imp_ident(a);
//  printf("\n");
//
//  resp = maior_elem(a);
//  if(resp) printf("MAIOR ELEMENTO = %d\n", resp->info);
//  int n, quant = 0;
//  printf("Digite o tamanho do caminho: ");
//  scanf("%d", &n);
//
//  TLSE** v = caminhos(a, n, &quant);
//  for (int i = 0; i < quant; i++) {
//   TLSE_imprime(v[i]);
//   printf("\n");
//   TLSE_libera(v[i]);
//  }
//  free(v);
//  TAB_libera(a);
//  return 0;
// }