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
    ListNode* insertionSortList(ListNode* head) {
        //因为是链表，所以从前往后遍历，即先找最小的，再找第二小的，再找第三小的
        ListNode* point = head;

        while (point) {
            int val = point -> val;
            ListNode* point1 = point -> next;
            while (point1) {
                if (val > point1 -> val) {
                    int mid = val;
                    val = point1 -> val;
                    point1 -> val = mid;
                }
                point1 = point1 -> next;
            }
            point -> val = val;
            point = point -> next;
        }

        return head;
    }
};