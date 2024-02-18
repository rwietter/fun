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
		printf("%d ", a->info); /* mostra raiz */
		imprime(a->esq); /* mostra sae */
		imprime(a->dir); /* mostra sad */
	}
}

void eh_abp (Arv* a)
{
	if (!vazia(a)){
		printf("%d ", a->info); /* mostra raiz */
		eh_abp(a->esq); /* mostra sae */
		eh_abp(a->dir); /* mostra sad */
	}
}


void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == 12)
			printf("<");
		printf("%d", a->info); /* mostra raiz */
		printf("<");
		imprime_alt(a->esq); /* mostra sae */
		printf(">");
		printf("<");
		imprime_alt(a->dir); /* mostra sad */
		printf(">");
		if (a->info == 12)
			printf(">");
	}
}	

Arv* libera (Arv* a){
	if (!vazia(a)){
		libera(a->esq); /* libera sae */
		libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
	}
	return NULL;
}

int altura(Arv* a) {
   if (a == NULL) 
      return -1; // altura da �rvore vazia
   else {
      int he = altura (a->esq);
      int hd = altura (a->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

int busca (Arv* a, char c){
	if (vazia(a))
		return 0; 
	else
		return a->info==c || busca(a->esq,c) || busca(a->dir,c);
}

main() {
	/*
	Arv* a1 = cria(10, inicializa(), inicializa());
	Arv* a2 = cria(16, inicializa(), inicializa()); 
	Arv* a3 = cria(30, inicializa(), inicializa()); 
	Arv* a4 = cria(1, inicializa(), a1); 
	Arv* a5 = cria(13, inicializa(), a2); 
	Arv* a6 = cria(15, a5, a3);
	Arv* a7 = cria(12, a4, a6);
	imprime(a7);
	puts("");
	imprime_alt(a7);
	*/
	
	
	Arv* a1 = cria(1, inicializa(), inicializa());
	Arv* a2 = cria(5, inicializa(), inicializa()); 
	Arv* a3 = cria(6, inicializa(), inicializa()); 
	Arv* a4 = cria(4, inicializa(), a2); 
	Arv* a5 = cria(3, a4, a3); 
	Arv* a6 = cria(2, a1, a5);
	imprime(a6);
	puts("");
	imprime_alt(a6);
	eh_abp(a6);
	
	printf("\nint altura(Arv* a) %d", altura(a6));

	//printf("\nint busca (Arv* a, char c) %d", busca (a7, 'a'));
	//printf("\nint busca (Arv* a, char c) %d", busca (a7, 'x'));
	//libera(a);
}
