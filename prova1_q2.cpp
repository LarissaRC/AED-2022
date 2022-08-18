#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct NODO{
	int conteudo;
	struct NODO * prox;
} no;

no * resultadoQuestao(no **lista, no **inicioFila, no**fimFila);
no * criarNo(int conteudo);
no * inserirNodosFinal(no **lista, int conteudo);
void imprimeListaRecursiva(no *lista);
void inqueue(no **cabeca, no**fim, int conteudo);

int main(){
	no * lista = NULL, *inicioFila = NULL, *fimFila = NULL;
	
	lista = inserirNodosFinal(&lista, 4);
	lista = inserirNodosFinal(&lista, 7);
	lista = inserirNodosFinal(&lista, 3);
	
	inqueue(&inicioFila, &fimFila, 2);
	inqueue(&inicioFila, &fimFila, 1);
	inqueue(&inicioFila, &fimFila, 9);
	
	lista = resultadoQuestao(&lista, &inicioFila, &fimFila);
	
	imprimeListaRecursiva(lista);
	
	return 0;
}

no * resultadoQuestao(no **lista, no **inicioFila, no**fimFila){
	no *lista2 = *lista;
	
	while(lista2->prox != NULL){
		lista2 = lista2->prox;
	}
	
	lista2->prox = *inicioFila;
	
	return *lista;
}

void inqueue(no **cabeca, no**fim, int conteudo){
    no *p;
    p = criarNo(conteudo);
    if (*cabeca==NULL){
        *fim = *cabeca = p;
    } else {
        (*fim)->prox = p;
        *fim = p;
    }
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
