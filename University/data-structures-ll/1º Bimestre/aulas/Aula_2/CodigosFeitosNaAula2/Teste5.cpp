#include <stdio.h>
#include <string.h>

char palavra1[20], palavra2[20];

main() {
	scanf("%s", palavra1);
	int i;
	printf("\n%c",palavra1[0]);
	strcpy(palavra2,palavra1);
	for(i=0;i<(strlen(palavra1));i++)
		printf("\n%c",palavra1[i]);
	for(i=(strlen(palavra1))-1;i<=0;i--)	
		palavra2[i] = palavra1[i];
	printf("\n%s",palavra2);	
}
