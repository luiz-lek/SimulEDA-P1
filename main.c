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
#include "gabarito/headers/q6.h"
#include "gabarito/headers/q8.h"

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

    // char op;
    // printf("Digite n ou a para retirar nos ou arestas...\n");
    // do{
    //     scanf(" %c", &op);
    //     if(op == 'n'){
    //         printf("Digite o no do grafo... ");
    //         scanf("%d", &n);
    //         g = TG_retira_no(g, n);
    //         TG_imprime(g);
    //     }
    //     else if(op == 'a'){
    //         printf("Digite os nos do grafo... ");
    //         scanf("%d%d", &n, &m);
    //         TG_retira_aresta(g, n, m);
    //         TG_imprime(g);
    //     }
    //     else break;
    // }while(1);
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