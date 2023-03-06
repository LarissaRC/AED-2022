#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASIZE 256 

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
        if (memcmp(x, y + j, m) == 0)
            return 1;
        j += qsBc[y[j + m]];
    }
    return 0;
}

void build_suffix_tree(char *str, int len) {
    // Implementação da árvore de sufixos aqui.
}

int longest_common_substring(char *str1, int len1, char *str2, int len2) {
    int max_len = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                // Encontrar o comprimento da substring comum começando em i e j.
                int k = 0;
                while (i + k < len1 && j + k < len2 && str1[i + k] == str2[j + k]) {
                    k++;
                }
                // Atualizar o comprimento máximo encontrado até agora.
                if (k > max_len) {
                    max_len = k;
                }
            }
        }
    }
    return max_len;
}

int main() {
    char str1[51], str2[51];
    int *res, bigger, result;
    res = (int*)calloc(1, sizeof(int));
    while (gets(str1) != NULL && gets(str2) != NULL) {
        // Encontrar a maior substring comum usando o algoritmo de Boyer-Moore.
        bigger = 0;
        for (int i = 1; i <= strlen(str1); i++) {
            for (int j = 0; j < strlen(str1) - i + 1; j++) {
                char substring[i + 1];
                strncpy(substring, str1 + j, i);
                substring[i] = '\0';
                result = BM(substring, strlen(substring), str2, strlen(str2));
                if (result == 1) {
                    if (i > bigger) {
                        bigger = i;
                    }
                }
            }
        }
        // Armazenar o resultado em um array dinâmico.
        res = realloc(res, (size_t)(sizeof(int) * (size + 1)));
        res[size++] = bigger;
    }
    // Imprimir as respostas.
    for (int i = 0; i < size; i++) {
        printf("%d\n", res[i]);
    }
    free(res);
    return 0;
}
