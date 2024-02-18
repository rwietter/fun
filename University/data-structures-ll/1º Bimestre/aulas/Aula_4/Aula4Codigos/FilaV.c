// Podemos declarar o tipo fila como sendo uma estrutura com três componentes:

// um vetor vet de tamanho N,
// um índice ini para o início da fila e
// um índice fim para o fim da fila.

/* Conforme ilustrado nas figuras acima, usamos as seguintes convenções para a
 identificação da fila:
 O ini marca a posição do próximo elemento a ser retirado da fila;
 O fim marca a posição (vazia), onde será inserido o próximo elemento.
 Desta forma, a fila vazia se caracteriza por ter ini == fim e a fila cheia (quando não é
 possível inserir mais elementos) se caracteriza por ter fim e ini em posições
 consecutivas (circularmente): incr(fim) == ini. Note que, com essas convenções,
 a posição indicada por fim permanece sempre vazia, de forma que o número máximo
 de elementos na fila é N-1. Isto é necessário porque a inserção de mais um elemento
 faria ini == fim, e haveria uma ambiguidade entre fila cheia e fila vazia. Outra
 estratégia possível consiste em armazenar uma informação adicional, n, que indicaria
 explicitamente o número de elementos armazenados na fila. Assim, a fila estaria vazia
 se n == 0 e cheia se n == N-1. Nos exemplos que se seguem, optamos por não
 armazenar n explicitamente.*/

#define N 100

struct fila {
	int ini, fim;
	float vet[N];
};

typedef struct fila Fila;

int incr (int i)
{
	if (i == N-1)
		return 0;
	else
		return i+1;
}

/* A função para criar a fila aloca dinamicamente essa estrutura e inicializa a fila como
 sendo vazia, isto é, com os �ndices ini e fim iguais entre si (no caso, usamos o valor
 zero).*/

Fila* cria (void)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = 0; /* inicializa fila vazia */
	return f;
}

/*Para inserir um elemento na fila, usamos a próxima posição livre do vetor, indicada por
 fim. Devemos ainda assegurar que há espaço para a inserção do novo elemento, tendo
 em vista que trata-se de um vetor com capacidade limitada. Consideraremos que a
 função auxiliar que faz o incremento circular está disponível.*/

void insere (Fila* f, float v)
{
	if (incr(f->fim) == f->ini) { /* fila cheia: capacidade esgotada */
		printf("Capacidade da fila estourou.\n");
		exit(1); /* aborta programa */
	}
	f->vet[f->fim] = v; /* insere elemento na próxima posiçao livre */
	f->fim = incr(f->fim);
}

float retira (Fila* f) // A função para retirar o elemento do início da fila fornece o valor do elemento retirado como retorno.
{
	float v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	v = f->vet[f->ini]; // retira elemento do início
	f->ini = incr(f->ini);
	return v;
}


int vazia (Fila* f) // Fila vazia?
{
	return (f->ini == f->fim);
}

void libera (Fila* f)
{
	free(f);
}

void imprime (Fila* f)
{
	int i;
	for (i=f->ini; i!=f->fim; i=incr(i))
		printf("%f\n",f->vet[i]);
}

main() {
	Fila* f;
	f = cria();
	insere(f, 2.2);
	insere(f, 3.2);
	insere(f, 4.2);
	imprime(f);
	printf("\n%f",retira(f));
	printf("\n%f\n",retira(f));
	imprime(f);
}
