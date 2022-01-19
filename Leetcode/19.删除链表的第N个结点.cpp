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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /**
        解释一下为什么要加上一个dummy结点
        如果当前要删除的是头结点的话，p2应该指向谁？谁都不好使是吧
        或者说，如果当前只有一个结点的话，p2又应该指向谁？
        所以，就可以在链表前面再接上一个结点，最后返回这个结点的next即可
        **/
        ListNode* dummy = new ListNode(0, head);
        ListNode* p1 = dummy;
        ListNode* p2 = dummy;

        while (n > 0){
            p1 = p1 -> next;
            -- n;
        }

        while(p1 -> next){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        p2 -> next = p2 -> next -> next;

        return dummy -> next;
    }
};