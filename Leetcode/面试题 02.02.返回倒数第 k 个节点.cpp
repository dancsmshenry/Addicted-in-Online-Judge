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
    int kthToLast(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;

        while (k > 1){
            -- k;
            fast = fast -> next;
        }

        while (fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow -> val;
    }
};