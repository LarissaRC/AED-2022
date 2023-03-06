#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef char * string;

void troca_char(string str, int p1, int p2)
{
  char tmp;
  tmp = str[p1]; 
  str[p1] = str[p2]; 
  str[p2] = tmp;
}

void permutacao_recursiva(string str, int k)
{
  int i, len;
  len = strlen(str);

  if (k == len) 
    printf( "%s\n", str);
  else 
  {
    for (i = k; i < len; i++) 
    {
      troca_char(str, k, i);
      permutacao_recursiva(str, k + 1);
      troca_char(str, i, k);
    }
  }
}

void lista_permutacoes(string str)
{
  permutacao_recursiva(str, 0);
}

void main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
  char lista[] = "ABC";
  lista_permutacoes(lista);
}
