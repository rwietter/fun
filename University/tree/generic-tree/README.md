# Generic Tree

Cada nó pode ter um número arbitrário de filhos. Essa estrutura deve ser usada, por exemplo, para representar uma árvore de diretórios.

## Regras

As árvores genéricas são as **árvores N-árias** que possuem as seguintes propriedades: 

1. Muitos filhos em cada nó.
2. O número de nós para cada nó não é conhecido antecipadamente.

```md
        a
     /  |  \
    b   f   g
   / \     / \
  c   e   h   i
  |           |
  d           j
```

Uma solução que leva a um aproveitamento melhor do espaço utiliza uma “lista de filhos”: um nó aponta apenas para seu primeiro (prim) filho, e cada um de seus filhos, exceto o último, aponta para o próximo (prox) irmão.

```c
struct arvgen {
  char info;
  struct arvgen *prim;
  struct arvgen *prox;
};
```