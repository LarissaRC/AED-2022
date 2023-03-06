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
	
   // printf("Permuta��o de 6 � %d\n",permutacao(6));
   // printf("Arranjo de 6,2 � %d\n",arranjo(6,2));
   // printf("Combina��o de 6,2 � %d\n\n",combinacao(6,2));
   
   // questions();
   
   // Sandu�ches
   printf("1 recheio: %d possibilidades\n", combinacao(5,1));
   printf("2 recheios: %d possibilidades\n", combinacao(5,2));
   printf("3 recheios: %d possibilidades\n", combinacao(5,3));
   printf("4 recheios: %d possibilidades\n", combinacao(5,4));
   printf("5 recheios: %d possibilidades\n", combinacao(5,5));
   printf("Resposta: %d\n\n", 31*3*2);
   
   // Apertos de m�o
   printf("Havia %d ministros, por isso houve %d apertos de m�o.\n\n", 6, combinacao(6,2));
   
   // Senha de 4 d�gitos
   printf("Marla poderia criar at� %d senhas.\n\n", 10*9*8*7);
   
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

	// 1) Quantas autom�veis  a mais podem ser emplacados, mudando-se o n�mero de letras de 2 para 3?
	// Como h� repeti��es de letra, n�o podemos resolver por arranjo. Usaremos os conceitos vistos para resolver:
	// Placa com 2 letras e 4 n�meros: 26 x 26 x 10 x 10 x 10 x 10 = 6.760.000
	// Placa com 3 letras e 4 n�meros: 26 x 26 x 26 x 10 x 10 x 10 x 10 = 175.760.000
	// Total = 175760000 - 6760000 = 169.000.000 ve�culos
	
	// 2) Quantos abra�os entre duas pessoas podemos ter em uma confraterniza��o de ano novo, em um lugar com 10 pessoas?
	printf("Total de abra�os = %d\n", combinacao(10,2));
	
	// 3) Quantos times podemos ter classificados para a Ta�a Libertadores da Am�rica, se o campeonato tem 24 clubes e 4 vagas?
	printf("Libertadores = %d\n", combinacao(20,4));
	
	// 4) Quantas maneiras distintas podemos ter um p�dio de uma competi��o de nado de costas em uma olimp�ada, sendo 32 competidores?
	printf("P�dio = %d\n", arranjo(32,3));
	
	// 5) Quantas maneiras podemos escrever a palavra ARARA?
	// Como h� repeti��es, n�o podemos resolver por permuta��o simples. 
	// Fazemos a repeti��o normal e depois dividimos pelas repeti��es: 5!/(3!*2!) = 120/(6*4) = 5.
	
	// 6) Uma prova de Matem�tica consta de 10 quest�es do tipo V ou F. De quantas maneiras distintas ela pode ser resolvida?
	// Repeti��o, pois podemos usar V ou F quantas vezes quiser. Logo = 2x2x2x2x2x2x2x2x2x2 = 1024.
	
	// 7) Qual a chance de um apostador ganhar a Mega-Sena, apostando 6 n�meros, sendo 6 sorteados e 60 no total?
	printf("Chances = 1 entre %d\n", combinacao(60,6));
	// 1 entre 50.063.860 possibilidades!!!!!!!!
	
	// 8) Qual a chance de um apostador ganhar a Mega-Sena, se a aposta fosse com 15 n�meros, 15 sorteados e 60 no total?
	printf("Chances = 1 entre %d\n", combinacao(60,15));
	// 1 entre 53.194.089.192.720 possibilidades .......
	
	// 9) Qual a chance de um apostador ganhar a Mega-Sena, apostando 15 n�meros, sendo 6 sorteados e 60 no total?
	printf("Chances = 1 entre %d\n", combinacao(60,6)/combinacao(15,6));
	// 1 entre 10.003 possibilidades!!
	// Note que a caixa cobra R$ 1,50 pela aposta por 6 n�meros e R$ 7.507,50 pelos 15, ou seja, 5005 vezes mais caro.
	// 5005 � o valor de combinacao(15,6).
	
	// 10) Uma turma tem 15 alunos, sendo 9 meninos e 6 meninas. Em um grupo de 4, quantos tem pelo menos 1 menino?
	printf("Meninos = %d\n", combinacao(15,4)-combinacao(6,4));
	
	// 11) Quantos jogos haver�o em um torneio com 12 participantes, onde cada time joga com outro em turno e returno?
	printf("Jogos = %d\n", combinacao(12,2)*2);
}

/*
Permuta��o busca analisar de quantas maneiras podemos organizar um grupo de n elementos, usando todos os elementos.

  Por exemplo, imaginemos tr�s poltronas vazias no cinema. De quantas maneiras tr�s pessoas podem se sentar?
  Seja o conjunto pessoas = {A, B, C}.
  Combina��es poss�veis:
	A,B,C
	A,C,B
	B,A,C
	B,C,A
	C,A,B
	C,B,A
  S�o 6 comina��es poss�veis.
  
  P(n) = n!
  ou
  P(n) = n x (n-1) x (n-2) x ... x 1
*/

/*
O arranjo s�o as combina��es poss�veis de um sub-grupo de dado grupo, onde a ordem dos elementos � levada em conta.

  Exemplo: seja uma corrida com 5 competidores. De quantas maneiras podemos ter os 3 primeiros colocados?
  Temos 5 possibilidades para o primeiro colocado, 4 possibilidades para o segundo e 3 possibilidades para o terceiro.
  Assim, a resposta � 5x4x3 = 60.
  
  A(n,p) = n! / (n-p)!
*/

/*
A combina��o � quase a mesma coisa que o arranjo. A diferen�a � que na combina��o, a ordem dos elementos do sub-grupo n�o � importante.
Basta que ocorra exatamente uma vez!

  Por exemplo, em um grupo de 10 pessoas, se desejarmos saber quantos abra�os entre 2 pessoas haver�o no total, o abra�o de
  Jo�o com M�rcia � o mesmo que o abra�o de M�rcia com Jo�o. Os dois ser�o computados como um s�.
  
  C(n,p) = n! / (p! x (n-p)!)
  ou
  C(n,p) = A(n,p) / p!
*/
