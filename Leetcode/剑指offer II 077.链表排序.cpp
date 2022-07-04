// 自顶向下归并排序（时间nlogn，空间logn）
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
        return mergesort(head, nullptr);
    }

    ListNode* mergesort(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head -> next == tail) {
            head -> next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast -> next != tail) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        return merge(mergesort(head, slow), mergesort(slow, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode *dummy = new ListNode(0), *temp = dummy;

        while (head1 && head2) {
            if (head1 -> val < head2 -> val) {
                temp -> next = head1;
                head1 = head1 -> next;
            } else {
                temp -> next = head2;
                head2 = head2 -> next;
            }
            temp = temp -> next;
        }
        temp -> next = head1 ? head1 : head2;

        return dummy -> next;
    }
};


// 自下向上的归并排序（时间nlogn，空间1）
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
        int length = 0;
        // 求长度
        for (ListNode* node = head; node != nullptr; node = node -> next) {
            ++ length;
        }

        ListNode* dummy = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength *= 2) {
            ListNode *prev = dummy, *curr = dummy -> next;
            // 整体思路就是按照2的次方，分别把整个链表切割成不同的部分，每个部分有两个链表head1和head2，然后把它们给merge
            while (curr != nullptr) {
                // 把链表切割为head1和head2两个部分，先merge
                ListNode *head1 = curr;
                for (int i = 1; i < subLength && curr -> next != nullptr; ++ i) {
                    curr = curr -> next;
                }
                ListNode* head2 = curr -> next;
                curr -> next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr -> next != nullptr; ++ i) {
                    curr = curr -> next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr -> next;
                    curr -> next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev -> next = merged;

                // 调整下一次链表排序部分的起点
                while (prev -> next != nullptr) {
                    prev = prev -> next;
                }
                curr = next;
            }
        }

        return dummy -> next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode *dummy = new ListNode(), *temp = dummy;

        while (head1 && head2) {
            if (head1 -> val < head2 -> val) {
                temp -> next = head1;
                head1 = head1 -> next;
            } else {
                temp -> next = head2;
                head2 = head2 -> next;
            }
            temp = temp -> next;
        }
        temp -> next = head1 ? head1 : head2;

        return dummy -> next;
    }
};