#include "../headers/q9.h"

void encadeador_aux(TABB* a, TABB* prox) {
    if (!a) return;
    a->prox = prox;

    encadeador_aux(a->esq, a->dir);

    if (!prox) return encadeador_aux(a->dir, NULL);
    if (!prox->esq) return encadeador_aux(a->dir, prox->dir);
    encadeador_aux(a->dir, prox->esq);
}

TABB* encadeador(TABB* a) {
    if (!a) return NULL;
    a->prox = NULL;
    encadeador_aux(a, NULL);
    return a;
}