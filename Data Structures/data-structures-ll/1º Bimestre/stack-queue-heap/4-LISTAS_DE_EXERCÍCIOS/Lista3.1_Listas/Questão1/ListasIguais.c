#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
}*inicio = NULL;

// --------------------------- Abstração de Dados --------------------------- //
int listaVazia(struct Node* l1, struct Node* l2);
struct Node* Insert(struct Node* l, int v);
int igual(struct Node* l1, struct Node* l2);

// ---------------------------------- Main ---------------------------------- //
void main() {
  int flag=0;
  struct Node* l1 = (struct Node*) malloc(sizeof(struct Node));
  struct Node* l2 = (struct Node*) malloc(sizeof(struct Node));

  l1 = NULL; l2 = NULL;

  l1 = Insert(l1, 22); l1 = Insert(l1, 23);
  l1 = Insert(l1, 77); l1 = Insert(l1, 25);
  l1 = Insert(l1, 26);

  if(listaVazia(l1, l2)==1){
    printf("Lista vazia\n");
  }else{
    printf("Lista não está vazia\n");
  }

  l2 = Insert(l2, 22); l2 = Insert(l2, 23);
  l2 = Insert(l2, 77); l2 = Insert(l2, 25);
  l2 = Insert(l2, 26);

  if(igual(l1, l2)==1){;
    printf("Não são iguais");
  }else{
    printf("São iguais");
  }
}

// ------------------------------ Lista Vazia? ------------------------------ //
int listaVazia(struct Node* l1, struct Node* l2){
  if ((l1 == NULL) && (l2 == NULL)){
    return 1;
  }else{
    return 0;
  }
}

// ---------------------------- Inserir no Inicio---------------------------- //
struct Node* Insert(struct Node* l, int v){
  struct Node* newNode = ( struct Node* )malloc(sizeof(struct Node));
  newNode->data = v;
  newNode->next = l;
  return newNode;
}

// ------------------------------- São Iguais? ------------------------------ //
int igual(struct Node* l1, struct Node* l2){
int flag;
while (l1 || l2 != NULL)
{
  if (l1->data != l2->data)
    {
      printf("[%d], [%d]\n", l1->data, l2->data);
      flag = 1;
    }else{
      printf("[%d], [%d]\n", l1->data, l2->data);
    }
    l1 = l1->next;
    l2 = l2->next;
  }
  return flag;
}
