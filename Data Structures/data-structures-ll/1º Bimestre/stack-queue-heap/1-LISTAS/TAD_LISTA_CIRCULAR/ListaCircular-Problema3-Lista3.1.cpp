#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "/home/ghost/OneDrive/1_SistemasInfo/2_Sem/PED/LISTAS_DE_EXERCÍCIOS/Lista3.1/Questao3/header.h";

using namespace std;


// ----------------------------------------------------------------------------//
// CRIA UM TIPO DE ESTRUTURA
// ----------------------------------------------------------------------------//
struct lista
{
  int info;
  struct lista* prox;
};


// ----------------------------------------------------------------------------//
// FUNÇÃO QUE INICIALIZA A LISTA
// ----------------------------------------------------------------------------//
Lista* inicializa(Lista* l1)
{
  return NULL;
}


// ----------------------------------------------------------------------------//
// FUNÇÃO QUE VERIFICA SE A LISTA ESTÁ VÁZIA
// ----------------------------------------------------------------------------//
int vazia(Lista* l1)
{
  if(l1 == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


// ----------------------------------------------------------------------------//
// FUNÇÃO ALOCA MEMÓRIA E INSERE ELEMENTOS À LISTA
// ----------------------------------------------------------------------------//
Lista* insere(Lista* l1, int i)
{
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = l1;
  return novo;
}


// ----------------------------------------------------------------------------//
// FUNÇÃO QUE IMPRIME A LISTA
// ----------------------------------------------------------------------------//
void imprime (Lista* l1)
{
	Lista* p; /* vari�vel auxiliar para percorrer a lista */
	
	for (p = l1; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
	puts("");
}


// ----------------------------------------------------------------------------//
// FUNÇÃO QUE REMOVE UM ELEMENTO DA LISTA
// ----------------------------------------------------------------------------//
Lista* retirar(Lista* l1, int v) {
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l1; /* ponteiro para percorrer a lista*/

	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}
	
	/* verifica se achou elemento */
	if (p == NULL)
		return l1; /* n�o achou: retorna lista original */
	/* retira elemento */
	if (ant == NULL) {
		/* retira elemento do inicio */
		l1 = p->prox;
	}	
	else {
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	free(p);
	return l1;
}


// ----------------------------------------------------------------------------//
// FUNÇÃO PRINCIPAL
// ----------------------------------------------------------------------------//
int main()
{
  Lista* l1;
  l1 = inicializa(l1);
  l1 = insere(l1, 24);
  l1 = insere(l1, 25);
  l1 = insere(l1, 26);
  l1 = insere(l1, 27);
  imprime(l1);
  l1 = retirar(l1, 26);
  cout << endl;
  imprime(l1);
  return 0;
}

/*
Problema 3
Escreva as funções para inserir e retirar um elemento de uma lista circular.
*/
