//
// Solucao para o problema "Quermesse" da OBI2000
//
// (jan)
//

#include <stdio.h>

int main(int, char*[])
{
  int teste = 1;
  while (true)
    {
      // lê número de convidados
      int convidados;
      scanf("%d", &convidados);
      
      if (!convidados) break;

      // header
      printf("Teste %d\n", teste);

      // lê entrada e encontra solução
      int solucao = -1;
      int posicao = 1;
      while (posicao <= convidados)
        {
          int ingresso;
          scanf("%d", &ingresso);
          
          if (posicao == ingresso) 
            {
              if (solucao != -1)
              	printf("*** + de uma solução \n");
              else
                solucao = posicao;
            }
          posicao++;
        }

      // imprime soluçao
      printf("solucao %d\n", solucao);

      // vai para próximo teste
      teste ++;
    }
}

