#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
    int conteudo;
    struct nodo *prox;
}no;

no * criarNo(int conteudo);
void inqueue(no **cabeca, no **fim, int conteudo);
void inqueueNo(no **cabeca, no **fim, no *p);
no *dequeue(no **cabeca);
void imprimirFila(no *fila);

int main(){
	int op = -1;
	no * cabeca = NULL, * fim = NULL, *nodo = NULL;
	int conteudo;
	
	while (op != 5){
		system("cls");
		
		printf("******** Menu ********\n\n");
		printf("1 - Criar Nodo\n");
		printf("2 - Adicionar um ítem na fila\n");
		printf("3 - Remover um ítem da fila\n");
		printf("4 - Imprimir fila\n");
		printf("5 - Sair\n\n");
		printf("Opção: ");
		
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nConteúdo a ser criado: ");
				scanf("%d", &conteudo);
				nodo = criarNo(conteudo);
				
				printf("\nNodo com o valor %d criado", (*nodo).conteudo);
				getch();
			break;
			case 2:
				printf("\nConteúdo a ser criado: ");
				scanf("%d", &conteudo);
				inqueue(&cabeca, &fim, conteudo);
				
				printf("\nÍtem inserido na fila com sucesso!");
				getch();
			break;
			case 3:
				if(cabeca != NULL){
					nodo = dequeue(&cabeca);
					printf("Ítem de valor %d removido comsucesso!", (*nodo).conteudo);
					getch();
				} else {
					printf("Não há ítens na fila.");
					getch();
				}
			break;
			case 4:
				imprimirFila(cabeca);
				getch();
			break;
		}
	}
	
	return 0;
}

no * criarNo(int conteudo){
    no *novo = (no *) malloc(sizeof(no));
    novo->conteudo = conteudo;
    novo->prox = NULL;
    return novo;
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

void inqueueNo(no **cabeca, no**fim, no *p){
    if (*cabeca==NULL){
        *fim = *cabeca = p;
    } else {
        (*fim)->prox = p;
        *fim = p;
    }
}

no *dequeue(no **cabeca){
    no *atual;
    atual = *cabeca;
    if (*cabeca!=NULL) {
        *cabeca =  (*cabeca)->prox;
        atual->prox = NULL;
    }
    return atual;
}

void imprimirFila(no *fila){
	no * aux = fila;
    while (aux!=NULL){
        printf(" : %d", aux->conteudo);
        aux = aux->prox;
    }
}
void imprimirFilaReal1(no *cabeca, no *fim){
    no *aux, *p;
    aux = NULL;
    while (cabeca!=NULL && cabeca!=aux){
        p = dequeue(&cabeca);
        if (aux==NULL){
            aux = p;
        }
        printf(" : %d ",p->conteudo);
        inqueueNo(&cabeca, &fim, p);
    }
}

void imprimirFilaReal2(no *cabeca, no *fim){
    no *p, *cabeca_2 = NULL, *fim_2 = NULL;
    while (cabeca!=NULL){
        p = dequeue(&cabeca);
        printf(" : %d ",p->conteudo);
        inqueueNo(&cabeca_2, &fim_2, p);
    }
    cabeca = cabeca_2;
    fim = fim_2;
}
