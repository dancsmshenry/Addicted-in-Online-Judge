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
        ListNode *fast = head, *slow = head;

        do {
            if (fast != nullptr && fast -> next != nullptr) {
                fast = fast -> next -> next;
                slow = slow -> next;
            } else {
                return false;
            }
        } while(fast != slow);

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