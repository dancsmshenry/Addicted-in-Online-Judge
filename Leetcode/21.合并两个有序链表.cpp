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
        ListNode *node1 = new ListNode(0), *node2 = node1;

        while(l1 && l2){
            if (l1 -> val > l2 -> val){
                node2 -> next = l2;
                l2 = l2 -> next;
            }else{
                node2 -> next = l1;
                l1 = l1 -> next;
            }
            node2 = node2 -> next;
        }
        
        node2 -> next = l1 ? l1 : l2;

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
        if (!list1 || !list2) {
            return list1 ? list1 : list2;
        }

        if (list1 -> val < list2 -> val){
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }

        list2 -> next = mergeTwoLists(list1, list2 -> next);
        return list2;
    }
};