#include "../headers/q2.h"

int aux_eh_simetrica(TAB *a, TAB *simetrica) {
    if(!a && !simetrica) return 1;
    if(!a || !simetrica || a->info != simetrica->info) return 0;

    return aux_eh_simetrica(a->esq, simetrica->dir) && aux_eh_simetrica(a->dir, simetrica->esq);
}

int eh_simetrica(TAB *a) {
    return aux_eh_simetrica(a, a);
}