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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head || !head -> next) {
            return head;
        }
        int length = 0;
        for (auto temp = head; temp; temp = temp -> next) {
            length ++ ;
        }

        k = k % length;
        if (k == 0) {
            return head;
        }

        ListNode *slow = head, *fast = head;

        while (k > 0) {
            fast = fast -> next;
            k -- ;
        }

        while (fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }

        fast -> next = head;
        ListNode *res = slow -> next;
        slow -> next = nullptr;
        return res;
    }
};