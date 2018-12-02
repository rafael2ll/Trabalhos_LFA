#ifndef LISTA_ESTADO
#define LISTA_ESTADO "LISTA_ESTADO"

#include <stdlib.h>
#include "lista_transicao.h"

typedef struct no_estado * ListaE;

void criar_listaEstados(ListaE * le);
void inserir_estado(ListaE l, int estado, int alf_c);
int inserir_estado_transicao(ListaE l, int estado, int simbolo, int estado_para);
void print(ListaE le, int alf_c);
#endif