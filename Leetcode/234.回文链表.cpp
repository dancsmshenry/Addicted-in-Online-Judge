//比较笨的做法，先获取链表的长度，然后翻转前半段，再快慢指针比较
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
    bool isPalindrome(ListNode* head) {
        /**
        先获取链表的长度
        然后把链表的前半段进行翻转
        然后用快慢指针，快指针先走到中间，慢指针从头开始走
        一一比较各个元素
        **/
        //先获取链表长度
        int length = 0;
        ListNode* point1 = new ListNode();
        point1 -> next = head;
        while(point1->next){
            length ++ ;
            point1 = point1 -> next;
        }

        //把链表前半段翻转
        ListNode* node1 = nullptr;
        ListNode* node2 = head;
        int half = length >> 1;
        while (half){
            ListNode* node3 = node2 -> next;
            node2 -> next = node1;
            node1 = node2;
            node2 = node3;
            half -- ;
        }
        
        //记录下半段开始的点
        if (length % 2 == 1){
            node2 = node2 -> next;
        }

        //接着，对两个指针指针进行比较
        while (node1 && node2){
            if (node1->val == node2 -> val){
                node1 = node1 -> next;
                node2 = node2 -> next;
            }else{
                return false;
            }
        }

        return true;
    }
};

//正宗的快慢指针做法
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
    bool isPalindrome(ListNode* head) {
        /*快慢指针做法*/
        ListNode *slow = head, *fast = head, *pre = nullptr;
        /*剪枝*/
        if (!head -> next){
            return true;
        }
        /*快慢指针，慢指针用于翻转前半段链表，快指针用于来判断慢指针是否指到中间的变量*/
        while (fast && fast -> next){
            fast = fast -> next -> next;
            ListNode *mid = slow -> next;
            slow -> next = pre;
            pre = slow;
            slow = mid;
        }
        /*如果快指针不为空，那就证明长度为奇数，则此时的slow为最中间的那个数，所以要把slow推到后面一个*/
        if (fast){
            slow = slow -> next;
        }
        /*从中间开始向两边移动指针，来看是否相等*/
        while (pre && slow){
            if (slow -> val != pre -> val){
                return false;
            }
            pre = pre -> next;
            slow = slow -> next;
        }
        return true;
    }
};

//递归版本
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
    ListNode* node = nullptr;
    bool isPalindrome(ListNode* head) {
        //递归版本的写法，非常的巧妙，特别是用的这个node全局变量来维护
        node = head;
        return solve(node);
    }

    bool solve(ListNode* head){
        /*
            一开始，node是head，然后head就因为!solve(head -> next)一直递归到最后一个点
            又因为最后一个点的next是nullptr，所以此时的solve(head -> next)就是true
            就跳到下面去判断此时node和head的值，不相等就false
            相等，就把node推到next（因为递归返回的过程就像是出栈，此时head就会回到倒数第二个结点）
            继续这样循环

            总结：这种做法非常巧妙地一点在于，用node维护了栈底
            因为递归的本质就是不断地把要算的东西积压到栈底，而回文链表是要两端比较地
            维护地全局变量刚好就弥补了这个缺点
        */
        if (head){
            if (!solve(head -> next)){
                return false;
            }
            if (head -> val != node -> val){
                return false;
            }
            node = node -> next;
        }
        return true;
    }
};