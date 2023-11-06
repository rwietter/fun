// Matriz representada por um vetor simples

// Conceitualmente, podemos representar uma matriz num vetor simples. Reservamos as
// primeiras posições do vetor para armazenar os elementos da primeira linha, seguidos dos
// elementos da segunda linha, e assim por diante. Como, de fato, trabalharemos com um
// vetor unidimensional, temos que criar uma disciplina para acessar os elementos da matriz,
// representada conceitualmente. A estratégia de endereçamento para acessar os elementos é a
// seguinte: se quisermos acessar o que seria o elemento mat[i][j] de uma matriz, devemos
// acessar o elemento v[i*n+j], onde n representa o número de colunas da matriz.

#define M 3
#define N 4

int mat[M][N];
int v[M*N];

// como achar v[]?

v[i*n+j]; // onde n representa o número de colunas da matriz.

// Com esta estratégia, a alocação da “matriz” recai numa alocação de vetor que tem m*n
// elementos, onde m e n representam as dimensões da matriz.

float *mat; /* matriz representada por um vetor */
...
mat = (float*) malloc(m*n*sizeof(float));
...

// No entanto, somos obrigados a usar uma notação desconfortável, v[i*n+j], para acessar
// os elementos, o que pode deixar o código pouco legível.

------------------------------

// Matriz representada por um vetor de ponteiros

// Nesta segunda estratégia, cada linha da matriz é representada por um vetor
// independente. A matriz é então representada por um vetor de vetores, ou vetor de ponteiros,
// no qual cada elemento armazena o endereço do primeiro elemento de cada linha. 

// A alocação da matriz agora é mais elaborada. Primeiro, temos que alocar o vetor de
// ponteiros. Em seguida, alocamos cada uma das linhas da matriz, atribuindo seus endereços
// aos elementos do vetor de ponteiros criado. O fragmento de código abaixo ilustra esta
// codificação:

int i;

float **mat; /* matriz representada por um vetor de ponteiros */
...

mat = (float**) malloc(m*sizeof(float*));
for (i=0; i<m; i++)
	m[i] = (float*) malloc(n*sizeof(float));

// A grande vantagem desta estratégia é que o acesso aos elementos é feito da mesma forma
// que quando temos uma matriz criada estaticamente, pois, se mat representa uma matriz
// alocada segundo esta estratégia, mat[i] representa o ponteiro para o primeiro elemento da
// linha i, e, conseqüentemente, mat[i][j] acessa o elemento da coluna j da linha i.
// A liberação do espaço de memória ocupado pela matriz também exige a construção de um
// laço, pois temos que liberar cada linha antes de liberar o vetor de ponteiros:

...
for (i=0; i<m; i++)
free(mat[i]);
free(mat);

mat[i][j]; // BOA NOTICIA!!!!
