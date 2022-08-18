#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct NODO{
	int conteudo;
	struct NODO * prox;
} no;

no * resultadoQuestao(no **lista, no **topo);
no * criarNo(int conteudo);
no * inserirNodosFinal(no **lista, int conteudo);
void imprimeListaRecursiva(no *lista);
no * cria_nodo(int valor);
no * push(no **topo, int valor);

int main(){
	no * lista = NULL, * lista2 = NULL, * topo = NULL;
	
	lista = inserirNodosFinal(&lista, 7);
	lista = inserirNodosFinal(&lista, 8);
	topo = push(&topo, 6);
	topo = push(&topo, 9);
	topo = push(&topo, 4);
	
	lista2 = resultadoQuestao(&lista, &topo);
	
	imprimeListaRecursiva(lista2);
	
	return 0;
}

no * resultadoQuestao(no **lista, no **topo){
	no ** inicio, * aux, *lista2, *topo2, *p;
	
	lista2 = *lista;
	topo2 = *topo;
	aux = NULL;
	
	while(lista2 != NULL){
		p = criarNo(lista2->conteudo);
		if(aux == NULL){
			inicio = &aux;
			aux = inserirNodosFinal(&aux, p->conteudo);
		} else {
			aux = inserirNodosFinal(&aux, p->conteudo);
		}
		lista2 = lista2->prox;
	}
	while(topo2 != NULL){
		p = criarNo(topo2->conteudo);
		aux = inserirNodosFinal(&aux, p->conteudo);
		topo2 = topo2->prox;
	}
	return *inicio;
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

no * cria_nodo(int valor){
	no *p;
	p = (no *) malloc (sizeof(no));
	p->conteudo = valor;
	p->prox = NULL;
	return p;
}

no * push(no **topo, int valor){
	no * nodo = cria_nodo(valor);
	if(*topo == NULL){
		*topo = nodo;
	}else{
		nodo->prox = *topo;
		*topo = nodo;
	}
	return *topo;
}
