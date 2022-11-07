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
        unordered_set<ListNode*> set_;

        while (head) {
            if (set_.count(head)) {
                return true;
            }
            set_.insert(head);
            head = head -> next;
        }

        return false;
    }
};