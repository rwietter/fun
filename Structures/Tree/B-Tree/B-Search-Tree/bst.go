func (n *Node) search(node *Node, target int) bool {
	if isNodeEmpty(node) {
		return false
	}

	if node.value == target {
		return true
	}

	if target < node.value {
		node.search(node.left, target)
	} else if target > node.value {
		node.search(node.right, target)
	}

	return false
}
