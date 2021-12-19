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
    Node* copyRandomList(Node* head) {
        unordered_map<int, Node*> hash;
        Node *res = new Node(0), *result = res;
        Node* head1 = head;

        for (int i = 0; head1; i ++ ){
            Node* mid = new Node(head1 -> val);
            head1 -> val = i;
            hash[i] = mid;
            res -> next = mid;
            res = res -> next;
            head1 = head1 -> next;
        }

        head1 = head;
        for (res = result -> next; res; res = res -> next){
            res -> random = head1 -> random ? hash[head1 -> random -> val] : nullptr;
            head1 = head1 -> next;
        }

        return result -> next;
    }
};