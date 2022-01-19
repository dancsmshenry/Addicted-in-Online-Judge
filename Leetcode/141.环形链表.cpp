//快慢指针实现
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *fast = head -> next;
        ListNode *slow = head;

        while(fast != slow){
            if (fast != nullptr && fast -> next != nullptr){
                fast = fast -> next -> next;
                slow = slow -> next;
            }
            else return false;
        }

        return true;
    }
};

//hash表实现
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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> map;

        while (head){
            if (map.count(head)){
                return true;
            }else{
                map[head] = true;
                head = head -> next;
            }
        }

        return false;
    }
};