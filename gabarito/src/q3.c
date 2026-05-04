#include "../headers/q3.h"

int aux(TAB *a, TAB *simetrica) {
    if(!a && !simetrica) return 1;
    if(!a || !simetrica || a->info != simetrica->info) return 0;

    return aux(a->esq, simetrica->dir) && aux(a->dir, simetrica->esq);
}

int eh_simetrica(TAB *a) {
    return aux(a, a);
}