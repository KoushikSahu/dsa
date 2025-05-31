package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func _GoodNode(root *TreeNode, maxAncestor int, ans *int) {
	if root == nil {
		return
	}
	if root.Val >= maxAncestor {
		*ans += 1
	}
	_GoodNode(root.Left, max(root.Val, maxAncestor), ans)
	_GoodNode(root.Right, max(root.Val, maxAncestor), ans)
}

func GoodNodes(root *TreeNode) int {
	ans := 0
	_GoodNode(root, int(-1e5), &ans)
	return ans
}
