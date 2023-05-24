#include <stdio.h>

char *palavra = "OLA_MUNDO";

// Exemplo. Impressão caractere por caractere.
// Uma versão recursiva da função para imprimir a cadeia 
// caractere por caractere é mostrada a seguir. 
void imprime_rec (char* s)
{
	if (s[0] != '\0')
	{
		printf("%c",s[0]);
		imprime_rec(&s[1]);
	}
}

// Imprime em ordem inversa
void imprime_inv (char* s)
{
	if (s[0] != '\0')
	{
		imprime_inv(&s[1]);
		printf("%c",s[0]);
	}
}

// Exemplo. Comprimento da cadeia de caracteres.
// Uma implementação recursiva da função que retorna o número de caracteres existentes na
// cadeia é mostrada a seguir:
int comprimento_rec (char* s)
{
	if (s[0] == '\0')
		return 0;
	else
		return 1 + comprimento_rec(&s[1]);
}

// Exemplo. Cópia de cadeia de caracteres.
// Vamos mostrar agora uma possível implementação recursiva 
// da função copia mostrada anteriormente.
void copia_rec (char* dest, char* orig)
{
	if (orig[0] == '\0')
		dest[0] = '\0';
	else {
		dest[0] = orig[0];
		copia_rec(&dest[1],&orig[1]);
	}
}

//É fácil verificar que o código acima pode ser escrito 
// de forma mais compacta:
void copia_rec_2 (char* dest, char* orig)
{
	dest[0] = orig[0];
	if (orig[0] != '\0')
		copia_rec_2(&dest[1],&orig[1]);
}

main() {
	imprime_rec(palavra);
	puts("");
	imprime_inv(palavra);
	puts("");
	printf("%d",comprimento_rec(palavra));
	puts("");
	char palavra_destino[sizeof(palavra)];
	copia_rec (palavra_destino, palavra);
	printf("%s",palavra_destino);
	puts("");
	char *palavra3 = "OLA_MUNDO_NOVO";
	char palavra4[sizeof(palavra3)];
	copia_rec_2 (palavra4, palavra3);
	printf("%s",palavra4);
}
