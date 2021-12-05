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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head, *slow = head, *temp = head;
        while(fast && fast -> next){
            temp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        /*这个位置有一个小坑：如果slow的下一个是null，那么可能1：链表只有一个结点，可能2：链表有两个结点（之前就忽略了这种情况）*/
        if (slow -> next == nullptr && slow == temp){
            return nullptr;
        }
        temp -> next = slow -> next;

        return head;
    }
};