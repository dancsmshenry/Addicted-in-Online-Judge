/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func removeNthFromEnd(head *ListNode, n int) *ListNode {
    var dummyhead *ListNode = &ListNode{Val:0, Next:head}
    
    fast := dummyhead
    for ;n > 0; n -- {
        fast = fast.Next
    }

    slow := dummyhead
    for fast.Next != nil || fast.Next != nil {
        slow = slow.Next
        fast = fast.Next
    }

    slow.Next = slow.Next.Next

    return dummyhead.Next
}