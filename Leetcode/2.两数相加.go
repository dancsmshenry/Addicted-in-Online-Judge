/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var ans *ListNode = &ListNode{Val: 0}
	res := ans
	carry := 0
	for l1 != nil || l2 != nil {
		number := carry
		if l1 != nil {
			number += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			number += l2.Val
			l2 = l2.Next
		}
		ans.Next = &ListNode{Val: number % 10}
		carry = number / 10
		ans = ans.Next
	}
	if carry > 0 {
		ans.Next = &ListNode{Val: carry}
	}
	return res.Next
}