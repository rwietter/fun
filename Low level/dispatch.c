#include <stdio.h>
#include <stdlib.h>

// Function prototypes for cases
// void case1();
// int case2();
// void case3();

// void func3(void) { printf("tres 3\n"); }
// int func2(void) { printf("dois 2\n"); }
// void func1(void) { printf("um 1\n"); }
// void func0(void) { printf("zero 0\n"); }

// int main()
// {
//     void (*dispatchTable[])(void) = {func0, func1, func2}; // Define a dispatch table of function pointers

//     // Example switch case using dispatch table
//     int choice;
//     printf("Enter a choice (1-3): ");
//     scanf("%d", &choice);

//     if (choice >= 1 && choice <= 3)
//     {
//         dispatchTable[choice - 1](); // Call the corresponding function using the dispatch table
//         return 0;
//     }
//     printf("Invalid choice\n");
//     return 1;
// }

// Functions corresponding to cases
// void case1()
// {
//     printf("Executing Case 1\n");
// }

// int case2(int a)
// {
//     printf("Executing Case 2\n");
//     return 1;
// }

// void case3()
// {
//     printf("Executing Case 3\n");
// }

// int main()
// {
//     int choice;
//     printf("Enter a choice (1-3): ");
//     scanf("%d", &choice);

//     switch (choice)
//     {
//     case 1:
//         printf("Executing Case 1\n");
//         break;
//     case 2:
//         printf("Executing Case 2\n");
//         break;
//     case 3:
//         printf("Executing Case 3\n");
//         break;
//     default:
//         printf("Invalid choice\n");
//         break;
//     }
//     return 0;
// }

// --------------------------------

// typedef void (*Handler)(void); /* A pointer to a handler function */

// /* The functions */
// void func3(void) { printf("tres 3\n"); }
// void func2(void) { printf("dois 2\n"); }
// void func1(void) { printf("um 1\n"); }
// void func0(void) { printf("zero 0\n"); }

// Handler jump_table[4] = {func0, func1, func2, func3};

// int main(int argc, char **argv)
// {
//     int value;

//     jump_table[2]();

//     return 0;
// }

// // ---------------------------------------

// void func3(void) { printf("tres 3\n"); }

// void func2(void) { printf("dois 2\n"); }

// void func1(void) { printf("um 1\n"); }

int main() {
    int index = 2;
    void (*jumpTable[])(void) = {&&Case1, &&Case2, &&Case3};


    goto *jumpTable[index];



Case1:
    func1();
    return 0;

Case2:
    func2();
    return 0;

Case3:
    func3();
    return 0;
}