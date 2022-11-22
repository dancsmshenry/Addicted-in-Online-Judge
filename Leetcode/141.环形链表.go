/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
	slow := head
	fast := head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if fast == slow {
			return true
		}
	}

	return false
}

func hasCycle(head *ListNode) bool {
	map_ := make(map[*ListNode]int)

	for head != nil {
		if _, ok := map_[head]; ok {
			return true
		}
		map_[head] = 1
		head = head.Next
	}

	return false
}