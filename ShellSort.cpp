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
	long int vet[100000];
	clock_t tempo;
	
	// Criando um vetor totalmente ordenado crescentemente
	criarVetorOrdenadoCrescente(vet);
	
	// Contar o tempo inicial
	tempo = clock();
	
	// Ordenar o vetor e calcular o tempo gasto
	shellSort(vet, 100000);
	tempo = clock();
	
	// Imprimir o tempo gasto pela ordenação
	printf("Tempo gasto para ordenar um vetor ordenado crescentemente: %f s\n\n", (double)tempo/CLOCKS_PER_SEC);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Criando um vetor totalmente ordenado decrescentemente
	criarVetorOrdenadoDecrescente(vet);
	
	// Contar o tempo inicial
	tempo = clock();
	
	// Ordenar o vetor e calcular o tempo gasto
	shellSort(vet, 100000);
	tempo = clock();
	
	// Imprimir o tempo gasto pela ordenação
	printf("Tempo gasto para ordenar um vetor ordenado decrescentemente: %f s\n\n", (double)tempo/CLOCKS_PER_SEC);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Criando um vetor totalmente ordenado metade crescente metade decrescente
	criarVetorCrescenteDecrescente(vet);
	
	// Contar o tempo inicial
	tempo = clock();
	
	// Ordenar o vetor e calcular o tempo gasto
	shellSort(vet, 100000);
	tempo = clock();
	
	// Imprimir o tempo gasto pela ordenação
	printf("Tempo gasto para ordenar um vetor metade crescente metade decrescente: %f s\n\n", (double)tempo/CLOCKS_PER_SEC);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Criando um vetor totalmente ordenado metade decrescentemente metade crescente
	criarVetorDecrescenteCrescente(vet);
	
	// Contar o tempo inicial
	tempo = clock();
	
	// Ordenar o vetor e calcular o tempo gasto
	shellSort(vet, 100000);
	tempo = clock();
	
	// Imprimir o tempo gasto pela ordenação
	printf("Tempo gasto para ordenar um vetor ordenado metade decrescentemente metade crescente: %f s\n\n", (double)tempo/CLOCKS_PER_SEC);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Criando um vetor totalmente desordenado
	criarVetorDecrescenteCrescente(vet);
	
	// Contar o tempo inicial
	tempo = clock();
	
	// Ordenar o vetor e calcular o tempo gasto
	shellSort(vet, 100000);
	tempo = clock();
	
	// Imprimir o tempo gasto pela ordenação
	printf("Tempo gasto para ordenar um vetor desordenado: %f s\n\n", (double)tempo/CLOCKS_PER_SEC);
	
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
