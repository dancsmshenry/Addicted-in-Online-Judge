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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode *pre = nullptr;

        while (fast && fast -> next) {
            fast = fast -> next -> next;
            ListNode *temp = slow -> next;
            slow -> next = pre;
            pre = slow;
            slow = temp;
        }

        if (fast) {
            slow = slow -> next;
        }

        while (pre && slow) {
            if (pre -> val != slow -> val) {
                return false;
            }
            pre = pre -> next;
            slow = slow -> next;
        }

        return true;
    }
};