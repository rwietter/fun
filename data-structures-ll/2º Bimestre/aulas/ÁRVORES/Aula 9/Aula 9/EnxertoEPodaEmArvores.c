#include <stdio.h>
#include <string.h>

//Cada nó deve armazenar três informações: a informação propriamente dita, no caso um
//caractere, e dois ponteiros para as sub-árvores, à esquerda e à direita. Então a estrutura
//de C para representar o nó da árvore pode ser dada por:

struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};

//Da mesma forma que uma lista encadeada é representada por um ponteiro para o
//primeiro nó, a estrutura da árvore como um todo é representada por um ponteiro para o
//nó raiz.
//Como acontece com qualquer TAD (tipo abstrato de dados), as operações que fazem
//sentido para uma árvore binária dependem essencialmente da forma de utilização que se
//pretende fazer da árvore. Nesta seção, em vez de discutirmos a interface do tipo abstrato
//para depois mostrarmos sua implementação, vamos optar por discutir algumas
//operações mostrando simultaneamente suas implementações. Ao final da seção
//apresentaremos um arquivo que pode representar a interface do tipo. Nas funções que se
//seguem, consideraremos que existe o tipo Arv definido por:

typedef struct arv Arv;

//Como veremos as funções que manipulam árvores são, em geral, implementadas de
//forma recursiva, usando a definição recursiva da estrutura.

//Vamos procurar identificar e descrever apenas operações cuja utilidade seja a mais geral
//possível. Uma operação que provavelmente deverá ser incluída em todos os casos é a
//inicialização de uma árvore vazia. Como uma árvore é representada pelo endereço do
//nó raiz, uma árvore vazia tem que ser representada pelo valor NULL. Assim, a função
//que inicializa uma árvore vazia pode ser simplesmente:

Arv* inicializa(void)
{
	return NULL;
}

//Para criar árvores não vazias, podemos ter uma operação que cria um nó raiz dadas a
//informação e suas duas sub-árvores, à esquerda e à direita. Essa função tem como valor
//de retorno o endereço do nó raiz criado e pode ser dada por:

Arv* cria(int c, Arv* sae, Arv* sad){
	Arv* p=(Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

//As duas funções inicializa e cria representam os dois casos da definição recursiva
//de árvore binária: uma árvore binária (Arv* a;) é vazia (a = inicializa();) ou é
//composta por uma raiz e duas sub-árvores (a = cria(c,sae,sad);). Assim, com
//posse dessas duas funções, podemos criar árvores mais complexas.
//Exemplo: Usando as operações inicializa e cria, crie uma estrutura que represente
//a árvore da Figura 13.5.

//	 a
//	/ \
//	b  c
//	\  /\
//	 d e f

//Para tratar a árvore vazia de forma diferente das outras, é importante ter uma operação
//que diz se uma árvore é ou não vazia. Podemos ter:
	
int vazia(Arv* a)
{
	return a==NULL;
}

//Uma outra função muito útil consiste em exibir o conteúdo da árvore. Essa função deve
//percorrer recursivamente a árvore, visitando todos os nós e imprimindo sua informação.
//A implementação dessa função usa a definição recursiva da árvore. Vimos que uma
//árvore binária ou é vazia ou é composta pela raiz e por duas sub-árvores. Portanto, para
//imprimir a informação de todos os nós da árvore, devemos primeiro testar se a árvore é
//vazia. Se não for, imprimimos a informação associada a raiz e chamamos
//(recursivamente) a função para imprimir os nós das sub-árvores.

void imprime (Arv* a)
{
	if (!vazia(a)){
		printf("%d ", a->info); /* mostra raiz */
		imprime(a->esq); /* mostra sae */
		imprime(a->dir); /* mostra sad */
	}
}	

// Exercício: Modifique a implementação de imprime, de forma que a saída impressa
//reflita, além do conteúdo de cada nó, a estrutura da árvore, usando a notação introduzida
//a n t e r i o r m e n t e . A s s i m , a s a í d a d a f u n ç ã o s e r i a :
//<a<b<><d<><>>><c<e<><>><f<><>>>>.

/*Retorna a soma do dado contido nas folhas*/
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
		printf("%d", a->info); /* mostra raiz */
		printf("<");
		imprime_alt(a->esq); /* mostra sae */
		printf(">");
		printf("<");
		imprime_alt(a->dir); /* mostra sad */
		printf(">");
		if (a->info == 6)
			printf(">");
	}
}	

//Uma outra operação que pode ser acrescentada é a operação para liberar a memória
//alocada pela estrutura da árvore. Novamente, usaremos uma implementação recursiva.
//Um cuidado essencial a ser tomado é que as sub-árvores devem ser liberadas antes de se
//liberar o nó raiz, para que o acesso às sub-árvores não seja perdido antes de sua
//remoção. Neste caso, vamos optar por fazer com que a função tenha como valor de
//retorno a árvore atualizada, isto é, uma árvore vazia, representada por NULL.

Arv* libera (Arv* a){
	if (!vazia(a)){
		libera(a->esq); /* libera sae */
		libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
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
	Arv* a1= cria(1,inicializa(),inicializa()); /* sub-árvore com 'd'*/
	Arv* a2= cria(2,inicializa(),a1); /* sub-árvore com 'b'*/
	Arv* a3= cria(3,inicializa(),inicializa()); /* sub-árvore com 'e'*/
	Arv* a4= cria(7,inicializa(),inicializa()); /* sub-árvore com 'f'*/
	Arv* a5= cria(5,a3,a4); /* sub-árvore com 'c'*/
	Arv* a = cria(6,a2,a5 ); /* árvore com raiz 'a'*/
	
	Arv* b1= cria(1,inicializa(),inicializa()); /* sub-árvore com 'd'*/
	Arv* b2= cria(2,inicializa(),b1); /* sub-árvore com 'b'*/
	Arv* b3= cria(3,inicializa(),inicializa()); /* sub-árvore com 'e'*/
	Arv* b4= cria(4,inicializa(),inicializa()); /* sub-árvore com 'f'*/
	Arv* b5= cria(5,b3,b4); /* sub-árvore com 'c'*/
	Arv* b = cria(6,b2,b5 );
	
	imprime(a);
	puts("");
	imprime(b);
	
	printf("\n\nIgual? %d\n",iguais(a,b));
	
	puts("");
	imprime_alt(a);
	puts("");
	// Devemos notar que a definição de árvore, por ser recursiva, não faz distinção entre
	// árvores e sub-árvores. Assim, cria pode ser usada para acrescentar (“enxertar”) uma
	// sub-árvore em um ramo de uma árvore, e libera pode ser usada para remover
	// (“podar”) uma sub-árvore qualquer de uma árvore dada.
	// Podemos acrescentar alguns nós, com:
	a->esq->esq = cria('x', // cria x
							cria('y',inicializa(),inicializa()), // cria y que e filho de b 
							cria('z',inicializa(),inicializa()) // cria z que e filho de b 
						);
	imprime_alt(a);						
	puts("");
	// E podemos liberar alguns outros, com:
	a->dir->esq = libera(a->dir->esq); // a direita da esquerda vai liberar o node e // poda árvore 
	imprime_alt(a);
	printf("\n\n%c", conta(a));					
}


