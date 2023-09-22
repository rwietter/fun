// Baseado no código de William Freire Drabach

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void poli (char * v){

	int a=0,i;
	int t=strlen(v);
	printf("\n Tamanho-%d,",t);
	for(i=0;i<t/2;i++){
		if(v[i] != v[t-i-1])
			a=1;
	}
	if(a==0)
		printf("\n e palindromo \n\n");
	else
		printf("\n nao e palindromo \n\n");
}

main() {
	poli("ABOBA");
	poli("ABOBA+");
	poli("+ABOBA+");
}
