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
        if (!head || !head -> next) {
            return head;
        }

        ListNode *dummy = new ListNode(0, nullptr), *even = dummy;//偶数节点
        ListNode *pre = nullptr, *odd = head;//奇数节点

        while (odd && odd -> next) {
            pre = odd;
            ListNode *mid = odd -> next -> next;
            even -> next = odd -> next;
            odd -> next = mid;
            odd = odd -> next;
            even = even -> next;
        }

        even -> next = nullptr;
        if (!odd) {
            pre -> next = dummy -> next;
        } else {
            odd -> next = dummy -> next;
        }

        return head;
    }
};