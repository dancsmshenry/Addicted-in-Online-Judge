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
    void reorderList(ListNode* head) {
        // ����ָ�����е㣨��ָ��Ҳ����Ҫ�жϵģ���Ϊhead����Ϊ�գ�
        ListNode *slow = head, *fast = head;
        while (slow && fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // ��ת��벿�ֵ�����
        ListNode *slow1 = slow -> next, *dummy = nullptr;
        slow -> next = nullptr;
        while (slow1) {
            ListNode *temp = slow1 -> next;
            slow1 -> next = dummy;
            dummy = slow1;
            slow1 = temp;
        }

        // �ϲ�����������
        while (head && dummy) {
            ListNode *l1 = head -> next, *l2 = dummy -> next;
            head -> next = dummy;
            dummy -> next = l1;
            head = l1;
            dummy = l2;
        }
    }
};