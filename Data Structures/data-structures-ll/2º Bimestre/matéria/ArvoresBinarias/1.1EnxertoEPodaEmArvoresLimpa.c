#include <stdio.h>
#include <string.h>

struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
	return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad){
	Arv* p=(Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}


int vazia(Arv* a)
{
	return a==NULL;
}

void imprime (Arv* a)
{
	if (!vazia(a)){
		printf("%d ", a->info);
		imprime(a->esq);
		imprime(a->dir);
	}
}	

int conta(Arv *a) {
	int soma;
	if(a == NULL) {
		return 0;
	}
		if((a->esq == NULL) && (a->dir == NULL)) {
			return soma += a->info;	
	}
}

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == 6)
			printf("<");
		printf("%d", a->info);
		printf("<");
		imprime_alt(a->esq);
		printf(">");
		printf("<");
		imprime_alt(a->dir);
		printf(">");
		if (a->info == 6)
			printf(">");
	}
}	

Arv* libera (Arv* a){
	if (!vazia(a)){
		libera(a->esq);
		libera(a->dir);
		free(a);
	}
	return NULL;
}

int iguais(Arv* a, Arv* b)
{
	if(!vazia(a))
	{
		if(a->info != b->info)
		{
			return 0;
		}
		else
		{
			return 1;
		}
		iguais(a->esq, b->esq);
		iguais(a->dir, b->dir);
	}
}

main() {
	Arv* a1= cria(1,inicializa(),inicializa());
	Arv* a2= cria(2,inicializa(),a1);
	Arv* a3= cria(3,inicializa(),inicializa());
	Arv* a4= cria(7,inicializa(),inicializa());
	Arv* a5= cria(5,a3,a4);
	Arv* a = cria(6,a2,a5 );
	
	Arv* b1= cria(1,inicializa(),inicializa());
	Arv* b2= cria(2,inicializa(),b1);
	Arv* b3= cria(3,inicializa(),inicializa());
	Arv* b4= cria(4,inicializa(),inicializa());
	Arv* b5= cria(5,b3,b4);
	Arv* b = cria(6,b2,b5 );
	
	printf("\n%d\n", conta(a));
	
	imprime(a);
	puts("");
	imprime(b);
	
	printf("\n\nIgual? %d\n",iguais(a,b));
	
	puts("");
	imprime_alt(a);
	puts("");

	a->esq->esq =cria('x',
						cria('y',inicializa(),inicializa()),
						cria('z',inicializa(),inicializa())
						);
	imprime_alt(a);						
	puts("");
	
	a->dir->esq = libera(a->dir->esq); 
	imprime_alt(a);
	printf("\n\n%c", conta(a));					
}


