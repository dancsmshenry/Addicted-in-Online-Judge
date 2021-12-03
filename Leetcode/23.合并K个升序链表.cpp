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
            result = solve(result, lists[i]);
        }
        return result;
    }

    ListNode* solve(ListNode* list1, ListNode* list2){
        ListNode* res = new ListNode(0);
        ListNode* l1 = list1, *l2 = list2, *ress = res;

        while (l1 && l2){
            int number = l2 -> val > l1 -> val ? l1 -> val : l2 -> val;
            ListNode* node = new ListNode(number);
            res -> next = node;
            res = res -> next;
            if (number == l2 -> val){
                l2 = l2 -> next;
            }else{
                l1 = l1 -> next;
            }
        }

        while (l1){
            ListNode* node = new ListNode(l1 -> val);
            res -> next = node;
            res = res -> next;
            l1 = l1 -> next;
        }

        while (l2){
            ListNode* node = new ListNode(l2 -> val);
            res -> next = node;
            res = res -> next;
            l2 = l2 -> next;
        }

        return ress -> next;
    }
};
/*这是臃肿的版本，非常的不ok*/


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

    ListNode* mergeTwo(ListNode* list1, ListNode* list2){
        ListNode* res = new ListNode(0);
        ListNode* l1 = list1, *l2 = list2, *ress = res;

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

/**
 * 这道题应该是链表合并的一个模板题
 * 我之前的思路是对的，但是写法上由太多的臃肿的地方，导致在最后一个数据的时候超时了
 * 为了防止这种情况的再次发生，先背下这个模板好吧
 **/


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
        return mergeK(lists, 0, lists.size() - 1);
    }

    ListNode* mergeTwo(ListNode* list1, ListNode* list2){
        ListNode* res = new ListNode(0);
        ListNode* l1 = list1, *l2 = list2, *ress = res;

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

    ListNode* mergeK(vector<ListNode*>& lists, int left, int right){
        if (left >= right){
            return lists[left];
        }

        int mid = (left + right) >> 1;
        ListNode* l1 = mergeK(lists, left, mid);
        ListNode* l2 = mergeK(lists, mid + 1, right);

        return mergeTwo(l1, l2);
    }
};/*参考归并排序的做法*/