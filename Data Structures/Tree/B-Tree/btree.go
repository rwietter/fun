package main

import (
	"fmt"
	"io"
	"os"
	"strings"
)

type Node struct {
	value       int
	left, right *Node
}

type BTree struct {
	root *Node
}

func isTreeEmpty(t *BTree) bool {
	return t.root == nil
}

func isNodeEmpty(n *Node) bool {
	return n == nil
}

func (t *BTree) insert(value int) *BTree {
	if isTreeEmpty(t) {
		t.root = &Node{value: value, left: nil, right: nil}
	} else {
		t.root.insertNode(value)
	}
	return t
}

// 1. value < root && node.left == nil: insert in left
// 2. value > root && node.right == nil: insert in right
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

func (n *Node) print(node *Node, space *int) {
	if node == nil {
		return
	}

	node.print(node.left, space)
	fmt.Print(strings.Repeat(" ", *space), node.value)
	node.print(node.right, space)
}

func main() {
	var tree *BTree = &BTree{}
	tree.
		insert(10).
		insert(11).
		insert(8).
		insert(5).
		insert(7).
		insert(14).
		insert(12).
		insert(8).
		insert(13)

	printTree(os.Stdout, tree.root, 0, 'T')
	// displayTree(tree.root, 0, 0)
}

/*
            10
         /     \
       8        11
     /            \
   5              14
    \            /
     7         12
      \         \
       8         13
*/

func printTree(w io.Writer, node *Node, ns int, ch rune) {
	if node == nil {
		return
	}

	for i := 0; i < ns; i++ {
		fmt.Fprint(w, " ")
	}
	fmt.Fprintf(w, "%c: %v\n", ch, node.value)
	printTree(w, node.left, ns+2, 'L')
	printTree(w, node.right, ns+2, 'R')
}

func displayTree(root *Node, level, space int) {
	if root == nil {
		return
	}
	space += 5

	// Recursively call for the right subtree
	displayTree(root.right, level+1, space)

	// Print spaces for the current level
	for i := 0; i < space; i++ {
		fmt.Printf("·")
	}
	fmt.Printf(" ")
	// Print the current node's value
	fmt.Printf("%d\n", root.value)

	// Recursively call for the left subtree
	displayTree(root.left, level+1, space)
}
