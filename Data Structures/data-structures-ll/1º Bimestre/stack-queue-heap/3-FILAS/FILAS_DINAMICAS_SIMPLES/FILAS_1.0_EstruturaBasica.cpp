#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct no
{
  int info;
  struct no* prox;
}Node;

typedef struct fila
{
  Node* inicio;
  Node* fim;
}Fila;

Fila* cria_fila(Fila* f1);
int fila_vazia();
Node* insere();
int imprime();


Node* insere(int i){
  Node* novo = (Node*) malloc(sizeof(Node));
  Fila* f1;
  novo->info = i;
  novo->prox = NULL;
  if (f1->inicio == NULL){
    f1->inicio = novo;
  }else{
    f1->fim->prox = novo;
  }
  f1->fim = novo;
  return novo;
}

int imprime(Fila* f)
{
	Node* q;
	for (q=f->inicio; q!=NULL; q=q->prox){
		printf("%d\n",q->info);
  }
}

Fila* cria_fila(Fila* f1){
  Fila* novo = (Fila*) malloc(sizeof(Fila));
  novo->inicio = NULL;
  novo->fim = NULL;
  return novo;
}

int fila_vazia(){
  Fila* f1;
  if (f1 == NULL){
    printf("Fila vazia\n");
  }else{
    printf("Fila não está vazia\n");
  }
}


int main()
{
  Fila* f1;

  fila_vazia();
  f1 = cria_fila(f1);
  insere(1);
  insere(2);
  insere(3);
  fila_vazia();
  imprime(f1);
  return 0;
}


/*
Uma fila é um conjunto ordenado de itens a partir do qual podem-se eliminar
itens numa extremidade — chamada início da fila — e no qual podem-se inserir
itens na outra extremidade — chamada final da fila.

Os elementos só podem ser eliminados a partir do início da fila.

O primeiro elemento inserido numa fila é o primeiro a ser removido.
Por essa razão, uma fila é ocasionalmente chamada lista fifo — first-in,
first-out — o primeiro que entra é o primeiro a sair —, ao contrário de uma
pilha, que é uma lista lifo — last-in, first-out — o último a entrar é o primeiro
a sair.

A operação inseri sempre pode ser executada, uma vez que não há
limite para o número de elementos que uma fila pode conter. A operação remove,
contudo, só pode ser aplicada se a fila não estiver vazia; não existe um método
para remover um elemento de uma fila sem elementos. O resultado de uma
tentativa inválida de remover um elemento de uma fila vazia é chamado de
underflow. Evidentemente, a operação empty é sempre aplicável.

Conforme ilustrado nas figuras acima, usamos as seguintes convenções para a
identificação da fila:
O início marca a posição do próximo elemento a ser retirado da fila;
O fim marca a posição — vazia —, onde será inserido o próximo elemento.
Desta forma, a fila vazia se caracteriza por ter início == fim e a fila cheia — quando não é
possível inserir mais elementos — se caracteriza por ter fim e início em posições
consecutivas — circularmente —:
*/
