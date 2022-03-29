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
        vector<int> v1, v2, v3;
        while (l1){
            v1.push_back(l1 -> val);
            l1 = l1 -> next;
        }

        while (l2){
            v2.push_back(l2 -> val);
            l2 = l2 -> next;
        }
        

        int mid = 0;
        for (int i = v1.size() - 1, j = v2.size() - 1; i >= 0 && j >= 0; i --, j -- ){//判断条件的位置要写&&
            v3.push_back((v1[i] + v2[j] + mid) % 10);
            mid = (v1[i] + v2[j] + mid) / 10;
        }
        if (v1.size() > v2.size()){
            for (int i = v1.size() - v2.size() - 1; i >= 0; i -- ){
                v3.push_back((v1[i] + mid) % 10);
                mid = (v1[i] + mid) / 10;
            }
        }else if (v2.size() > v1.size()){
            for (int i = v2.size() - v1.size() - 1; i >= 0; i -- ){
                v3.push_back((v2[i] + mid) % 10);
                mid = (v2[i] + mid) / 10;
            }
        }
        if (mid == 1) v3.push_back(mid);

        ListNode* result = new ListNode(0);
        ListNode* res = result;
        for (int i = v3.size() - 1; i >= 0; i -- ){
            ListNode* node = new ListNode(v3[i]);
            res -> next = node;
            res = res -> next;
        }

        return result -> next;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, s3;

        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }

        int count = 0;
        while (!s1.empty() || !s2.empty() || count != 0) {
            int sum = count;
            if (!s1.empty()) {
                sum += s1.top(); 
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top(); 
                s2.pop();
            }
            s3.push(sum % 10);
            count = sum / 10;
        }

        ListNode *dummy = new ListNode(0), *res = dummy;
        while (!s3.empty()) {
            res -> next = new ListNode(s3.top());
            res = res -> next;
            s3.pop();
        }

        return dummy -> next;
    }
};