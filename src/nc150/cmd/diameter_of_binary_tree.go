package main

func maxNodes(root *TreeNode) (int, int) {
	if root == nil {
		return 0, 0
	}
	lh, ld := maxNodes(root.Left)
	rh, rd := maxNodes(root.Right)
	return 1 + max(lh, rh), max(1 + lh + rh, ld, rd)
}

func diameterOfBinaryTree(root *TreeNode) int {
	_, a := maxNodes(root)
	return a - 1
}
