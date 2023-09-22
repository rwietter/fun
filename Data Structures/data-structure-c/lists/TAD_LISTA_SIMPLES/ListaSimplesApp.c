
#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

void insertAtBeginning(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(head == NULL)
   {
      newNode->next = NULL;
      head = newNode;
   }
   else
   {
      newNode->next = head;
      head = newNode;
   }
   printf("\nNó inserido com sucesso no início\n");
}

void insertAtEnd(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   if(head == NULL)
      head = newNode;
   else
   {
      struct Node *temp = head;
      while(temp->next != NULL)
 temp = temp->next;
      temp->next = newNode;
   }
   printf("\nNó inserido com êxito no final\n");
}

void insertPosition(int value, int pos)
{
   int i = 0;
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(head == NULL)
   {
      newNode->next = NULL;
      head = newNode;
   }
   else {
        struct Node *temp = head;
        for (i = 0; i < pos - 1; i++) {
            temp = temp-> next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
   }

   printf("\nNó inserido com sucesso\n");
}

void removeBeginning()
{
   if(head == NULL)
 printf("\n\nLista está vazia!!!");
   else
   {
      struct Node *temp = head;
      if(head->next == NULL)
      {
       head = NULL;
       free(temp);
      }
      else
      {
         head = temp->next;
         free(temp);
         printf("\nNó excluído no início\n\n");
      }
   }
}
void removeEnd()
{
   if(head == NULL)
   {
      printf("\nLista está vazia\n");
   }
   else
   {
      struct Node *temp1 = head,*temp2;
      if(head->next == NULL)
         head = NULL;
      else
      {
         while(temp1->next != NULL)
         {
             temp2 = temp1;
             temp1 = temp1->next;
         }
         temp2->next = NULL;
      }
      free(temp1);
      printf("\nNó excluído no final\n\n");
   }
}

void removePosition(int pos)
{
   int i,flag = 1;

   if (head==NULL)
        printf("Lista está vazia");
   else {
       struct Node *temp1 = head, *temp2;
       if (pos == 1) {
            head = temp1->next;
            free(temp1);
            printf("\nNode deletado\n\n");
       }
       else {
           for (i = 0; i < pos - 1; i++)
           {
             if (temp1->next != NULL) {
                 temp2 = temp1;
                 temp1 = temp1 -> next;
             }
             else {
                flag = 0;
                break;
             }
           }
           if (flag) {
               temp2 -> next = temp1 -> next;
               free(temp1);
               printf("\nNode deletado\n\n");
           }
           else {
               printf("A posição excede o número de elementos na lista vinculada. Por favor, tente novamente");
           }
       }
    }
}

void display()
{
   if(head == NULL)
   {
      printf("\nLista está vazia\n");
   }
   else
   {
      struct Node *temp = head;
      printf("\n\nOs elementos da lista são - \n");
      while(temp->next != NULL)
      {
        printf("%d --->",temp->data);
        temp = temp->next;
      }
      printf("%d --->NULL",temp->data);
   }
}


void main()
{
  int choice,value,choice1,pos,del;
  while(1){
  printf("\n\n------ MENU ------\n");
  printf ("1. Inserir no início\n 2. Inserir no final \n 3. Inserir no local \n 4. Excluir no início \n 5. Excluir no final \n 6. Excluir no local \n 7. Exibir \n 8. Exibir \n 8. Sair \n \n Enter sua escolha: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:  printf("Digite o valor a ser inserido: ");
              scanf("%d",&value);
              insertAtBeginning(value);
              break;
    case 2:  printf("Digite o valor a ser inserido: ");
              scanf("%d",&value);
              insertAtEnd(value);
              break;
    case 3:   printf("Digite o valor a ser inserido: ");
              scanf("%d",&value);
              printf("Digite a posição após a qual você deseja inserir: ");
              scanf("%d",&pos);
              insertPosition(value,pos);
              break;
    case 4:  removeBeginning();
              break;
    case 5:  removeEnd();
              break;
    case 6:   printf("Digite o valor que você deseja excluir: ");
              scanf("%d",&pos);
              removePosition(pos);
              break;
    case 7:   display();
              break;
    case 8:   exit(0);
    default: printf("\nEntrada errada !! Tente novamente!!!\n\n");
          }
      }
}
