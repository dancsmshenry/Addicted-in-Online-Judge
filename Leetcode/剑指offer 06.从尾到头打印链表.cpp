//方法一，先顺序，再倒序
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        
        /*放置数据*/
        while (head){
            res.push_back(head -> val);
            head = head -> next;
        }

        /*反转vector*/
        reverse(res.begin(), res.end());
        return res;
    }
};

//方法二，栈
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> s1;

        while (head){
            s1.push(head -> val);
            head = head -> next;
        }

        while (!s1.empty()){
            res.push_back(s1.top());
            s1.pop();
        }

        return res;
    }
};