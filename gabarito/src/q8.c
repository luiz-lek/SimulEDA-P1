//
// Created by eric on 02/05/2026.
//

#include "../headers/q8.h"

int busca_maior(TG* l) {
    if (!l) return INT_MIN;
    int maior = INT_MIN;

    while (l->prox_no) {
        if (l->id_no > maior) maior = l->id_no;
        l = l->prox_no;
    }

    return maior+1;
}

int pop(TLSE** l) {
    if (!l) return -33;
    TLSE* aux = *l;
    int resp;
    if (!(*l)->prox) {
        resp = (*l)->info;
        free(*l);
        (*l) = NULL;
        return resp;
    }
    while (aux->prox) {
        *l = aux;
        aux = aux->prox;
    }
    resp = aux->info;
    free(aux);
    (*l)->prox = NULL;
    return resp;
}

TLSE* menor_caminho(TG *g, int origem, int destino) {
    if (!g) return NULL;

    TLSE* visitados = TLSE_inicializa();
    TLSE* fila = TLSE_inicializa();
    fila = TLSE_insere(fila, origem);
    visitados = TLSE_insere(visitados, origem);
    int tam = busca_maior(g);
    int pais[tam];
    for (int i = 0; i < tam; i++) pais[i] = INT_MIN;

    while (fila) {
        int pai = pop(&fila);
        if (pai == destino) {
            break;
        }
        TVIZ* vizinho = TG_busca_no(g, pai)->prim_viz;
        //TVIZ* vizinho = aux->prim_viz;

        while(vizinho) {
            if (!TLSE_busca(visitados, vizinho->id_viz)) {
                visitados = TLSE_insere(visitados, vizinho->id_viz);
                fila = TLSE_insere(fila, vizinho->id_viz);
                pais[vizinho->id_viz] = pai;
            }
            vizinho = vizinho->prox_viz;
        }
    }
    if (!TLSE_busca(visitados, destino)) {
        TLSE_libera(visitados);
        return NULL;
    }
    TLSE* caminho = NULL;
    int no = destino;
    while (pais[no] != INT_MIN) {
        caminho = TLSE_insere(caminho, no);
        no = pais[no];
    }
    caminho = TLSE_insere(caminho, no);
    TLSE_libera(visitados);
    return caminho;
}