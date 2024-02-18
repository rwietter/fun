#include <stdio.h>

void Quick(int vetor[10], int inicio, int fim);

int main(int argc, char const *argv[])
{
	int vetor[10] = {2,4,1,8,5,8,9,8,6,0};
	int inicio = 0;
	int fim = 10;
	Quick(vetor, inicio, fim);

	return 0;
}

void Quick(int vetor[10], int inicio, int fim){

   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo)
	 	i = i + 1;
      while (vetor[j] > pivo)
	 	j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j)
   	Quick(vetor, inicio, j);

   if(i < fim)
   Quick(vetor, i, fim);
   for ( i = 0; i < fim; i++)
   {
	   printf("%d \n", vetor[i]);
   }
}
