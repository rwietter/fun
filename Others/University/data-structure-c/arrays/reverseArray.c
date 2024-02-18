#include <stdio.h>

int *inv(int start, int end, int vet[])
{
  if (start >= end)
  {
    return vet;
  }

  int aux = vet[start];
  vet[start] = vet[end];
  vet[end] = aux;

  return inv(start + 1, end - 1, vet);
}

int main()
{
  int i, p = 6;
  int vet[6] = {5, 1, 8, 7, 2, 0};
  printf("Ordem original:");
  for (i = 0; i < p; i++)
  {
    printf("%d", vet[i]);
  }
  int *arr = inv(0, 5, vet);
  printf("\nOrdem invertida:");
  for (i = 0; i < p; i++)
  {
    printf("%d", arr[i]);
  }
}
