#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
int info;
struct lista *prox;
};

int main()
{
	struct lista *base, *l1, *l2;
	struct lista *node;
	int lista_len = 0;
	int i;
	int len;

	for (i = 0; i < 5; i++, lista_len++)
	{
		node = (struct lista*) malloc(sizeof(struct lista));
		node->info = i+1;
		node->prox = NULL;

		if (lista_len == 0)
		{
			l1 = node;
			base = node;
		}
		else
		{
			base->prox = node;
			base = base->prox;
		}

	}

	//Copiando l1 para l2;
	len = sizeof(struct lista) * lista_len;
	l2 = (struct lista*) malloc(len);
	memcpy(l2, l1, len);

	//Verificando se copiou
	while (l2->prox != NULL)
	{
		node = l2;
		printf("Info: %d\n", node->info);
		l2 = l2->prox;
	}

	return 0;
}
