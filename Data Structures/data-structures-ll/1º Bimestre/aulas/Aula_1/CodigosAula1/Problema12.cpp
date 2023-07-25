#include <stdio.h>

int a, i, soma_div = 0;

int perfeito(int a) {
	printf("\nVERIFICANDO NUMERO %d", a);
	puts("");
	for(i=1;i<a;i++) {
		if((a%i)==0) {
			printf("Divisor %d\n",i);
			soma_div += i;
		}
	}
	if (soma_div == a)
		return 1; //puts("EH UM NUMERO PERFEITO");
	else	
		return 0; //puts("NAO EH UM NUMERO PERFEITO");
}

main() {
	/*do {
		a++;
	} while (a < 1000);*/
	
	printf("%d",perfeito(6));	
	
	//scanf("%d", &a);
	//Perfeito: Número perfeito é aquele cuja soma de seus divisores, 
	//exceto ele próprio é igual ao número. 
	//Exemplo: 6 é perfeito porque 1 + 2 + 3 = 6.
}
