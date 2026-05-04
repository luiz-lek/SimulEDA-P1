#include "../../estrturas/headers/TG.h"
TLSE* aux_caminho(TG* grafo, TLSE** visitados, int atual, int destino) {
    if(!grafo) return NULL;

    if(atual == destino) {
        TLSE* dest = NULL;
        dest = TLSE_insere(dest, destino);
        return dest;
    }

    TG* no = TG_busca_no(grafo, atual);
    if(!no) return NULL;
    *visitados = TLSE_insere(*visitados, atual);

    TVIZ* vizinho = no->prim_viz;
    TLSE* caminho = NULL;
    while(vizinho) {
        if(!TLSE_busca(*visitados, vizinho->id_viz)) {
            TLSE* busca = aux_caminho(grafo, visitados, vizinho->id_viz, destino);
            if(busca) return TLSE_insere(busca, atual);
        }
        vizinho = vizinho->prox_viz;
    }

    return NULL;
}

TLSE* caminho(TG *g, int origem, int destino) {
    TLSE* visitados = NULL;
    TLSE* caminho = aux_caminho(g, &visitados, origem, destino);
    TLSE_libera(visitados);
    return caminho;
}