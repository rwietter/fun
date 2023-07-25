/* programa que le um numero e imprime seu fatorial (versão 2) */
#include <stdio.h>
int fat (int n);

int main (void)
{
	int n, r;
	scanf("%d", &n);
	r = fat(n);
	printf("Fatorial = %d\n", r);
	return 0;
}

/* funcao para calcular o valor do fatorial */
int fat (int n)
{
	int i;
	int f = 1;
	for (i = 1; i <= n; i++)
		f *= i;
	return f;
}
