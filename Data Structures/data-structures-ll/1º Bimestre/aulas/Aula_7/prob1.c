#include <stdio.h>
#include <stdlib.h>

int tam;
int lista_circular[10] = {1,2,3,4,5,6,7,8,9,10};
int intervalor = 3;
int pos = 0;
#define TAM 10

int main(int argc, char const *argv[])
{
	int aux = 1;
	int mortos;
	int vivo=0;
	do
	{
		if (aux == 3)
		{
			printf("mortos: %d\n", lista_circular[pos]);
			lista_circular[pos] = -1;
			aux = 0;
			mortos++;
		}
		pos++;
		if (pos > 9)
		{
			pos = 0;
		}
		if (lista_circular[pos] != -1)
		{
			aux++;
		}
		if (lista_circular[pos] -1)
		{
			vivo = pos;
		}
	} while (mortos < TAM-1);
	printf("%d", vivo);
	return 0;
}
