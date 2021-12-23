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
public:
    unordered_map<Node*, Node*> hash;
    Node* copyRandomList(Node* head) {
        if (!head){
            return nullptr;
        }

        if (!hash.count(head)){
            Node* node = new Node(head -> val);
            hash[head] = node;
            node -> next = copyRandomList(head -> next);
            node -> random = copyRandomList(head -> random);
        }
        
        return hash[head];
    }
};