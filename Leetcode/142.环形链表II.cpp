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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, ListNode*> m;

        while (head){
            if (!m.count(head)){
                m[head] = head -> next;
            }else{
                return head;
            }
            head = head -> next;
        }

        return nullptr;
    }
};