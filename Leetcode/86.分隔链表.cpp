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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head -> next) {
            return head;
        }
        
        ListNode *dummy = new ListNode(x - 1, head), *node = dummy;
        ListNode *big = new ListNode(0, nullptr), *b = big;

        while (node -> next) {
            if (node -> next -> val < x) {
                node = node -> next;
            } else {
                ListNode *mid = node -> next -> next;
                b -> next = node -> next;
                node -> next = mid;
                b = b -> next;
                b -> next = nullptr;
            }
        }

        node -> next = big -> next;

        return dummy -> next;
    }
};