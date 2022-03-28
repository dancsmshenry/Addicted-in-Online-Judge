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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        while (head) {
            int value = head -> val;
            ListNode *fast = head -> next;
            while (fast) {
                if (fast -> val < value) {
                    swap(value, fast -> val);
                }
                fast = fast -> next;
            }
            head -> val = value;
            head = head -> next;
        }

        return dummy -> next;
    }
};