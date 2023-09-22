#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <math.h> /* sqrt */
#include "/home/ghost/Downloads/PED/ESTUDAR_PROVA/LISTAS_DE_EXERCÍCIOS/Lista2.1/QUES2/ques1.h"

// Como só precisamos guardar as coordenadas de um ponto, podemos definir a estrutura ponto da seguinte forma:
struct ponto {
	float x;
	float y;
};

Ponto *p;
float px, py;

// A função que cria um ponto dinamicamente deve alocar a estrutura que representa o ponto e inicializar os seus campos:
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

// Para esse TAD, a função que libera um ponto deve apenas liberar a estrutura que foi criada dinamicamente através da função cria:
void libera (Ponto* p) {
	free(p);
}

// As funções para acessar e atribuir valores as coordenadas de um ponto são de fácil
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

float soma (Ponto* p1, Ponto* p2, float aumento) {
	do {
		p2->x += 1;
		p2->y += 1;
	} while (distancia(p1, p2)<=aumento);
	return distancia(p1, p2);
}

float subtrai (Ponto* p1, Ponto* p2, float aumento) {
	do {
		p2->x -= 1;
		p2->y -= 1;
	} while (distancia(p1, p2)>=aumento);
	return distancia(p1, p2);
}

main() {
	Ponto *p1, *p2;
	float aumento = 40.5;
  float px, py;
  printf("Digite a distância de px: "); scanf("%f", &px);
  printf("Digite a distância de py: "); scanf("%f", &py);
	p1 = cria(px, px);	
	p2 = cria(py, py);
	printf("Distância: %.2f",distancia(p1, p2));
	soma(&px,&py,50);
	printf("\nSoma: %.2f %.2f",p1->x, p2->y);
	subtrai(p1, p2, aumento);
	printf("\nSubtração: %.2f %.2f",p1->x, p2->y);
}

/*
Problema 2
Acrescente novas operações ao TAD ponto, tais que permitam o armazenamento de pontos de uma trajetória
de tamanho desconhecido
*/
