#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
    int conteudo;
    struct nodo *prox;
}no;

no * criarNo(int conteudo);
no * inserirNodosFinal(no **lista, int conteudo);
no * inserirNodosInicio(no **lista, int conteudo);
no * inserirNodosPosicao(no **lista, int conteudo, int posicao);
no * removerNodos(no **lista, int conteudo);
int busca(no *prim, int chave);
void imprimirLista(no *lista);
void imprimirReverse(no *lista);
void imprimeListaRecursiva(no *lista);

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
		printf("4 - Inserir Nodo em uma posição\n");
		printf("5 - Remover Nodos\n");
		printf("6 - Buscar Nodo\n");
		printf("7 - Imprimir lista\n");
		printf("8 - Imprimir lista reversa\n");
		printf("9 - imprimir lista com recursividade\n");
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
				printf("\nConteúdo a ser inserido: ");
				scanf("%d", &conteudo);
				printf("\nPosição da Lista onde inserir ítem: ");
				scanf("%d", &posicao);
				lista = inserirNodosPosicao(&lista, conteudo, posicao);
				
				printf("\nÍtem inserido com sucesso!");
				getch();
			break;
			case 5:
				printf("\nConteúdo a ser removido: ");
				scanf("%d", &conteudo);
				lista = removerNodos(&lista, conteudo);
				
				getch();
			break;
			case 6:
				printf("\nChave: ");
				scanf("%d", &conteudo);
				if(busca(lista, conteudo) == 1){
					printf("\nO ítem %d está contido na lista!", conteudo);
				} else {
					printf("\nO ítem %d não está contido na lista!", conteudo);
				}
				getch();
			break;
			case 7:
				imprimirLista(lista);
				getch();
			break;
			case 8:
				imprimirReverse(lista);
				getch();
			break;
			case 9:
				imprimeListaRecursiva(lista);
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

no * inserirNodosInicio(no **lista, int conteudo){
    no *inicio, *p;

    if (*lista==NULL){
        p = criarNo(conteudo);
        inicio = *lista = p;
    } else {
        p = criarNo(conteudo);
        p->prox = *lista;
        inicio = p;
    }
    return inicio;
}

no * inserirNodosPosicao(no **lista, int conteudo, int posicao){
    no *inicio, *p, *ant;
    ant = inicio = *lista;
    int pos=1;
    if (*lista==NULL){
        p = criarNo(conteudo);
        inicio = *lista = p;
    } else {
        if (posicao==1){
            p = criarNo(conteudo);
            p->prox = *lista;
            inicio = p;
        } else {
            while (pos != (posicao-1) && ant->prox !=NULL){
                ant = ant->prox;
                pos++;
            }
            p = criarNo(conteudo);
            if (ant->prox==NULL){
                ant->prox = p;
            } else {
                p->prox = ant->prox;
                ant->prox = p;
            }
        }
    }
    return inicio;
}

no * removerNodos(no **lista, int conteudo){
    no *ant, *aux, *inicio;
    inicio = aux = ant = *lista;

    if (aux->conteudo == conteudo) {
        aux = aux->prox;
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
                aux->prox = NULL;
                free(aux);
                printf("\nElemento %d removido",conteudo);
            } else if (aux->prox == NULL) {
                ant->prox = NULL;
                free(aux);
                printf("\nElemento %d removido",conteudo);
            }
        } else {
            printf("\nElemento Inexistente!!");
        }
    }
    return inicio;
}

void imprimirLista(no *lista){
	no * aux = lista;
    while (aux!=NULL){
        printf(" : %d", aux->conteudo);
        aux = aux->prox;
    }
}

void imprimeListaRecursiva(no *lista)
{
    if (lista != NULL)   {
        printf(" : %d", lista->conteudo);
        imprimeListaRecursiva(lista->prox);
    }
}

void imprimirReverse(no *lista){
    if (lista!=NULL){
        imprimirReverse(lista->prox);
        printf(" : %d", lista->conteudo);
    }
}

int busca(no *prim, int chave){
    while (prim!=NULL){
        if (prim->conteudo==chave)
            return 1;
        prim = prim->prox;
    }
    return 0;
}
