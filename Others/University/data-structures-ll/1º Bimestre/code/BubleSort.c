#include <stdio.h>

int BobbleSort(int vet[], int n);

int main(int argc, char const *argv[])
{
	int vet[] = {1,7,8,4,2,9,0,8,3,2};
	int n=10;
	BobbleSort(vet, n);

	return 0;
}

int BobbleSort(int vet[], int n)
{
	int k = n;
	int i, j;
	int aux;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < k; j++)
		{
			if (vet[j] > vet[j+1])
			{
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
		}
		k--;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", vet[i]);
	}
	return aux;
}
