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
        ListNode *dummy = new ListNode(0, head), *big = new ListNode(0);
        ListNode *node1 = dummy, *node2 = big;

        while (node1 -> next) {
            if (node1 -> next -> val < x) {
                node1 = node1 -> next;
            } else {
                ListNode *temp = node1 -> next -> next;
                node2 -> next = node1 -> next;
                node2 = node2 -> next;
                node2 -> next = nullptr;
                node1 -> next = temp;
            }
        }

        node1 -> next = big -> next;
        return dummy -> next;
    }
};