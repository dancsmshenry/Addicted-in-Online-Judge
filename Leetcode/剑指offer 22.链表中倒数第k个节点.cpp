//方法一，顺序查找
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* pre = head;
        int n = 1;
        
        for (; pre -> next; n ++){
            pre = pre -> next;
        }

        pre = head;
        for (int i = 1; i <= n - k; i ++ ){
            pre = pre -> next;
        }

        return pre;
    }
};

//方法二，快慢指针(需要考虑的问题，快指针后续要落到哪个位置)
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head || !head -> next) {
            return head;
        }

        ListNode *fast = head, *slow = head;
        
        while (-- k) {
            fast = fast -> next;
        }

        while (fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;
    }
};