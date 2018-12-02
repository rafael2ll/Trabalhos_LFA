#include "arvore.h"
#include "lista_estado.h"

int main(int argc, char const *argv[])
{
    Arvore arv = criar_arvore();
    ListaE matriz_transicao;

    char  alfabeto[] = {'0', '1'};
    char * expressao_regular = ".*+011+10";
    

    criar_listaEstados(&matriz_transicao);
    inserir_estado(matriz_transicao, 0, strlen(alfabeto));
    inserir_estado(matriz_transicao, 1, strlen(alfabeto));
    inserir_estado_transicao(matriz_transicao, 0, 0, 1);
    print(matriz_transicao, strlen(alfabeto));
    
    int i = 0;

    for(i = 0; i< strlen(expressao_regular); i++){
        inserir_profundidade(&arv, alfabeto, expressao_regular[i]);
    }
    print_arvore(arv);
    return 0;
}
