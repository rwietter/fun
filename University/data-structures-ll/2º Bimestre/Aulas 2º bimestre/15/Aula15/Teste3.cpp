
#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */


int f1(int a) {
	if (a == 1)
		return 1;
	return a * f1 (a-1);
}

main() {
	printf("%d",f1(5));
}


mostra() {
	mostra(esq);
	mostra(dir);
	printf();
}

mostra() {
	empilha() mostra(esq);
	empilha() mostra(dir);
}

mostra() {
	re() mostra(esq);
	re() mostra(dir);
}


