#include <stdio.h>
#include <D:\TESE\Dropbox\DRIVE_D\Aulas UFSM-FW\Programação e Estrutura 2019-2\Aula2\str.h>

int comprimento (char* str) {
	return sizeof(str);
}

void copia (char* dest, char* orig) {
}

void concatena (char* dest, char* orig) {
}

int main (void) {
	char str[101], str1[51], str2[51];
	printf("Entre com uma sequência de caracteres: ");
	scanf(" %50[^\n]", str1);
	printf("Entre com outra sequência de caracteres: ");
	scanf(" %50[^\n]", str2);
	copia(str, str1);
	concatena(str, str2);
	printf("Comprimento da concatenação: %d\n",comprimento(str));
	return 0;
}
