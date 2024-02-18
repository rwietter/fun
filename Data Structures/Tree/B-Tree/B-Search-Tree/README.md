# Binary Search Tree (bst)

>[!NOTE]
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

```md
Função insert(t: BTree, valor: inteiro) -> BTree
1) Verificar se a árvore está vazia:
    a) Se estiver vazia:
        i) Criar um novo nó com o valor fornecido.
        ii) Este nó se torna a raiz da árvore.
    b) Senão:
        i) Chamar a função insertNode na raiz da árvore, passando o valor fornecido.
2) Retornar a árvore modificada.

Função insertNode(n: Node, valor: inteiro)
1) Verificar se o valor é menor ou igual ao valor do nó atual (n):
    a) Se sim:
        i) Verificar se o filho esquerdo do nó atual é nulo:
            - Se for nulo, criar um novo nó com o valor fornecido e atribuí-lo como filho esquerdo do nó atual.
        ii) Senão:
            - Chamar recursivamente a função insertNode com o filho esquerdo como o novo nó atual.
    b) Senão:
        i) Verificar se o filho direito do nó atual é nulo:
            - Se for nulo, criar um novo nó com o valor fornecido e atribuí-lo como filho direito do nó atual.
        ii) Senão:
            - Chamar recursivamente a função insertNode com o filho direito como o novo nó atual.
```


```js
func (t *BTree) insert(value int) *BTree {
  if isTreeEmpty(t) {
    t.root = &Node{value: value, left: nil, right: nil}
  } else {
    t.root.insertNode(value)
  }
  return t
}

func (n *Node) insertNode(value int) {
  if value <= n.value {
    if n.left == nil {
      n.left = &Node{value: value, left: nil, right: nil}
    } else {
      n.left.insertNode(value)
    }
  } else {
    if n.right == nil {
      n.right = &Node{value: value, left: nil, right: nil}
    } else {
      n.right.insertNode(value)
    }
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
