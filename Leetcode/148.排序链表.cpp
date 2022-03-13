//自顶向下的归并排序
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

    ListNode* mergeSort(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head -> next == tail) {
            head -> next = nullptr;
            return head;
        }
        /*寻找中点*/
        ListNode *fast = new ListNode(0, head), *slow = head;
        while (fast != tail && fast -> next != tail) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        /*对左右两边进行合并*/
        ListNode* l1 = mergeSort(head, slow);
        ListNode* l2 = mergeSort(slow, tail);
        return mergeTwo(l1, l2);
    }

    /*基本的链表合并*/
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0), *ress = res;

        while (l1 && l2) {
            if (l2 -> val > l1 -> val) {
                res -> next = l1;
                l1 = l1 -> next;
            } else {
                res -> next = l2;
                l2 = l2 -> next;
            }
            res = res -> next;
        }

        res -> next = l1 ? l1 : l2;

        return ress -> next;
    }
};

//自底向上的归并排序
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
        if (head == nullptr) {
            return head;
        }
        //计算链表长度
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length ++ ;
            node = node -> next;
        }
  
        ListNode *dummyHead = new ListNode(0, head); //建立一个指向list的节点， 因为在计算过程中头节点会改变
        for (int subLength = 1; subLength < length; subLength <<= 1) {  //左移就是*2
            ListNode* prev = dummyHead, *curr = dummyHead -> next;
            //注意这里curr为dummy->next, 不是head，因为curr要记录每一轮的开头值， 而head是题目给的固定
            while (curr != nullptr) {
                //找到第一个符合sublength的序列
                ListNode *head1 = curr;
                for (int i = 1; i < subLength && curr -> next != nullptr; ++ i) {
                    curr = curr -> next;
                }
                
                 //找到第二个符合sublength的序列
                ListNode *head2 = curr -> next;
                curr -> next = nullptr; // 断尾巴
                curr = head2;               
                for (int i = 1; i < subLength && curr != nullptr && curr -> next != nullptr; ++ i) {
                    curr = curr -> next;
                }
                
                // 要看第二个序列是不是在list最后， 如果不是则要记录第三个头
                ListNode *next = nullptr;
                if (curr != nullptr) {
                    next = curr -> next;
                    curr -> next = nullptr;
                }
               
                //合并两个头！
                ListNode *merged = merge(head1, head2);
                //pre指向新归并出来的list
                prev -> next = merged;
                //这里pre要更新到归并后的数组的最后一个
                while (prev -> next != nullptr) {  
                    prev = prev -> next;  
                }
                //将curr更新到第三个头，进行循环
                curr = next;
            }
        }
        return dummyHead -> next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0), *ress = res;

        while (l1 && l2) {
            if (l2 -> val > l1 -> val) {
                res -> next = l1;
                l1 = l1 -> next;
            } else {
                res -> next = l2;
                l2 = l2 -> next;
            }
            res = res -> next;
        }

        res -> next = l1 ? l1 : l2;

        return ress -> next;
    }
};