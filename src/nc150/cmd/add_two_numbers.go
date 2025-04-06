package solutions

type ListNode struct {
	Val  int
	Next *ListNode
}

func AddTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l := (*ListNode)(nil)
	last := (*ListNode)(nil)
	res := 0
	carry := 0

	for l1 != nil && l2 != nil {
		l1v := l1.Val
		l2v := l2.Val

		sm := l1v + l2v + carry
		res = sm % 10
		carry = carry / 10

		if l == nil {
			l = &ListNode{
				Val:  res,
				Next: nil,
			}
		} else {
			Next := &ListNode{
				Val:  res,
				Next: nil,
			}
			last.Next = Next
			last = Next
		}

		l1 = l1.Next
		l2 = l2.Next
	}

	for l1 != nil {
		l1v := l1.Val
		sm := l1v + carry
		res = sm % 10
		carry = carry / 10

		if l == nil {
			l = &ListNode{
				Val:  res,
				Next: nil,
			}
		} else {
			Next := &ListNode{
				Val:  res,
				Next: nil,
			}
			last.Next = Next
			last = Next
		}
	}

	for l2 != nil {
		l2v := l2.Val
		sm := l2v + carry
		res = sm % 10
		carry = carry / 10

		if l == nil {
			l = &ListNode{
				Val:  res,
				Next: nil,
			}
		} else {
			Next := &ListNode{
				Val:  res,
				Next: nil,
			}
			last.Next = Next
			last = Next
		}
	}

	return l
}
