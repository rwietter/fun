//Problema 3
//Faça uma função recursiva que permita inverter um número 
//inteiro N. Ex: 123 - 321

#include <stdio.h>

// Imprime em ordem inversa
void imprime_inv (char* s)
{
	if (s[0] != '\0')
	{
		imprime_inv(&s[1]);
		printf("%c",s[0]);
	}
}

main() {
	int n = 14823;
	/*printf("\n%d",n%10);
	int x = (n - (n%10));*/
	int x, y;
	int mod = 10;
	do {
		x = n / mod;
		y = n % mod;		
		printf("\n%d",x);
		printf("\n%d",y);
		mod *= 10;
		n = x;
	} while (mod < (n*10));
	//printf("\n%d",n % 10000);
		
	
}




