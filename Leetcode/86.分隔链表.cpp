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
    ListNode* partition(ListNode* head, int x) {
        /*找到第一个大于x的元素的位置*/
        ListNode *node1 = nullptr, *node2 = new ListNode(x - 1, head), *result = node2;
        while (node2 && node2 -> val < x){
            node1 = node2;
            node2 = node2 -> next;
        }        

        ListNode *node3 = node2, *pre = new ListNode(0, node2);
        while (node3){
            if (node3 -> val < x){
                pre -> next = node3 -> next;
                node1 -> next = node3;
                node1 = node1 -> next;
                node3 -> next = node2;
                node3 = pre -> next;
            }else{
                pre = pre -> next;
                node3 = node3 -> next;
            }
        }
        
        return result -> next;
    }
};