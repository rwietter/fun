# BTree

BTree é uma estrutura de dados em árvore balanceada que mantém os dados classificados e permite pesquisas, acesso sequencial, inserções e exclusões em tempo logarítmico. É amplamente utilizado em bancos de dados e sistemas de arquivos.

Uma árvore binária é uma estrutura de dados em árvore na qual cada nó tem no máximo dois filhos, chamados de filho esquerdo e filho direito. —  Wikipédia

Uma árvore binária é uma coleção de nós. Cada nó tem três atributos: **value**, **left** e **right**:

O Address de uma Binary Tree deve ser a raiz da árvore. A raiz é o único nó que não tem um nó pai.

## Tipos de Árvore Binárias

- Balanced tree: Uma árvore na qual as alturas das subárvores esquerda e direita de qualquer nó diferem em no máximo 1. No Exemplo 1, as árvores B, C estão balanceadas.
- Full Binary Tree: uma árvore binária em que cada nó possui 0 ou 2 filhos.
- Complete binary tree: Uma árvore binária na qual todos os níveis, exceto possivelmente o último nível, são completamente preenchidos e todos os nós do último nível estão o mais à esquerda possível.
- Degenerate tree: cada nó não-folha tem apenas um filho em uma árvore binária conhecida como árvore binária degenerada.

### Balanced tree

Uma árvore equilibrada permitirá que você corte a árvore ao meio, deixando metade à esquerda e a outra metade à direita. Ao contrário de uma árvore degenerada onde 100% dos nós restantes ainda estão no mesmo lado. Árvores degeneradas são ruins para fazer uma árvore de pesquisa binária. Eles são mais semelhantes a uma lista vinculada ou a um array.

### Full Binary Tree

### Complete binary tree

### Degenerate tree

```md
    1
   /
  2
 /
3

2
  \
    3
      \
       4
```

## Terminologia

- **Tree**: é uma estrutura de dados que representa dados hierárquicos. Uma árvore consiste em nós com um relacionamento pai-filho.
- **Subtree**: é uma árvore derivada de outro nó, chamado de nó pai que possui pelo menos um nó filho.
- **Root**: é o nó mais alto da árvore
- **Nodes | Cells**: é um elemento da árvore que tem um valor e referencia outros nós
- **Edge**: é a ligação entre dois nós
- **Parent**: é um nó que tem uma aresta para um nó filho
- **Child**: é um nó que tem um nó pai, ou seja, é um nó filho de outro nó
- **Leaf**: é um nó que não tem um nó filho na árvore
- **Depth**: é o comprimento do caminho até à sua raiz
- **Height**: é o comprimento do caminho mais longo até uma folha, representado pelo número de arestas da raiz até a folha mais distante. A altura de uma árvore vazia é -1 e a altura de uma árvore com apenas um nó é 0.

Um Node precisa ter um valor de dados e referências para seus filhos esquerdo e direito.

```go
type Node struct {
  content uint64
  left *Node
  right *Node
}
```

## Operações

- **Insert**: insere um novo nó na árvore
- **Search**: pesquisa um nó na árvore
- **Delete**: remove um nó da árvore
- **Traverse**: percorre a árvore (DFS e BFS)
- **Height**: retorna a altura da árvore
- **Depth**: retorna a profundidade da árvore
- **Size**: retorna o número de nós na árvore
- **Min**: retorna o menor valor da árvore
- **Max**: retorna o maior valor da árvore
- **Successor**: retorna o sucessor de um nó
- **Predecessor**: retorna o predecessor de um nó
- **PreOrder | Prefix**: retorna os nós em pré-ordem
- **InOrder | Infix**: retorna os nós em ordem crescente
- **PostOrder | Postfix**: retorna os nós em pós-ordem
- **Free**: remove todos os nós da árvore

## Inserção de Nodes (Rules)

1. Se o Node atual não tiver um filho esquerdo, criar-se-á um novo node e insira-o à esquerda do node atual.
2. Se tiver o filho esquerdo, criamos um novo node e o colocamos no lugar do filho esquerdo atual.
3. Se o Node atual não tiver um filho direito, criar-se-á um novo node e insira-o à direita do node atual.
4. Se tiver o filho esquerdo, criamos um novo node e o colocamos no lugar do filho direito atual.

# Height

A altura de uma árvore pode ser obtida percorrendo da raiz até a folha mais distante em qualquer ordem. A altura de uma árvore vazia é -1 e a altura de uma árvore com apenas um nó é 0.

```go
func (n *Node) height() {
  if isEmpty(n) {
		return -1
	}
  return max(n.left.height(), n.right.height()) + 1 // +1 para somar cada nível da árvore
}
```

## First (left-root-right)

```go
func (n *Node) first() *Node {
	if isEmpty(n) {
		return nil
	}

	if n.left != nil {
		n = n.left
		n.left.first()
	}
	return n
}
``````

## Tree Traversal (Percorrer a árvore)

### Depth-First Search (DFS)

O DFS explora um caminho até uma folha antes de retroceder e explorar outro caminho. Ou seja, ele vai descendo até o nó mais baixo da esquerda e volta subindo e descendo até o nó mais baixo da direita (Pre-order).

- **Pre-order**: primeiro visitamos o nó raiz, depois o nó esquerdo e, por fim, o nó direito.
- **In-order**: primeiro visitamos o nó esquerdo mais baixo, depois o nó atual e, por fim, o nó direito.
- **Post-order**: primeiro visitamos o nó esquerdo, depois o nó direito e, por fim, o nó atual.

```js
preOrder() {
  console.log(this.value);
  if (this.left) this.left.preOrder();
  if (this.right) this.right.preOrder();
}

inOrder() {
  if (this.left) this.left.inOrder();
  console.log(this.value);
  if (this.right) this.right.inOrder();
}

postOrder() {
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
