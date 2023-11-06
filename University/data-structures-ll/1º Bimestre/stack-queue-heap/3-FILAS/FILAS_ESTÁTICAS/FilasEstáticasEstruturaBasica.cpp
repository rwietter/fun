#include <stdio.h>
//definindo tamanho como uma constante...
#define tam 10
//inicializando a fila com tamanho 0...
int fila[tam];
int head = 0;
int tail = 0;

void listar_fila(){
	int i=0;
	for(i=0; i<tam; i++){
		printf("%d\n", fila[i]);
	}
	printf("Head = %d\n", head);
	printf("Tail = %d\n", tail);
}

void inserir(int data){
	int i=0, val;
	if(tail<tam){
		val = data;
		fila[tail] = val; //Tail, recebe valor para ir preenchendo espa�os da fila...
		tail++;
	}else{
		printf("A fila esta cheia\n");
	}
}

void remover(){
	if(head<tail){ //se head < tail ae remove/significa que tem valores...
		fila[head] = 0;
		head++;
		listar_fila();
	}else{//se não...
		printf("A fila esta vazia\n");
	}
}

void limpar_fila(){
	int i=0;
	for(i=0; i<tam; i++){
		fila[i] = 0;
	}
	head = 0;
	tail = 0;
}

int main(){
	inserir(21);
	inserir(22);
	inserir(23);
	inserir(24);
	inserir(21);
	inserir(22);
	inserir(23);
	inserir(24);
	inserir(23);
	inserir(24);
	listar_fila();
	return 0;
}
