struct arvgen {
   char info;
   struct arvgen *prim;
   struct arvgen *prox;
};
 
typedef struct arvgen ArvGen;

ArvGen* insere(int valor)
{
    ArvGen *node = (ArvGen*) malloc(sizeof(ArvGen));
    node->info = valor;
    node->prim = NULL;
    node->prox = NULL;
    return node;
}

void organizaArvore(ArvGen* arv, ArvGen* subarv)
{
  	subarv->prox = arv->prim;
	arv->prim = subarv;
}

void imprime (ArvGen* a)
{
	ArvGen* p;
	printf("%d ",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
	{
		imprime(p);
	}
}

// remover uma folha qualquer desta árvore, sem alterar sua estrutura restante
void apaga_folha (ArvGen* a, ArvGen* folha) {

}


int main(int argc, char const *argv[]) {
  ArvGen* a = insere(6);
  ArvGen* b = insere(5);
  ArvGen* c = insere(4);
  ArvGen* d = insere(3);
  ArvGen* e = insere(2);
  ArvGen* f = insere(1);
  organizaArvore(a,b);
  organizaArvore(a,c);
  organizaArvore(a,d);
  organizaArvore(d,e);
  organizaArvore(b,f);
  imprime(a);
  return 0;
}
