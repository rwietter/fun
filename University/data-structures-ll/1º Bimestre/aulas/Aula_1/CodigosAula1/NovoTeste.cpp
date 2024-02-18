#include <stdio.h>

int a;

main() {
	scanf("%d", &a);
	if ((a % 2) == 0)
		puts("EH UM NUMERO PAR");
	else	
		puts("EH UM NUMERO IMPAR");
}
