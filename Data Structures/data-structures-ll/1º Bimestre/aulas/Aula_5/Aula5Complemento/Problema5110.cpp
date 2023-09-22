#include <stdio.h>

int x = 762021192;

main() {
	printf("%d", x);
	int y, desl = 10; 
	puts("");	
	do {
		y = x % desl;
		desl *= 10;
		printf("\n%d", y);
	} while (y != x);
	
}
