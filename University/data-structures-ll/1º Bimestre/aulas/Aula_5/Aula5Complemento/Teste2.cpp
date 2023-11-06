/* Cálculo da media e da variância de 10 reais (segunda versão) */
#include <stdio.h>
/* Função para cálculo da média */
float media (int n, float* v)
{
	int i;
	float s = 0.0;
	for (i = 0; i < n; i++)
		s += v[i];
	return s/n;
}
/* Função para cálculo da variância */
float variancia (int n, float* v, float m)
{
	int i;
	float s = 0.0;
	for (i = 0; i < n; i++)
		s += (v[i] - m) * (v[i] - m);
	return s/n;
}
int main ( void )
{
	float v[5];
	float* pv;
	int i;
	
	pv = v;
	
	/* leitura dos valores */
	for ( i = 0; i < 10; i++ ) {
		scanf("%f", &pv[i]);
	}
	
	for ( i = 0; i < 10; i++ ) {
		printf("%f", *pv++);
	}	

	return 0;
}







