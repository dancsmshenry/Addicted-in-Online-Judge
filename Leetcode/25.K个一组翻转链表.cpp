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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1){
            return head;
        }
        /*先求链表的长度*/
        int n = 0;
        for (ListNode* node = head; node; node = node -> next){
            n ++ ;
        }
        n -= (n % k);

        ListNode* result = new ListNode(0, head);
        /*p1是每一组链表的结点的前一个结点，p2是该组链表的头结点，pre是尾节点，p3是尾结点的后一个结点（其中p3和pre都是用来向前推进的）*/
        ListNode *p1 = result, *p2 = head, *p3 = head -> next, *pre = head;
        /*count=1是因为，对于十个结点，只需要反转9次*/
        for (int count = 1; n > 0; n -- ){
            if (count == k){
                /*前面一组链表的每一项都反转好了，就把整个链表反转到前面*/
                p1 -> next = pre;
                p2 -> next = p3;
                /*处理结点的位置*/
                p1 = p2;
                pre = p2 = p3;
                p3 = p3 ? p3 -> next : p3;/*如果是最后一组的话，就不用继续next了，因为此时的p3就是null了*/
                count = 1;
            }else{
                count ++ ;
                /*反转两个结点的方向*/
                ListNode* mid = p3 -> next;
                p3 -> next = pre;
                pre = p3;
                p3 = mid;
            }
        }

        return result -> next;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
            在题解区看到的一种非常非常巧妙的方法
            https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/5fen-dai-ma-ji-jian-cdai-ma-by-fengziluo-ucsi/
        */
        ListNode* node = head;
        /*本质：如果当前以head开头的链表的长度小于k，就会出现node为nullptr的情况，此时只要直接直接返回head即可*/
        for (int i = 0; i < k; i ++ ){
            if (!node){
                return head;
            }
            node = node -> next;
        }

        /*对于给定的区间k长度的链表，每次反转当前区间的链表，再对后续的链表进行相同的操作*/
        ListNode *pre = nullptr, *cur = head, *next = nullptr;
        for (int i = 0; i < k; i ++ ){
            next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
        /*这里很精髓，因为head始终是那个结点，而经过上面的反转以后，造成了说，此时的head是当前区间链表的最后一个结点，所以就续下去了*/
        head -> next = reverseKGroup(cur, k);
        
        /*这个最后的pre实际上就是最后一个结点了，但是反转以后不就是最前面的那个结点*/
        return pre;
    }
};