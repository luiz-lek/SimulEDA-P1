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
    if(!g) return NULL;

    TLSE* fila = TLSE_inicializa();
    int tam = busca_maior(g);
    int pai[tam];
    int visitados[tam];

    for(int i = 0; i < tam; i++) {
        visitados[i] = 0;
        pai[i] = INT_MIN;
    }
    visitados[origem] = 1;
    fila = TLSE_insere(fila, origem);

    while(fila) {
        int vertice = pop(&fila);
        if (vertice == destino) break;

        TVIZ* vizinho = TG_busca_no(g, vertice)->prim_viz;
        while(vizinho) {
            if (!visitados[vizinho->id_viz]) {
                fila = TLSE_insere(fila, vizinho->id_viz);
                visitados[vizinho->id_viz] = 1;
                pai[vizinho->id_viz] = vertice;
            }
            vizinho = vizinho->prox_viz;
        }
    }

    if(fila) TLSE_libera(fila);

    if(!visitados[destino]) return NULL;

    TLSE* caminho = NULL;
    int no = destino;
    while(pai[no] != INT_MIN) {
        caminho = TLSE_insere(caminho, no);
        no = pai[no];
    }
    caminho = TLSE_insere(caminho, no);

    return caminho;
}