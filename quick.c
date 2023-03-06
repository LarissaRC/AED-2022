#include <stdio.h>
#include <string.h>

#define ASIZE 256 


void preQsBc(char *x, int m, int qsBc[]) {
int i;
   
	for (i = 0; i < ASIZE; ++i)
		qsBc[i] = m + 1;
   
	for (i = 0; i < m; ++i)
		qsBc[x[i]] = m - i;
}

void BM(char *x, int m, char *y, int n) {
	int j, qsBc[ASIZE];
 
	preQsBc(x, m, qsBc);
	
	printf("%d %d\n", qsBc['A'], qsBc['N']);
 
	j = 0;

	while (j <= n - m) {
		if (memcmp(x, y + j, m) == 0) {
			printf("Pattern found at index %d\n", j);
		}
		j += qsBc[y[j + m]];
	}
}

int main() {
	//char *y = "GCATCGCAGAGAGTATACAGTACGGCAGAGAGGTTAGTGAATGCAGAGAG";
	//char *x = "GCAGAGAG";
   
	//char *y = "GATOMELBANANAMELRATOMEL";
	//char *x = "MEL";
	char *y = "ANABANANA";
	char *x = "ANA";
   
	BM(x, strlen(x), y, strlen(y));
   
return 0;
}
