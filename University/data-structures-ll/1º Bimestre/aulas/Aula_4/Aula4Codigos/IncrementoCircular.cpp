#include <stdio.h>

// Para essa implementação, os índices do vetor são incrementados de maneira que seus
// valores progridam “circularmente”. Desta forma, se temos 100 posições no vetor, os
// valores dos índices assumem os seguintes valores:

// 0, 1, 2, 3, …, 98, 99, 0, 1, 2, 3, …, 98, 99, 0, 1,…

// Podemos definir uma função auxiliar responsável por incrementar o valor de um índice.
// Essa função recebe o valor do índice atual e fornece com valor de retorno o índice
// incrementado, usando o incremento circular. Uma possível implementação dessa função
// é:

# define N 20

int incr (int i)
{
	if (i == N-1)
		return 0;
	else
		return i+1;
}

// Essa mesma função pode ser implementada de uma forma mais compacta, usando o
// operador módulo:

int incrC(int i)
{
	return (i+1)%N;
}

// Com o uso do operador módulo, muitas vezes optamos inclusive por dispensar a função
// auxiliar e escrever diretamente o incremento circular:
// ...
// i=(i+1)%N;
// ...

main() {
	int j=0; int i = 0;
	for(j=0;j<50;j++) {
		i = incrC(i);
		printf("%d\n",i);
	}
		
}
