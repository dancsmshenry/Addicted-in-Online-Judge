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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0), *res = result;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr){
            int sum = carry;
            if (l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            ListNode* node = new ListNode(sum % 10);
            result -> next = node;
            result = result -> next;
            carry = sum / 10;
        }
        
        if (carry > 0){
            ListNode* node = new ListNode(carry);
            result -> next = node;
        }

        return res -> next;
    }
};