#include <stdio.h>
#include <stdlib.h>

int main()
{
	int v;
	v = malloc (10 * sizeof (int));
	printf("%d", v);
	return 0;
}
