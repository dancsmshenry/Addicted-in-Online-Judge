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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || !head || !head -> next) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *l = dummy, *prev = nullptr;
        for (int i = 0; i < left; i ++ ) {
            prev = l;
            l = l -> next;
        }

        ListNode *start = l, *pre = nullptr;
        for (; right >= left; ++ left) {
            ListNode *mid = start -> next;
            start -> next = pre;
            pre = start;
            start = mid;
        }

        prev -> next = pre;
        l -> next = start;
        
        return dummy -> next;
    }
};

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || !head || !head -> next) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *l = dummy, *r = dummy;

        while (left > 1) {
            l = l -> next;
            left -- ;
        }
        while (right > 0) {
            r = r -> next;
            right -- ;
        }

        l -> next = reverse(l -> next, r);

        return dummy -> next;
    }

    ListNode* reverse(ListNode* l, ListNode* r) {
        ListNode *pre = r -> next;

        while (l != r) {
            ListNode *mid = l -> next;
            l -> next = pre;
            pre = l;
            l = mid;
        }
        r -> next = pre;
        
        return r;
    }
};