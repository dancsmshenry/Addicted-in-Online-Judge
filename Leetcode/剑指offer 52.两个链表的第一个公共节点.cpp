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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*之前没看到会出现空节点的情况*/
        if (!headA || !headB){
            return nullptr;
        }
        ListNode *heada = headA, *headb = headB;
        /*防止因没有交点而导致无限循环*/
        int flag = 0;

        while(heada != headb){
            if (heada -> next){
                heada = heada -> next;
            }else{
                heada = headB;
                flag ++ ;
            }

            if (headb -> next){
                headb = headb -> next;
            }else{
                headb = headA;
            }

            if (flag > 1){
                return nullptr;
            }
        }
        return heada;
    }
};