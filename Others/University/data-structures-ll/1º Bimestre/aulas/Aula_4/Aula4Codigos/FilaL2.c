#include <stdio.h>

// O nó da lista duplamente encadeada para armazenar valores reais pode ser dado por:
struct no2 {
	float info;
	struct no2* ant;
	struct no2* prox;
};
typedef struct no2 No2;

// A estrutura da fila dupla agrupa os ponteiros para o início e o fim da lista:
struct fila2 {
	No2* ini;
	No2* fim;
};
typedef struct fila2 Fila2;

// Interessa-nos discutir as funções para inserir e retirar elementos. As demais são
// praticamente idênticas às de fila simples. Podemos inserir um novo elemento em
// qualquer extremidade da fila. Portanto, precisamos de duas funções auxiliares de lista:
// para inserir no início e para inserir no fim. Ambas as funções são simples e já foram
// exaustivamente discutidas para o caso da lista simples. No caso da lista duplamente
// encadeada, a diferença consiste em termos que atualizar também o encadeamento para o
// elemento anterior. Uma possível implementação dessas funções é mostrada a seguir.
// Essas funções retornam, respectivamente, o novo nó inicial e final.

/* função auxiliar: insere no início */
No2* ins2_ini (No2* ini, float v) {
	No2* p = (No2*) malloc(sizeof(No2));
	p->info = v;
	p->prox = ini;
	p->ant = NULL;
	if (ini != NULL) /* verifica se lista não estava vazia */
		ini->ant = p;
	return p;
}

/* função auxiliar: insere no fim */
No2* ins2_fim (No2* fim, float v) {
	No2* p = (No2*) malloc(sizeof(No2));
	p->info = v;
	p->prox = NULL;
	p->ant = fim;
	if (fim != NULL) /* verifica se lista não estava vazia */
		fim->prox = p;
	return p;
}

// Uma possível implementação das funções para remover o elemento do início ou do fim
// é mostrada a seguir. Essas funções também retornam, respectivamente, o novo nó
// inicial e final.

/* função auxiliar: retira do início */
No2* ret2_ini (No2* ini) {
	No2* p = ini->prox;
	if (p != NULL) /* verifica se lista não ficou vazia */
		p->ant = NULL;
	free(ini);
	return p;
}

/* função auxiliar: retira do fim */
No2* ret2_fim (No2* fim) {
	No2* p = fim->ant;
	if (p != NULL) /* verifica se lista não ficou vazia */
		p->prox = NULL;
	free(fim);
	return p;
}

// A função cria aloca a estrutura da fila e inicializa a lista como sendo vazia.

Fila2* cria (void)
{
	Fila2* f = (Fila2*) malloc(sizeof(Fila2));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

// As funções que manipulam a fila fazem uso dessas funções de lista, atualizando os
// ponteiros ini e fim quando necessário.

void insere_ini (Fila2* f, float v) {
	f->ini = ins2_ini(f->ini,v);
	if (f->fim==NULL) /* fila antes vazia? */
		f->fim = f->ini;
}

void insere_fim (Fila2* f, float v) {
	f->fim = ins2_fim(f->fim,v);
	if (f->ini==NULL) /* fila antes vazia? */
		f->ini = f->fim;
}

// A fila estará vazia se a lista estiver vazia:

int vazia (Fila2* f)
{
	return (f->ini==NULL);
}

float retira_ini (Fila2* f) {
	float v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	v = f->ini->info;
	f->ini = ret2_ini(f->ini);
	if (f->ini == NULL) /* fila ficou vazia? */
		f->fim = NULL;
	return v;
}

float retira_fim (Fila2* f) {
	float v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	v = f->fim->info;
	f->fim = ret2_fim(f->fim);
	if (f->fim == NULL) /* fila ficou vazia? */
		f->ini = NULL;
	return v;
}

main () {
	Fila2* fi = cria();
	insere_ini (fi, 10.5);
	insere_fim (fi, 11.5);
}
