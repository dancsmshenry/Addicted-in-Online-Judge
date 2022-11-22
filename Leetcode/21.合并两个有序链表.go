/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	var dummyhead *ListNode = &ListNode{Val: 0}
	temp := dummyhead

	for list1 != nil || list2 != nil {
		if list2 == nil {
			temp.Next = list1
			list1 = list1.Next
		} else if list1 == nil {
			temp.Next = list2
			list2 = list2.Next
		} else {
			if list1.Val >= list2.Val {
				temp.Next = list2
				list2 = list2.Next
			} else {
				temp.Next = list1
				list1 = list1.Next
			}
		}
		temp = temp.Next
	}

	return dummyhead.Next
}