#include <stdio.h>

int a, i; // Global

int primo(int a) { // Local
	if (a <= 2) // Exceção
		return 1;
	for(i=2;i<a;i++) {
		if((a%i)==0) 
			return 0;
	}
	return 1;		
}

main() {
	do {
		scanf("%d", &a);
		if (a == 0)
			break;
		if (primo(a)==1)
			puts("EH PRIMO!");
		else	
			puts("NAO EH PRIMO!");
	} while (a != 0);
}

