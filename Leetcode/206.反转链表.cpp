//手动翻转链表
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }

        ListNode* pre = nullptr;

        while (head) {
            ListNode* mid = head -> next;
            head -> next = pre;
            pre = head;
            head = mid;
        }

        return pre;
    }
};

//递归的写法
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next){
            //如果当前结点是空，就直接返回了（存在0个结点的情况）
            //如果head->next是空，就证明原来的head是最后一个结点了，所以此时的head就是反转链表后的第一个结点
            return head;
        }

        auto newhead = reverseList(head -> next);
        head -> next -> next = head;//让后面一个结点指向前面一个结点
        head -> next = nullptr;//其实这句话是针对最后一个结点的（因为如果最后一个结点指的还是第二个结点的话，就会形成环）

        return newhead;
    }
};