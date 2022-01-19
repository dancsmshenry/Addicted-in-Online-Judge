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

//方法二，快慢指针
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
        ListNode* pre1 = head;
        ListNode* pre2 = head;
        
        for (int i = 1; i < k; ++ i){//注意，这里被返回的结点和最后一个结点差了k-个单位，即倒数第一和倒数第三差了2
            pre1 = pre1 -> next;
        }

        while (pre1 -> next){
            pre1 = pre1 -> next;
            pre2 = pre2 -> next;
        }

        return pre2;
    }
};