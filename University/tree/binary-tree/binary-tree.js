class BinaryTree {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }

  insertLeft(value) {
    if (this.left) {
      const node = new BinaryTree(value);
      node.left = this.left; // node esquerdo do novo nó recebe o nó esquerdo do nó atual
      this.left = node; // nó esquerdo do nó atual recebe o novo nó
    } else {
      this.left = new BinaryTree(value);
    }
  }

  insertRight(value) {
    if (this.right) {
      const node = new BinaryTree(value);
      node.right = this.right; // node direito do novo nó recebe o nó direito do nó atual
      this.right = node; // nó direito do nó atual recebe o novo nó
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
      console.log(" ".repeat(6 * level) + `—> ${node.value}`);
      this.showBinaryTree(node.left, level + 1);
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
