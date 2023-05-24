//
// Solucao para o problema "Bit" da OBI2000
//
// (jan)
//

#include <stdio.h>

int main(int, char*[])
{
  int teste = 1;
  while (true)
    {
      // lê valor para este teste
      int valor;
      scanf("%d", &valor);
      if (!valor) break;

      // header
      printf("Teste %d\n", teste);

      // encontra solução
      int notas1 = 0, notas5 = 0, notas10 = 0, notas50 = 0;

      notas50 = valor / 50;
      valor %= 50;
      notas10 = valor / 10;
      valor %= 10;
      notas5 = valor / 5;
      valor %= 5;
      notas1 = valor;

      // imprime soluçao
      printf("%d %d %d %d\n", notas50, notas10, notas5, notas1);

      // vai para próximo teste
      teste ++;
    }
}

