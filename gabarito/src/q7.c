//
// Created by luiz-p on 04/05/2026.
//
#include "../headers/q7.h"

int maior_no(TG* g) {
    if(!g) return -1;
    int maior = 0;
    while(g) {
        if(g->id_no > maior) maior = g->id_no;
        g = g->prox_no;
    }
    return maior;
}

int conta_nos(TG* g) {
    if(!g) return -1;
    int acumulador = 0;
    while(g) {
        acumulador++;
        g = g->prox_no;
    }
    return acumulador;
}

TLSE** preenche_caminho_vetor(TLSE** caminhos, int* tam_vet_caminhos, int* caminho_encontrado, int i) { //Preenche uma lista e pôe no fim do vetor de caminhos
    TLSE** aux = realloc(caminhos, *tam_vet_caminhos * sizeof(TLSE*));
    if(!aux) exit(1);
    caminhos = aux;

    TLSE* caminho = NULL; //Passa o vetor com o caminho até i para uma lista, e põe essa lista no fim do vetor de caminhos
    for(int j = i; j >= 0; j--) {
        caminho = TLSE_insere(caminho, caminho_encontrado[j]);
    }
    caminhos[*tam_vet_caminhos-1] = caminho;
    return caminhos;
}

TLSE** aux(TG* g, int atual, int destino, int* visitados, int* caminho_atual, int i,
    TLSE** caminhos, int* tam_vet_caminhos) {
    TG* no = TG_busca_no(g, atual);
    if(!no) return caminhos;

    caminho_atual[i] = atual;
    if(atual == destino) {
        (*tam_vet_caminhos)++;
        caminhos = preenche_caminho_vetor(caminhos, tam_vet_caminhos, caminho_atual, i);
        return caminhos;
    }

    visitados[atual] = 1;
    TVIZ* vizinho = no->prim_viz;
    while(vizinho) {
        if(!visitados[vizinho->id_viz]) {
            caminhos = aux(g, vizinho->id_viz, destino, visitados, caminho_atual, i+1, caminhos, tam_vet_caminhos);
        }
        vizinho = vizinho->prox_viz;
    }

    visitados[atual] = 0; //Tira o nó atual dos visitados.
    return caminhos;
}

TLSE** caminho(TG *g, int origem, int destino) {
    if(!g) return NULL;
    if(!TG_busca_no(g, origem) || !TG_busca_no(g, destino)) return NULL;

    int tam_vet_visitados = maior_no(g)+1;
    int qtd_nos = conta_nos(g);

    int visitados[tam_vet_visitados];
    for(int i = 0; i < tam_vet_visitados; i++) {
        visitados[i] = 0;
    }
    int caminho[qtd_nos];
    TLSE** caminhos = NULL;
    int tam_vet_caminhos = 0;

    caminhos = aux(g, origem, destino, visitados, caminho, 0, caminhos, &tam_vet_caminhos);

    return caminhos;
}