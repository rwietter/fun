# BTree

BTree é uma estrutura de dados em árvore balanceada que mantém os dados classificados e permite pesquisas, acesso sequencial, inserções e exclusões em tempo logarítmico. É amplamente utilizado em bancos de dados e sistemas de arquivos.

Uma árvore binária é uma estrutura de dados em árvore na qual cada nó tem no máximo dois filhos, chamados de filho esquerdo e filho direito. —  Wikipédia

Uma árvore binária é uma coleção de nós. Cada nó tem três atributos: **value**, **left** e **right**:

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
- **Root**: é o nó mais alto da árvore
- **Edge**: é a ligação entre dois nós
- **Parent**: é um nó que tem uma aresta para um nó filho
- **Child**: é um nó que tem um nó pai
- **Leaf**: é um nó que não tem um nó filho na árvore
- **Depth**: é o comprimento do caminho até à sua raiz
- **Height**: é o comprimento do caminho mais longo até uma folha, representado pelo número de arestas da raiz até a folha mais distante. A altura de uma árvore vazia é -1 e a altura de uma árvore com apenas um nó é 0.

## Inserção de nodes (Regras)
1. Se o node atual não tiver um filho esquerdo, criar-se-á um novo node e insira-o à esquerda do node atual (this.left).
2. Se tiver o filho esquerdo, criamos um novo node e o colocamos no lugar do filho esquerdo atual (this.left). Aloque este filho esquerdo para o filho esquerdo do novo node.

Fazemos o mesmo para o filho direito.

## Tree Traversal (Percorrer a árvore)

### Depth-First Search (DFS)
O DFS explora um caminho até uma folha antes de retroceder e explorar outro caminho. Ou seja, ele vai descendo até o nó mais baixo da esquerda e volta subindo e descendo até o nó mais baixo da direita (Pre-order).

- **Pre-order**: primeiro visitamos o nó atual, depois o nó esquerdo e, por fim, o nó direito.
- **In-order**: primeiro visitamos o nó esquerdo mais baixo, depois o nó atual e, por fim, o nó direito.
- **Post-order**: primeiro visitamos o nó esquerdo, depois o nó direito e, por fim, o nó atual.

```js
preOrderDFS() {
  console.log(this.value);
  if (this.left) this.left.preOrder();
  if (this.right) this.right.preOrder();
}

inOrderDFS() {
  if (this.left) this.left.inOrder();
  console.log(this.value);
  if (this.right) this.right.inOrder();
}

postOrderDFS() {
  if (this.left) this.left.postOrder();
  if (this.right) this.right.postOrder();
  console.log(this.value);
}
```

### Breadth-First Search (BFS)
O algoritmo BFS percorre a árvore nível por nível e por profundidade.

```js
bfs() {
  const queue = [this];
  while (queue.length) {
    const node = queue.shift();
    console.log(node.value);
    if (node.left) queue.push(node.left);
    if (node.right) queue.push(node.right);
  }
}
```

---

### Algoritmo Completo

```js
class BinaryTree {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }

  insertLeft(value) {
    if (this.left) {
      const node = new BinaryTree(value);
       // left node do novo nó recebe o nó esquerdo do nó atual
      node.left = this.left;
      // nó esquerdo do nó atual recebe o novo nó
      this.left = node;
    } else {
      this.left = new BinaryTree(value);
    }
  }

  insertRight(value) {
    if (this.right) {
      const node = new BinaryTree(value);
      node.right = this.right;
      this.right = node;
    } else {
      this.right = new BinaryTree(value);
    }
  }

  preOrderDFS() {
    console.log(this.value);
    if (this.left) this.left.preOrder();
    if (this.right) this.right.preOrder();
  }

  inOrderDFS() {
    if (this.left) this.left.inOrder();
    console.log(this.value);
    if (this.right) this.right.inOrder();
  }

  postOrderDFS() {
    if (this.left) this.left.postOrder();
    if (this.right) this.right.postOrder();
    console.log(this.value);
  }

  /**
  * Breadth-first search: percorre a árvore em largura
  */
  bfs() {
    const queue = [this];
    while (queue.length) {
      const node = queue.shift();
      console.log(node.value);
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
  }

  showBinaryTree(node, level = 0) {
    if (node) {
        this.showBinaryTree(node.right, level + 1);
        const space = " ".repeat(6 * level)
        console.log(space + `—> ${node.value}`);
        this.showBinaryTree(node.left, level + 1);
      }
    }
  }
}


const tree = new BinaryTree("a");
tree.insertLeft("b");
tree.insertRight("c");
tree.left.insertLeft("d");
tree.left.insertRight("e");
tree.right.insertLeft("f");
tree.right.insertRight("g");

tree.preOrder();
tree.inOrder();
tree.postOrder();
tree.bfs();

tree.showBinaryTree(tree);
```
