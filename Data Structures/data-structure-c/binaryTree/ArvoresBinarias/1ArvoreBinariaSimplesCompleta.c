#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define contSpace 8

struct arvore{
	int info;
	struct arvore *esq;
	struct arvore *dir;
};
typedef struct arvore Arvore;


// ------------ INICIA ---------------------- //
Arvore* inicializa()
{
	return NULL;
}
// --------------------------------------- //
	


// ------------ INSER��O ------------------- //
Arvore* insert(int data, Arvore *left, Arvore *right)
{
	Arvore *node = (Arvore*)malloc(sizeof(Arvore));
	node->info = data;
	node->dir = right;
	node->esq = left;
	return node;
}
// --------------------------------------- //



// ------------ VAZIA --------------------- //
int *vazia(Arvore *a)
{
	return a == NULL;
}
// --------------------------------------- //



// ------------ IMPRIME ------------------- //
void imprime_alt(Arvore* a)
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
// --------------------------------------- //



// ------------ ALTURA ------------------- //
int alturaArvore(Arvore* node)
{
   if (node == NULL) 
      return -1;
   else {
      int alturaEsquerda = alturaArvore(node->esq);
      int alturaDireita = alturaArvore(node->dir);
      if (alturaEsquerda < alturaDireita)
         return alturaDireita + 1;
      else
         return alturaEsquerda + 1;
   }
}
// --------------------------------------- //



// ------------ BUSCA -------------------- //
int busca(Arvore* a, int c){
	if (vazia(a))
		return 0;
	else
		return a->info==c || busca(a->esq,c) || busca(a->dir,c);
}
// --------------------------------------- //



// ------------ IGUAIS? ------------------ //
int iguais(Arvore *a, Arvore *b)
{
	if(!vazia(a))
	{
     iguais(a->esq, b->esq);
     iguais(a->dir, b->dir);
     if(a->info != b->info)
     {
     	printf("\nAs Árvore são diferentes");
     	printf("\nDiferentes: %d", a->info);
     	printf(" %d", b->info);
       return 0;
       exit(1);
     }
     else
     {
     	printf("\n%d", a->info);
     	printf(" %d", b->info);
     }
	}
}
// --------------------------------------- //


// ------------ Pré ordem ------------------- //
Arvore* preOrdem(Arvore* a) 
{
	// pré-ordem: trata raiz, percorre sae, percorre sad

	if (!vazia(a))
	{
		printf("%d ", a->info);
		preOrdem(a->esq);
		preOrdem(a->dir);
	}
	return 1;
}
// --------------------------------------- //

// ------------ Pré ordem ------------------- //
Arvore* ordemSimetrica(Arvore* a)
{
	// ordem simétrica: percorre sae, trata raiz, percorre sad;

	if (!vazia(a))
	{
		ordemSimetrica(a->esq);
		printf("%d ", a->info);
		ordemSimetrica(a->dir);
	}
	return 1;
}
// --------------------------------------- //

// ------------ Pré ordem ------------------- //
Arvore* posOrdem(Arvore* a)
{
	// pós-ordem: percorre sae, percorre sad, trata raiz.

	if (!vazia(a))
	{
		posOrdem(a->esq);
		posOrdem(a->dir);
		printf("%d ", a->info);
	}
	return 1;
}
// --------------------------------------- //

// ------------ LIBERA ------------------- //
Arvore* liberaTodosNodes(Arvore* a){
	if (!vazia(a)){
		liberaTodosNodes(a->esq);
		liberaTodosNodes(a->dir);
		free(a);
	}
	return NULL;
}
// --------------------------------------- //



// ------------ IMPRIME 2D --------------- //
void display_em_2D(Arvore* node, int espaco) 
{
	int i;
	if (node == NULL)
	{
		return;
	}
	espaco += contSpace;
	display_em_2D(node->dir, espaco);
	printf("\n");
	for (i = contSpace; i < espaco; i++)
	{
		printf(" ");
	}
	printf("%d\n", node->info); 
	display_em_2D(node->esq, espaco); 
}
// --------------------------------------- //



