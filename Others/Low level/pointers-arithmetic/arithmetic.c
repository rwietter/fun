#include <stdlib.h>
void main()
{
  int *vet;
  int *ptr;

  vet = (int *)malloc(sizeof(int) * 10);
  vet[4] = 44; // 'vet' funciona como um vetor, depois de malloc

  ptr = vet; // 'ptr'  aponta para o início da área alocada por 'vet

  *ptr = 11; // vet[0] = 11 coloca 11 na primeira posição da área alocada
  printf("%d\n", *ptr);

  ptr++;     // avança o apontador
  *ptr = 12; // vet[1] = 12
  printf("%d\n", *ptr);

  ptr++;
  *ptr = 13; // vet[2] = 13
  printf("%d\n", *ptr);

  // free(ptr);  // Liberar 'ptr' direto causa NULL POINTER ASSIGNMENT
  // Corrigindo, a forma correta é:
  ptr--;
  ptr--;
  free(ptr); // Libera a referência para a memória alocada por 'vet' (vet[0])
}
