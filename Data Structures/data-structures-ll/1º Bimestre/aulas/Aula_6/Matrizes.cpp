// A linguagem C permite a criação de vetores bidimensionais, 
// declarados estaticamente. Por exemplo, para declararmos uma 
// matriz de valores reais com 4 linhas e 3 colunas, fazemos:

float mat[4][3];

// Esta declaração reserva um espaço de memória necessário para 
// armazenar os 12 elementos da matriz, que são armazenados de 
// maneira contínua, organizados linha a linha.

float m[4][3] = {{ 5.0,10.0,15.0},
				 {20.0,25.0,30.0},
				 {35.0,40.0,45.0},
				 {50.0,55.0,60.0}};
				 
// As matrizes também podem ser inicializadas na declaração:

float mat[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

// Ou podemos inicializar seqüencialmente:

float mat[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};

// O número de elementos por linha pode ser omitido numa 
// inicialização, mas o número de colunas deve, obrigatoriamente, 
// ser fornecido:

float mat[][3] = {1,2,3,4,5,6,7,8,9,10,11,12};				 

// Passagem de matrizes para funções

void f (..., float (*mat)[3], ...);

//Uma segunda opção é declarar o parâmetro como matriz, podendo 
// omitir o número de linhas2:

void f (..., float mat[][3], ...);

// De qualquer forma, o acesso aos elementos da matriz dentro da 
// função é feito da forma usual, com indexação dupla.

// ALTERNATIVA:

// Por exemplo, podemos definir o tipo Matrix4.

typedef float Matrix4[4][4];

// Com esta definição podemos declarar variáveis e parâmetros deste 
// tipo:

Matrix4 m; /* declaração de variável */
...
void f (..., Matrix4 m, ...); /* especificação de parâmetro */
