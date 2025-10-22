package main

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	itr := head
	fastitr := head
	prev := (*ListNode)(nil)
	for i := 0; i < n; i++ {
		fastitr = fastitr.Next
	}
	for fastitr != nil {
		fastitr = fastitr.Next
		prev = itr
		itr = itr.Next
	}
	prev.Next = itr.Next
	return head
}
