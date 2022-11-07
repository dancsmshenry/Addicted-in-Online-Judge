/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> map_;
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }

        if (!map_.count(head)) {
            Node *node = new Node(head -> val);
            map_[head] = node;
            node -> next = copyRandomList(head -> next);
            node -> random = copyRandomList(head -> random);
        }

        return map_[head];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        for (Node *node = head; node != nullptr; node = node -> next -> next) {
            Node *temp = new Node(node -> val);
            temp -> next = node -> next;
            node -> next = temp;
        }

        for (Node *node = head; node != nullptr; node = node -> next -> next) {
            if (node -> random != nullptr) {
                node -> next -> random = node -> random -> next;
            }
        }
        
        Node *res = head -> next;
        for (Node *node = head; node != nullptr; node = node -> next) {
            Node *temp = node -> next;
            node -> next = temp -> next;
            temp -> next = (node -> next == nullptr) ? nullptr: temp -> next -> next;
        }

        return res;
    }
};