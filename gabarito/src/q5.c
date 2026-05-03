//
// Created by eric on 02/05/2026.
//

#include "../headers/q5.h"
#include <limits.h>

TLSE** caminhos_aux(TAB* a, int n, TLSE** v, int* pos) {
    if (!a) return v;
    if ((n - a->info) == 0) {
        v[*pos] = TLSE_insere(v[*pos], a->info);
        (*pos)++;
        v = realloc(v, ((*pos)+1) * sizeof(TLSE*));
        if (!v) return NULL;
        v[(*pos)] = NULL;
        return v;
    }

    n = n - a->info;
    v = caminhos_aux(a->esq, n, v, pos);
    v = caminhos_aux(a->dir, n, v, pos);

    int esq, dir;
    esq = dir = INT_MAX;
    if (a->esq) {
        esq = a->esq->info;
    }
    if (a->dir) {
        dir = a->dir->info;
    }

    for (int i = 0; i < (*pos); i++) {
        if ((v[i]->info == esq) || (v[i]->info == dir)) {
            v[i] = TLSE_insere(v[i], a->info);
        }
    }
    return v;
}

TLSE** caminhos(TAB *a, int n, int* pos) {
    if (!a) return NULL;
    TLSE** v = (TLSE**)malloc(sizeof(TLSE*));
    if (!v) return NULL;
    v[*pos] = NULL;
    v = caminhos_aux(a, n, v, pos);

    return v;
}