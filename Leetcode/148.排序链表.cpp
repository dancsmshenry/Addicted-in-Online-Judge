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
    ListNode* sortList(ListNode* head) {
        if (!head){
            return nullptr;
        }
        vector<int> f;
        while (head){
            f.push_back(head -> val);
            head = head -> next;
        }

        sort(f.begin(), f.end());
        ListNode* res = new ListNode(0), *ress = new ListNode(0);
        ress = res;
        for (int i: f){
            ListNode* node = new ListNode(i);
            res -> next = node;
            res = res -> next;
        }

        return ress -> next;
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
    ListNode* sortList(ListNode* head) {
        /*看到了一个比较好的思路：就是通过快慢指针找到链表的中点，保存mid和之前的begin的位置，并对其进行归并排序*/
        return mergeSort(head, nullptr);
    }

    ListNode* mergeSort(ListNode* head, ListNode* tail){
        if (head == nullptr){
            return head;
        }
        if (head -> next == tail){
            head -> next = nullptr;
            return head;
        }
        /*寻找中点*/
        ListNode* slow = head, * fast = head;
        while(fast != tail){
            slow = slow -> next;
            fast = fast -> next;
            if (fast != tail){
                fast = fast -> next;
            }
        }
        /*对左右两边进行合并*/
        ListNode* l1 = mergeSort(head, slow);
        ListNode* l2 = mergeSort(slow, tail);
        return mergeTwo(l1, l2);
    }

    /*基本的链表合并*/
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