#include <stdio.h>

int acum(int n)
{
	printf("Acumulador progressivo ... %d\n", n);
	if (n == 1)
		return 1;
	return n + acum(n-1);
}

int cont(int n)
{
	printf("Contagem progressiva ... %d\n", n);
	if (n == 1)
		return 1;
	return 1 + cont(n-1);
}

main()
{
	printf("%d",acum(10));
	puts("");
	printf("%d",cont(10));
}
