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