#include <stdio.h>

int main(int argc, char const *argv[])
{
	int valor = 10;
	int *pontValor = &valor;
	printf("Valor = %d\n", valor);
	printf("Hexadecimal pontValor = %x\n", pontValor);
	printf("*pontValor = %d\n", *pontValor);
	return 0;
}
