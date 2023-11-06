# Binary Search Tree (bst)

> "Uma árvore de busca binária às vezes é chamada de árvore binária ordenada ou classificada, pois mantém seus valores em ordem de classificação, para que a pesquisa e outras operações possam usar o princípio da pesquisa binária" —  Wikipedia

Uma propriedade importante de uma árvore de busca binária é que o **valor de um nó da árvore de busca binária** é **maior que o valor do filho de seu filho esquerdo**, mas **menor que o valor do filho de seu filho direito**. Exemplo:

- **Valor da raiz**: 5
- **Valor do filho da esquerda**: 3
- **Valor do filho da direita**: 7

Valores menores que o valor da raiz vão para a esquerda da árvore e os valores maiores que o valor da raiz vão para a direita da raiz.

```md
		 5
	 /   \
	3     7
 / \   / \
1   4 6   8
```

### Inserção

A inserção deve seguir o padrão de ordenação, onde os valores menores que o valor raiz vão para a esquerda e os valores maiores que a raiz vão para a direita. O filho da subárvore a esquerda é menor que a subárvore e o filho da subárvore a direita é maior que a subárvore.

```js
procedimento insert(valor)
    se valor menor que valor da raiz então
        se o nó da esquerda não for nulo então
            nó.da.esquerda.insere(valor)
        senão
            nó da esquerda := cria BinarySearchTree(valor)
        fim se
    senão
        se nó da direita não for nulo então
            nó.da.direita.insere(valor)
        senão
            nó.da.direita := cria BinarySearchTree(valor)
        fim se
    fim se
fim procedimento
```


```js
insert(value) { // O(log n)
	if (value <= this.value) {
		if (this.left) {
			this.left.insert(value);
		} else {
			this.left = new BinarySearchTree(value);
		}
	}
}
else {
	if (this.right) {
		this.right.insert(value)
	}
	else {
		this.right = new BinarySearchTree(value);
	}
}
```

### Busca

A busca consiste em criar duas ramificações, a primeira vai verificar se o valor é menor que o valor da esquerda, se for, vai para a esquerda, se não, vai para a direita. A segunda ramificação vai para a direita.

```js
find(value) { // O(log n)
	if (value === this.value) return this;
	
	if (value < this.value) {
		if (this.left) {
			return this.left.find(value);
		} {
			else return null;
		}
	}
	else {
		if (this.right) {
			return this.right.find(value);
		}
		else {
			return null;
		}
	}
}
```