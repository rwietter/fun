#include <stdio.h>

int b = 0;

void fx(int *a) {
	*a = *a + 1;
}


main() {
	fx(&b);
	printf("%d",b);
}
