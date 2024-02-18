package main

import (
	"fmt"
	"io"
	"os"
)

type Node struct {
	value uint16
	left  *Node
	right *Node
}

func (n *Node) insert(value uint16, sae *Node, sad *Node) *Node {
	return &Node{
		value: value,
		left:  sae,
		right: sad,
	}
}

func isLeaf(n *Node) bool {
	return !isEmpty(n) && n.left == nil && n.right == nil
}

func isEmpty(n *Node) bool {
	return n == nil
}

func (n *Node) height() int {
	if isEmpty(n) {
		return 0
	}
	return max(n.left.height(), n.right.height()) + 1
}

func (n *Node) inOrder() {
	if isEmpty(n) {
		return
	}

	n.left.inOrder()
	fmt.Print(" -> ", n.value)
	n.right.inOrder()
}

func (n *Node) preOrder() {
	if isEmpty(n) {
		return
	}

	fmt.Print(" -> ", n.value)
	n.left.preOrder()
	n.right.preOrder()
}

func (n *Node) postOrder() {
	if isEmpty(n) {
		return
	}

	n.left.postOrder()
	n.right.postOrder()
	fmt.Print(" -> ", n.value)
}

// return first element by left-root-right
func (n *Node) first(node *Node, count *int, target int) *Node {
	if isEmpty(node) {
		return nil
	}

	left := n.first(node.left, count, target)
	if left != nil {
		return left
	}

	*count++
	if *count == target {
		return node
	}

	return n.first(node.right, count, target)
}

// return last element by left-root-right
func (n *Node) last(node *Node) *Node {
	if isEmpty(node) {
		return nil
	}

	n = n.last(node.left)

	if isLeaf(node) {
		return node
	}

	return n.last(node.right)
}

func main() {
	var tree, root *Node
	var l0 *Node = tree.insert(6, nil, nil)
	var l1 *Node = tree.insert(5, nil, l0)
	var l2 *Node = tree.insert(14, nil, nil)
	var r1 *Node = tree.insert(35, nil, nil)
	var l3 *Node = tree.insert(20, l1, l2)
	root = tree.insert(10, l3, r1)

	fmt.Println("Tree")
	printTree(os.Stdout, root, 0, 'R')

	fmt.Print("\nPre Order:")
	root.preOrder() //  10 -> 20 -> 5 -> 14 -> 35

	fmt.Print("\nIn Order:")
	root.inOrder() //  5 -> 20 -> 14 -> 10 -> 35

	fmt.Print("\nPost Order:")
	root.postOrder() // 5 -> 20 -> 14 -> 35 -> 10

	fmt.Print("\nHeight:", root.height())

	var count = 0
	fmt.Println("\nFirst:", root.first(root, &count, 3).value)

	fmt.Println("Last:", root.last(root).value)
}

/*
        10
      /    \
    20      35
  |   \
5      14
 \
  6
*/

func printTree(w io.Writer, node *Node, ns int, ch rune) {
	if node == nil {
		return
	}

	for i := 0; i < ns; i++ {
		fmt.Fprint(w, " ")
	}
	fmt.Fprintf(w, "%c:%v\n", ch, node.value)
	printTree(w, node.left, ns+2, 'E')
	printTree(w, node.right, ns+2, 'D')
}
