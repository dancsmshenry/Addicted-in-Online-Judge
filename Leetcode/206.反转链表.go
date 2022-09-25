/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	var res *ListNode
	cur := head

	for cur != nil {
		next := cur.Next
		cur.Next = res
		res = cur
		cur = next
	}

	return res
}