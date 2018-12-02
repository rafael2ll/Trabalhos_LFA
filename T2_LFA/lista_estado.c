#include "lista_estado.h"

struct no_estado
{
    int estado;
    ListaT * transicoes;
    struct no_estado * prox;
};


void criar_listaEstados(ListaE * le){
    *le = malloc(sizeof(struct no_estado));
    (*le)->estado = -1;
    (*le)->prox = NULL;
}

void inserir_estado(ListaE l, int est, int alf_c){
    int i;
    struct no_estado * estado= malloc(sizeof(struct no_estado));
    estado->prox = l->prox;
    estado->estado = est;
    estado->transicoes = malloc(5*alf_c);
    l->prox = estado;

    for(i=0; i<alf_c; i++) estado->transicoes[i] = criar_listaT();

}

int inserir_estado_transicao(ListaE l, int estado, int simbolo, int estado_para){
    ListaE aux =  l->prox;

    while(aux->estado != estado && aux != NULL) aux = aux->prox;

    if(aux != NULL){
        inserir_transicao(aux->transicoes[simbolo], estado_para);
        return 1;
    }
    return 0;
}

void print(ListaE le, int alf_c){
    ListaE aux = le->prox;
    int i;
    while(aux != NULL){
        printf("----%d----\n", aux->estado);
        for(i=0; i<alf_c; i++){
            printf("Lendo %d:{", i);
            print_transicoes(le->transicoes[i]);
            printf("}\n");
        }
        aux = aux->prox;
    }
}