#include "../headers/q5.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../estrturas/headers/TAB.h"
#include "../../estrturas/headers/TLSE.h"

TLSE** caminho_aux(TAB *a, TLSE **vet, int* caminho, int n, int *tam_vet_caminhos, int i){
    if(!a) return vet;

    caminho[i] = a->info;
    n-=a->info;

    if(n == 0) {
        (*tam_vet_caminhos)++;
        vet = (TLSE**)realloc(vet,(*tam_vet_caminhos)*sizeof(TLSE*));
        vet[(*tam_vet_caminhos)-1] = NULL;
        for (int j = i; j >= 0; j--) {
            vet[*tam_vet_caminhos-1] = TLSE_insere(vet[*tam_vet_caminhos-1], caminho[j]);
        }
    }

    vet = caminho_aux(a->esq,vet,caminho, n, tam_vet_caminhos, i+1);
    vet = caminho_aux(a->dir,vet,caminho, n,tam_vet_caminhos, i+1);
    return vet;
}

TLSE** caminhos(TAB *a,int n){
    if(!a) return NULL;

    TLSE** vet = NULL;
    int caminho[TAB_altura(a)];
    int i =  0;
    int tam_vet_caminhos = 0;

    vet = caminho_aux(a, vet,caminho,n,&tam_vet_caminhos,i);
    for (int j = 0; j < i; j++) {
        TLSE_imprime(vet[j]);
        printf("\n");
    }
    return vet;
}