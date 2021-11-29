/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* result = new ListNode(0);
        result = res;
        
        ListNode *head1 = l1, *head2 = l2;
        while (l1 && l2){
            if (l1 -> val > l2 -> val){
                ListNode* node1 = new ListNode(l2 -> val);
                res -> next = node1;
                l2 = l2 -> next;
            }else{
                ListNode* node1 = new ListNode(l1 -> val);
                res -> next = node1;
                l1 = l1 -> next;
            }
            res = res -> next;
        }
        /*看了解析，觉得下面的循环就可以优化一下*/
        res -> next = l1 ? l1 : l2;
        // while (l1){
        //     ListNode* node1 = new ListNode(l1 -> val);
        //     res -> next = node1;
        //     res = res -> next;
        //     l1 = l1 -> next;
        // }
        // while (l2){
        //     ListNode* node1 = new ListNode(l2 -> val);
        //     res -> next = node1;
        //     res = res -> next;
        //     l2 = l2 -> next;
        // }

        return result -> next;
    }
};