#include "lista.h"

struct no_estado
{
    int estado;
    ListaT * transicoes;
    struct no_estado * prox;
};


void criar_listaEstados(ListaE le, int alfabeto_count){
    l = malloc(sizeof(struct no_estado));
    l->estado = -1;
    l->prox = NULL;
}

void inserir_estado(ListaE l, int estado, int alf_c){
    int i;
    struct no_estado estado= malloc(sizeof(struct no_estado));
    estado->prox = l->prox;
    estado->estado = estado;
    estado->transicoes = malloc(5*alf_c);
    l->prox = no_estado;

    for(i=0; i<alf_c; i++) criar_listaT(estado-> transicoes[i]);

}

int inserir_transicao(ListaE l, int estado, int simbolo, int estado_para){
    Lista aux =  l->prox;

    while(aux->estado != estado && aux != NULL) aux = aux->prox;

    if(aux != NULL){
        inserir_transicao(aux->transicoes[simbolo], estado_para);
        return 1;
    }
    return 0;
}