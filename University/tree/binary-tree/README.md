# Binary Tree

Na ciência da computação, uma árvore binária é uma estrutura de dados em árvore na qual cada nó tem no máximo dois filhos, chamados de filho esquerdo e filho direito. — Wikipédia

Uma árvore binária é uma coleção de nós. Cada nó tem três atributos: valor, left e right:

```js
class BinaryTree {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}
```

## Terminologia

- Root: é o nó mais alto da árvore
- Edge: é a ligação entre dois nós
- Parent: é um nó que tem uma aresta para um nó filho
- Child: é um nó que tem um nó pai
- Leaf: é um nó que não tem um nó filho na árvore
- Depth: é o comprimento do caminho até à sua raiz
- Height: é o comprimento do caminho mais longo até uma folha, representado pelo número de arestas da raiz até a folha mais distante. A altura de uma árvore vazia é -1 e a altura de uma árvore com apenas um nó é 0.

## Inserção de nodes (Regras)

1. Se o node atual não tiver um filho esquerdo, criar-se-á um novo node e insira-o à esquerda do node atual (this.left).
2. Se tiver o filho esquerdo, criamos um novo node e o colocamos no lugar do filho esquerdo atual (this.left). Aloque este filho esquerdo para o filho esquerdo do novo node.

Fazemos o mesmo para o filho direito.

## Tree Traversal (Percorrer a árvore)

### Depth-First Search (DFS)

O DFS explora um caminho até uma folha antes de retroceder e explorar outro caminho. Ou seja, ele vai descendo até o nó mais baixo da esquerda e volta subindo e descendo até o nó mais baixo da direita (Pre-order).

- Pre-order: primeiro visitamos o nó atual, depois o nó esquerdo e, por fim, o nó direito.
- In-order: primeiro visitamos o nó esquerdo mais baixo, depois o nó atual e, por fim, o nó direito.
- Post-order: primeiro visitamos o nó esquerdo, depois o nó direito e, por fim, o nó atual.

### Breadth-First Search (BFS)

O algoritmo BFS percorre a árvore nível por nível e por profundidade.
