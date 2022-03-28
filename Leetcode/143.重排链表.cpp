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
        if (!head || !head -> next) {
            return ;
        }
        //快慢指针找中点
        ListNode *fast = head, *slow = head;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast != nullptr) {//则当前是偶数
            ListNode *mid = slow -> next;
            slow -> next = nullptr;
            slow = mid;
        }
        //翻转后半段链表
        ListNode *pre = nullptr;
        while (slow) {
            ListNode *mid = slow -> next;
            slow -> next = pre;
            pre = slow;
            slow = mid;
        }
        //合并两链表
        while (head && pre && head -> next != pre) {
            ListNode *mid = head -> next;
            head -> next = pre;
            pre = pre -> next;
            head -> next -> next = mid;
            head = mid;
        }
    }
};