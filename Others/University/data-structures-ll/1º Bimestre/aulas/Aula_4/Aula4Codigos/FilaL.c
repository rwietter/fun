// Um exemplo simples de utiliza��o da estrutura de fila � apresentado a seguir:

/* M�dulo para ilustrar utiliza��o da fila */
#include <stdio.h>
//#include "fila.h"


// O n� da lista para armazenar valores reais, como j� vimos, pode ser dado por:

struct no {
	float info;
	struct no* prox;
};

typedef struct no No;

// A estrutura da fila agrupa os ponteiros para o in�cio e o fim da lista:

struct fila {
	No* ini;
	No* fim;
};

typedef struct fila Fila;

// A fun��o cria aloca a estrutura da fila e inicializa a lista como sendo vazia.

Fila* cria (void)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

// Cada novo elemento � inserido no fim da lista e, sempre que solicitado, retiramos o
// elemento do in�cio da lista. Desta forma, precisamos de duas fun��es auxiliares de lista:
// para inserir no fim e para remover do in�cio. A fun��o para inserir no fim ainda n�o foi
// discutida, mas � simples, uma vez que temos explicitamente armazenado o ponteiro
// para o �ltimo elemento. Essa fun��o deve ter como valor de retorno o novo �fim� da
// lista. A fun��o para retirar do in�cio � id�ntica � fun��o usada na implementa��o de
// pilha.

/* fun��o auxiliar: insere no fim */

No* ins_fim (No* fim, float v)
{
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = NULL;
	if (fim != NULL) /* verifica se lista n�o estava vazia */
		fim->prox = p;
	return p;
}

/* fun��o auxiliar: retira do in�cio */

No* ret_ini (No* ini)
{
	No* p = ini->prox;
	free(ini);
	return p;
}

// As fun��es que manipulam a fila fazem uso dessas fun��es de lista. Devemos salientar
// que a fun��o de inser��o deve atualizar ambos os ponteiros, ini e fim, quando da
// inser��o do primeiro elemento. Analogamente, a fun��o para retirar deve atualizar
// ambos se a fila tornar-se vazia ap�s a remo��o do elemento:

void insere (Fila* f, float v)
{
	f->fim = ins_fim(f->fim,v);
	if (f->ini==NULL) /* fila antes vazia? */
		f->ini = f->fim;
}

float retira (Fila* f)
{
	float v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	v = f->ini->info;
	f->ini = ret_ini(f->ini);
	if (f->ini == NULL) /* fila ficou vazia? */
		f->fim = NULL;
	return v;
}

// A fila estar� vazia se a lista estiver vazia:

int vazia (Fila* f)
{
	return (f->ini==NULL);
}

// Por fim, a fun��o que libera a fila deve antes liberar todos os elementos da lista.

void libera (Fila* f)
{
	No* q = f->ini;
	while (q!=NULL) {
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

// Analogamente � pilha, para testar o c�digo, pode ser �til implementarmos uma fun��o
// que imprima os valores armazenados na fila. Os c�digos abaixo ilustram a
// implementa��o dessa fun��o nas duas vers�es de fila (vetor e lista). A ordem de
// impress�o adotada � do in�cio para o fim.

/* imprime: vers�o com lista */
void imprime (Fila* f)
{
	No* q;
	for (q=f->ini; q!=NULL; q=q->prox)
		printf("%f\n",q->info);
}

int main (void)
{
	Fila* f = cria();
	insere(f,20.0);
	insere(f,20.8);
	insere(f,21.2);
	insere(f,24.3);
	printf("Primeiro elemento: %f\n", retira(f));
	printf("Segundo elemento: %f\n", retira(f));
	printf("Configuracao da fila:\n");
	imprime(f);
	libera(f);
	return 0;
}
