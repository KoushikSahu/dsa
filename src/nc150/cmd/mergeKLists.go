package main

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 1 {
		return lists[0]
	}
	n := len(lists)
	list1 := lists[0]
	list2 := mergeKLists(lists[1:n])
	ans := (*ListNode)(nil)
	lst := (*ListNode)(nil)
	for list1 != nil && list2 != nil {
		if list1.Val < list2.Val {
			if ans == nil {
				ans = &ListNode {Val: list1.Val, Next: nil}
				lst = ans
			} else {
				lst.Next = &ListNode {Val: list1.Val, Next: nil}
				lst = lst.Next
			}
			list1 = list1.Next
		} else {
			if ans == nil {
				ans = &ListNode {Val: list2.Val, Next: nil}
				lst = ans
			} else {
				lst.Next = &ListNode {Val: list2.Val, Next: nil}
				lst = lst.Next
			}
			list2 = list2.Next
		}
	}
	for list1 != nil {
		if ans == nil {
			ans = &ListNode {Val: list1.Val, Next: nil}
			lst = ans
		} else {
			lst.Next = &ListNode {Val: list1.Val, Next: nil}
			lst = lst.Next
		}
		list1 = list1.Next
	}
	for list2 != nil {
		if ans == nil {
			ans = &ListNode {Val: list2.Val, Next: nil}
			lst = ans
		} else {
			lst.Next = &ListNode {Val: list2.Val, Next: nil}
			lst = lst.Next
		}
		list2 = list2.Next
	}
	return ans
}
