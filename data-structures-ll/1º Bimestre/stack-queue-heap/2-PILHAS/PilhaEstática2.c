#include<stdio.h>

#define SIZE 10

int stack[SIZE], top = -1;

void push(int value){
   if(top == SIZE-1)
      printf("\nOverflow. Stack is Full");
   else{
      top++;
      stack[top] = value;
      printf("\nInsertion was successful");
   }
}
void pop(){
   if(top == -1)
      printf("\nUnderflow. Stack is empty");
   else{
      printf("\nDeleted : %d", stack[top]);
      top--;
   }
}
void display(){
   if(top == -1)
      printf("\nStack is Empty!");
   else{
      int i;
      printf("\nStack elements are:\n");
      for(i=top; i>=0; i--)
        printf("%d\n",stack[i]);
   }
}

void main()
{
   push(21);
   push(22);
   push(23);
   display();
   pop(23);
   display();

}
