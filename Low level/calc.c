#include <stdio.h>
#include <stdlib.h>

void sum(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);

void sum(int a, int b)
{
  printf("%d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b)
{
  printf("%d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b)
{
  printf("%d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b)
{
  printf("%d / %d = %d\n", a, b, a / b);
}

int disp()
{
  char option[4];
  int num1, num2;

  printf("Enter an operation \n1) sum\n2) multiply\n3) subtract\n4) divide\n");
  printf("Choose an operation: ");
  scanf("%4s", option);

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  int op = atoi(option);
  void (*dispatchTable[])(int, int) = {sum, multiply, subtract, divide};
  dispatchTable[op - 1](num1, num2);

  return 0;
}

// enum OPTION
// {
//   SUM = '1',
//   MULTIPLY = '2',
//   SUBTRACT = '3',
//   DIVIDE = '4',
//   EXIT = '0'
// };

// int main()
// {
//   char option[4];
//   int num1, num2;

//   printf("Enter an operation \n1) sum\n2) multiply\n3) subtract\n4) divide\n");
//   printf("Choose an operation: ");
//   scanf("%4s", option);

//   printf("Enter two numbers: ");
//   scanf("%d %d", &num1, &num2);

//   switch (option[0])
//   {
//   case SUM:
//     sum(num1, num2);
//     break;

//   case MULTIPLY:
//     multiply(num1, num2);
//     break;

//   case SUBTRACT:
//     subtract(num1, num2);
//     break;

//   case DIVIDE:
//     divide(num1, num2);
//     break;

//   default:
//     printf("Invalid operation\n");
//     break;
//   }

//   return 0;
// }