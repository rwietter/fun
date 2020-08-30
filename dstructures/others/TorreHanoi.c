#include <stdio.h>


void mov_discos(int d, char ori, char dest, char aux)
{
	if (d == 1)
	{
		printf("Mover disco %d, de %c, para %c\n", d, ori, dest);
	}
	else
	{
		mov_discos(d-1, ori, aux, dest);
		printf("Mover disco %d, de %c, para %c\n", d, ori, dest);
		mov_discos(d-1, aux, dest, ori);
	}
}
int main(int argc, char const *argv[])
{
	int discos = 20;
	mov_discos(discos,'A', 'C', 'B');
	return 0;
}
