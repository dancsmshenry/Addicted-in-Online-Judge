//顺序排序
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0){
            return nullptr;
        }
        ListNode* result = lists[0];
        for (int i = 1; i < lists.size(); i ++ ){
            result = mergeTwo(result, lists[i]);
        }
        return result;
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        ListNode* res = new ListNode(0), *ress = res;

        while (l1 && l2){
            if (l2 -> val > l1 -> val){
                res -> next = l1;
                l1 = l1 -> next;
            }else{
                res -> next = l2;
                l2 = l2 -> next;
            }
            res = res -> next;
        }

        res -> next = l1 ? l1 : l2;

        return ress -> next;
    }
};


//归并排序
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return merageK(lists, 0, lists.size() - 1);
    }

    ListNode* merageK(vector<ListNode*>& lists, int left, int right) {
        if (left >= right) {
            return lists[left];
        }

        int mid = left + (right - left) / 2;
        ListNode* l1 = merageK(lists, left, mid);
        ListNode* l2 = merageK(lists, mid + 1, right);

        return meragetwo(l1, l2);
    }

    ListNode* meragetwo(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(), *res = result;

        while (l1 && l2) {
            if (l1 -> val > l2 -> val) {
                res -> next = l2;
                l2 = l2 -> next;
            } else {
                res -> next = l1;
                l1 = l1 -> next;
            }
            res = res -> next;
        }

        res -> next = (l2) ? l2 : l1;

        return result -> next;
    }
};