// ------------ IMPRIME 2D --------------- //  
void display_2D(Arvore* node) 
{
	display_em_2D(node, 0); 
}
// --------------------------------------- //



// ------------ FOLHAS++ ----------------- //  
int folhas(Arvore* a)
{
	if(a == NULL)
	{
		return 0;
	}
	if(a->esq == a->dir)
	{
		return 1;
	}
	return folhas(a->esq) + folhas(a->dir);
}
// --------------------------------------- //



// ------------ FOLHAS+= ----------------- //  
int folhasSoma(Arvore* a)
{
	int x=0;
	if(a == NULL)
	{
		return 0;
	}
	if(a->esq == a->dir)
	{
		return 1;
	}
	folhasSoma(a->esq);
   x += a->esq->info + a->dir->info;
   printf("\n%d + %d: %d", a->esq->info, a->dir->info, x);
   folhasSoma(a->dir);
   return x;
}
// --------------------------------------- //




// ------------ MAIN -------------------- //
int main()
{
	Arvore* a9 = insert(1, inicializa(), inicializa());
	Arvore* a8 = insert(8, inicializa(), inicializa());
	Arvore* a7 = insert(4, a8, a9);
	Arvore* a6 = insert(7, inicializa(), inicializa());
	Arvore* a5 = insert(0, inicializa(), inicializa());
	Arvore* a4 = insert(3, a6, a5);
	Arvore* a3 = insert(9, inicializa(), inicializa());
	Arvore* a2 = insert(4, inicializa(), inicializa());
	Arvore* a1 = insert(2, a3, a2);
	Arvore* b9 = insert(5, a4, a1);
	Arvore* b8 = insert(6, b9, a7);

	printf("========PRE-ORDEM==========\n");
	preOrdem(b8);

	printf("\n\n========Ordem-Simetrica==========\n");
	ordemSimetrica(b8);

	printf("\n\n========POS-ORDEM==========\n");
	posOrdem(b8);
	
	printf("\n\n--------- Busca ---------------------\n");
	if((busca(b8, 88))==1)
	{
		printf("Elemento encontra-se na Árvore");
	}
	else
	{
		printf("\nElemento não encontra-se na Árvore");
	}
	
	printf("\n--------- Hierarquia ----------------\n\n");
	imprime_alt(b8);
	
	printf("\n\n-------------------------------------\n");
	printf("\nAltura da Árvore: %d\n", alturaArvore(b8));
	
	printf("\n\n-------------------------------------\n");
	printf("\nQuantidade de folhas: %d", folhas(b8));
	
	printf("\n\n-------------------------------------\n");
	printf("\nSoma das folhas: %d", folhasSoma(b8));
	
	
	printf("\n\n--------- Árvore --------------------\n");
	display_2D(b8);
	
	//printf("\n\n----------- Libera -----------------\n");
	//liberaTodosNodes(b8);
	//display_2D(b8);
	/*
	printf("------------------------------------\n");
	
		printf("\nPrimeira Arvore\n");
		Arvore *c6 = insert(1, inicializa(), inicializa());
		Arvore *c5 = insert(2, inicializa(), inicializa());
		Arvore *c4 = insert(3, c5, c6);
		Arvore *c3 = insert(4, inicializa(), inicializa());
		Arvore *c2 = insert(5, inicializa(), c3);
		Arvore *c1 = insert(6, c2, c4);
		imprime_alt(c1);
		printf("\n");
		printf("\n");

		printf("Segunda Arvore\n");
		Arvore *d6 = insert(1, inicializa(), inicializa());
		Arvore *d5 = insert(2, inicializa(), inicializa());
		Arvore *d4 = insert(7, d5, d6);
		Arvore *d3 = insert(4, inicializa(), inicializa());
		Arvore *d2 = insert(5, inicializa(), d3);
		Arvore *d1 = insert(6, d2, d4);
		imprime_alt(d1);
		puts("");
		iguais(c1, d1);
		*/
}
// --------------------------------------- //
