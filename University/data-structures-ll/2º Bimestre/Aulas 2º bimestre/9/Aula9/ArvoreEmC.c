#include <stdio.h>
#include <string.h>

//Cada n� deve armazenar tr�s informa��es: a informa��o propriamente dita, no caso um
//caractere, e dois ponteiros para as sub-�rvores, � esquerda e � direita. Ent�o a estrutura
//de C para representar o n� da �rvore pode ser dada por:

struct arv {
	char info;
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

Arv* cria(char c, Arv* sae, Arv* sad){
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
		printf("%c ", a->info); /* mostra raiz */
		imprime(a->esq); /* mostra sae */
		imprime(a->dir); /* mostra sad */
	}
}

// Exerc�cio: Modifique a implementa��o de imprime, de forma que a sa�da impressa
//reflita, al�m do conte�do de cada n�, a estrutura da �rvore, usando a nota��o introduzida
//a n t e r i o r m e n t e . A s s i m , a s a � d a d a f u n � � o s e r i a :
//<a<b<><d<><>>><c<e<><>><f<><>>>>.

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == 'a')
			printf("<");
		printf("%c", a->info); /* mostra raiz */
		printf("<");
		imprime_alt(a->esq); /* mostra sae */
		printf(">");
		printf("<");
		imprime_alt(a->dir); /* mostra sad */
		printf(">");
		if (a->info == 'a')
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

// Uma propriedade fundamental de todas as �rvores � que s� existe um caminho da raiz
// para qualquer n�. Com isto, podemos definir a altura de uma �rvore como sendo o
// comprimento do caminho mais longo da raiz at� uma das folhas. Por exemplo, a altura
// da �rvore da Figura 13.5 � 2, e a altura das �rvores da Figura 13.6 � 1. Assim, a altura
// de uma �rvore com um �nico n� raiz � zero e, por conseguinte, dizemos que a altura de
// uma �rvore vazia � negativa e vale -1.
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
		return 0; /* �rvore vazia: n�o encontrou */
	else
		return a->info==c || busca(a->esq,c) || busca(a->dir,c);
	// Note que esta forma de programar busca, em C, usando o operador l�gico || (�ou�)
	// faz com que a busca seja interrompida assim que o elemento � encontrado. Isto acontece
	// porque se c==a->info for verdadeiro, as duas outras express�es n�o chegam a ser
	// avaliadas. Analogamente, se o caractere for encontrado na sub-�rvore da esquerda, a
	// busca n�o prossegue na sub-�rvore da direita.
	// Podemos dizer que a express�o:
	// return c==a->info || busca(a->esq,c) || busca(a->dir,c);
	// � equivalente a:
	// if (c==a->info)
	//		return 1;
	// else if (busca(a->esq,c))
	// 		return 1;
	// else
	// 		return busca(a->dir,c);
}

main() {
	Arv* a1= cria('d',inicializa(),inicializa()); /* sub-�rvore com 'd'*/
	Arv* a2= cria('b',inicializa(),a1); /* sub-�rvore com 'b'*/
	Arv* a3= cria('e',inicializa(),inicializa()); /* sub-�rvore com 'e'*/
	Arv* a4= cria('f',inicializa(),inicializa()); /* sub-�rvore com 'f'*/
	Arv* a5= cria('c',a3,a4); /* sub-�rvore com 'c'*/
	Arv* a = cria('a',a2,a5 ); /* �rvore com raiz 'a'*/
	imprime(a);
	puts("");
	imprime_alt(a);
	// Exerc�cio: Escreva uma fun��o que percorre uma �rvore bin�ria para determinar sua
	// altura. O prot�tipo da fun��o pode ser dado por:
	// int altura(Arv* a);
	printf("\nint altura(Arv* a) %d", altura(a));
	// Uma outra fun��o que podemos considerar percorre a �rvore buscando a ocorr�ncia de
	// um determinado caractere c em um de seus n�s. Essa fun��o tem como retorno um
	// valor booleano (um ou zero) indicando a ocorr�ncia ou n�o do caractere na �rvore.
	// int busca (Arv* a, char c);
	printf("\nint busca (Arv* a, char c) %d", busca (a, 'a'));
	printf("\nint busca (Arv* a, char c) %d", busca (a, 'x'));
	libera(a);
}

// Finalmente, considerando que as fun��es discutidas e implementadas acima formam a
// interface do tipo abstrato para representar uma �rvore bin�ria, um arquivo de interface
// arvbin.h pode ser dado por:
//	typedef struct arv Arv;
//	Arv* inicializa (void);
//	Arv* cria (char c, Arv* e, Arv* d);
//	int vazia (Arv* a);
//	void imprime (Arv* a);
//	Arv* libera (Arv* a);
//	int busca (Arv* a, char c);

//Alternativamente, a �rvore poderia ser criada com uma �nica atribui��o, seguindo a sua
///estrutura, �recursivamente�:
//Arv* a = cria('a',
//cria('b',
//		inicializa(),
//		cria('d', inicializa(), inicializa())
//			),
//		cria('c',
//			cria('e', inicializa(), inicializa()),
//			cria('f', inicializa(), inicializa())
//			)
//		);
