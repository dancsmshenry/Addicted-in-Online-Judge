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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //  �����뵽�˼��ַ�������һ����дһ����ת��������ԭ����ͽ��������ת����
        //  �ڶ�������vector���洢����
        //  �������ǿ���֮ǰ����������stack���洢����

        vector<int> v1{}, v2{}, v3{};

        while (l1) {
            v1.push_back(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            v2.push_back(l2 -> val);
            l2 = l2 -> next;
        }

        int count = 0;
        while (!v1.empty() || !v2.empty() || count) {
            if (!v1.empty()) {
                count += v1.back();
                v1.pop_back();
            }
            if (!v2.empty()) {
                count += v2.back();
                v2.pop_back();
            }
            v3.push_back(count % 10);
            count /= 10;
        }

        ListNode *res = new ListNode(), *result = res;
        for (int i = v3.size() - 1; i >= 0; -- i) {
            res -> next = new ListNode(v3[i]);
            res = res -> next;
        }

        return result -> next;
    }
};