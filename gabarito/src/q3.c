//
// Created by luiz-p on 04/05/2026.
//

#include "../headers/q3.h"

int aux_mesmo_nivel(TAB* a, int* nivel_folha, int i) {
    if(!a) return 1;
    if(!a->esq && !a->dir) {
        if(*nivel_folha == -1) {
            *nivel_folha = i;
            return 1;
        }
        if(i == *nivel_folha) return 1;
        return 0;
    }

    return aux_mesmo_nivel(a->esq, nivel_folha, i+1) && aux_mesmo_nivel(a->dir, nivel_folha, i+1);
}

int mesmo_nivel(TAB *a) {
    if(!a) return 1;
    int nivel_folha = -1;
    return aux_mesmo_nivel(a, &nivel_folha, 0);
}