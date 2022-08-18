#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct NODO{
	int conteudo;
	struct NODO * prox;
} no;

no * resultadoQuestao(no **lista);
no * criarNo(int conteudo);
no * inserirNodosFinal(no **lista, int conteudo);
void imprimeListaRecursiva(no *lista);

int main(){
	no * lista = NULL;
	
	lista = inserirNodosFinal(&lista, 4);
	lista = inserirNodosFinal(&lista, 7);
	lista = inserirNodosFinal(&lista, 3);
	lista = inserirNodosFinal(&lista, 5);
	lista = inserirNodosFinal(&lista, 2);
	lista = inserirNodosFinal(&lista, 1);
	
	lista = resultadoQuestao(&lista);
	
	imprimeListaRecursiva(lista);
	
	return 0;
}

no * resultadoQuestao(no **lista){
	no * resposta = NULL, * inicio = *lista, ** inicioResposta;
	
	while(*lista != NULL){
		if((*lista)->conteudo % 2 == 0){
			if(resposta == NULL){
				resposta = inserirNodosFinal(&resposta, (*lista)->conteudo);
				inicioResposta = &resposta;
			} else {
				resposta = inserirNodosFinal(&resposta, (*lista)->conteudo);
			}
		}
		*lista = (*lista)->prox;
	}
	
	*lista = inicio;
	
	while(*lista != NULL){
		if((*lista)->conteudo % 2 == 1){
			resposta = inserirNodosFinal(&resposta, (*lista)->conteudo);
		}
		*lista = (*lista)->prox;
	}
	
	return *inicioResposta;
}

no * criarNo(int conteudo){
    no *novo = (no *) malloc(sizeof(no));
    novo->conteudo = conteudo;
    novo->prox = NULL;
    return novo;
}

no * inserirNodosFinal(no **lista, int conteudo){
    no *inicio, *p;

    if (*lista==NULL){
        p = criarNo(conteudo);
        inicio = *lista = p;
    } else {
        inicio = *lista;
        while ((*lista)->prox!=NULL){
            *lista = (*lista)->prox;
        }

        p = criarNo(conteudo);
        (*lista)->prox = p;
    }
    return inicio;
}

void imprimeListaRecursiva(no *lista)
{
    if (lista != NULL)   {
        printf(" : %d", lista->conteudo);
        imprimeListaRecursiva(lista->prox);
    }
}
