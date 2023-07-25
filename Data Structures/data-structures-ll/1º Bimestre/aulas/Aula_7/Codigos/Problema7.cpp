#include <stdio.h>
#include <stdlib.h>

int n, j, r;
int *vitorias;


main() {
	
	scanf("%d",&j);
	scanf("%d",&r);
	vitorias = (int*) malloc ((j * r) * sizeof(int));

	int i;
	for(i=0;i<(j * r);i++) {
		scanf("%d",&vitorias[i]);
		printf("%d",vitorias[i]);
	}
	
	int 
		
}
