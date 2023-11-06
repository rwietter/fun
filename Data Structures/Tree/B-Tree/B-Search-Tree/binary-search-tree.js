class BinarySearchTree {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }

  insert(value) { // O(log n)
    if (value <= this.value) {
      if (this.left) this.left.insert(value);
      else this.left = new BinarySearchTree(value);
    }
    else {
      if (this.right) this.right.insert(value);
      else this.right = new BinarySearchTree(value);
    }
  }

  printTreeDebug(node, level = 0) {
    if(node.right) this.printTreeDebug(node.right, level + 1);
    console.log((" ").repeat(6 * level) + `—> ${node.value}`);
    if (node.left) this.printTreeDebug(node.left, level + 1);
  }

  find(value) { // O(log n)
    if (value === this.value) return this;

    if (value < this.value) {
      if (this.left) return this.left.find(value);
      else return null;
    }
    else {
      if (this.right) return this.right.find(value);
      else return null;
    }
  }
}

const bst = new BinarySearchTree(10);
bst.insert(5);
bst.insert(15);
bst.insert(8);
bst.insert(3);
bst.insert(20);

bst.printTreeDebug(bst);

console.log(bst.find(8));