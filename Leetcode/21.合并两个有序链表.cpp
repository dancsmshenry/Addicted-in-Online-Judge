//双指针实现
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node1 = new ListNode(0);
        ListNode* node2 = node1;

        //比较l1和l2的值谁比较小，小的就放到新的链表中
        while(l1 && l2){//这里的循环的结束条件是l1或l2谁的结尾不是null的
            if (l1->val > l2 -> val){
                node2 -> next = l2;
                l2 = l2 -> next;
            }else{
                node2 -> next = l1;
                l1 = l1 -> next;
            }
            node2 = node2 -> next;
        }
        
        if(!l1){//如果l1走完了，但是l2还没走完，就把l2后面的部分接上去
            node2 -> next = l2;
        }
        if(!l2){//如果l2走完了，但是l1还没走完，就把l1后面的部分接上去
            node2 -> next = l1;
        }

        return node1 -> next;
    }
};

//递归版本的实现
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1){
            return list2;
        }
        if (!list2){
            return list1;
        }

        if (list1 -> val < list2 -> val){
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }

        list2 -> next = mergeTwoLists(list1, list2 -> next);
        return list2;
    }
};