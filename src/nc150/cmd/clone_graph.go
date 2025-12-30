package main;

type Node struct {
	Val int
	Neighbors []*Node
}

func cloneGraph(node *Node) *Node {
    if node == nil {
        return nil
    }

    seen := make(map[*Node]*Node)

    var dfs func(n *Node) *Node
    dfs = func(n *Node) *Node {
        if v, ok := seen[n]; ok {
            return v
        }
        clone := &Node{Val: n.Val}
        seen[n] = clone
        for _, nei := range n.Neighbors {
            clone.Neighbors = append(clone.Neighbors, dfs(nei))
        }
        return clone
    }

    return dfs(node)
}
