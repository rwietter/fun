// Implementação de pilha com vetor

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

#define MAX 50

// A estrutura que representa o tipo pilha deve, portanto, ser composta pelo vetor e pelo
// número de elementos armazenados.
struct pilha {
	int n;
	float vet[MAX];
};

typedef struct pilha Pilha;

// A função para criar a pilha aloca dinamicamente essa estrutura e inicializa a pilha como
//sendo vazia, isto é, com o número de elementos igual a zero.
Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->n = 0; /* inicializa com zero elementos */
	return p;
}

// Para inserir um elemento na pilha, usamos a próxima posição livre do vetor. Devemos
// ainda assegurar que exista espaço para a inserção do novo elemento, tendo em vista que
// trata-se de um vetor com dimensão fixa.
void push (Pilha* p, float v)
{
	if (p->n == MAX) { /* capacidade esgotada */
		printf("OVERFLOW - Capacidade da pilha estourou.\n");
		exit(1); /* aborta programa */
	}
	/* insere elemento na próxima posição livre */
	p->vet[p->n] = v;
	p->n++;
}	

int vazia (Pilha* p);

// A função pop retira o elemento do topo da pilha, fornecendo seu valor como retorno.
// Podemos também verificar se a pilha está ou não vazia.
float pop (Pilha* p)
{
	float v;
	if (vazia(p)) {
		printf("UNDERFLOW - Pilha vazia.\n");
		exit(1); /* aborta programa */
	}
	/* retira elemento do topo */
	v = p->vet[p->n-1];
	p->n--;
	return v;
}

// A função mostra_pilha mostra todos os elementos da pilha
// Podemos também verificar se a pilha está ou não vazia.
void mostra_pilha (Pilha* p)
{
	float v;
	if (vazia(p)) {
		printf("UNDERFLOW - Pilha vazia.\n");
		exit(1); /* aborta programa */
	}
	puts("MOSTRA PILHA:");
	int topo = p->n-1;
	do {
		/* retira elemento do topo */
		v = p->vet[topo];
		printf("%f\n",v);
		topo--;
	} while (topo != -1);
	printf("**** %d\n",topo);
}

/* imprime: versão com vetor */
void imprime (Pilha* p)
{
	int i;
	for (i=p->n-1; i>=0; i--)
		printf("%f\n",p->vet[i]);
}

// A função que verifica se a pilha está vazia pode ser dada por:
int vazia (Pilha* p)
{
	return (p->n == 0); // if (p->n == 0)
}

// Finalmente, a função para liberar a memória alocada pela pilha pode ser:
void libera (Pilha* p)
{
	free(p);
}

main () {
	Pilha *p;
	p = cria();
	push(p, 4);
	push(p, 6);
	push(p, 8);
	mostra_pilha(p);
	printf("\npop() %f\n",pop(p));
	push(p, 10);
	mostra_pilha(p);
}
