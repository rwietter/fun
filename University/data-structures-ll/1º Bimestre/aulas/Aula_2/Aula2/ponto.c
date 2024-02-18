#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <math.h> /* sqrt */
#include "D:\TESE\Dropbox\DRIVE_D\Aulas UFSM-FW\Programação e Estrutura 2019-2\Aula2\ponto.h"

// Como só precisamos guardar as coordenadas de um ponto, podemos definir a estrutura
// ponto da seguinte forma:
struct ponto {
	float x;
	float y;
};

// A função que cria um ponto dinamicamente deve alocar a estrutura que representa o
// ponto e inicializar os seus campos:
Ponto* cria (float x, float y) {
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	if (p == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	p->x = x;
	p->y = y;
	return p;
}

// Para esse TAD, a função que libera um ponto deve apenas liberar a estrutura que foi
// criada dinamicamente através da função cria:
void libera (Ponto* p) {
	free(p);
}

// As funções para acessar e atribuir valores às coordenadas de um ponto são de fácil
// implementação, como pode ser visto a seguir.
void acessa (Ponto* p, float* x, float* y) {
	*x = p->x;
	*y = p->y;
}

void atribui (Ponto* p, float x, float y) {
	p->x = x;
	p->y = y;
}

// Já a operação para calcular a distância entre dois pontos pode ser implementada da
// seguinte forma:
float distancia (Ponto* p1, Ponto* p2) {
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	return sqrt(dx*dx + dy*dy);
}

Ponto *p;
float px, py;

main() {
	p = cria(10,10);	
	acessa(p, &px, &py);
	printf("%f %f\n", px, py);
	atribui (p, 15, -15);
	acessa(p, &px, &py);
	printf("%f %f\n", px, py);
	Ponto *p2;
	p2 = cria(20,20);	
	printf("%f",distancia(p, p2));
	libera(p);
	libera(p2);
}
