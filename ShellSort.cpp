#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Funções para a inicialização dos vetores
void criarVetorOrdenadoCrescente(long int vet[]);
void criarVetorOrdenadoDecrescente(long int vet[]);
void criarVetorDecrescenteCrescente(long int vet[]);
void criarVetorCrescenteDecrescente(long int vet[]);
void criarVetorDesordenado(long int vet[]);

void imprimirVetor(long int vet[]);

// Método de ordenação Shellsort
void shellSort(long int vet[], int tamanho);

int main() {
	long int vetOrdenadoCrescente[100000],
		vetOrdenadoDecrescente[100000],
		vetDecrescenteCrescente[100000],
		vetCrescenteDecrescente[100000],
		vetDesordenado[100000];
	
	// Inicialização dos vetores
	printf("Vetor ordenado crescentemente sem SHELLSORT\n");
	criarVetorOrdenadoCrescente(vetOrdenadoCrescente);
	imprimirVetor(vetOrdenadoCrescente);
	getch();
	system("cls");
	printf("Vetor ordenado crescentemente com SHELLSORT\n");
	shellSort(vetOrdenadoCrescente, 100000);
	imprimirVetor(vetOrdenadoCrescente);
	getch();
	system("cls");
	
	printf("\nVetor ordenado decrescentemente sem SHELLSORT\n");
	criarVetorOrdenadoDecrescente(vetOrdenadoDecrescente);
	imprimirVetor(vetOrdenadoDecrescente);
	getch();
	printf("Vetor ordenado decrescentemente com SHELLSORT\n");
	shellSort(vetOrdenadoDecrescente, 100000);
	getch();
	imprimirVetor(vetOrdenadoDecrescente);
	getch();
	
	printf("\nVetor ordenado decrescente/crescente sem SHELLSORT\n");
	criarVetorDecrescenteCrescente(vetDecrescenteCrescente);
	imprimirVetor(vetDecrescenteCrescente);
	printf("Vetor ordenado decrescente/crescente com SHELLSORT\n");
	shellSort(vetDecrescenteCrescente, 100000);
	imprimirVetor(vetDecrescenteCrescente);
	getch();
	
	printf("\nVetor ordenado crescente/decrescente sem SHELLSORT\n");
	criarVetorCrescenteDecrescente(vetCrescenteDecrescente);
	imprimirVetor(vetCrescenteDecrescente);
	printf("Vetor ordenado crescente/decrescente com SHELLSORT\n");
	shellSort(vetCrescenteDecrescente, 100000);
	imprimirVetor(vetCrescenteDecrescente);
	getch();
	
	printf("\nVetor desordenado sem SHELLSORT\n");
	criarVetorDesordenado(vetDesordenado);
	imprimirVetor(vetDesordenado);
	printf("Vetor desordenado com SHELLSORT\n");
	shellSort(vetDesordenado, 100000);
	imprimirVetor(vetDesordenado);
	getch();
	
	return 0;
}

void shellSort(long int vet[], int tamanho) {
    long int i, j, valor;
    int h = 1;
    
    // Cálculo do valor de h(s), onde s representa o taamnho do vetor
    for(h = 1; h < tamanho; h = (3 * h + 1));
    
    //
    while(h > 1){
    	h /= 3;
    	for(i = h; i < tamanho; i++){
    		valor = vet[i];
    		j = i - h;
    		
    		while(j >= 0 && valor < vet[j]){
    			vet[j + h] = vet[j];
    			j -= h;
			}
			
			vet[j + h] = valor;
		}
	}
	
	printf("\nFoi\n");
}

// Funções para a inicialização dos vetores
void criarVetorOrdenadoCrescente(long int vet[]){
	for(long int i = 0; i < 100000; i++){
		vet[i] = i + 1;
	}
}

void criarVetorOrdenadoDecrescente(long int vet[]){
	for(long int i = 0; i < 100000; i++){
		vet[i] = 100000 - i;
	}
}

void criarVetorDecrescenteCrescente(long int vet[]){
	for(long int i = 0; i < 5; i++){
		vet[i] = 50000 - i;
	}
	for(long int i = 5; i < 100000; i++){
		vet[i] = i + 1;
	}
}

void criarVetorCrescenteDecrescente(long int vet[]){
	for(long int i = 0; i < 50000; i++){
		vet[i] = i + 1;
		vet[i + 50000] = 100000 - i;
	}
}

void criarVetorDesordenado(long int vet[]){
	long int i, valor;
	
	// Garantir que rand() gere um valor aleatória sempre que rodar o programa
	srand((unsigned)time(NULL));
	
	// Iniciar todas as posições com 0
	for(i = 0; i < 100000; i++){
		vet[i] = 0;
	}
	
	// Adicionar um valor em uma posição aleatória
	for(i = 0; i < 100000; i++){
		
		do{
			valor = rand() % 100000;
		}while(vet[valor] != 0);
		
		vet[valor] = i + 1;
	}
}

void imprimirVetor(long int vet[]){
	for(long int i = 0; i < 100000; i++){
		printf("%dª: %d\n", i+1, vet[i]);
	}
	
	printf("\n");
}
