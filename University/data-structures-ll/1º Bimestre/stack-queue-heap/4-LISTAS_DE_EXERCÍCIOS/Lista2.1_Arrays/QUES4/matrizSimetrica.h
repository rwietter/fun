/* TAD: matriz m por n */

/* Tipo exportado */
typedef struct matrizSimetrica Matriz;

/* Fun��es exportadas */

/* Fun��o cria
** Aloca e retorna uma matriz de dimens�o m por n
*/
Matriz* cria (int m, int n);

/* Fun��o libera
** Libera a mem�ria de uma matriz previamente criada.
*/
void libera (Matriz* mat);

/* Fun��o acessa
** Retorna o valor do elemento da linha i e coluna j da matriz
*/
int acessa(Matriz* mat, int i, int j);

/* Fun��o atribui
** Atribui o valor dado ao elemento da linha i e coluna j da matriz
*/
Matriz* insere(Matriz* mat, int i, int j, int v);

/* Fun��o linhas
** Retorna o n�mero de linhas da matriz
*/
int linhas (Matriz* mat);

/* Fun��o colunas
** Retorna o n�mero de colunas da matriz
*/
int colunas (Matriz* mat);
