#include <stdio.h>

char *origem, *destino;

void strcpy (char *s, char *t) {
   int i;
   for (i = 0; t[i] != '\0'; ++i) 
      s[i] = t[i];
   s[i] = '\0';
}

main() {
	origem = "ABABO";
	printf("%s", origem);
	strcpy(destino, origem);
	printf("%s", destino);
}
