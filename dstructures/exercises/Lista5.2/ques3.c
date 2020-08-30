#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


typedef char string[100];
string s, nome_site[100], link[200];

struct list {
  int info;
  string meuSite;
  string link;
  struct lista* prox;
};

typedef struct list Lista;

Lista* inicializa(){
  
}

int main()
{

  return 0;
}

/*
Problema 3
Considere uma coleção de nomes de sites da web e seus respectivos links na Internet armazenados através de
uma lista simplesmente encadeada. Escreva a respectiva estrutura e um método que, dado o nome de um site,
busque o seu link correspondente na lista e ao mesmo tempo mova o nó que contém o nome buscado para o
início da lista, de forma que ele possa ser encontrado mais rapidamente na próxima vez que for buscado.
*/
