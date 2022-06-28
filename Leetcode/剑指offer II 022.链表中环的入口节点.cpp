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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hashset;
        int count = 0;

        while (head) {
            if (!hashset.count(head)) {
                hashset.insert(head);
            } else {
                return head;
            }
            head = head -> next;
        }

        return nullptr;
    }
};