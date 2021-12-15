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
    void reorderList(ListNode* head) {
        ListNode *slow = new ListNode(0, head), *quick = new ListNode(0, head);
        while (quick && quick -> next){
            slow = slow -> next;
            quick = quick -> next -> next;
        }
        
        /*反转后半段链表*/
        ListNode *pre = nullptr, *slow1 = slow;
        slow = slow1 -> next;
        slow1 -> next = nullptr;
        while (slow){
            ListNode* mid = slow -> next;
            slow -> next = pre;
            pre = slow;
            if (!mid) break;
            slow = mid;
        }
        
        /*合并两链表*/
        while (slow){
            ListNode* next1 = head -> next;
            ListNode* next2 = slow -> next;
            head -> next = slow;
            slow -> next = next1;
            slow = next2;
            head = next1;
        }
    }
};