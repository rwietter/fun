#include <stdio.h>
#include <string.h>

//Cada n� deve armazenar tr�s informa��es: a informa��o propriamente dita, no caso um
//caractere, e dois ponteiros para as sub-�rvores, � esquerda e � direita. Ent�o a estrutura
//de C para representar o n� da �rvore pode ser dada por:

struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};

//Da mesma forma que uma lista encadeada � representada por um ponteiro para o
//primeiro n�, a estrutura da �rvore como um todo � representada por um ponteiro para o
//n� raiz.
//Como acontece com qualquer TAD (tipo abstrato de dados), as opera��es que fazem
//sentido para uma �rvore bin�ria dependem essencialmente da forma de utiliza��o que se
//pretende fazer da �rvore. Nesta se��o, em vez de discutirmos a interface do tipo abstrato
//para depois mostrarmos sua implementa��o, vamos optar por discutir algumas
//opera��es mostrando simultaneamente suas implementa��es. Ao final da se��o
//apresentaremos um arquivo que pode representar a interface do tipo. Nas fun��es que se
//seguem, consideraremos que existe o tipo Arv definido por:

typedef struct arv Arv;

//Como veremos as fun��es que manipulam �rvores s�o, em geral, implementadas de
//forma recursiva, usando a defini��o recursiva da estrutura.

//Vamos procurar identificar e descrever apenas opera��es cuja utilidade seja a mais geral
//poss�vel. Uma opera��o que provavelmente dever� ser inclu�da em todos os casos � a
//inicializa��o de uma �rvore vazia. Como uma �rvore � representada pelo endere�o do
//n� raiz, uma �rvore vazia tem que ser representada pelo valor NULL. Assim, a fun��o
//que inicializa uma �rvore vazia pode ser simplesmente:

Arv* inicializa(void)
{
	return NULL;
}

//Para criar �rvores n�o vazias, podemos ter uma opera��o que cria um n� raiz dadas a
//informa��o e suas duas sub-�rvores, � esquerda e � direita. Essa fun��o tem como valor
//de retorno o endere�o do n� raiz criado e pode ser dada por:

Arv* cria(int c, Arv* sae, Arv* sad){
	Arv* p=(Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

//As duas fun��es inicializa e cria representam os dois casos da defini��o recursiva
//de �rvore bin�ria: uma �rvore bin�ria (Arv* a;) � vazia (a = inicializa();) ou �
//composta por uma raiz e duas sub-�rvores (a = cria(c,sae,sad);). Assim, com
//posse dessas duas fun��es, podemos criar �rvores mais complexas.
//Exemplo: Usando as opera��es inicializa e cria, crie uma estrutura que represente
//a �rvore da Figura 13.5.

//	 a
//	/ \
//	b  c
//	\  /\
//	 d e f

//Para tratar a �rvore vazia de forma diferente das outras, � importante ter uma opera��o
//que diz se uma �rvore � ou n�o vazia. Podemos ter:
	
int vazia(Arv* a)
{
	return a==NULL;
}

//Uma outra fun��o muito �til consiste em exibir o conte�do da �rvore. Essa fun��o deve
//percorrer recursivamente a �rvore, visitando todos os n�s e imprimindo sua informa��o.
//A implementa��o dessa fun��o usa a defini��o recursiva da �rvore. Vimos que uma
//�rvore bin�ria ou � vazia ou � composta pela raiz e por duas sub-�rvores. Portanto, para
//imprimir a informa��o de todos os n�s da �rvore, devemos primeiro testar se a �rvore �
//vazia. Se n�o for, imprimimos a informa��o associada a raiz e chamamos
//(recursivamente) a fun��o para imprimir os n�s das sub-�rvores.

void imprime (Arv* a)
{
	if (!vazia(a)){
		printf("%d ", a->info); /* mostra raiz */
		imprime(a->esq); /* mostra sae */
		imprime(a->dir); /* mostra sad */
	}
}	

// Exerc�cio: Modifique a implementa��o de imprime, de forma que a sa�da impressa
//reflita, al�m do conte�do de cada n�, a estrutura da �rvore, usando a nota��o introduzida
//a n t e r i o r m e n t e . A s s i m , a s a � d a d a f u n � � o s e r i a :
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

//Uma outra opera��o que pode ser acrescentada � a opera��o para liberar a mem�ria
//alocada pela estrutura da �rvore. Novamente, usaremos uma implementa��o recursiva.
//Um cuidado essencial a ser tomado � que as sub-�rvores devem ser liberadas antes de se
//liberar o n� raiz, para que o acesso �s sub-�rvores n�o seja perdido antes de sua
//remo��o. Neste caso, vamos optar por fazer com que a fun��o tenha como valor de
//retorno a �rvore atualizada, isto �, uma �rvore vazia, representada por NULL.

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
	Arv* a1= cria(1,inicializa(),inicializa()); /* sub-�rvore com 'd'*/
	Arv* a2= cria(2,inicializa(),a1); /* sub-�rvore com 'b'*/
	Arv* a3= cria(3,inicializa(),inicializa()); /* sub-�rvore com 'e'*/
	Arv* a4= cria(7,inicializa(),inicializa()); /* sub-�rvore com 'f'*/
	Arv* a5= cria(5,a3,a4); /* sub-�rvore com 'c'*/
	Arv* a = cria(6,a2,a5 ); /* �rvore com raiz 'a'*/
	
	Arv* b1= cria(1,inicializa(),inicializa()); /* sub-�rvore com 'd'*/
	Arv* b2= cria(2,inicializa(),b1); /* sub-�rvore com 'b'*/
	Arv* b3= cria(3,inicializa(),inicializa()); /* sub-�rvore com 'e'*/
	Arv* b4= cria(4,inicializa(),inicializa()); /* sub-�rvore com 'f'*/
	Arv* b5= cria(5,b3,b4); /* sub-�rvore com 'c'*/
	Arv* b = cria(6,b2,b5 );
	
	imprime(a);
	puts("");
	imprime(b);
	
	printf("\n\nIgual? %d\n",iguais(a,b));
	
	puts("");
	imprime_alt(a);
	puts("");
	// Devemos notar que a defini��o de �rvore, por ser recursiva, n�o faz distin��o entre
	// �rvores e sub-�rvores. Assim, cria pode ser usada para acrescentar (�enxertar�) uma
	// sub-�rvore em um ramo de uma �rvore, e libera pode ser usada para remover
	// (�podar�) uma sub-�rvore qualquer de uma �rvore dada.
	// Podemos acrescentar alguns n�s, com:
	a->esq->esq = cria('x', // cria x
							cria('y',inicializa(),inicializa()), // cria y que e filho de b 
							cria('z',inicializa(),inicializa()) // cria z que e filho de b 
						);
	imprime_alt(a);						
	puts("");
	// E podemos liberar alguns outros, com:
	a->dir->esq = libera(a->dir->esq); // a direita da esquerda vai liberar o node e // poda �rvore 
	imprime_alt(a);
	printf("Conta: %d", conta(a));
	printf("\n\nIgual? %d\n",iguais(a,a));
}


