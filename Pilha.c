#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct NODO{
	int valor;
	struct NODO *prox;
} nodo;


nodo * cria_nodo(int);
void empilha_nodo(nodo **, nodo *);
nodo * push(nodo **, nodo *);
nodo * push_int(nodo **topo, int valor);
int desempilha_nodo(nodo **);
nodo * pop(nodo **);
void imprime_pilha(nodo *);
void imprime_pilha_real(nodo **topo);

int main(){
	int op = -1;
	nodo * pilha = NULL, *no = NULL;
	int conteudo, posicao;
	
	while (op != 5){
		system("cls");
		
		printf("******** Menu ********\n\n");
		printf("1 - Criar Nodo\n");
		printf("2 - Push\n");
		printf("3 - Pop\n");
		printf("4 - Imprimir pilha\n");
		printf("5 - Sair\n\n");
		printf("Opção: ");
		
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nValor do Nodo a ser criado: ");
				scanf("%d", &conteudo);
				no = cria_nodo(conteudo);
				
				printf("\nNodo com o valor %d criado", (*no).valor);
				getch();
			break;
			case 2:
				push(&pilha, no);
				
				printf("\nÍtem empilhado com sucesso!");
				getch();
			break;
			case 3:
				no = pop(&pilha);
				
				printf("\nNodo de valor %d desempilhado com sucesso!", (*no).valor);
				free(no);
				
				getch();
			break;
			case 4:
				imprime_pilha(pilha);
				
				getch();
			break;
		}
	}
	
	return 0;
}

nodo * cria_nodo(int valor){
	nodo *p;
	p = (nodo *) malloc (sizeof(nodo));
	p->valor = valor;
	p->prox = NULL;
	return p;
}

void empilha_nodo(nodo **topo, nodo *no){
	if(*topo == NULL){
		*topo = no;
	}else{
		no->prox = *topo;
		*topo = no;
	}
}

nodo * push(nodo **topo, nodo *no){
	if(*topo == NULL){
		*topo = no;
	}else{
		no->prox = *topo;
		*topo = no;
	}
	return *topo;
}

nodo * push_int(nodo **topo, int valor){
	nodo * no = cria_nodo(valor);
	if(*topo == NULL){
		*topo = no;
	}else{
		no->prox = *topo;
		*topo = no;
	}
	return *topo;
}

int desempilha_nodo(nodo **topo){
	nodo *aux = *topo;
	int valor;
	if(aux == NULL){
		printf("PILHA VAZIA!");
		return;
	}else{
		valor = aux->valor;
		aux = *topo;
		*topo = (*topo)->prox;
		free(aux);
		return valor;
	}
}

nodo * pop(nodo **topo){
	nodo *aux = *topo;
	if(aux == NULL){
		printf("PILHA VAZIA!");
		return NULL;
	}else{		
		aux = *topo;
		*topo = (*topo)->prox;		
		return aux;
	}
}

void imprime_pilha(nodo *topo){
	nodo *aux = topo;
	if(aux == NULL)
		printf("PILHA VAZIA!");

	while(aux != NULL){
		printf("%d ",aux->valor);
		aux = aux->prox;
	}
}

void imprime_pilha_real(nodo **topo){	
	nodo *pilha_temp = NULL;
	int value;
	
	if (*topo == NULL)
		printf("PILHA VAZIA!");

	while(*topo != NULL){
		value = desempilha_nodo(&topo);
		empilha_nodo(&pilha_temp,cria_nodo(value));
		printf("%d",value);		
	}
	while(pilha_temp != NULL){
		value = desempilha_nodo(pilha_temp);
		empilha_nodo(&topo,cria_nodo(value));		
	}
	
}
