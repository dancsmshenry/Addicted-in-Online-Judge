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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *dummy = new ListNode(0, head) ,*tail = head;
        ListNode *oushu = new ListNode(0), *oushu_pointer = oushu;

        while (head && head -> next) {
            ListNode *temp = head -> next;
            head -> next = temp -> next;
            tail = (head -> next == nullptr) ? head: head -> next;
            head = head -> next;

            oushu_pointer -> next = temp;
            oushu_pointer = oushu_pointer -> next;
            oushu_pointer -> next = nullptr;
        }

        if (tail) {
            tail -> next = oushu -> next;
        }
        return dummy -> next;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode *node1 = head -> next;
        ListNode *node2 = head;
        ListNode *node3 = node1;

        while (node3 && node3 -> next) {//前者是防奇数，后者防止偶数
            node2 -> next = node3 -> next;
            node2 = node2 -> next;
            node3 -> next = node2 -> next;
            node3 = node3 -> next;
        }
        node2 -> next = node1;

        return head;
    }
};