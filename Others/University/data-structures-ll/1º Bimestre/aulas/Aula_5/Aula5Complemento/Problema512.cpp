//Problema 2
//Faça uma função recursiva que calcule e retorne o 
//N-ésimo termo da sequência Fibonacci. Alguns números 
//desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...

#include <stdio.h>

int a = 0;
int b = 1;
int prox;

/*F0 = 0
F1 = 1
Fn = Fn - 1 + Fn - 2, para n > 1*/


int fibonacci(int n) { 
	printf("%d\n",n);
	if (n == 0 || n == 1)
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}
     
main() {
	int qtermos = 20;
	int i;
	printf("%d",fibonacci(6));
	/*for(i=0;i<qtermos;i++) {
		prox = a + b;
		printf("%d\n", prox);	
		a = b;
		b = prox;
	}*/
}


