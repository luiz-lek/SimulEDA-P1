//
// Created by eric on 04/05/2026.
//

#include "TABB.h"

int maior(int a, int b) {
    if (a > b) return a;
    return b;
}

int altura(TABB *a) {
    if (!a) return 0;
    return 1 + maior(altura(a->esq), altura(a->dir));
}

int eh_AVL(TABB* a) {
    if (!a) return 1;
    int fb = altura(a->esq) - altura(a->dir);
    if ((fb < -1) || (fb > 1)) return 0;
    if (!eh_AVL(a->esq) || (!eh_AVL(a->dir))) return 0;
    return 1;
}