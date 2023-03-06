#include <stdio.h>
#include <locale.h>

int fatorial(int n)
{
   if (n>0)
      return n*fatorial(n-1);
   else
      return 1;
}

int permutacao(int n)
{
  return fatorial(n);
}

int arranjo(int n, int p)
{
  if (p>1)
      return n*arranjo(n-1,p-1);
   else
      return n;
}

int combinacao(int n, int p)
{
   return arranjo(n,p)/fatorial(p);
}

main()
{
	setlocale(LC_ALL, "Portuguese");
	
   // printf("Permutação de 6 é %d\n",permutacao(6));
   // printf("Arranjo de 6,2 é %d\n",arranjo(6,2));
   // printf("Combinação de 6,2 é %d\n\n",combinacao(6,2));
   
   // questions();
   
   // Sanduíches
   printf("1 recheio: %d possibilidades\n", combinacao(5,1));
   printf("2 recheios: %d possibilidades\n", combinacao(5,2));
   printf("3 recheios: %d possibilidades\n", combinacao(5,3));
   printf("4 recheios: %d possibilidades\n", combinacao(5,4));
   printf("5 recheios: %d possibilidades\n", combinacao(5,5));
   printf("Resposta: %d\n\n", 31*3*2);
   
   // Apertos de mão
   printf("Havia %d ministros, por isso houve %d apertos de mão.\n\n", 6, combinacao(6,2));
   
   // Senha de 4 dígitos
   printf("Marla poderia criar até %d senhas.\n\n", 10*9*8*7);
   
   // Bolas
   // 4 vermelhas
   // 3 amarelas
   // 2 azuis
   // 1 verde
   int resp = fatorial(10)/(fatorial(4)*fatorial(3)*fatorial(2));
   printf("Podemos ter %d colunas distintas com estas bolas.", resp);
   
   return 0;
}

void questions(){

	// 1) Quantas automóveis  a mais podem ser emplacados, mudando-se o número de letras de 2 para 3?
	// Como há repetições de letra, não podemos resolver por arranjo. Usaremos os conceitos vistos para resolver:
	// Placa com 2 letras e 4 números: 26 x 26 x 10 x 10 x 10 x 10 = 6.760.000
	// Placa com 3 letras e 4 números: 26 x 26 x 26 x 10 x 10 x 10 x 10 = 175.760.000
	// Total = 175760000 - 6760000 = 169.000.000 veículos
	
	// 2) Quantos abraços entre duas pessoas podemos ter em uma confraternização de ano novo, em um lugar com 10 pessoas?
	printf("Total de abraços = %d\n", combinacao(10,2));
	
	// 3) Quantos times podemos ter classificados para a Taça Libertadores da América, se o campeonato tem 24 clubes e 4 vagas?
	printf("Libertadores = %d\n", combinacao(20,4));
	
	// 4) Quantas maneiras distintas podemos ter um pódio de uma competição de nado de costas em uma olimpíada, sendo 32 competidores?
	printf("Pódio = %d\n", arranjo(32,3));
	
	// 5) Quantas maneiras podemos escrever a palavra ARARA?
	// Como há repetições, não podemos resolver por permutação simples. 
	// Fazemos a repetição normal e depois dividimos pelas repetições: 5!/(3!*2!) = 120/(6*4) = 5.
	
	// 6) Uma prova de Matemática consta de 10 questões do tipo V ou F. De quantas maneiras distintas ela pode ser resolvida?
	// Repetição, pois podemos usar V ou F quantas vezes quiser. Logo = 2x2x2x2x2x2x2x2x2x2 = 1024.
	
	// 7) Qual a chance de um apostador ganhar a Mega-Sena, apostando 6 números, sendo 6 sorteados e 60 no total?
	printf("Chances = 1 entre %d\n", combinacao(60,6));
	// 1 entre 50.063.860 possibilidades!!!!!!!!
	
	// 8) Qual a chance de um apostador ganhar a Mega-Sena, se a aposta fosse com 15 números, 15 sorteados e 60 no total?
	printf("Chances = 1 entre %d\n", combinacao(60,15));
	// 1 entre 53.194.089.192.720 possibilidades .......
	
	// 9) Qual a chance de um apostador ganhar a Mega-Sena, apostando 15 números, sendo 6 sorteados e 60 no total?
	printf("Chances = 1 entre %d\n", combinacao(60,6)/combinacao(15,6));
	// 1 entre 10.003 possibilidades!!
	// Note que a caixa cobra R$ 1,50 pela aposta por 6 números e R$ 7.507,50 pelos 15, ou seja, 5005 vezes mais caro.
	// 5005 é o valor de combinacao(15,6).
	
	// 10) Uma turma tem 15 alunos, sendo 9 meninos e 6 meninas. Em um grupo de 4, quantos tem pelo menos 1 menino?
	printf("Meninos = %d\n", combinacao(15,4)-combinacao(6,4));
	
	// 11) Quantos jogos haverão em um torneio com 12 participantes, onde cada time joga com outro em turno e returno?
	printf("Jogos = %d\n", combinacao(12,2)*2);
}

/*
Permutação busca analisar de quantas maneiras podemos organizar um grupo de n elementos, usando todos os elementos.

  Por exemplo, imaginemos três poltronas vazias no cinema. De quantas maneiras três pessoas podem se sentar?
  Seja o conjunto pessoas = {A, B, C}.
  Combinações possíveis:
	A,B,C
	A,C,B
	B,A,C
	B,C,A
	C,A,B
	C,B,A
  São 6 cominações possíveis.
  
  P(n) = n!
  ou
  P(n) = n x (n-1) x (n-2) x ... x 1
*/

/*
O arranjo são as combinações possíveis de um sub-grupo de dado grupo, onde a ordem dos elementos é levada em conta.

  Exemplo: seja uma corrida com 5 competidores. De quantas maneiras podemos ter os 3 primeiros colocados?
  Temos 5 possibilidades para o primeiro colocado, 4 possibilidades para o segundo e 3 possibilidades para o terceiro.
  Assim, a resposta é 5x4x3 = 60.
  
  A(n,p) = n! / (n-p)!
*/

/*
A combinação é quase a mesma coisa que o arranjo. A diferença é que na combinação, a ordem dos elementos do sub-grupo não é importante.
Basta que ocorra exatamente uma vez!

  Por exemplo, em um grupo de 10 pessoas, se desejarmos saber quantos abraços entre 2 pessoas haverão no total, o abraço de
  João com Márcia é o mesmo que o abraço de Márcia com João. Os dois serão computados como um só.
  
  C(n,p) = n! / (p! x (n-p)!)
  ou
  C(n,p) = A(n,p) / p!
*/
