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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res = head;

        while (head && head -> next) {
            if (head -> val == head -> next -> val) {
                ListNode *node = head -> next;
                head -> next = head -> next -> next;
                delete node;
            } else {
                head = head -> next;
            }
        }

        return res;
    }
};


// 和82题一样的模板，只是改了一下
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *current = dummy;

        while (current -> next && current -> next -> next) {
            if (current -> next -> val == current -> next -> next -> val) {
                int number = current -> next -> val;
                ListNode *temp = current -> next -> next;
                while (temp && temp -> val == number) {
                    temp = temp -> next;
                }
                current -> next -> next = temp;
            } else {
                current = current -> next;
            }
        }

        return dummy -> next;
    }
};