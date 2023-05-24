#include <stdio.h>

int a = 10, *p;

void f1(int *b) {
	printf("\n%d",*b);
	*b = *b + 1;
	printf("\n%d",*b);
}

main() {
	//p = &a;
	//printf("%d",*p);
	f1(&a);
	//a++;
	printf("\n%d",a);
}
