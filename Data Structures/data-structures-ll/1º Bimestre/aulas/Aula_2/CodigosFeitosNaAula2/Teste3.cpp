#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

double *p;

main() {
	printf("%d\n", sizeof(p));
	p = (double*) malloc(sizeof(double)*5);
	printf("%d\n", sizeof(p));
	free(p);
	printf("%d\n", sizeof(p));
}
