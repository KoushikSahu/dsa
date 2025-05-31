package main

func MergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	ans := (*ListNode)(nil)
	lst := ans
	itr1, itr2 := list1, list2
	for itr1 != nil && itr2 != nil {
		if itr1.Val <= itr2.Val {
			tmp := &ListNode{Val: itr1.Val, Next: nil}
			if lst != nil {
				lst.Next = tmp
				lst = lst.Next
			} else {
				ans = tmp
				lst = tmp
			}
			itr1 = itr1.Next
		} else {
			tmp := &ListNode{Val: itr2.Val, Next: nil}
			if lst != nil {
				lst.Next = tmp
				lst = lst.Next
			} else {
				ans = tmp
				lst = tmp
			}
			itr2 = itr2.Next
		}
	}
	for itr1 != nil {
		tmp := &ListNode{Val: itr1.Val, Next: nil}
		if lst != nil {
			lst.Next = tmp
			lst = lst.Next
		} else {
			ans = tmp
			lst = tmp
		}
		itr1 = itr1.Next
	}
	for itr2 != nil {
		tmp := &ListNode{Val: itr2.Val, Next: nil}
		if lst != nil {
			lst.Next = tmp
			lst = lst.Next
		} else {
			ans = tmp
			lst = tmp
		}
		itr2 = itr2.Next
	}
	return ans
}
