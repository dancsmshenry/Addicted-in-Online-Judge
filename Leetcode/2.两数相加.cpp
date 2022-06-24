/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(), *result = res;
        int count = 0;

        while (l1 || l2 || count) {
            int mid = count;
            if (l1) {
                mid += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                mid += l2 -> val;
                l2 = l2 -> next;
            }
            res -> next = new ListNode(mid % 10);
            res = res -> next;
            count = mid / 10;
        }

        return result -> next;
    }
};