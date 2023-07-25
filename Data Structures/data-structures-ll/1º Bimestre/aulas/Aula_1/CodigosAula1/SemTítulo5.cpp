//Um número será quadrado perfeito quando respeitar 
//a regra de formação: n2= a. Nessa regra, n é 
//qualquer número inteiro positivo e a é o 
//número quadrado perfeito.

#include <stdio.h>
#include <math.h>

int n, a;

main() {
	scanf("%d",&a);
	n = sqrt(a);
	if ((n*n) == a) // n2= a
		printf("%d eh um quadrado perfeito",n);
	else
		puts("nao eh");	
}
