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
        ListNode *res = new ListNode(0, head);
        ListNode *fast = res, *slow = res;

        while (n --) {
            fast = fast -> next;
        }

        while (fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
        }

        slow -> next = slow -> next -> next;
        
        return res -> next;
    }
};