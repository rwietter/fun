#include <stdio.h>
#include <string.h>

char palavra1[20], palavra2[20];

main() {
	// ABOBA+
	scanf("%s", palavra1);
	int tam1 = strlen(palavra1);
	//printf("%s", palavra);
	//printf("%d", tam1);
	int x, y = 0;
	for(x=(tam1);x>0;x--) {
		printf("%c", palavra1[x]);
		palavra2[y] = palavra1[x];
		y++;
	}
	//palavra2[y] = putchar('\n');
	//considere Teste5.cpp -> strcpy(palavra2,palavra1);
	printf("%s", palavra2);	
	palavra2[0] = tam1;
	int tam2 = strlen(palavra2);
	printf("\n%d", tam2);
	if (strcmp(palavra1, palavra2) == 0)
		puts("SAO PALINDROMOS");
}
