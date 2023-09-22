#include <stdio.h>

int i = 10, *pi;

void f1(int *i) {
	*i += 15;
}

main() {
	printf("%d\n",i);
	pi = &i;
	*pi = 20;
	printf("%d\n",i);
	f1(&i);
	printf("%d\n",i);
}
