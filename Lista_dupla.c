#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
    int conteudo;
    struct nodo *prox;
    struct nodo *ant;
}no;

no * criarNo(int conteudo);
no * inserirNodosFinal(no **lista, int conteudo);
no * inserirNodosInicio(no **lista, int conteudo);
no * removerNodos(no **lista, int conteudo);
int busca(no *prim, int chave);
void imprimirLista(no *lista);
void imprimirReverse(no *lista);
void imprimeListaRecursiva(no *lista);
void imprimirListaDupla(no *lista);
no * Josephus(no **lista_item, int posicao);

int main(){
	int op = -1;
	no * lista = NULL, *nodo = NULL;
	int conteudo, posicao;
	
	while (op != 10){
		system("cls");
		
		printf("******** Menu ********\n\n");
		printf("1 - Criar Nodo\n");
		printf("2 - Inserir Nodo no final\n");
		printf("3 - Inserir Nodo no inicio\n");
		printf("4 - Remover Nodos\n");
		printf("5 - Buscar Nodo\n");
		printf("6 - Imprimir lista\n");
		printf("7 - Imprimir lista reversa\n");
		printf("8 - Imprimir lista com recursividade\n");
		printf("9 - Imprimir lista nos dois sentidos\n");
		printf("10 - Sair\n\n");
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
				printf("\nConteúdo a ser inserido: ");
				scanf("%d", &conteudo);
				lista = inserirNodosFinal(&lista, conteudo);
				
				printf("\nÍtem inserido com sucesso!");
				getch();
			break;
			case 3:
				printf("\nConteúdo a ser inserido: ");
				scanf("%d", &conteudo);
				lista = inserirNodosInicio(&lista, conteudo);
				
				printf("\nÍtem inserido com sucesso!");
				getch();
			break;
			case 4:
				printf("\nConteúdo a ser removido: ");
				scanf("%d", &conteudo);
				lista = removerNodos(&lista, conteudo);
				
				getch();
			break;
			case 5:
				printf("\nChave: ");
				scanf("%d", &conteudo);
				if(busca(lista, conteudo) == 1){
					printf("\nO ítem %d está contido na lista!", conteudo);
				} else {
					printf("\nO ítem %d não está contido na lista!", conteudo);
				}
				getch();
			break;
			case 6:
				imprimirLista(lista);
				getch();
			break;
			case 7:
				imprimirReverse(lista);
				getch();
			break;
			case 8:
				imprimeListaRecursiva(lista);
				getch();
			break;
			case 9:
				imprimirListaDupla(lista);
				getch();
			break;
		}
	}
	
	return 0;
}

no * criarNo(int conteudo){
    no *novo = (no *) malloc(sizeof(no));
    novo->conteudo = conteudo;
    novo->ant = NULL;
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
        p->ant = *lista;
    }
    return inicio;
}

no * inserirNodosInicio(no **lista, int conteudo){
    no *inicio, *p;

    if (*lista==NULL){
        p = criarNo(conteudo);
        inicio = *lista = p;
    } else {
        inicio = *lista;
        p = criarNo(conteudo);
        p->prox = inicio;
        inicio->ant = p;
        inicio = p;
    }
    return inicio;
}

no * removerNodos(no **lista, int conteudo){
    no *ant, *aux, *inicio;
    inicio = aux = ant = *lista;

    if (aux->conteudo == conteudo) {
        aux = aux->prox;
        aux->ant = NULL;
        ant->prox = NULL;
        free(ant);
        inicio = aux;
        printf("\nElemento %d removido",conteudo);
    } else {
        while (aux->conteudo != conteudo && aux->prox !=NULL){
            ant = aux;
            aux = aux->prox;
        }

        if (aux->conteudo == conteudo){
            if (aux->prox !=NULL){
                ant->prox = aux->prox;
                aux->prox->ant = ant;
                aux->prox = NULL;
                aux->ant = NULL;
                free(aux);
                printf("\nElemento %d removido",conteudo);
            } else if (aux->prox == NULL) {
                ant->prox = NULL;
                aux->ant = NULL;
                free(aux);
                printf("\nElemento %d removido",conteudo);
            }
        } else {
            printf("\nElemento Inexistente!!");
        }
    }
    return inicio;
}

int busca(no *prim, int chave){
    while (prim!=NULL){
        if (prim->conteudo==chave)
            return 1;
        prim = prim->prox;
    }
    return 0;
}

void imprimirLista(no *lista){
	no * aux = lista;
    while (aux!=NULL){
        printf(" : %d", aux->conteudo);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimirListaDupla(no *lista){
    no *ant, *aux;
    ant = aux = lista;
    while (aux!=NULL){
        printf(" : %d", aux->conteudo);
        ant = aux;
        aux = aux->prox;
    }
    printf("\n");
    aux = ant;
    while (aux!=NULL){
        printf(" : %d", aux->conteudo);
        aux = aux->ant;
    }
}


void imprimeListaRecursiva(no *lista)
{
    if (lista == NULL)
        return;
    printf(" : %d", lista->conteudo);
    imprimeListaRecursiva(lista->prox);
}

void imprimirReverse(no *lista){
    if (lista==NULL)
    	return;
    imprimirReverse(lista->prox);
    printf(" : %d", lista->conteudo);
}

no * Josephus(no **lista_item, int posicao){
    no *ant, *aux, *inicio;
    inicio = aux = ant = *lista_item;
    int posicao_atual = 0;
    while (inicio->prox!=NULL){
    if (posicao == posicao_atual) {
        aux = aux->prox;
        aux->ant = NULL;
        ant->prox = NULL;
        printf("Elemento removido %d\n",ant->conteudo);
        free(ant);
        posicao_atual = 1;
        inicio = aux;
    } else {
        while (posicao_atual != posicao){
            ant = aux;
            if (aux->prox == NULL) {
                aux = inicio;
            } else aux = aux->prox;
            posicao_atual++;
        }
        if (ant->prox == NULL) {
            ant = aux;
            aux = aux->prox;
            aux->ant = NULL;
            ant->prox = NULL;
            printf("Elemento removido %d\n",ant->conteudo);
            free(ant);
            inicio = aux;
        } else if (aux->prox == NULL){
            ant->prox = NULL;
            aux->ant = NULL;
            printf("Elemento removido %d\n",aux->conteudo);
            free(aux);
            aux = inicio;
        } else {
            ant->prox = aux->prox;
            aux->prox->ant = ant;
            aux->prox = NULL;
            aux->ant = NULL;
            printf("Elemento removido %d\n",aux->conteudo);
            free(aux);
            aux = ant->prox;
        }
        posicao_atual = 1;
    }
    }
    return inicio;
}
