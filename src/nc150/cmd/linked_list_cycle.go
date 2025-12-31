package main

func hasCycle(node *ListNode) bool {
	if node == nil {
		return false
	}

	slowItr := node
	fastItr := node
	
	for fastItr != nil && fastItr.Next != nil {
		slowItr = slowItr.Next
		fastItr = fastItr.Next.Next

		if slowItr == fastItr {
			return true
		}
	}

	return false
}
