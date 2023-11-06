//Um número será quadrado perfeito quando respeitar 
//a regra de formação: n2= a. Nessa regra, n é 
//qualquer número inteiro positivo e a é o 
//número quadrado perfeito.

#include <stdio.h>
#include <math.h>

int a;
float n;

main() {
	scanf("%d",&a);
	n = sqrt(a);
	// Testando a 1a propriedade
	// Somente o número quadrado perfeito possui raiz 
	// quadrada exata
	printf("%f",n);
	
	int y = n;
	float x = n - y;
	//x = n - x;
	printf("%d xxxxx %f", y, x);
	if (x > 0.0)
		puts("NAO EH UMA RAIZ QUADRADA EXATA");
	else	
		puts("EH UMA RAIZ QUADRADA EXATA");
		
	// Segunda Regra: Quando o número é quadrado perfeito,
	// ele não possui como último algarismo os seguintes 
	// números: 2, 3, 7 e 8.
	
	7658762
	7658763
	7658767
	7658768	
	b = a % 10;
	if ((b == 2) || (b==3) || (b==7) || (b==8))
		puts("NAO ATENDE A 2a PROPRIEDADE");
	else
		puts("ATENDE A 2a PROPRIEDADE");
	
	printf("%d",b);
}
