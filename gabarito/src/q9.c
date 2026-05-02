#include "../headers/q9.h"

void encadeador_aux(TABB* a, TABB* viz) {
    if (!a) return;
    a->prox = viz;

    encadeador_aux(a->esq, a->dir);

    if (!viz) {
        encadeador_aux(a->dir, NULL);
        return;
    }
    if (!viz->esq) {
        encadeador_aux(a->dir, viz->dir);
        return;
    }
    encadeador_aux(a->dir, viz->esq);

}

TABB* encadeador(TABB* a) {
    if (!a) return NULL;
    a->prox = NULL;
    encadeador_aux(a, NULL);
    return a;
}