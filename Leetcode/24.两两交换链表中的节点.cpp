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
    ListNode* swapPairs(ListNode* head) {
        /**
        想法一：
        这里有1 2 3 4这四个点
        分别命名为point1 point2 point3 point4
        然后先让point1指向point3
        接着让point2指向point4
        最后让point3指向point2

        导致思绪混乱的原因：没能设定好 方便代码表示 的变量，以至于被变量绕的团团转

        整理思路：
        先设一个空结点，让这个空结点指向目标链表的头结点
        然后，因为我们是要对链表进行处理的，肯定就要用一个循环的结点对链表进行处理
        就设一个结点等于此前设立的空结点
        然后对空结点进行while循环操作

        后续的关键就是，要捋清思路，设好方便的变量
        **/
        ListNode *dummy = new ListNode(0, head);
        ListNode *p3 = dummy, *p1 = head;

        while (p1 && p1 -> next) {
            ListNode *p2 = p1 -> next;
            ListNode *temp = p2 -> next;
            p3 -> next = p2;
            p2 -> next = p1;
            p1 -> next = temp;
            p3 = p1;
            p1 = temp;
        }

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }

        ListNode* res = head -> next;
        head -> next = swapPairs(res -> next);
        res -> next = head;

        return res;
    }
};