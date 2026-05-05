//
// Created by luiz-p on 05/05/2026.
//

#include "../headers/q4.h"

int eh_avl(TAB *a) {
    if(!a) return 1;

    int fb = TAB_altura(a->dir) - TAB_altura(a->esq);
    if(fb < -1 || fb > 1) return 0;

    return eh_avl(a->esq) && eh_avl(a->dir);
}