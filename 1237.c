#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASIZE 256 
int size = 0;

void preQsBc(char *x, int m, int qsBc[]) {
int i;
   
	for (i = 0; i < ASIZE; ++i)
		qsBc[i] = m + 1;
   
	for (i = 0; i < m; ++i)
		qsBc[x[i]] = m - i;
}

int BM(char *x, int m, char *y, int n) {
	int j, qsBc[ASIZE];
 
	preQsBc(x, m, qsBc);
 
	j = 0;
	
	while (j <= n - m) {
		if (memcmp(x, y + j, m) == 0) {
			return 1;
		}
		j += qsBc[y[j + m]];
	}
	
	return 0;
}

int main() {
	char frase_1[51], frase_2[51], aux[51];
	int res[50], bigger, result;
	
	while(1){
		// Reading the phrases
		fgets(frase_1, 51, stdin);
		if(strlen(frase_1) == 1) break;
		fgets(frase_2, 51, stdin);
		if(strlen(frase_2) == 1) break;
		
		// Checking the substrings
		strncpy(aux, frase_2, 50);
		bigger = 0;
		for(int i = 1; i <= strlen(frase_1); i++){
			for(int j = 0; j < strlen(frase_1) - i + 1; j++){
				// Creating each substring
				char substring[i+1];
				for(int k = 0; k < i; k++){
					
					if(frase_1[k+j] != '\n')
						substring[k] = frase_1[k+j];
				}
				
				// Verifying if the substring exists in the other string
				result = BM(substring, strlen(substring), frase_2, strlen(frase_2)-1);
				if(result == 1)
					if(strlen(substring) > bigger){
						bigger = strlen(substring);
					}
			}
		}
		
		size++;
		res[size-1] = bigger;
		printf("Bigger: %d\n", bigger);
	}
	
	// Print answers
	for(int i = 0; i < size; i++){
		printf("%d\n", res[i]);
	}
   
	return 0;
}
